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
void printPixel(char [][65], char [][65], int, int);
void run(char [][65], char [][65]);
void changeText(char [][65],int,int,char []);
void changeColor(char [][65], int, int, char);
void removeBackBlanks(char []);
void changeEnemyName(char [][65],char [][65],char [],char);
void changePlayerName(char [][65],char [][65],char [],char);
void changeEnemyHp(char [][65],float,float);
void changePlayerHp(char [][65],float,float);
void changeEnemyType(char [][65],char [][65],char);
void changePlayerType(char [][65], char [][65],char);
void changeEnemyLvl(char [][65],int);
void changePlayerLvl(char [][65],int);
void changeEnemyXp(char [][65],int);
void changePlayerXp(char [][65],int);
void changeEnemyMove1(char [][65],char []);
void changeEnemyMove2(char [][65],char []);
void changePlayerMove1(char [][65],char []);
void changePlayerMove2(char [][65],char []);
void changeEnemyUltimate(char [][65],char [],int);
void changePlayerUltimate(char [][65],char [],int);
void changeEnemyConsumable(char [][65],char [],int,int);
void changePlayerConsumable(char [][65],char [],int,int);
void resetScreen(char [][65]);
void resetColorScreen(char [][65]);
void changeEnemyPokemon(char [][65],int);
void changePlayerPokemon(char [][65],int);
void battleUI(int);
void displayScreen();

#endif
