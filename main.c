#include<stdio.h>
#include <stdio.h>
#include"Pendu.h"

#include<string.h>
#include "/Users/abouda/Desktop/Esiea/Project CCCCCC/raylib-master/src/raylib.h"
#define MAX_INPUT_CHARS 1


int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Welcome to Pendu");

    char name[MAX_INPUT_CHARS + 1] = "\0";
    char name2[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount = 0;
    int letterCount2 = 0;
    bool mouseOnText = false;
    bool mouseOnText2 = false ;
    int framesCounter = 0;
    int framesCounter2 = 0;

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
    bool tmpGenerated = false;

    int theme ;
    int lvl ;

    char* res;
    char tmp[MAX_LEN + 1];
    int life = 6;
    bool verif;
    int Play = 1;


    enum GameState currentState = WELCOME_SCREEN;

    while (!WindowShouldClose()) {
        // Update
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (currentState) {
            case WELCOME_SCREEN:
                if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    startGame = true;
                }

                if (startGame) {
                    currentState = LEVEL_SELECTION_SCREEN;
                    CloseWindow();
                    InitWindow(screenWidth, screenHeight, "Difficulty");
                    SetTargetFPS(60);
                }
                DrawText("Welcome to Pendu", 50, 100, 30, BLACK);
                DrawText("Instructions:", 50, 150, 20, BLACK);
                DrawText("- Guess the hidden word by entering letters.", 50, 180, 20, BLACK);
                DrawText("- You have 6 lives. Each incorrect guess costs a life.", 50, 210, 20, BLACK);
                DrawText("- Try to guess the word before running out of lives.", 50, 240, 20, BLACK);

                DrawRectangleRec(startButton, LIGHTGRAY);
                DrawText("Start Game", startButton.x + 40, startButton.y + 10, 20, BLACK);
                break;

            case LEVEL_SELECTION_SCREEN:

                if (CheckCollisionPointRec(GetMousePosition(), inputBox)) mouseOnText = true;
                else mouseOnText = false;
                DrawRectangleRec(inputBox, LIGHTGRAY);

                if (mouseOnText) {

                // Set the window's cursor to the I-Beam
                SetMouseCursor(MOUSE_CURSOR_IBEAM);

                // Get char pressed (unicode character) on the queue
                int key = GetCharPressed();

                // Check if more characters have been pressed on the same frame
                while (key > 0) {
                    // NOTE: Only allow keys in range [32..125]
                    if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
                        name[letterCount] = (char) key;
                        name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
                        letterCount++;
                    }

                    key = GetCharPressed(); // Check next character in the queue
                }

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

                if ((Conti) && ((strcmp(name, "1") == 0) || (strcmp(name, "2") == 0) || (strcmp(name, "3") == 0))) {
                    currentState = THIRD_WINDOW;
                    CloseWindow();
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

            case THIRD_WINDOW:

                if (CheckCollisionPointRec(GetMousePosition(), inputBoxTheme)) mouseOnText2 = true;
                else mouseOnText2 = false;
                DrawRectangleRec(inputBoxTheme, LIGHTGRAY);

                if (mouseOnText2) {

                    // Set the window's cursor to the I-Beam
                    SetMouseCursor(MOUSE_CURSOR_IBEAM);

                    // Get char pressed (unicode character) on the queue
                    int key2 = GetCharPressed();

                    // Check if more characters have been pressed on the same
                    while (key2 > 0) {
                        // NOTE: Only allow keys in range [32..125]
                        if ((key2 >= 32) && (key2 <= 125) && (letterCount2 < MAX_INPUT_CHARS)) {
                            name2[letterCount2] = (char) key2;
                            name2[letterCount2 + 1] = '\0'; // Add null terminator at the end of the string.
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
                    currentState = game_window;
                    CloseWindow();
                    InitWindow(screenWidth, screenHeight, "Game");
                    SetTargetFPS(60);
                }
                DrawText("Choisissez votre thème ", 50, 100, 20, BLACK);
                DrawText("1 - Animaux",50,150,20,BLACK);
                DrawText("2 - Ville",50,180,20,BLACK);
                DrawText("2 - Film",50,210,20,BLACK);
                DrawRectangleRec(OKButtonTheme, LIGHTGRAY);
                DrawText(name2,(int) inputBoxTheme.x + 5, (int) inputBoxTheme.y + 10, 20, BLACK);
                DrawText("Ok", (int) OKButtonTheme.x + 40, (int) OKButtonTheme.y + 10, 20, BLACK);
                if (mouseOnText2) framesCounter2++;
                break;
                break;

            case game_window:

                if (CheckCollisionPointRec(GetMousePosition(), StartGuess) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    startguess = true;
                }

                if (startguess)
                {
                    theme = atoi(name2);
                    lvl = atoi(name);

                    switch (theme) {
                        case 1:
                            switch (lvl) {

                                case 1:
                                    res = Word(animauxFacile);
                                    break;

                                case 2:
                                    res = Word(animauxMoyen);
                                    break;
                                case 3:
                                    res = Word(animauxDifficile);
                                    break;

                                default:
                                    printf("Erreur causé au niveau du thème animaux, des niveaux");
                                    break;
                            }

                            break;

                        case 2:
                            switch (lvl) {

                                case 1:
                                    res = Word(villesFacile);
                                    break;

                                case 2:
                                    res = Word(villesMoyen);
                                    break;
                                case 3:
                                    res = Word(villesDifficile);
                                    break;
                                default:
                                    printf("Erreur causé au niveau du thème villes, des niveaux");
                                    break;
                            }
                            break;
                        case 3:
                            switch (lvl) {

                                case 1:
                                    res = Word(filmsFacile);
                                    break;

                                case 2:
                                    res = Word(filmsMoyen);
                                    break;
                                case 3:
                                    res = Word(filmsDifficile);
                                    break;
                                default:
                                    printf("Erreur causé au niveau du thème films, des niveaux");
                                    break;
                            }
                            break;
                    }

                    int i = 0;
                    while(Play == 1)
                    {

                        printf("Game %d \n",i);
                        Mot_Cache(res, tmp);
                        printf("%s\n", tmp);
                        life = 6;

                        //Scores = realloc(Scores, (i +1 ) * sizeof(struct Track));

                        while (life > 0 && strcmp(res, tmp) != 0) { // tant que vie >0 et res n'est pas égale à tmp
                            dessine_pendu(life);
                            deviner(&res, &tmp, &verif);
                            printf("%s\n", tmp);

                            if (!verif) {
                                life--;
                                printf("Il vous reste %d vies.\n", life);
                                DrawText("2 - Moyen", 50, 180, 20, BLACK);

                            }

                        }
                        //Scores[i]->score = Scores[i]->FoundLetters* Scores[i]->FoundLettersNum;

                        if (strcmp(res, tmp) == 0) {
                            printf("Félicitations ! Vous avez deviné le mot : %s\n", res);
                            //printf("Score = %d\n",Scores[i].score);

                        } else {
                            printf("Désolé, vous avez épuisé toutes vos vies. Le mot était : %s\n", res);
                            //printf("Score = %d\n",Scores[i].score);
                        }

                        i++;
                        printf("Taper 1 si vous voulez Commencer une nouvelle partie \n");
                        printf("Taper 0 si vous voulez quittez le jeu \n");
                        scanf("%d",&Play);

                    }



                }
        }

        EndDrawing();

    }

    CloseWindow();


/*
    //struct Track *Scores = NULL;
    //int score = 60 ;
    //int theme = sujet();
    theme = atoi(name2);
    lvl = atoi(name);
    //int lvl = niveau_jeu();

    switch (theme) {
        case 1:
            switch (lvl) {

                case 1:
                    res = Word(animauxFacile);
                    break;

                case 2:
                    res = Word(animauxMoyen);
                    break;
                case 3:
                    res = Word(animauxDifficile);
                    break;

                default:
                    printf("Erreur causé au niveau du thème animaux, des niveaux");
                    break;
            }

            break;

        case 2:
            switch (lvl) {

                case 1:
                    res = Word(villesFacile);
                    break;

                case 2:
                    res = Word(villesMoyen);
                    break;
                case 3:
                    res = Word(villesDifficile);
                    break;
                default:
                    printf("Erreur causé au niveau du thème villes, des niveaux");
                    break;
            }
            break;
        case 3:
            switch (lvl) {

                case 1:
                    res = Word(filmsFacile);
                    break;

                case 2:
                    res = Word(filmsMoyen);
                    break;
                case 3:
                    res = Word(filmsDifficile);
                    break;
                default:
                    printf("Erreur causé au niveau du thème films, des niveaux");
                    break;
            }
            break;
    }

    int life = 6;
    bool verif;
    int Play = 1;

    //printf("Le nom tire par hasard est  = %s\n", res);



int i = 0;
//int score = 0;
while(Play == 1)
{

    printf("Game %d \n",i);
    Mot_Cache(res, tmp);
    printf("%s\n", tmp);
    life = 6;

    //Scores = realloc(Scores, (i +1 ) * sizeof(struct Track));

    while (life > 0 && strcmp(res, tmp) != 0) { // tant que vie >0 et res n'est pas égale à tmp
        dessine_pendu(life);
        deviner(&res, &tmp, &verif);
        printf("%s\n", tmp);

        if (!verif) {
            life--;
            printf("Il vous reste %d vies.\n", life);

        }

    }
    //Scores[i]->score = Scores[i]->FoundLetters* Scores[i]->FoundLettersNum;

    if (strcmp(res, tmp) == 0) {
            printf("Félicitations ! Vous avez deviné le mot : %s\n", res);
            //printf("Score = %d\n",Scores[i].score);

        } else {
            printf("Désolé, vous avez épuisé toutes vos vies. Le mot était : %s\n", res);
            //printf("Score = %d\n",Scores[i].score);
        }

        i++;
        printf("Taper 1 si vous voulez Commencer une nouvelle partie \n");
        printf("Taper 0 si vous voulez quittez le jeu \n");
        scanf("%d",&Play);
    }



*/

    return 0;
}
