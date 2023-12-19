#include<stdio.h>
#include <stdio.h>
#include"Pendu.h"

#include<string.h>
#include"./raylib-master/src/raylib.h"
#define MAX_INPUT_CHARS 1
int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    typedef enum{
        startScreen,
        levelScreen,
        topicScreen,
        penduScreen
    } gameScreen;

    InitWindow(screenWidth, screenHeight, "Welcome to Pendu");



        gameScreen currentScreen = startScreen;
        switch (currentScreen) {
            case levelScreen:
                levelScreen();
                break;
            case topicScreen:
                break;
            case penduScreen:
                break;
            defaut :
                startScreen;
            break;
        }


        EndDrawing();
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
