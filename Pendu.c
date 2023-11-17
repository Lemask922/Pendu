//
// Created by Oussaama Ammar El Idrissi on 17/11/2023.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include"Pendu.h"
#include<string.h>
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

void afficherCadre(int largeur) {
    for (int i = 0; i < largeur; i++) {
        printf("-");
    }
    printf("\n");
}

void afficherPendu() {
    // Affiche le cadre supérieur
    afficherCadre(26);

    // Affiche les lignes du milieu avec le dessin du pendu
    printf("|                          |\n");
    printf("|                          |\n");
    printf("|");
    // Dessin du pendu
    printf(" +------+      \n");
    printf(" |     |\n");
    printf(" |     O\n");
    printf(" |    /|\\\n");
    printf(" |    / \\\n");
    printf("_|_\n");
    printf(" Le pendu!\n");
    printf("|                          |\n");
    printf("|                          |\n");

    // Affiche le cadre inférieur
    afficherCadre(26);
}

char* Word(char tab[100][15])
{
    srand(time(NULL)); // initialisation de la fonction rand
    int value = rand() % 101; // intervalle de la fonction
    char* result = malloc(15 * sizeof(char)); // allouer de la mémoire pour le resultat

    strncpy(result, tab[value], 15); //copie de chaine de caractère dans une autre avec la limite de 15
    return result;
}
void Mot_Cache(char* res)
{
    int L = strlen(res);
    for (int i = 0; i < L; i++)
    {
        printf("-");
    }
}