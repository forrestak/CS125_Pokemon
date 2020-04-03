/*  CS125_Pokemon
    CS125 Programming Project
    battleui.c
    Retry at battle UI File
*/
//temporarily removing the h files on my side so i can work on the project
//no clue how to compile with folders/directories
// Header File
//#include "battleUI.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
 #include "pokeFilesBubble.c"


//////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//changes made on 4/3/2020
void printPixel(char screen[33][65],char colorScreen[33][65],int x, int y){
//        printf("\033[0;31m");//red
//        printf("\033[0m");//white
//        printf("\e[0;34m");//blue
//        printf("\e[0;32m");//green
//        printf("\e[0;35m");//purple
//        printf("\e[0;33m");//yellow
if(colorScreen[x][y]=='r')
        printf("\033[0;31m");
if(colorScreen[x][y]=='w')
        printf("\033[0m");
if(colorScreen[x][y]=='b')
        printf("\e[0;34m");
if(colorScreen[x][y]=='g')
        printf("\e[0;32m");
if(colorScreen[x][y]=='p')
        printf("\e[0;35m");
if(colorScreen[x][y]=='y')
        printf("\e[0;33m");




printf("%c",screen[x][y]);
}
//////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



// void getPokemon(char holder[17][31],int pokemonIndex);
void getPokemon(char [][31],int);
void delay(int);
void clear();

void delay(int milliseconds)
{
    milliseconds*=1000;
    clock_t start_time =clock();
    while(clock()<start_time + milliseconds);
}

void clear()
{
    printf("\e[2J\e[H");
}
void run(char screen[33][65],char colorScreen[33][65])
{
    int x=0;
    int y=0;
    for(x=0;x<33;x++)
    {

        for(y=0;y<65;y++)
        {
        //printf("%c",screen[x][y]);
        printPixel(screen,colorScreen,x,y);    
    //printpixel will go here
        }
    printf("\n");
    }   
}
///////////////////////////////////////
void changeText(char screen[33][65],int xScreenPos,int yScreenPos,char sentence[])
{
    char spareLine[65];
    char secondSpareLine[65];
    char completeSpareLine[65];

    strncpy(spareLine,screen[yScreenPos],xScreenPos);
    strncpy(secondSpareLine,screen[yScreenPos]+xScreenPos+strlen(sentence),65);
    strcat(completeSpareLine,spareLine);
    strcat(completeSpareLine,sentence);
    strcat(completeSpareLine,secondSpareLine);
    strncpy(screen[yScreenPos],completeSpareLine,65);

}

///////////////////////////////////////
void changeEnemyPokemon(char screen[33][65],int pokemonIndex)
{
    int count;
    char enemyPokemon[17][31];
    char cleanSpare[65-30];
    char spare[65-30];
    char completeSpare[65];
    char cleanCompleteSpare[65];
    getPokemon(enemyPokemon,pokemonIndex);
    for(count=0;count<16;count++)
    {
        memcpy(spare,cleanSpare,sizeof(spare));
        memcpy(completeSpare,cleanCompleteSpare,sizeof(completeSpare));
        strncpy(spare,enemyPokemon[count],30);
        strncpy(completeSpare,screen[count],34);
        strcat(completeSpare,spare);
        strncpy(screen[count],completeSpare,64);
    }
}

///////////////////////////////////////
void changePlayerPokemon(char screen[33][65],int pokemonIndex)
{

//screen[33]="0123456789012345678901234567890123456789012345678901234567890123";


    int count;
    int shift=16;//how down
    char enemyPokemon[17][31];
    char cleanSpare[65-30];
    char spare[65-30];
    char completeSpare[65];
    char cleanCompleteSpare[65];
    char dummy[10]="hellodummy";
    getPokemon(enemyPokemon,pokemonIndex);
    for(count=shift+0;count<16+shift;count++)
    {
        memcpy(spare,cleanSpare,sizeof(spare));
        memcpy(completeSpare,cleanCompleteSpare,sizeof(completeSpare));
        strncpy(completeSpare,enemyPokemon[count-shift],31);
        strncpy(spare,screen[count]+30,65-31);
        strcat(completeSpare,spare);
        strncpy(screen[count],completeSpare,64);
    }
}
///////////////////////////////////////
//////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//changes made on x/x/2020
//////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
void battleUI()
{
  clear();
  //32 rows, 64 columns
  char screen[33][65] ={
    "+--------------------------------+-----------------------------+",
    "|insert name here6789012345678901|23456789012345678901234567890|",
    "|graphical health6789012345678901|23456789012345678901234567890|",
    "|numerical stuff56789012345678901|23456789012345678901234567890|",
    "|graphical exp3456789012345678901|23456789012345678901234567890|",
    "+--------------------------------+23456789012345678901234567890|",
    "                                  34567890123456789012345678901|",
    "                                  34567890123456789012345678901|",
    "                                  34567890123456789012345678901|",
    "                                  34567890123456789012345678901|",
    "                                  34567890123456789012345678901|",
    "                                  34567890123456789012345678901|",
    "                                  34567890123456789012345678901|",
    "                                  34567890123456789012345678901|",
    "                                  34567890123456789012345678901|",
    "                                  34567890123456789012345678901|",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678                                  ",
    "|01234567890123456789012345678+--------------------------------+",
    "|01234567890123456789012345678|insert name here6789012345678901|",
    "|01234567890123456789012345678|graphical hpalth6789012345678901|",
    "|01234567890123456789012345678|numerical stuffh6789012345678901|",
    "|01234567890123456789012345678|graphical exp3456789012345678901|",
    "+-----------------------------+--------------------------------+",};

    char colorScreen[33][65]={
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwgggggggggbbbbbgbgbgwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwpppppppppppwwwwwyyyywwwww",};
    

    //bot left pokemon 30 width
    //top right pokemon 32 width? wtf
    //test 16 lines height
    //30 char width

    //changeText(screen,1,1,"not pikachu");
    char testInput[100];
    int testInputInt=1;
    int ice;
    for(ice=1;ice<=151;ice++)
    {
      //printf("here%d\n",testInputInt);
      changeEnemyPokemon(screen,testInputInt);
      //    changeEnemyPokemon(screen,ice);
      //    changePlayerPokemon(screen,152-ice);
      changePlayerPokemon(screen,152-testInputInt);
      run(screen,colorScreen);
      delay(100);
      scanf("%s",testInput);
      testInputInt=atoi(testInput);
      clear();
    }
}
int main()
{
battleUI();
}
