//
// Created by aboudaay on 17/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include"Pendu.h"
#include<string.h>
#include <time.h>
#include <ctype.h>


char tab[100][15] = {
        "Aventure", "Énigme", "Mystère", "Fantaisie", "Magie",
        "Labyrinthe", "Exploration", "Evasion", "Conquête", "Héros",
        "Légende", "Trésor", "Épique", "Sirène", "Chimère",
        "Dragon", "Sorcellerie", "Quête", "Enchanté", "Alliance",
        "Potion", "Courage", "Voyage", "Oracle", "Destin",
        "Illusion", "Éclat", "Renaissance", "Sagesse", "Vision",
        "Harmonie", "Création", "Insolite", "Incantation", "Rêverie",
        "Odyssée", "Phénix", "Portail", "Révélation", "Harmonie",
        "Destinée", "Éclipse", "Miraculeux", "Persévérance", "Fraternité",
        "Merveille", "Secret", "Nirvana", "Vortex", "Mirage",
        "Esprit", "Mirage", "Illimité", "Extase", "Divin",
        "Délire", "Astre", "Mirage", "Illimité", "Extase",
        "Divin", "Délire", "Astre", "Mirage", "Illimité",
        "Extase", "Divin", "Délire", "Astre", "Mirage",
        "Illimité", "Extase", "Divin", "Délire", "Astre",
        "Mirage", "Illimité", "Extase", "Divin", "Délire",
        "Astre", "Mirage", "Illimité", "Extase", "Divin",
        "Délire", "Astre", "Mirage", "Illimité", "Extase",
        "Divin", "Délire", "Astre", "Mirage", "Illimité",
        "Extase", "Divin", "Délire", "Astre", "Mirage"
};
char* Word(char tab[100][15])
{
    srand(time(NULL)); // initialisation de la fonction rand
    int value = rand() % 101; // intervalle de la fonction
    char* result = malloc(15 * sizeof(char)); // allouer de la mémoire pour le resultat

    strncpy(result, tab[value], 14); // Copy up to 14 characters from tab[value] to result
    result[14] = '\0'; // Null-terminate the result string
    return result;
}
void Mot_Cache(char* res, char* tmp)
{
    int L = strlen(res);
    for (int i = 0; i < L; i++)
    {
        tmp[i]='-';
    }
    tmp[L] = '\0';
}

void deviner(char* res, char* tmp, bool* verif) {
    char Lettre;
    *verif = false;

    printf("Saisir une lettre : \n");
    scanf(" %c", &Lettre);

    for (int i = 0; i < strlen(res); i++) {
        if (toupper(Lettre) == toupper(res[i])) {
            tmp[i] = res[i];
            *verif = true;
        }
    }

    if (!(*verif)) {
        printf("La lettre %c n'est pas dans le mot.\n", Lettre);
    }
}
//
// Created by Abouda on 23/11/2023.
//
