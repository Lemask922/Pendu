#include<stdio.h>
#include <stdio.h>
#include"Pendu.h"

#include<string.h>
#include "/Users/abouda/Desktop/Esiea/Project CCCCCC/raylib-master/src/raylib.h"
#define MAX_INPUT_CHARS 1
int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Welcome to Pendu");
    char name[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount = 0;
    bool mouseOnText = false;
    int framesCounter = 0;
    Rectangle startButton = {50, 300, 200, 50};
    Rectangle OkButton = {50, 50, 50, 50};
    bool startGame = false;
    bool Conti = false;

    while (!WindowShouldClose()) {
        // Update
        if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            startGame = true;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Welcome to Pendu", 50, 100, 30, BLACK);
        DrawText("Instructions:", 50, 150, 20, BLACK);
        DrawText("- Guess the hidden word by entering letters.", 50, 180, 20, BLACK);
        DrawText("- You have 6 lives. Each incorrect guess costs a life.", 50, 210, 20, BLACK);
        DrawText("- Try to guess the word before running out of lives.", 50, 240, 20, BLACK);

        DrawRectangleRec(startButton, LIGHTGRAY);
        DrawText("Start Game", startButton.x + 40, startButton.y + 10, 20, BLACK);

        EndDrawing();

        if (startGame) {
            CloseWindow();
            InitWindow(screenWidth, screenHeight, "Pendu Game");
            SetTargetFPS(60);

            while (!WindowShouldClose()) {
                // Update
                DrawText("Choisissez votre niveau de jeu", 50, 100, 20, BLACK);
                DrawText("1 - Facile", 50, 150, 20, BLACK);
                DrawText("2 - Moyen", 50, 180, 20, BLACK);
                DrawText("3 - Difficile", 50, 210, 20, BLACK);
                Rectangle inputBox = { screenWidth / 2 - 100, screenHeight / 2 - 20, 200, 40 };

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
                            name[letterCount] = (char)key;
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

                // Draw entered text
                DrawText(name, (int)inputBox.x + 5, (int)inputBox.y + 10, 20, BLACK);
                DrawRectangleRec(OkButton, LIGHTGRAY);
                DrawText("Ok", (int)OkButton.x + 50, (int)OkButton.y + 70, 20, BLACK);
                if (mouseOnText) framesCounter++;

                BeginDrawing();
                ClearBackground(RAYWHITE);
                if (CheckCollisionPointRec(GetMousePosition(), OkButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
                    (strcmp(name, "1") == 0)) {
                    Conti = true;
                }
                if (strcmp(name, "1") == 0 && Conti) {
                    InitWindow(screenWidth, screenHeight, "Window for '1'");
                }

                EndDrawing();


            }

            CloseWindow(); // Close the Pendu Game window
        }
    }

    CloseWindow();  // Close the welcome window



    //struct Track *Scores = NULL;
    //int score = 60 ;
    int theme = sujet();
    char* res;

    int lvl = niveau_jeu();
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

    char tmp[MAX_LEN + 1];
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





    return 0;
}
