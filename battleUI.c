/*  CS125 Group Project
    File: battleUI.c
    Description: Generates ASCII/text-based UI
    Authors: Vince Tran, Forrest Mobley
    References: Unknown
*/

// Utilized libraries
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// Header files
#include "battleUI.h"
#include "util.h"
#include "pokeFiles.h"

//changes made on 4/3/2020
void printPixel(char screen[33][65],char colorScreen[33][65],int x, int y){
//        printf("\033[0;31m");//red
//        printf("\033[0m");//white
//        printf("\e[0;34m");//blue
//        printf("\e[0;32m");//green
//        printf("\e[0;35m");//purple
//        printf("\e[0;33m");//yellow
if(colorScreen[x][y]=='r')
        printf("\033[0;31m");//red
if(colorScreen[x][y]=='w')
        printf("\033[0m");//white
if(colorScreen[x][y]=='b')
        printf("\e[0;34m");//blue
if(colorScreen[x][y]=='g')
        printf("\e[0;32m");//green
if(colorScreen[x][y]=='p')
        printf("\e[0;35m");//purple
if(colorScreen[x][y]=='y')
        printf("\e[0;33m");//yellow

printf("%c",screen[x][y]);
}

void run(char screen[33][65], char colorScreen[33][65])
{
    int x=0;
    int y=0;
    for(x=0;x<33;x++)
    {

        for(y=0;y<65;y++)
        {
            printPixel(screen,colorScreen,x,y);
        }
    printf("\n");
    }
}

void changeText(char screen[33][65],int xScreenPos,int yScreenPos,char sentence[])
{
    fflush(stdout);//lol the godly function that runs the machine
    char spareLine[65]="";
    char secondSpareLine[65]="";
    char completeSpareLine[65]="";
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
        removeBackBlanks(shift);
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
    changeText(screen,14,1,emptyName); 
    
}


void changePlayerHp(char screen[33][65],int currentHp,int maxHp){
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
    strcat(emptyName,emptyCurrentHp2);//now its just putting the pieces together
    strcat(emptyName,"/");
    strcat(emptyName,emptyMaxHp2);
    strcat(emptyName,"]");
    changeText(screen,44,28,emptyName);
    
}

void changeEnemyType(char screen[33][65], char colorScreen[33][65],char enemyTypeChar)
{
    //g is grass,r is fire, b is water
    char clearThisVariable[]="     ";
    char emptyName[5]="     ";//max name size is 5//no idea why but this is causing an insane amount of problems
    //maybe a memory leak or something, but this is taking data from previous functions, even if i change the variable names
    strncpy(emptyName,clearThisVariable,30);//somehow this works to fix the mysterious bug .-.
    char enemyType[5]="blank";

    char ifWaterType[5]="Water";
        if(enemyTypeChar=='b')strncpy(enemyType,ifWaterType,5);
    char ifFireType[5]="Fire ";
        if(enemyTypeChar=='r')strncpy(enemyType,ifFireType,5);
    char ifGrassType[5]="Grass";    
        if(enemyTypeChar=='g')strncpy(enemyType,ifGrassType,5);

    //printf("%sbeep\n\nwww\n",emptyName);//this is the checker to see whats in the variable
    //it should theoretically be empty, but nope, for some darn reason xD
    
    int count=0;
    strncpy(emptyName,enemyType,5);
    changeText(screen,28,1,emptyName);//changes appearance or text
    for(count=0;count<5;count++)//also sorry,x isnt x and y isnt y
        changeColor(colorScreen,1,28+count,enemyTypeChar);//this is just to change the color map

}

void changePlayerType(char screen[33][65], char colorScreen[33][65],char enemyTypeChar)
{
    //g is grass,r is fire, b is water
    char clearThisVariable[]="     ";
    char emptyName[5]="     ";//max name size is 5//no idea why but this is causing an insane amount of problems
    //maybe a memory leak or something, but this is taking data from previous functions, even if i change the variable names
    strncpy(emptyName,clearThisVariable,30);//somehow this works to fix the mysterious bug .-.
    char enemyType[5]="blank";

    char ifWaterType[5]="Water";
        if(enemyTypeChar=='b')strncpy(enemyType,ifWaterType,5);
    char ifFireType[5]="Fire ";
        if(enemyTypeChar=='r')strncpy(enemyType,ifFireType,5);
    char ifGrassType[5]="Grass";    
        if(enemyTypeChar=='g')strncpy(enemyType,ifGrassType,5);
    char ifPsychType[5]="Psych";    
        if(enemyTypeChar=='p')strncpy(enemyType,ifPsychType,5);

    //printf("%sbeep\n\nwww\n",emptyName);//this is the checker to see whats in the variable
    //it should theoretically be empty, but nope, for some darn reason xD
    
    int count=0;
    strncpy(emptyName,enemyType,5);
    changeText(screen,58,28,emptyName);//changes appearance or text
    for(count=0;count<5;count++)//also sorry,x isnt x and y isnt y
        changeColor(colorScreen,28,58+count,enemyTypeChar);//this is just to change the color map

}

void changeEnemyLvl(char screen[33][65],int lvl){
    fflush(stdin);
    char emptyName[13]="Lvl:";//max name size is 13
    char emptyCurrentLvl[]="    ";//max name size is 4(3 digits, 1 sign)
    char emptyCurrentLvl2[]="    ";//max name size is 4(3 digits, 1 sign)
    //char emptyMaxHp[]="   ";//max name size is 3(3 digits)
    //char emptyMaxHp2[]="   ";//max name size is 3(3 digits)
    int spare1 = sprintf(emptyCurrentLvl, "%d", lvl);
    //int spare2 =sprintf(emptyMaxHp, "%d", maxHp);
    strncpy(emptyCurrentLvl2,emptyCurrentLvl,strlen(emptyCurrentLvl));
    //strncpy(emptyMaxHp2,emptyMaxHp,strlen(emptyMaxHp));
    removeBackBlanks(emptyCurrentLvl2);
    //removeBackBlanks(emptyMaxHp2);
    strcat(emptyName,emptyCurrentLvl2);//now its just putting the pieces together
    //strcat(emptyName,"/");
    //strcat(emptyName,emptyMaxHp2);
    //strcat(emptyName,"]");
    changeText(screen,1,2,emptyName);
}

void changePlayerLvl(char screen[33][65],int lvl){
    fflush(stdin);
    char emptyName[13]="Lvl:";//max name size is 13
    char emptyCurrentLvl[]="    ";//max name size is 4(3 digits, 1 sign)
    char emptyCurrentLvl2[]="    ";//max name size is 4(3 digits, 1 sign)
    //char emptyMaxHp[]="   ";//max name size is 3(3 digits)
    //char emptyMaxHp2[]="   ";//max name size is 3(3 digits)
    int spare1 = sprintf(emptyCurrentLvl, "%d", lvl);
    //int spare2 =sprintf(emptyMaxHp, "%d", maxHp);
    strncpy(emptyCurrentLvl2,emptyCurrentLvl,strlen(emptyCurrentLvl));
    //strncpy(emptyMaxHp2,emptyMaxHp,strlen(emptyMaxHp));
    removeBackBlanks(emptyCurrentLvl2);
    //removeBackBlanks(emptyMaxHp2);
    strcat(emptyName,emptyCurrentLvl2);//now its just putting the pieces together
    //strcat(emptyName,"/");
    //strcat(emptyName,emptyMaxHp2);
    //strcat(emptyName,"]");
    changeText(screen,31,29,emptyName);

}

void changeEnemyXp(char screen[33][65],int experience)
{
    fflush(stdin);
    char emptyName[13]="EXP:";//max name size is 13
    char emptyCurrentLvl[]="    ";//max name size is 4(3 digits, 1 sign)
    char emptyCurrentLvl2[]="    ";//max name size is 4(3 digits, 1 sign)
    //char emptyMaxHp[]="   ";//max name size is 3(3 digits)
    //char emptyMaxHp2[]="   ";//max name size is 3(3 digits)
    int spare1 = sprintf(emptyCurrentLvl, "%d", experience);
    //int spare2 =sprintf(emptyMaxHp, "%d", maxHp);
    strncpy(emptyCurrentLvl2,emptyCurrentLvl,strlen(emptyCurrentLvl));
    //strncpy(emptyMaxHp2,emptyMaxHp,strlen(emptyMaxHp));
    removeBackBlanks(emptyCurrentLvl2);
    //removeBackBlanks(emptyMaxHp2);
    strcat(emptyName,emptyCurrentLvl2);//now its just putting the pieces together
    //strcat(emptyName,"/");
    //strcat(emptyName,emptyMaxHp2);
    //strcat(emptyName,"]");
    changeText(screen,14,2,emptyName);


}

void changePlayerXp(char screen[33][65],int experience)
{
    fflush(stdin);
    char emptyName[13]="EXP:";//max name size is 13
    char emptyCurrentLvl[]="    ";//max name size is 4(3 digits, 1 sign)
    char emptyCurrentLvl2[]="    ";//max name size is 4(3 digits, 1 sign)
    //char emptyMaxHp[]="   ";//max name size is 3(3 digits)
    //char emptyMaxHp2[]="   ";//max name size is 3(3 digits)
    int spare1 = sprintf(emptyCurrentLvl, "%d", experience);
    //int spare2 =sprintf(emptyMaxHp, "%d", maxHp);
    strncpy(emptyCurrentLvl2,emptyCurrentLvl,strlen(emptyCurrentLvl));
    //strncpy(emptyMaxHp2,emptyMaxHp,strlen(emptyMaxHp));
    removeBackBlanks(emptyCurrentLvl2);
    //removeBackBlanks(emptyMaxHp2);
    strcat(emptyName,emptyCurrentLvl2);//now its just putting the pieces together
    //strcat(emptyName,"/");
    //strcat(emptyName,emptyMaxHp2);
    //strcat(emptyName,"]");
    changeText(screen,44,29,emptyName);

}
    
void changeEnemyMove1(char screen[33][65],char move1[12])
{
    changeText(screen,1,3,"            ");//12 spaces
    changeText(screen,1,3,move1);

}

void changeEnemyMove2(char screen[33][65],char move1[12])
{
    changeText(screen,1,4,"            ");//12 spaces
    changeText(screen,1,4,move1);

}

void changePlayerMove1(char screen[33][65],char move1[12])
{
    changeText(screen,31,30,"            ");//12 spaces
    changeText(screen,31,30,move1);

}

void changePlayerMove2(char screen[33][65],char move1[12])
{
    changeText(screen,31,31,"            ");//12 spaces
    changeText(screen,31,31,move1);

}

void changeEnemyUltimate(char screen[33][65],char move1[12],int ultimateUsed){
    changeText(screen,14,3,"              [ /1]");//19 spaces//careful if you shift everything over, might ruin the border
    changeText(screen,14,3,move1);
    char spareUlt[2]; 
    sprintf(spareUlt, "%d", ultimateUsed);

    changeText(screen,29,3,spareUlt);

}

void changePlayerUltimate(char screen[33][65],char move1[12],int ultimateUsed){
    changeText(screen,44,30,"              [ /1]");//19 spaces//careful if you shift everything over, might ruin the border
    changeText(screen,44,30,move1);
    char spareUlt[2]; 
    sprintf(spareUlt, "%d", ultimateUsed);

    changeText(screen,59,30,spareUlt);


}
void changeEnemyConsumable(char screen[33][65],char consumableName[15],int consumableRemaining,int consumableMax)
{
    changeText(screen,14,4 ,"                   ");//20 spaces//this makes it so i dont have to size check stuff
    changeText(screen,14,4,consumableName);

    char spareRemains[2]; 
    sprintf(spareRemains, "%d", consumableRemaining);
    char spareMax[2]; 
    sprintf(spareMax, "%d", consumableMax);

    changeText(screen,28,4,"[");
    changeText(screen,29,4,spareRemains);
    changeText(screen,30,4,"/");
    changeText(screen,31,4,spareMax);
    changeText(screen,32,4,"]");

}

void changePlayerConsumable(char screen[33][65],char consumableName[15],int consumableRemaining,int consumableMax)
{
    changeText(screen,44,31 ,"                   ");//20 spaces//this makes it so i dont have to size check stuff
    changeText(screen,44,31,consumableName);

    char spareRemains[2]; 
    sprintf(spareRemains, "%d", consumableRemaining);
    char spareMax[2]; 
    sprintf(spareMax, "%d", consumableMax);


    changeText(screen,58,31,"[");
    changeText(screen,59,31,spareRemains);
    changeText(screen,60,31,"/");
    changeText(screen,61,31,spareMax);
    changeText(screen,62,31,"]");

}

void resetScreen(char screen[33][65])
{



    changeText(screen,0,0, "+--------------------------------+                              ");
    changeText(screen,0,1, "|                                |                              ");
    changeText(screen,0,2, "|                                |                              ");
    changeText(screen,0,3, "|                                |                              ");
    changeText(screen,0,4, "|                                |                              ");
    changeText(screen,0,5, "+--------------------------------+                              ");
    changeText(screen,0,6, "                                                                ");
    changeText(screen,0,7, "                                                                ");
    changeText(screen,0,8, "                                                                ");
    changeText(screen,0,9, "                                                                ");
    changeText(screen,0,10,"                                                                ");
    changeText(screen,0,11,"                                                                ");
    changeText(screen,0,12,"                                                                ");
    changeText(screen,0,13,"                                                                ");
    changeText(screen,0,14,"                                                                ");
    changeText(screen,0,15,"                                                                ");
    changeText(screen,0,16,"                                                                ");
    changeText(screen,0,17,"                                                                ");
    changeText(screen,0,18,"                                                                ");
    changeText(screen,0,19,"                                                                ");
    changeText(screen,0,20,"                                                                ");
    changeText(screen,0,21,"                                                                ");
    changeText(screen,0,22,"                                                                ");
    changeText(screen,0,23,"                                                                ");
    changeText(screen,0,24,"                                                                ");
    changeText(screen,0,25,"                                                                ");
    changeText(screen,0,26,"                                                                ");
    changeText(screen,0,27,"                              +--------------------------------+");
    changeText(screen,0,28,"                              |                                |");
    changeText(screen,0,29,"                              |                                |");
    changeText(screen,0,30,"                              |                                |");
    changeText(screen,0,31,"                              |                                |");
    changeText(screen,0,32,"                              +--------------------------------+");




/* lol this array of array causes segmentation faults
    char cleanScreen[33][65] ={ 
        "+--------------------------------+                              ",
        "|                                |                              ",
        "|                                |                              ",
        "|                                |                              ",
        "|                                |                              ",
        "+--------------------------------+                              ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                              +--------------------------------+",
        "                              |                                |",
        "                              |                                |",
        "                              |                                |",
        "                              |                                |",
        "                              +--------------------------------+",};
*/
    //memcpy(screen,cleanScreen,sizeof(cleanScreen));//unforunately memcpy method wont work
    //printf("%s",screen[2]);

}

void resetColorScreen(char colorScreen[33][65])
{
    int countColorScreen=0;
    for(countColorScreen=0;countColorScreen<33;countColorScreen++)
        changeText(colorScreen,0,countColorScreen,"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");


}





//////////////////////////////////////////////////////////////////
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

void battleUI()
{
    clear();
    char screen[33][65] ={ //32 rows, 64 columns
        "+--------------------------------+                              ",
        "|                                |                              ",
        "|                                |                              ",
        "|                                |                              ",
        "|                                |                              ",
        "+--------------------------------+                              ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                              +--------------------------------+",
        "                              |                                |",
        "                              |                                |",
        "                              |                                |",
        "                              |                                |",
        "                              +--------------------------------+",};

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
    //top right pokemon 32 width?
    //test 16 lines height
    //30 char width

    //changeText(screen,1,1,"a");
    char testInput[100];
    int testInputInt=1;
    int ice;
    
    //                                "
    //charizard   hp:[23/33] Fire
    //level 100  EXP:102
    //earthquake  flash cannon
    //ultimate attack hyper potion
    //later replace these with actual stats
    char enemyName[20]="Charizard";
    char playerName[20]="Mewtwo";
    int enemyHp=11;
    int enemyTotalHp=20;
    int playerHp=100;
    int playerTotalHp=169;
    char enemyType='r';
    char playerType='p';
    int playerLevel=55;
    int enemyLevel=99;
    int playerCurrentXp=222;
    int enemyCurrentXp=696;
    char playerMove1[12]="bullet seed";
    char playerMove2[12]="intimidate";
    char playerMoveUltimate[12]="superpower";
    char enemyMove1[12]="rain dance";
    char enemyMove2[12]="volt tackle";
    char enemyMoveUltimate[12]="hyper beam";
    int enemyUltimateUsed=0;
    int playerUltimateUsed=1;
    char playerConsumableName[15]="super potion";
    char enemyConsumableName[15] ="full restore";
    int playerConsumableCount=1;
    int enemyConsumableCount=3;
    int playerConsumableMaxCount=7;
    int enemyConsumableMaxCount=4;

    


    changeEnemyName(screen,colorScreen,enemyName,enemyType);
    changePlayerName(screen,colorScreen,playerName,playerType);
    changeEnemyHp(screen,enemyHp,enemyTotalHp);
    changePlayerHp(screen,playerHp,playerTotalHp);
    changeEnemyType(screen,colorScreen,enemyType);
    changePlayerType(screen,colorScreen,playerType);
    changeEnemyLvl(screen,enemyLevel);
    changePlayerLvl(screen,playerLevel);
    changeEnemyXp(screen,enemyCurrentXp);
    changePlayerXp(screen,playerCurrentXp);
    changeEnemyMove1(screen,enemyMove1);
    changeEnemyMove2(screen,enemyMove2);
    changePlayerMove1(screen,playerMove1);
    changePlayerMove2(screen,playerMove2);
    changeEnemyUltimate(screen,enemyMoveUltimate,enemyUltimateUsed);
    changePlayerUltimate(screen,playerMoveUltimate,playerUltimateUsed);
    changeEnemyConsumable(screen,enemyConsumableName,enemyConsumableCount,enemyConsumableMaxCount);
    changePlayerConsumable(screen,playerConsumableName,playerConsumableCount,playerConsumableMaxCount);



    

    //resetScreen(screen);
    //resetColorScreen(colorScreen);








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
