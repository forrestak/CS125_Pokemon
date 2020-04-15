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
#include "readPokemonStats.h"
#include "combat.h"

void printPixel(char screen[33][65],char colorScreen[33][65],int x, int y){
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
    fflush(stdout);
    char spareLine[65]="";
    char secondSpareLine[65]="";
    char completeSpareLine[65]="";
    strncpy(spareLine,screen[yScreenPos],xScreenPos);
    strncpy(secondSpareLine,screen[yScreenPos]+xScreenPos+strlen(sentence),65);
    strncpy(completeSpareLine,spareLine,strlen(spareLine));
    strcat(completeSpareLine,sentence);
    strcat(completeSpareLine,secondSpareLine);
    strncpy(screen[yScreenPos],completeSpareLine,65);
}

void changeColor(char colorScreen[33][65],int x, int y,char input){
    colorScreen[x][y]=input;
}

void removeBackBlanks(char shift[]){
    char copy[20]=""; // this is to right-align the numbers
    char copy2[20]=" ";
    strncpy(copy,shift,strlen(shift)-1);
    strcat(copy2,copy);
    if(shift[strlen(shift)-1]==' ')
    {
        strncpy(shift,copy2,strlen(copy2));
        removeBackBlanks(shift);
    }
}

float round2(float number)
{
    int change =(int)(number*100);
    return ((float)change)/100;
}

void changeEnemyName(char screen[33][65],char colorScreen[33][65],char enemyName[],char type){
    //g is grass,r is fire, b is water
    char emptyName[]="           "; // max name size is 11
    int count=0;
    strncpy(emptyName,enemyName,strlen(enemyName));
    changeText(screen,1,1,emptyName);
    for(count=0;count<11;count++)
        changeColor(colorScreen,1,1+count,type);
}

void changePlayerName(char screen[33][65],char colorScreen[33][65],char playerName[],char type){
    char emptyName[]="           "; // max name size is 11
    int count=0;
    strncpy(emptyName,playerName,strlen(playerName));
    changeText(screen,31,28,emptyName);
    for(count=0;count<11;count++)
        changeColor(colorScreen,28,31+count,type);
}

void changeEnemyHp(char screen[33][65],float currentHp,float maxHp){

    char emptyName[19]="HP:["; // max name size is 13
    char emptyCurrentHp[]= "      "; // max name size is 4(3 digits, 1 sign)
    char emptyCurrentHp2[]="      "; // max name size is 4(3 digits, 1 sign)
    char emptyMaxHp[]=     "      "; // max name size is 3(3 digits)
    char emptyMaxHp2[]=    "      "; // max name size is 3(3 digits)
    int spare1;int spare2;



    if(((float)((int)(currentHp*100))/100)==((float)((int)(currentHp))))
    spare1 = sprintf(emptyCurrentHp, "%.2f", currentHp);
        else if(((float)((int)(currentHp*100))/100)==((float)((int)(currentHp*10))/10))
            spare1 = sprintf(emptyCurrentHp, "%.2f", currentHp);
            else
                spare1 = sprintf(emptyCurrentHp, "%.2f", currentHp);


    if(((float)((int)(maxHp*100))/100)==((float)((int)(maxHp))))
        spare2 = sprintf(emptyMaxHp, "%.2f", maxHp);
        else if(((float)((int)(maxHp*100))/100)==((float)((int)(maxHp*10))/10))
            spare2 = sprintf(emptyMaxHp, "%.2f", maxHp);
            else
                spare2 = sprintf(emptyMaxHp, "%.2f", maxHp);
    

    strncpy(emptyCurrentHp2,emptyCurrentHp,strlen(emptyCurrentHp));
    strncpy(emptyMaxHp2,emptyMaxHp,strlen(emptyMaxHp));
    removeBackBlanks(emptyCurrentHp2);
    removeBackBlanks(emptyMaxHp2);
    strcat(emptyName,emptyCurrentHp2);
    strcat(emptyName,"/");
    strcat(emptyName,emptyMaxHp2);
    strcat(emptyName,"]");
    changeText(screen,1,2,emptyName);
}

void changePlayerHp(char screen[33][65],float currentHp,float maxHp){

    char emptyName[19]="HP:["; // max name size is 13
    char emptyCurrentHp[]= "      "; // max name size is 4(3 digits, 1 sign)
    char emptyCurrentHp2[]="      "; // max name size is 4(3 digits, 1 sign)
    char emptyMaxHp[]=     "      "; // max name size is 3(3 digits)
    char emptyMaxHp2[]=    "      "; // max name size is 3(3 digits)
    int spare1;int spare2;

    if(((float)((int)(currentHp*100))/100)==((float)((int)(currentHp))))
    spare1 = sprintf(emptyCurrentHp, "%.2f", currentHp);
        else if(((float)((int)(currentHp*100))/100)==((float)((int)(currentHp*10))/10))
            spare1 = sprintf(emptyCurrentHp, "%.2f", currentHp);
            else
                spare1 = sprintf(emptyCurrentHp, "%.2f", currentHp);

    if(((float)((int)(maxHp*100))/100)==((float)((int)(maxHp))))
        spare2 = sprintf(emptyMaxHp, "%.2f", maxHp);
        else if(((float)((int)(maxHp*100))/100)==((float)((int)(maxHp*10))/10))
            spare2 = sprintf(emptyMaxHp, "%.2f", maxHp);
            else
                spare2 = sprintf(emptyMaxHp, "%.2f", maxHp);
    
    strncpy(emptyCurrentHp2,emptyCurrentHp,strlen(emptyCurrentHp));
    strncpy(emptyMaxHp2,emptyMaxHp,strlen(emptyMaxHp));
    removeBackBlanks(emptyCurrentHp2);
    removeBackBlanks(emptyMaxHp2);
    strcat(emptyName,emptyCurrentHp2);
    strcat(emptyName,"/");
    strcat(emptyName,emptyMaxHp2);
    strcat(emptyName,"]");
    changeText(screen,31,29,emptyName);
}

void changeEnemyType(char screen[33][65], char colorScreen[33][65],char enemyTypeChar)
{
    // g is grass, r is fire, b is water
    char clearThisVariable[]="     ";
    char emptyName[5]="     "; // max name size is 5
    strncpy(emptyName,clearThisVariable,30);
    char enemyType[5]="blank";

    char ifWaterType[5]="Water";
        if(enemyTypeChar=='b')strncpy(enemyType,ifWaterType,5);
    char ifFireType[5]="Fire ";
        if(enemyTypeChar=='r')strncpy(enemyType,ifFireType,5);
    char ifGrassType[5]="Grass";    
        if(enemyTypeChar=='g')strncpy(enemyType,ifGrassType,5);

    int count=0;
    strncpy(emptyName,enemyType,5);
    changeText(screen,28,1,emptyName); // changes appearance of text
    for(count=0;count<5;count++) 
        changeColor(colorScreen,1,28+count,enemyTypeChar); // to change the color map

}

void changePlayerType(char screen[33][65], char colorScreen[33][65],char enemyTypeChar)
{
    // g is grass, r is fire, b is water
    char clearThisVariable[]="     ";
    char emptyName[5]="     "; // max name size is 5
    strncpy(emptyName,clearThisVariable,30);
    char enemyType[5]="blank";

    char ifWaterType[5]="Water";
        if(enemyTypeChar=='b')strncpy(enemyType,ifWaterType,5);
    char ifFireType[5]="Fire ";
        if(enemyTypeChar=='r')strncpy(enemyType,ifFireType,5);
    char ifGrassType[5]="Grass";    
        if(enemyTypeChar=='g')strncpy(enemyType,ifGrassType,5);
    char ifPsychType[5]="Psych";    
        if(enemyTypeChar=='p')strncpy(enemyType,ifPsychType,5);
    
    int count=0;
    strncpy(emptyName,enemyType,5);
    changeText(screen,58,28,emptyName); // changes appearance of text
    for(count=0;count<5;count++)
        changeColor(colorScreen,28,58+count,enemyTypeChar); // to change the color map

}

void changeEnemyLvl(char screen[33][65],int lvl){

    char emptyName[13]="Lvl:"; // max name size is 13
    char emptyCurrentLvl[]="   "; // max name size is 4(3 digits, 1 sign)
    char emptyCurrentLvl2[]="   "; // max name size is 4(3 digits, 1 sign)
    int spare1 = sprintf(emptyCurrentLvl, "%d", lvl);
    strncpy(emptyCurrentLvl2,emptyCurrentLvl,strlen(emptyCurrentLvl));
    removeBackBlanks(emptyCurrentLvl2);
    strcat(emptyName,emptyCurrentLvl2);
    changeText(screen,20,1,emptyName);
    changeText(screen,16,1,"NPC");
}

void changePlayerLvl(char screen[33][65],int lvl){
    char emptyName[13]="Lvl:"; // max name size is 13
    char emptyCurrentLvl[]="   "; // max name size is 4(3 digits, 1 sign)
    char emptyCurrentLvl2[]="   "; // max name size is 4(3 digits, 1 sign)
    int spare1 = sprintf(emptyCurrentLvl, "%d", lvl);
    strncpy(emptyCurrentLvl2,emptyCurrentLvl,strlen(emptyCurrentLvl));
    removeBackBlanks(emptyCurrentLvl2);
    strcat(emptyName,emptyCurrentLvl2);
    changeText(screen,50,28,emptyName);
    changeText(screen,46,28,"YOU");

}

void changeEnemyXp(char screen[33][65],int experience)
{
    char emptyClearance[18]= "EXP:         "; // max name size is 17 duh
    changeText(screen,20,2,emptyClearance); // your customary clearance is here 
    char emptyName[18]=  "EXP:";
    char emptyCurrentLvl[]=  "                   "; // max name size is 15 digits :o
    int spare1 = sprintf(emptyCurrentLvl, "%d", experience); // but technically you can only go up to 10 digits
    removeBackBlanks(emptyCurrentLvl); // since like 2 billion is like the max integer number limit
    strcat(emptyName,emptyCurrentLvl); // now its just putting the pieces together
    changeText(screen,20,2,emptyName);
}

void changePlayerXp(char screen[33][65],int experience)
{
    char emptyClearance[18]= "EXP:         "; // max name size is 17
    changeText(screen,50,29,emptyClearance);
    char emptyName[18]=  "EXP:";
    char emptyCurrentLvl[]=  "                   "; // max name size is 15 digits
    int spare1 = sprintf(emptyCurrentLvl, "%d", experience); // technically you can only go up to 10 digits
    removeBackBlanks(emptyCurrentLvl); 
    strcat(emptyName,emptyCurrentLvl); 
    changeText(screen,50,29,emptyName);
}
    
void changeEnemyMove1(char screen[33][65],char move1[12])
{
    changeText(screen,1,3,"1-          "); // 12 spaces
    changeText(screen,3,3,move1);
}

void changeEnemyMove2(char screen[33][65],char move1[12])
{
    changeText(screen,1,4,"2-          "); // 12 spaces
    changeText(screen,3,4,move1);
}

void changePlayerMove1(char screen[33][65],char move1[12])
{
    changeText(screen,31,30,"1-          "); // 12 spaces
    changeText(screen,33,30,move1);
}

void changePlayerMove2(char screen[33][65],char move1[12])
{
    changeText(screen,31,31,"2-          "); // 12 spaces
    changeText(screen,33,31,move1);
}

void changeEnemyUltimate(char screen[33][65],char move1[12],int ultimateUsed){
    changeText(screen,16,3,"3-            [ ]"); // 19 spaces
    changeText(screen,18,3,move1);
    char spareUlt[2]; 
    sprintf(spareUlt, "%d", ultimateUsed);

    changeText(screen,31,3,spareUlt);
}

void changePlayerUltimate(char screen[33][65],char move1[12],int ultimateUsed){
    changeText(screen,46,30,"3-            [ ]");
    changeText(screen,48,30,move1);
    char spareUlt[2]; 
    sprintf(spareUlt, "%d", ultimateUsed);

    changeText(screen,61,30,spareUlt);

}
void changeEnemyConsumable(char screen[33][65],char consumableName[15],int consumableRemaining,int consumableMax)
{
    changeText(screen,16,4 ,"4-               ");
    changeText(screen,18,4,consumableName);

    char spareRemains[2]; 
    sprintf(spareRemains, "%d", consumableRemaining);
    char spareMax[2]; 
    sprintf(spareMax, "%d", consumableMax);

    changeText(screen,30,4,"[");
    changeText(screen,31,4,spareRemains);
    changeText(screen,32,4,"]");
}

void changePlayerConsumable(char screen[33][65],char consumableName[15],int consumableRemaining,int consumableMax)
{
    changeText(screen,46,31 ,"4-               ");
    changeText(screen,48,31,consumableName);

    char spareRemains[2]; 
    sprintf(spareRemains, "%d", consumableRemaining);
    char spareMax[2]; 
    sprintf(spareMax, "%d", consumableMax);

    changeText(screen,60,31,"[");
    changeText(screen,61,31,spareRemains);
    changeText(screen,62,31,"]");
}

void subtractEnemyHp(char screen[33][65],int current, int max, int subtract)
{   
    current-=subtract;
    if(current<0)current=0;
    changeEnemyHp(screen,current,max);
}

void subtractPlayerHp(char screen[33][65],int current, int max, int subtract)
{   
    current-=subtract;
    if(current<0)current=0;
    changePlayerHp(screen,current,max);
}

char stringToCharType(char type[6])
{
    if(0==strcmp(type,"Grass"))
        return 'g'; // green
    if(0==strcmp(type,"Fire"))
        return 'r'; // red
    if(0==strcmp(type,"Water"))
        return 'b'; // blue
    if(0==strcmp(type,"Psych"))
        return 'p'; // purple

    return 'w';
}

int nameToNational(char name[12])
{

    if(0==strcmp(name,"Bulbasaur"))
        return 1;
    if(0==strcmp(name,"Charmander"))
        return 4;
    if(0==strcmp(name,"Squirtle"))
        return 7;
    if(0==strcmp(name,"Oddish"))
        return 43;
    if(0==strcmp(name,"Bellsprout"))
        return 69;//nice
    if(0==strcmp(name,"Growlithe"))
        return 58;
    if(0==strcmp(name,"Ponyta"))
        return 77;
    if(0==strcmp(name,"Slowpoke"))
        return 79;
    if(0==strcmp(name,"Seel"))
        return 86;
    return 816;
}

char* emptyString(char objectToEmpty[])
{
    char blank[]="                                                                  ";
    strncpy(objectToEmpty,blank,strlen(objectToEmpty));
    return objectToEmpty;
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
}

void resetColorScreen(char colorScreen[33][65])
{
    int countColorScreen=0;
    for(countColorScreen=0;countColorScreen<33;countColorScreen++)
        changeText(colorScreen,0,countColorScreen,"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
}

void changeEnemyPokemon(char screen[33][65],int pokemonIndex)
{
    int count=0;
    char enemyPokemon[17][31];
    char cleanSpare[65-30]="";
    char spare[65-30]="";
    char completeSpare[65]="";
    char cleanCompleteSpare[65]="";
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
    int count;
    int shift=16;
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

int floatToInt(float number)
{
    return ((int)number);
}

void enemyAttackBuffer(char screen[33][65], char colorScreen[33][65])
{
        changeEnemyPokemon(screen,0);//get that flicker in :D
        delay(500);
        clear();
        run(screen,colorScreen);

        changeEnemyPokemon(screen,nameToNational(NPCPOKEMONCHOICE));
        delay(250);
        clear();
        run(screen,colorScreen);

        changeEnemyPokemon(screen,0);//get that flicker in :D
        delay(250);
        clear();
        run(screen,colorScreen);

        changeEnemyPokemon(screen,nameToNational(NPCPOKEMONCHOICE));
        delay(250);
        clear();
        run(screen,colorScreen);

        changeEnemyPokemon(screen,0);//get that flicker in :D
        delay(250);
        clear();
        run(screen,colorScreen);

        changeEnemyPokemon(screen,nameToNational(NPCPOKEMONCHOICE));
}

void playerAttackBuffer(char screen[33][65], char colorScreen[33][65])
{
        changePlayerPokemon(screen,0);//get that flicker in :D
        delay(250);
        clear();
        run(screen,colorScreen);

        changePlayerPokemon(screen,nameToNational(PLAYERPOKEMONCHOICE));
        delay(250);
        clear();
        run(screen,colorScreen);

        changePlayerPokemon(screen,0);//get that flicker in :D
        delay(250);
        clear();
        run(screen,colorScreen);

        changePlayerPokemon(screen,nameToNational(PLAYERPOKEMONCHOICE));
        delay(250);
        clear();
        run(screen,colorScreen);

        changePlayerPokemon(screen,0);
        delay(250);
        clear();
        run(screen,colorScreen);

        changePlayerPokemon(screen,nameToNational(PLAYERPOKEMONCHOICE));
}

void initializeScreen(char screen[33][65],char colorScreen[33][65])
{
    char enemyName[13]= "";
    char playerName[13]="";
    float enemyHp=1;
    float enemyTotalHp=1;
    float playerHp=1;
    float playerTotalHp=1;
    char enemyType='w';
    char playerType='w';
    int playerLevel=1;
    int enemyLevel=1;
    int playerCurrentXp=1;
    int enemyCurrentXp=1;
    char playerMove1[13]="";
    char playerMove2[13]="";
    char playerMoveUltimate[13]="";
    char enemyMove1[13]="";
    char enemyMove2[13]="";
    char enemyMoveUltimate[13]="";
    int enemyUltimateUsed=1;
    int playerUltimateUsed=1;
    char playerConsumableName[13]="";
    char enemyConsumableName[13] ="";
    int playerConsumableCount=1;
    int enemyConsumableCount=1;
    int playerConsumableMaxCount=1;
    int enemyConsumableMaxCount=1;
    int playerPokemonNumber=1;
    int enemyPokemonNumber=1;

    strncpy(emptyString(playerName),PLAYERPOKEMONCHOICE,strlen(PLAYERPOKEMONCHOICE));
    strncpy(emptyString(enemyName),NPCPOKEMONCHOICE,strlen(NPCPOKEMONCHOICE));
    playerHp=round2(STATSTORAGE.p_hp);
    enemyHp=round2(STATSTORAGE.n_hp);
    playerTotalHp=round2(readPokemonStats("player",3));
    enemyTotalHp=round2(readPokemonStats("npc",3));
    playerType=stringToCharType(STATSTORAGE.p_type);
    enemyType=stringToCharType(STATSTORAGE.n_type);
    playerLevel=readPokemonStats("player",1);
    enemyLevel=readPokemonStats("npc",1);
    playerCurrentXp=readPokemonStats("player",2);
    enemyCurrentXp=readPokemonStats("npc",2);
    strncpy(emptyString(playerMove1),STATSTORAGE.p_moveOne,strlen(STATSTORAGE.p_moveOne));
    strncpy(emptyString(playerMove2),STATSTORAGE.p_moveTwo,strlen(STATSTORAGE.p_moveTwo));
    strncpy(emptyString(playerMoveUltimate),STATSTORAGE.p_ability,strlen(STATSTORAGE.p_ability));
    strncpy(emptyString(enemyMove1),STATSTORAGE.n_moveOne,strlen(STATSTORAGE.n_moveOne));
    strncpy(emptyString(enemyMove2),STATSTORAGE.n_moveTwo,strlen(STATSTORAGE.n_moveTwo));
    strncpy(emptyString(enemyMoveUltimate),STATSTORAGE.n_ability,strlen(STATSTORAGE.n_ability));
    strncpy(emptyString(playerConsumableName),STATSTORAGE.p_consumable,strlen(STATSTORAGE.p_consumable));
    strncpy(emptyString(enemyConsumableName),STATSTORAGE.n_consumable,strlen(STATSTORAGE.n_consumable));
    playerConsumableCount=STATSTORAGE.p_consumableCount;
    enemyConsumableCount=STATSTORAGE.n_consumableCount;
    playerUltimateUsed=STATSTORAGE.p_abilityCount;
    enemyUltimateUsed=STATSTORAGE.n_abilityCount;
    playerConsumableMaxCount=1;
    enemyConsumableMaxCount=1;
    playerPokemonNumber=nameToNational(PLAYERPOKEMONCHOICE);
    enemyPokemonNumber=nameToNational(NPCPOKEMONCHOICE);

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
    changeEnemyPokemon(screen,enemyPokemonNumber);
    changePlayerPokemon(screen,playerPokemonNumber);
}

void battleUI(int animationNumber)
{
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

    initializeScreen(screen,colorScreen);
    if(animationNumber==1)
    {
        playerAttackBuffer(screen,colorScreen);
    }
    if(animationNumber==2)
    {
       enemyAttackBuffer(screen,colorScreen);
    }
    clear();
    run(screen,colorScreen);
}

void displayScreen()
{
    battleUI(0);
}






