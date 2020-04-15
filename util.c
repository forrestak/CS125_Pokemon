/*  CS125 Group Project
    File: util.c
    Description: Utility file to include useful functions
    Authors: Forrest Mobley, Colton Van Orsdel
    References: N/A
*/

// Header File
#include "util.h"
#include "battleUI.h"
#include "generatePokemonStats.h"
#include "levelupPokemonStats.h"
#include "readPokemonStats.h"
#include "combat.h"
#include "endSim.h"

// Standard libraries
#include <stdio.h>
#include <time.h>
#include <string.h>

// Global variables
int DELAYMODIFIER = 600; // default readPrint() speed, modified by debugLauncher()

void delay(int milliseconds){ // Applies millisecond delay for usage in readPrint()
  milliseconds*=DELAYMODIFIER;
  clock_t start_time =clock();
  while(clock()<start_time + milliseconds);
}

void clear(){ // Clears the entire screen
  printf("\e[2J\e[H");
}

void readPrint(int count, char text[], char color[]){ // Reads out text incrementally and with color options
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

int pokemonChoiceToInt(char who[7]) // Converts choices from starter.c into usable pokemon IDs
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

int debugLauncher() // Enables several options to modify the behavior of main at the start of the program, for use in testing and debugging
{ 
  int debugChoice;
  printf("You have started Pokemon Battle Simulator (Eagle Version) via the debug launcher!\nYou have the following testing options:\n\n");
  printf("1. Full Program\n2. Full Program (testing speed)\n3. Skip to Starter (testing speed)\n4. Skip to Battle (level 20 preset Pokemon)\n\n");
  printf("Enter your launch option here: ");
  scanf("%d", &debugChoice);
  switch(debugChoice)
  {
    case 1 :
    {
      return 1;
    }
    case 2 :
    {
      DELAYMODIFIER = 10;
      return 1;
    }
    case 3 :
    {
      DELAYMODIFIER = 10;
      return 2;
    }
    case 4 :
    {
      BATTLECOUNT = 1; // to limit overcapping on experience from playing too many battles
      DELAYMODIFIER = 10;
      return 3;
    }
    default :
    {
      printf("Invalid entry - Choose an option 1-4:\n");
      main();
    }
  }
}

void playerStatReadout() // Prints all stats from playerStats.txt to the terminal
{
  printf("%s is Level %.0f with:\n", PLAYERPOKEMONCHOICE, readPokemonStats("player", 1));
  printf("  %.0f XP\n", readPokemonStats("player", 2));
  printf("  %.2f HP\n", readPokemonStats("player", 3));
  printf("  %.2f Attack\n", readPokemonStats("player", 4));
  printf("  %.2f Defense\n", readPokemonStats("player", 5));
  printf("  %.2f Special Attack\n", readPokemonStats("player", 6));
  printf("  %.2f Special Defense\n", readPokemonStats("player", 7));
  printf("  %.2f Speed\n", readPokemonStats("player", 8));
}

void npcStatReadout() // Prints all stats from npcStats.txt to the terminal
{
  printf("%s is Level %.0f with:\n", NPCPOKEMONCHOICE, readPokemonStats("npc", 1));
  printf("  %.0f XP\n", readPokemonStats("npc", 2));
  printf("  %.2f HP\n", readPokemonStats("npc", 3));
  printf("  %.2f Attack\n", readPokemonStats("npc", 4));
  printf("  %.2f Defense\n", readPokemonStats("npc", 5));
  printf("  %.2f Special Attack\n", readPokemonStats("npc", 6));
  printf("  %.2f Special Defense\n", readPokemonStats("npc", 7));
  printf("  %.2f Speed\n", readPokemonStats("npc", 8));
}