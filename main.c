/*  CS125 Group Project
    File: main.c
    Description: Main function file; combines all support functions
    Authors: Forrest Mobley, Colton Van Orsdel
    References: https://www.poftut.com/what-is-sleep-function-and-how-to-use-it-in-c-program/
*/

// Cross-Platform library solution for sleep() function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// Utilized libraries
#include <string.h>
#include <stdio.h>

// Header files
#include "util.h"
#include "intro.h"
#include "starter.h"
#include "art.h"
#include "battleUI.h"
#include "pokeFiles.h"
#include "combatSandbox.h"
#include "generatePokemonStats.h"
#include "combat.h"
#include "levelupPokemonStats.h"
#include "readPokemonStats.h"
#include "endSim.h"

// Global variables
statStruct STATSTORAGE; 
char TYPE[6];
char MOVESELECTED[15];
char EFFECTIVENESS[30];
char POTIONSELECTED[15];
char USERNAME[50];
char PLAYERPOKEMONCHOICE[20];
char NPCPOKEMONCHOICE[20];
int NPCRANDOMIZE;
int WINORLOSE;

int main(){
  char dummy; // Dummy var
  int count; // Count for printing

  char text1[]="Hi! Sorry to keep you waiting! Welcome to the world of Pokemon!\nMy name is Heather Marriott. But everyone calls me the\nCoding Professor. This world is widely inhabited by creatures known\nas Pokemon. We humans live alongside Pokemon, at times\nas friendly playmates, and at times as cooperative workmates.\nAnd sometimes, we band together and battle others like us.\nBut despite our closeness, we don't know everything about Pokemon.\nIn fact, there are many, many secrets surrounding Pokemon.\nTo unravel Pokemon mysteries, I've been undertaking research.\nThat's what I do.\n";
  char text2[]="\nAnd you are? ";
  char text3[]="\nAh, okay! You're ";
  char text4[]=" who's moving to my hometown of Prescott. I get it now!\nAll right, are you ready? Your very own adventure is\nabout to unfold. Take courage, and leap into the world of Pokemon\nwhere dreams, adventure and friendships await!\nFirst, let's choose a Pokemon companion!\n";
  char text5[]="\nBefore you head out, I've created a simulator where you can practice working\nwith your Pokemon companion in battles! It's a series of battles,\nsort of like the Champion's League. It's even VR!\n\nCheck it out!";

/*  // Running Start Screen & looking for Enter input
  intro();
  scanf("%c", &dummy);
  clear();
  fflush(stdout);

  // Printing Intro Text
  sleep(3);
  readPrint(count, text1, "standard");

  // Get user's name
  readPrint(count, text2, "standard");
  fgets(USERNAME, 50, stdin);
  USERNAME[strcspn(USERNAME, "\n")]=0;

  // Reacting to USERNAME
  readPrint(count, text3, "standard");
  readPrint(count, USERNAME, "yellow");
  readPrint(count, text4, "standard");
  sleep(1);
*/
  // Pokemon Choice
  starter();
  sleep(1);
  clear();

  // Stat file creation
  generatePokemonStats(pokemonChoiceToInt("player"), 0);
  generatePokemonStats(pokemonChoiceToInt("npc"), 2);

  // Example usage of level-up function - purposefully commented out here
/*  levelupPokemonStats("player", pokemonChoiceToInt("player"), 30000);
  levelupPokemonStats("npc", pokemonChoiceToInt("npc"), 30000);*/

  // Player stat readout before initiating battle simulator
  printf("You chose %s!\n", PLAYERPOKEMONCHOICE);
  printf("%s is Level %.0f with:\n", PLAYERPOKEMONCHOICE, readPokemonStats("player", 1));
  printf("%.2f XP\n", NPCPOKEMONCHOICE, readPokemonStats("player", 2));
  printf("%.2f HP\n", readPokemonStats("player", 3));
  printf("%.2f Attack\n", readPokemonStats("player", 4));
  printf("%.2f Defense\n", readPokemonStats("player", 5));
  printf("%.2f Special Attack\n", readPokemonStats("player", 6));
  printf("%.2f Special Defense\n", readPokemonStats("player", 7));
  printf("%.2f Speed\n", readPokemonStats("player", 8));

  // NPC stat readout before initiating battle simulator
  printf("\nYour opponent is %s!\n", NPCPOKEMONCHOICE);
  printf("%s is Level %.0f with:\n", NPCPOKEMONCHOICE, readPokemonStats("npc", 1));
  printf("%.2f XP\n", NPCPOKEMONCHOICE, readPokemonStats("npc", 2));
  printf("%.2f HP\n", readPokemonStats("npc", 3));
  printf("%.2f Attack\n", readPokemonStats("npc", 4));
  printf("%.2f Defense\n", readPokemonStats("npc", 5));
  printf("%.2f Special Attack\n", readPokemonStats("npc", 6));
  printf("%.2f Special Defense\n", readPokemonStats("npc", 7));
  printf("%.2f Speed\n", readPokemonStats("npc", 8));

  initializeStats(); // populate STATSTORAGE struct with default values from files

  // Remove after battleUI implementation
  printf("\nbattleUI Variable Testing below:");
  printf("\nTEST: Player Move One: %s", STATSTORAGE.p_moveOne);
  printf("\nTEST: Player Move Two: %s", STATSTORAGE.p_moveTwo);
  printf("\nTEST: Player Ability: %s", STATSTORAGE.p_ability);
  printf("\nTEST: Player Consumable: %s", STATSTORAGE.p_consumable);
  printf("\nTEST: NPC Move One: %s", STATSTORAGE.n_moveOne);
  printf("\nTEST: NPC Move Two: %s", STATSTORAGE.n_moveTwo);
  printf("\nTEST: NPC Ability: %s", STATSTORAGE.n_ability);
  printf("\nTEST: NPC Consumable: %s\n\n", STATSTORAGE.n_consumable);

  // Start of simulation
  readPrint(count, text5, "standard");

  battleUI();
  endSim();
  battleUI();

  // Clean up directory by deleting temporary files; will later implement an ask if player wants to "save" their game
  remove("playerStats.txt");
  remove("npcStats.txt");
  return 0;
}