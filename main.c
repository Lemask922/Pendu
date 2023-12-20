#include<stdio.h>
#include <stdio.h>
#include"Pendu.h"

#include<string.h>
#include "/Users/abouda/Desktop/Esiea/Project CCCCCC/raylib-master/src/raylib.h"
#define MAX_INPUT_CHARS 1


int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Bienvenu to Pendu");

    char name[MAX_INPUT_CHARS + 1] = "\0";
    char name2[MAX_INPUT_CHARS + 1] = "\0";
    char* res;
    char tmp[MAX_LEN + 1];

    Rectangle inputBox = {screenWidth / 2 - 100, screenHeight / 2 - 20, 200, 40};
    Rectangle inputBoxTheme = {screenWidth / 2 - 100, screenHeight / 2 - 20, 200, 40};
    Rectangle StartGuess = {screenWidth / 2 - 100, screenHeight - 60, 200, 40};
    Rectangle InputLetterBox = {screenWidth / 2 - 100, screenHeight / 2 - 20 - 40, 200, 40};
    Rectangle startButton = {50, 300, 200, 50};
    Rectangle OkButton = {screenWidth / 2 - 100, screenHeight / 2 - 20 + 50, 200, 40};
    Rectangle OKButtonTheme = {screenWidth / 2 - 100, screenHeight / 2 - 20 + 50, 200, 40};

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

    enum Windows Window = WELCOME_Window;

    struct Track *Scores = NULL;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (Window) {
            case WELCOME_Window:
                if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    startGame = true;
                }

                if (startGame) {
                    Window = LEVEL_SELECTION_Window; // Met à jour la fenêtre vers la Sélection du Niveau

                    CloseWindow();
                    InitWindow(screenWidth, screenHeight, "Difficulty");
                    SetTargetFPS(60);
                }

                DrawText("Bienvenue au Pendu", 50, 100, 30, BLACK);
                DrawText("Instructions:", 50, 150, 20, BLACK);
                DrawText("- Devinez le mot caché en entrant des lettres", 50, 180, 20, BLACK);
                DrawText("- Vous avez 6 vies. Chaque supposition incorrecte coûte une vie.", 50, 210, 20, BLACK);
                DrawText("- Essayez de deviner le mot avant de manquer de vies.", 50, 240, 20, BLACK);

                DrawRectangleRec(startButton, LIGHTGRAY);
                DrawText("Start Game", startButton.x + 40, startButton.y + 10, 20, BLACK);
                break;

            case LEVEL_SELECTION_Window:

                if (CheckCollisionPointRec(GetMousePosition(), inputBox)) mouseOnText = true;
                else mouseOnText = false;
                DrawRectangleRec(inputBox, LIGHTGRAY);

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
                DrawText("Choisissez votre niveau de jeu", 50, 100, 20, BLACK);
                DrawText("1 - Facile", 50, 150, 20, BLACK);
                DrawText("2 - Moyen", 50, 180, 20, BLACK);
                DrawText("3 - Difficile", 50, 210, 20, BLACK);
                DrawText(name, (int) inputBox.x + 5, (int) inputBox.y + 10, 20, BLACK);
                DrawRectangleRec(OkButton, LIGHTGRAY);

                DrawText("Ok", (int) OkButton.x + 40, (int) OkButton.y + 10, 20, BLACK);
                if (mouseOnText) framesCounter++;
                break;

            case Start_Window:

                if (CheckCollisionPointRec(GetMousePosition(), inputBoxTheme)) mouseOnText2 = true;
                else mouseOnText2 = false;
                DrawRectangleRec(inputBoxTheme, LIGHTGRAY);

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
                DrawText("Choisissez votre thème ", 50, 100, 20, BLACK);
                DrawText("1 - Animaux",50,150,20,BLACK);
                DrawText("2 - Ville",50,180,20,BLACK);
                DrawText("3 - Film",50,210,20,BLACK);
                DrawRectangleRec(OKButtonTheme, LIGHTGRAY);
                DrawText(name2,(int) inputBoxTheme.x + 5, (int) inputBoxTheme.y + 10, 20, BLACK);
                DrawText("Ok", (int) OKButtonTheme.x + 40, (int) OKButtonTheme.y + 10, 20, BLACK);
                if (mouseOnText2) framesCounter2++;
                break;
                break;

            case game_window:
                DrawRectangleRec(StartGuess,LIGHTGRAY);
                DrawText("Start guessing", (int)(StartGuess.x + (StartGuess.width - MeasureText("Start guessing", 20)) / 2), (int)(StartGuess.y + StartGuess.height / 2 - 10), 20, BLACK);
                drawHangman();
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
                ScoresTable(Scores,i);
                break;
        }

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
