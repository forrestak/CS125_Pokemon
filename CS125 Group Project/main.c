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
	int launchMode;
	launchMode = debugLauncher(); // calls debugLauncher() and sets value for usage in main() switch below
	char dummy; // Dummy var
	int count; // Count for printing
	char text1[]="Hi! Sorry to keep you waiting! Welcome to the world of Pokemon!\nMy name is Heather Marriott. But everyone calls me the\nCoding Professor. This world is widely inhabited by creatures known\nas Pokemon. We humans live alongside Pokemon, at times\nas friendly playmates, and at times as cooperative workmates.\nAnd sometimes, we band together and battle others like us.\nBut despite our closeness, we don't know everything about Pokemon.\nIn fact, there are many, many secrets surrounding Pokemon.\nTo unravel Pokemon mysteries, I've been undertaking research.\nThat's what I do.\n";
	char text2[]="\nAnd you are? ";
	char text3[]="\nAh, okay! You're ";
	char text4[]=" who's moving to my hometown of Prescott. I get it now!\nAll right, are you ready? Your very own adventure is\nabout to unfold. Take courage, and leap into the world of Pokemon\nwhere dreams, adventures, and friendships await!\nFirst, let's choose a Pokemon companion!\n";
	char text5[]="\nBefore you head out, I've created a simulator where you can practice working\nwith your Pokemon companion in battles! It's a series of battles,\nsort of like the Champion's League. It's even VR!\n\nCheck it out!";
	switch(launchMode)
	{
	case 1 : // Runs the full program
	{
		// Running Start Screen & looking for Enter input
		intro();
		scanf("%c", &dummy);
		clear();
		fflush(stdout);

		// Printing Intro Text
		sleep(1);
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

		// Pokemon Choice
		starter();
		sleep(2);
		clear();

		// Stat file creation
		generatePokemonStats(pokemonChoiceToInt("player"), 0);
		generatePokemonStats(pokemonChoiceToInt("npc"), 2);

		printf("You chose %s!\n", PLAYERPOKEMONCHOICE);
		playerStatReadout(); // Player stat readout before initiating battle simulator

		printf("\nYour opponent is %s!\n", NPCPOKEMONCHOICE);
		npcStatReadout(); // NPC stat readout before initiating battle simulator

		initializeStats(); // populate STATSTORAGE struct with default values from files

		// Start of simulation
		readPrint(count, text5, "standard");
		sleep(5);
		combatScenario();
		endSim();
		break;
	}
	case 2 : // Skips to starter with increased text read-out speed
	{
		// Catches stray input that causes bug on combatScenario() load
		scanf("%c", &dummy);
		clear();
		fflush(stdout);

		// Pokemon Choice
		starter();
		sleep(2);
		clear();

		// Stat file creation
		generatePokemonStats(pokemonChoiceToInt("player"), 0);
		generatePokemonStats(pokemonChoiceToInt("npc"), 2);

		printf("You chose %s!\n", PLAYERPOKEMONCHOICE);
		playerStatReadout(); // Player stat readout before initiating battle simulator

		printf("\nYour opponent is %s!\n", NPCPOKEMONCHOICE);
		npcStatReadout(); // NPC stat readout before initiating battle simulator

		initializeStats(); // populate STATSTORAGE struct with default values from files

		// Start of simulation
		readPrint(count, text5, "standard");
		sleep(5);
		combatScenario();
		endSim();
		break;
	}
	case 3: // Skips to battleUI with Bulbasaur auto-selected as player's Pokemon
	{
		// Catches stray input that causes bug on combatScenario() load
		scanf("%c", &dummy);
		clear();
		fflush(stdout);
		// Stat file creation
		generatePokemonStats(1, 0); // preset with Bulbasaur
		generatePokemonStats(6, 2); // preset with water-type

		// Set preset Pokemon level to 50
		levelupPokemonStats("player", pokemonChoiceToInt("player"), 19000);
		levelupPokemonStats("npc", pokemonChoiceToInt("npc"), 19000);

		printf("You chose %s!\n", PLAYERPOKEMONCHOICE);
		playerStatReadout(); // Player stat readout before initiating battle simulator

		printf("\nYour opponent is %s!\n", NPCPOKEMONCHOICE);
		npcStatReadout(); // NPC stat readout before initiating battle simulator

		initializeStats(); // populate STATSTORAGE struct with default values from files

		// Start of simulation
		readPrint(count, text5, "standard");
		sleep(5);
		combatScenario();
		endSim();
		break;
	}
	default : 
		printf("ERROR: main() switch defaulted; debug"); // only occurs from developer error in implementation code
		break;
	}

	// Clean up directory by deleting temporary files
	remove("playerStats.txt");
	remove("npcStats.txt");

	return 0;
	}
