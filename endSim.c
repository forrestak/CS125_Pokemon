/*  CS125 Group Project
    File: endSim.c
    Description: Animations and menus to play after sim win/loss
    Authors: Forrest Mobley, Colton Van Orsdel
    References: N/A
*/

// Utilized libraries
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Header files
#include "endSim.h"
#include "battleUI.h"
#include "generatePokemonStats.h"
#include "levelupPokemonStats.h"
#include "readPokemonStats.h"
#include "combat.h"

// Global variables
int BATTLECOUNT;

void endSim(){
  clear();
  int count;
  char text1[] = "Congratulations! You have completed a simulated combat scenario, and you even won!\n";
  char text2[] = "Aww! That's too bad! You gave a good show though! I'm sure\nif you try again you'll win next time!\n";
  char text3[] = "Both Pokemon have gained combat experience and have grown in strength!\nThey gained new abilities and improved their stats:\n\n";
  if (WINORLOSE == 1) // Win scenario
  { 
    BATTLECOUNT+=1;
    readPrint(count, text1, "standard");
    // Printing Trophy
    printf("\n");
    sleep(1);
    asciiart(6);
    printf("\n");
    sleep(1);
    levelupPokemonStats("player", pokemonChoiceToInt("player"), randomizeExperienceGain()); // Level up player's Pokemon
    levelupPokemonStats("npc", pokemonChoiceToInt("npc"), randomizeExperienceGain()); // Level up NPC's Pokemon
    initializeStats(); // Populate STATSTORAGE struct with default values from files
    readPrint(count, text3, "standard");
    playerStatReadout(); // Print new player Pokemon stats to terminal
    npcStatReadout(); // Print new NPC Pokemon stats to terminal
    playAgainPrompt();
  }
  else if (WINORLOSE == 0) // Lose Scenario
  { 
    BATTLECOUNT+=1;
    readPrint(count, text2, "standard");
    printf("\n");
    sleep(1);
    asciiart(7);
    printf("\n");
    levelupPokemonStats("player", pokemonChoiceToInt("player"), randomizeExperienceGain()); // Level up player's Pokemon
    levelupPokemonStats("npc", pokemonChoiceToInt("npc"), randomizeExperienceGain()); // Level up NPC's Pokemon
    initializeStats(); // Populate STATSTORAGE struct with default values from files
    readPrint(count, text3, "standard");
    playerStatReadout(); // Print new player Pokemon stats to terminal
    npcStatReadout(); // Print new NPC Pokemon stats to terminal
    playAgainPrompt();
  }
}

void playAgainPrompt() // Enables choices to play another battle or quit the game
{
  int count;
  int loopCheck; // Used to error-check (loop) prompt entries until they match a desired input
  char endChoice[20];
  char text4[] = "\nDo you want to continue training? (Yes/No): ";
  char text5[] = "You have completed the maximum number of tutorial battles.\n";
  char text6[] = "\nThis is the end of the tutorial simulator. I hope you enjoyed it\nand learned the basics for your upcoming adventure. I look forward to\nhearing all of the amazing stories about you and your companions!\n\nSee ya!\n";
  if (BATTLECOUNT < 5) // Checks to ensure the player has not already completed 5 batles
  {
    do
    {
      readPrint(count, text4, "standard");
      fgets(endChoice, 20, stdin);
      endChoice[strcspn(endChoice, "\n")]=0;
      for (count=0; count<=strlen(endChoice); count++)
        endChoice[count] = tolower(endChoice[count]);
      fflush(stdin);
      printf("\n");
      if ((strcmp(endChoice, "yes")==0) || (strcmp(endChoice, "y")==0))
      {
        loopCheck = 1;
        combatScenario();
        endSim();
      }
      else if ((strcmp(endChoice, "no")==0) || (strcmp(endChoice, "n")==0))
      {
        loopCheck = 1;
        readPrint(count, text6, "standard");
      }
      else 
      {
        loopCheck = 0;
        printf("Invalid entry.\n");
      }
    } while (loopCheck != 1);
  }
  else // Runs if the player has completed 5 battles to prevent more
  {
    readPrint(count, text5, "standard");
    readPrint(count, text6, "standard");
  }
}

int randomizeExperienceGain() // Generates psuedo-randomized experience between 21000 and 19000 for use in endSim()
{
  srand(time(NULL)); 
  return rand()%1000+19000;
}