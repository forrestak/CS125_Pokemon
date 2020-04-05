/*  CS125 Group Project
    File: util.c
    Description: Utility file to include useful functions
    Authors: Forrest Mobley, Colton Van Orsdel
    References: N/A
*/

// Header File
#include "util.h"
#include "battleUI.h"

// Standard libraries
#include <stdio.h>
#include <time.h>
#include <string.h>

void delay(int milliseconds){
  milliseconds*=10; // DEBUG: sped up for testing purposes; SHOULD BE: 1000
  clock_t start_time =clock();
  while(clock()<start_time + milliseconds);
}

void clear(){
  printf("\e[2J\e[H");
}

void readPrint(int count, char text[], char color[]){
  if (strcmp(color, "standard")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
  else if (strcmp(color, "red")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0;31m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
  else if (strcmp(color, "blue")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0;34m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
  else if (strcmp(color, "green")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0;32m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
  else if (strcmp(color, "yellow")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0;33m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
  else if (strcmp(color, "purple")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0;35m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
}

int pokemonChoiceToInt(char who[7]) // converts choices from starter.c into usable pokemon IDs
{
  if (strcmp(who, "player")==0)
  {
    if (strcmp(PLAYERPOKEMONCHOICE, "bulbasaur")==0)
    {
      return 1;
    }
    else if (strcmp(PLAYERPOKEMONCHOICE, "charmander")==0)
    {
      return 2;
    }
    else if (strcmp(PLAYERPOKEMONCHOICE, "squirtle")==0)
    {
      return 3;
    }
  }
  else if (strcmp(who, "npc")==0)
  {
    if (strcmp(NPCPOKEMONCHOICE, "grass")==0)
    {
      return 4;
    }
    else if (strcmp(NPCPOKEMONCHOICE, "fire")==0)
    {
      return 5;
    }
    else if (strcmp(NPCPOKEMONCHOICE, "water")==0)
    {
      return 6;
    }
  }


}