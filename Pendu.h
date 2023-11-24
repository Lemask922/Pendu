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
extern char tab[100][MAX_LEN];

// Function declaration
char* Word(char tab[100][MAX_LEN]);
void Mot_Cache(char* res,char* tmp);
void deviner(char* res, char* tmp, bool* verif) ;

#endif //PENDU_PENDU_H
