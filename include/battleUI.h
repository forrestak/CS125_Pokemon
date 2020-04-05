/*  CS125 Group Project
    File: battleUI.h
    Description: Header file to include battleUI.c functions and global variables
    Authors: Vince Trance, Forrest Mobley, Colton Van Orsdel
    References: N/A
*/

#ifndef BATTLEUI
#define BATTLEUI

// Global variables
extern char USERNAME[50];
extern char PLAYERPOKEMONCHOICE[20];
extern char NPCPOKEMONCHOICE[20];
extern int WINORLOSE;

// Function prototypes
void run(char [][65], char [][65]);
void changeText(char [][65],int,int,char []);
void changeEnemyPokemon(char [][65],int);
void changePlayerPokemon(char [][65],int);
void battleUI();

#endif
