#include<stdio.h>
#include <stdio.h>
#include"Pendu.h"
#include<string.h>

int main() {
    char* res;
    int theme = sujet();
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

    //printf("Le nom tire par hasard est  = %s\n", res);

    Mot_Cache(res, tmp);
    printf("%s\n", tmp);

    while (life > 0 && strcmp(res, tmp) != 0) { // tant que vie >0 et res n'est pas égale à tmp
        dessine_pendu(life);
        deviner(res, tmp, &verif);
        printf("%s\n", tmp);

        if (!verif) {
            life--;
            printf("Il vous reste %d vies.\n", life);
        }
    }

    if (strcmp(res, tmp) == 0) {
        printf("Félicitations ! Vous avez deviné le mot : %s\n", res);
        free(res);
    } else {
        printf("Désolé, vous avez épuisé toutes vos vies. Le mot était : %s\n", res);
        free(res);
    }

    free(res);
    return 0;
}
