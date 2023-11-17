//
// Created by Oussaama Ammar El Idrissi on 17/11/2023.
//

#ifndef PENDU_PENDU_H
#define PENDU_PENDU_H
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 15 // constante

// Declaration of the global array
extern char tab[100][MAX_LEN];

// Function declaration
void afficherCadre();
void afficherPendu();
char* Word(char tab[100][MAX_LEN]);
void Mot_Cache(char* res);
#endif //PENDU_PENDU_H
