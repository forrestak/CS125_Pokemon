/*  CS125_Pokemon
    CS125 Programming Project
    battleui.c
    Retry at battle UI File
*/

// Header File
#include "battleUI.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
// #include "pokeFiles.c"


// void getPokemon(char holder[17][31],int pokemonIndex);
void getPokemon(char [][31],int);
void delay(int);
void clear();


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

void run(char screen[33][65], char colorScreen[33][65])
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
//////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///////////////////////////////////////
void changeText(char screen[33][65],int xScreenPos,int yScreenPos,char sentence[])
{
    fflush(stdout);
    char spareLine[65]="";
    char secondSpareLine[65]="";
    char completeSpareLine[65]="";
    //literally had an issue because i didnt intialize the chars with an empty string
    //printf("screenq%s\n",screen[yScreenPos]);
    strncpy(spareLine,screen[yScreenPos],xScreenPos);
    //printf("spare q%s\n",spareLine);
    strncpy(secondSpareLine,screen[yScreenPos]+xScreenPos+strlen(sentence),65);
    //printf("2ndsreq%s\n",secondSpareLine);
    //next three functions are to put together the final result
    strncpy(completeSpareLine,spareLine,strlen(spareLine));
    //printf("final1q%s\n",completeSpareLine);
    strcat(completeSpareLine,sentence);
    //printf("final2q%s\n",completeSpareLine);
    strcat(completeSpareLine,secondSpareLine);
    //printf("final3q%s\n",completeSpareLine);
    //copy the final result
    strncpy(screen[yScreenPos],completeSpareLine,65);
    //printf("last  q%s\n",screen[yScreenPos]);

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

    char testInput[100];
    int testInputInt=1;
    int ice;
    changeText(screen,3,3,"wheee");
    changeText(screen,0,0,"asparagus");
    changeText(screen,8,3,"waffles");
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
