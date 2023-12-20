//
// Created by aboudaay on 17/11/2023.
//

#ifndef PENDU_PENDU_H
#define PENDU_PENDU_H
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define MAX_LEN 15


struct Track
{
    int score ;
};


enum Windows {
    WELCOME_Window,
    LEVEL_SELECTION_Window,
    Start_Window,
    game_window,
    ScoreWindow
};

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
char* Settings(int theme,int lvl,char* res);
bool deviner(char* res, char* tmp);
void game(int i,char* res,char tmp[MAX_LEN + 1],int life,bool* verif);
void drawHangman();
void dessine_pendu(int life);
void ScoresTable(struct Track *Scores, int i);

#endif //PENDU_PENDU_H
