#include<stdio.h>
#include <stdio.h>
#include"Pendu.h"
#include<string.h>


int main() {

    printf("Bienvenue dans le jeu du pendu!\n");

    // Appel de la fonction pour afficher le pendu
    afficherPendu();

    char* res;
    res = Word(tab);

    printf("Le nom tire par hasard = %s \n", res);

    Mot_Cache(res);
    free(res);
    return 0;
}