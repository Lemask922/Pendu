//
// Created by aboudaay on 17/11/2023.
//

#ifndef PENDU_PENDU_H
#define PENDU_PENDU_H
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define MAX_LEN 15
//#define life 6

// Declaration of the global array
// extern char tab1[100][MAX_LEN];
// extern char tab2[100][MAX_LEN];
// extern char tab3[100][MAX_LEN];
extern char animauxFacile[50][MAX_LEN];
extern char animauxMoyen[50][MAX_LEN];
extern char animauxDifficile[50][MAX_LEN];
extern char villesFacile[50][MAX_LEN];
extern char villesMoyen[50][MAX_LEN];
extern char villesDifficile[50][MAX_LEN];
extern char filmsFacile[50][MAX_LEN];
extern char filmsMoyen[50][MAX_LEN];
extern char filmsDifficile[50][MAX_LEN];
// Function declaration
char* Word(char tab[50][MAX_LEN]);
void Mot_Cache(char* res,char* tmp);
void deviner(char* res, char* tmp, bool* verif);
        void dessine_pendu(int life);
int niveau_jeu();
int sujet();




#endif //PENDU_PENDU_H
