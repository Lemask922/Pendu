#include<stdio.h>
#include <stdio.h>
#include"Pendu.h"
#include<string.h>

int main() {

    char* res;
    char tmp[MAX_LEN + 1];
    res = Word(tab);
    int life = 6;
    bool verif;

    printf("Le nom tire par hasard est  = %s\n", res);

    Mot_Cache(res, tmp);
    printf("%s\n", tmp);

    while (life > 0 && strcmp(res, tmp) != 0) {
        deviner(res, tmp, &verif);
        printf("%s\n", tmp);

        if (!verif) {
            life--;
            printf("Il vous reste %d vies.\n", life);
        }
    }

    if (strcmp(res, tmp) == 0) {
        printf("Félicitations ! Vous avez deviné le mot : %s\n", res);
    } else {
        printf("Désolé, vous avez épuisé toutes vos vies. Le mot était : %s\n", res);
    }

    free(res);
    return 0;
}
