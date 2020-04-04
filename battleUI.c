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
void changeColor(char colorScreen[33][65],int x, int y,char input){
    colorScreen[x][y]=input;
}
void removeBackBlanks(char shift[]){
    char copy[20]=""; //this is to right adjust the numbers
    char copy2[20]=" ";
    strncpy(copy,shift,strlen(shift)-1);
    strcat(copy2,copy);
    if(shift[strlen(shift)-1]==' ')
    {
        strncpy(shift,copy2,strlen(copy2));
        removeBackBlanks(shift);//recursion baby
    }

}
void changeEnemyName(char screen[33][65],char colorScreen[33][65],char enemyName[],char type){
    //g is grass,r is fire, b is water
    char emptyName[]="           ";//max name size is 11
    int count=0;
    strncpy(emptyName,enemyName,strlen(enemyName));
    changeText(screen,1,1,emptyName);
    for(count=0;count<11;count++)//also sorry,x isnt x and y isnt y
        changeColor(colorScreen,1,1+count,type);
}
void changePlayerName(char screen[33][65],char colorScreen[33][65],char playerName[],char type){
    char emptyName[]="           ";//max name size is 11
    int count=0;
    strncpy(emptyName,playerName,strlen(playerName));
    changeText(screen,31,28,emptyName);
    for(count=0;count<11;count++)//also sorry,x isnt x and y isnt y, must have mixed up somewhere
        changeColor(colorScreen,28,31+count,type);
}
void changeEnemyHp(char screen[33][65],int currentHp,int maxHp){
    fflush(stdin);
    char emptyName[13]="HP:[";//max name size is 13
    char emptyCurrentHp[]="    ";//max name size is 4(3 digits, 1 sign)
    char emptyCurrentHp2[]="    ";//max name size is 4(3 digits, 1 sign)
    char emptyMaxHp[]="   ";//max name size is 3(3 digits)
    char emptyMaxHp2[]="   ";//max name size is 3(3 digits)
    int spare1 = sprintf(emptyCurrentHp, "%d", currentHp);
    int spare2 =sprintf(emptyMaxHp, "%d", maxHp);
    strncpy(emptyCurrentHp2,emptyCurrentHp,strlen(emptyCurrentHp));
    strncpy(emptyMaxHp2,emptyMaxHp,strlen(emptyMaxHp));
    removeBackBlanks(emptyCurrentHp2);
    removeBackBlanks(emptyMaxHp2);
    strcat(emptyName,emptyCurrentHp2);
    strcat(emptyName,"/");
    strcat(emptyName,emptyMaxHp2);
    strcat(emptyName,"]");
    changeText(screen,13,1,emptyName);
    
}
void changePlayerHp(){
    char emptyName[]="           ";//max name size is 11

}
void changeEnemyLvl(){
    char emptyName[]="           ";//max name size is 11

}
void changePlayerLvl(){
    char emptyName[]="           ";//max name size is 11

}

//^^^^^^^^^^^^^^^^^
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
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",};
    //bot left pokemon 30 width
    //top right pokemon 32 width? wtf
    //test 16 lines height
    //30 char width

    //changeText(screen,1,1,"a");
    char testInput[100];
    int testInputInt=1;
    int ice;
    //changeText(screen,3,3,"wheee");
    //changeText(screen,0,0,"asparagus");
    //changeText(screen,8,3,"waffles");
    //changeColor(colorScreen,1,1,'b');
    changeEnemyName(screen,colorScreen,"takoyaki",'g');
    changeEnemyName(screen,colorScreen,"daifuku",'b');
    changePlayerName(screen,colorScreen,"mirror cake",'r');
    changePlayerName(screen,colorScreen,"leche",'p');
    changeEnemyHp(screen,-100,420);
    changeEnemyHp(screen,1,2);

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
