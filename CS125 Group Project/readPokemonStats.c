/*	CS125 Group Project
	File: readPokemonStats.c
	Description: Enables other functions to pull Pokemon stats directly from their file
	Authors: Colton Van Orsdel
	References: N/A
*/

// Utilized libraries
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Header files
#include "generatePokemonStats.h"
#include "levelupPokemonStats.h"
#include "readPokemonStats.h"
#include "combat.h"

float readPokemonStats(char who[7], int stat) // used to read stat values from playerStats.txt and npcStats.txt
{
	float statResult[9];
	if (strcmp(who, "player")==0)
	{
		FILE* playerStats = fopen("playerStats.txt", "r");
		fscanf(playerStats, "Pokemon ID: %f\n", &statResult[0]);
		fscanf(playerStats, "Level: %f\n", &statResult[1]);
		fscanf(playerStats, "Experience: %f\n", &statResult[2]);
		fscanf(playerStats, "HP: %f\n", &statResult[3]);
		fscanf(playerStats, "Attack: %f\n", &statResult[4]);
		fscanf(playerStats, "Defense: %f\n", &statResult[5]);
		fscanf(playerStats, "Sp. Attack: %f\n", &statResult[6]);
		fscanf(playerStats, "Sp. Defense: %f\n", &statResult[7]);
		fscanf(playerStats, "Speed: %f", &statResult[8]);
		fclose(playerStats);
	}
	else if (strcmp(who, "npc")==0)
	{
		FILE* npcStats = fopen("npcStats.txt", "r");
		fscanf(npcStats, "Pokemon ID: %f\n", &statResult[0]);
		fscanf(npcStats, "Level: %f\n", &statResult[1]);
		fscanf(npcStats, "Experience: %f\n", &statResult[2]);
		fscanf(npcStats, "HP: %f\n", &statResult[3]);
		fscanf(npcStats, "Attack: %f\n", &statResult[4]);
		fscanf(npcStats, "Defense: %f\n", &statResult[5]);
		fscanf(npcStats, "Sp. Attack: %f\n", &statResult[6]);
		fscanf(npcStats, "Sp. Defense: %f\n", &statResult[7]);
		fscanf(npcStats, "Speed: %f", &statResult[8]);
		fclose(npcStats);
	}
	else
		printf("ERROR: readPokemonStats() 'if' defaulted; debug"); // only occurs from developer error in implementation code

	return statResult[stat];
}