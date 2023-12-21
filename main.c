#include<stdio.h>
#include"Pendu.h"
#include<string.h>
#include "raylib.h"
#define MAX_INPUT_CHARS 1


int main(void) {
    const int screenWidth = 1050;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Bienvenu to Pendu");

    Texture2D backgroundImage = LoadTexture("/Users/abouda/Desktop/Esiea/Project CCCCCC/Pendu/Background.png");

    if (backgroundImage.id == 0) {
        printf("Failed to load background image.\n");
        CloseWindow();
        return -1;
    } // Boucle utilisé pour verifier si l'image est correctement loader
      // un utilisateur pourra avoir besoin si il a des problemes avec le background image


    char name[MAX_INPUT_CHARS + 1] = "\0";
    char name2[MAX_INPUT_CHARS + 1] = "\0";
    char* res;
    char tmp[MAX_LEN + 1];

    Rectangle inputBox = {screenWidth / 2 - 150, screenHeight / 2 + 140, 200, 40};
    Rectangle inputBoxTheme = {screenWidth / 2 - 150, screenHeight / 2 + 140, 200, 40};
    Rectangle StartGuess = {screenWidth / 2 - 150, screenHeight - 60, 200, 40};
    Rectangle InputLetterBox = {screenWidth / 2 - 100, screenHeight / 2 - 20 - 40, 200, 40};
    Rectangle startButton = {50, 300, 200, 50};
    Rectangle OkButton = {screenWidth / 2 - 150, screenHeight / 2 + 200, 200, 40};
    Rectangle OKButtonTheme = {screenWidth / 2 - 150, screenHeight / 2 + 200, 200, 40};

    bool startGame = false;
    bool startguess = false;
    bool Conti = false;
    bool Conti2 = false;
    bool verif = false;
    bool mouseOnText = false;
    bool mouseOnText2 = false ;

    int theme ;
    int lvl ;
    int i = 0;
    int life = 6;
    int Play = 1;
    int letterCount = 0;
    int letterCount2 = 0;
    int framesCounter = 0;
    int framesCounter2 = 0;

    float roundness = 0.4f;

    enum Windows Window = WELCOME_Window;

    struct Track *Scores = NULL;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);


        // Draw the background texture with scaling
        DrawTexture(backgroundImage, 0, 0, WHITE);

        switch (Window) {
            case WELCOME_Window:
                backgroundImage = LoadTexture("/Users/abouda/Desktop/Esiea/Project CCCCCC/Pendu/Background.png");

                if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    startGame = true;
                }

                if (startGame) {
                    Window = LEVEL_SELECTION_Window; // Met à jour la fenêtre vers la Sélection du Niveau

                    CloseWindow();
                    InitWindow(screenWidth, screenHeight, "Difficulty");

                    SetTargetFPS(60);
                }

                DrawText("Bienvenue au Pendu", 50, 100, 30, WHITE);
                DrawText("Instructions:", 50, 150, 20, WHITE);
                DrawText("- Devinez le mot caché en entrant des lettres", 50, 180, 20, WHITE);
                DrawText("- Vous avez 6 vies. Chaque supposition incorrecte coûte une vie.", 50, 210, 20, WHITE);
                DrawText("- Essayez de deviner le mot avant de manquer de vies.", 50, 240, 20, WHITE);

                DrawRectangleRounded(startButton,roundness,0, DARKBLUE);
                DrawText("Start Game", startButton.x + 40, startButton.y + 10, 20, BLACK);
                break;

            case LEVEL_SELECTION_Window:
                 backgroundImage = LoadTexture("/Users/abouda/Desktop/Esiea/Project CCCCCC/Pendu/Background.png");

                if (CheckCollisionPointRec(GetMousePosition(), inputBox)) mouseOnText = true;
                else mouseOnText = false;
                DrawRectangleRounded(inputBox,roundness,0, DARKBLUE);

                if (mouseOnText) {

                // Chosir le format du cursor = I-Beam
                SetMouseCursor(MOUSE_CURSOR_IBEAM);

                // récupérer le cartére saisi par le joueur
                int key = GetCharPressed();

                // verification de nombre de caracteres saisie par le joueur
                while (key > 0) {
                    // verification sur le carctere saisie par l'utilisateur qui doit etre un carctere visible
                    // par exmple ctrl n'est pas un carctere visible : verification avec le code ascii [32..125]
                    if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
                        name[letterCount] = (char) key;
                        name[letterCount + 1] = '\0'; // null terminator a la fin du string
                        letterCount++;
                    }
                    key= GetCharPressed(); // Check next character in the queue

                }
                // supprimer un carctere saisie
                if (IsKeyPressed(KEY_BACKSPACE)) {
                    letterCount--;
                    if (letterCount < 0) letterCount = 0;
                    name[letterCount] = '\0';
                }
        } else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            framesCounter = 0;
        }

                if (CheckCollisionPointRec(GetMousePosition(), OkButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Conti = true;
                }
                // le boolean conti sert a verifier si le joueur appuie sur OK
                if ((Conti) && ((strcmp(name, "1") == 0) || (strcmp(name, "2") == 0) || (strcmp(name, "3") == 0))) {
                    Window = Start_Window; // lorsque on appuie sur "ok" le Window se met a jour pour passer a prochaine Window
                    CloseWindow();// fermer le window courant
                    InitWindow(screenWidth, screenHeight, "Theme");
                    SetTargetFPS(60);
                }

                DrawText("Choisissez votre niveau de jeu", 50, 100, 20, WHITE);
                DrawText("1 - Facile", 50, 150, 20, WHITE);
                DrawText("2 - Moyen", 50, 180, 20, WHITE);
                DrawText("3 - Difficile", 50, 210, 20, WHITE);
                DrawText(name, (int) inputBox.x + 5, (int) inputBox.y + 10, 20, WHITE);
                DrawRectangleRounded(OkButton,roundness, 0,DARKBLUE);

                DrawText("Valider", (int) OkButton.x + 60, (int) OkButton.y + 10, 20, BLACK);
                if (mouseOnText) framesCounter++;
                break;

            case Start_Window:
                backgroundImage = LoadTexture("/Users/abouda/Desktop/Esiea/Project CCCCCC/Pendu/Background.png");

                if (CheckCollisionPointRec(GetMousePosition(), inputBoxTheme)) mouseOnText2 = true;
                else mouseOnText2 = false;
                DrawRectangleRounded(inputBoxTheme, roundness,0,DARKBLUE);

                if (mouseOnText2) {

                    SetMouseCursor(MOUSE_CURSOR_IBEAM);

                    int key2 = GetCharPressed();

                    while (key2 > 0) {
                        if ((key2 >= 32) && (key2 <= 125) && (letterCount2 < MAX_INPUT_CHARS)) {
                            name2[letterCount2] = (char) key2;
                            name2[letterCount2 + 1] = '\0';
                            letterCount2++;
                        }

                        key2 = GetCharPressed(); // Check next character in the queue
                    }

                    if (IsKeyPressed(KEY_BACKSPACE)) {
                        letterCount2--;
                        if (letterCount2 < 0) letterCount2 = 0;
                        name2[letterCount2] = '\0';
                    }
                } else {
                    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
                    framesCounter2 = 0;
                }

                if (CheckCollisionPointRec(GetMousePosition(), OKButtonTheme) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Conti2 = true;
                }

                if ((Conti2) && ((strcmp(name2, "1") == 0) || (strcmp(name2, "2") == 0) || (strcmp(name2, "3") == 0))) {
                    Window = game_window; // Met à jour la fenêtre vers game window
                    CloseWindow();
                    InitWindow(screenWidth, screenHeight, "Game");
                    SetTargetFPS(60);
                }
                DrawText("Choisissez votre thème ", 50, 100, 20, WHITE);
                DrawText("1 - Animaux",50,150,20,WHITE);
                DrawText("2 - Ville",50,180,20,WHITE);
                DrawText("3 - Film",50,210,20,WHITE);
                DrawRectangleRounded(OKButtonTheme,roundness,0, DARKBLUE);
                DrawText(name2,(int) inputBoxTheme.x + 5, (int) inputBoxTheme.y + 10, 20, WHITE);
                DrawText("Valider", (int) OKButtonTheme.x + 60, (int) OKButtonTheme.y + 10, 20, BLACK);
                if (mouseOnText2) framesCounter2++;
                break;
                break;

            case game_window:
                backgroundImage = LoadTexture("/Users/abouda/Desktop/Esiea/Project CCCCCC/Pendu/Background.png");

                DrawRectangleRounded(StartGuess,roundness,0,DARKBLUE);
                DrawText("Start guessing", (int)(StartGuess.x + (StartGuess.width - MeasureText("Start guessing", 20)) / 2), (int)(StartGuess.y + StartGuess.height / 2 - 10), 20, BLACK);
                if (CheckCollisionPointRec(GetMousePosition(), StartGuess) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    startguess = true;
                }

                if (startguess)
                {

                    while(Play == 1)
                    {
                        theme = atoi(name2); // convertir name2 en int ( name2 c'est le string saisie par le joueur dans le inputboxtheme
                        lvl = atoi(name); // convertir name1 en int ( name1 c'est le string saise par le joueur dans le inputbox lvl
                        res = Settings(theme,lvl,res); // Utiliser lvl et theme pour generer le mot a deviner
                        printf("Game %d \n",i);
                        Mot_Cache(res, tmp); // cacher le mot
                        printf("%s\n", tmp);
                        printf("%s\n",res);
                        life = 6;
                        Scores = realloc(Scores, (i +1 ) * sizeof(struct Track));// allouer dynamiquement Scores a chaque fois le joueur joue une nouvelle partie

                        while (life > 0 && strcmp(res, tmp) != 0) {
                            dessine_pendu(life);
                            verif = deviner(res, tmp);
                            printf("%s\n", tmp);

                            if (!verif) {
                                life--;
                                printf("Il vous reste %d vies.\n", life);
                            }

                        }

                        if (strcmp(res, tmp) == 0) {
                            printf("Félicitations ! Vous avez deviné le mot : %s\n", res);
                            Scores[i].score = 10 * life; // le score est calculé a la base de vies restante pour un joueur qui a deviner le mot
                                                         // Un joueur qui a pas deviné le mot son score = 0
                            printf("Score = %d\n",Scores[i].score);
                        } else {
                            printf("Désolé, vous avez épuisé toutes vos vies. Le mot était : %s\n", res);
                            Scores[i].score = 0 ;
                            printf("Score = %d\n",Scores[i].score);
                        }

                        i++;

                        printf("Taper 1 si vous voulez Commencer une nouvelle partie \n");
                        printf("Taper 0 si vous voulez quittez le jeu \n");
                        scanf("%d",&Play);

                        if (Play == 0)
                        {
                            Window = ScoreWindow;
                            CloseWindow();
                            InitWindow(screenWidth, screenHeight, "Score");
                            SetTargetFPS(60);
                            ClearBackground(RAYWHITE);

                        }

                    }
                }

                break;
            case ScoreWindow:
                backgroundImage = LoadTexture("/Users/abouda/Desktop/Esiea/Project CCCCCC/Pendu/Background.png");
                ScoresTable(Scores,i);
                break;
        }

        EndDrawing();

    }
    UnloadTexture(backgroundImage);  // Unload background texture

    CloseWindow();

    return 0;
}
