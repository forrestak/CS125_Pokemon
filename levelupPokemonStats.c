/*	CS125 Group Project
	File: levelupPokemonStats.c
	Description: Modifies pokemon stat files to "level-up" player/NPC
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

float getStatGrowth(int pokemonID, int stat);

void levelupPokemonStats(char who[7], int pokemonID, int experience)
{
	int i; // loop counter
	float leveledStatsArray[9];
	float previousStatStorage[9];

	if (strcmp(who, "player")==0)
	{
		for (i = 0; i < 9; i++)
		{
			previousStatStorage[i]=readPokemonStats("player", i); // store pre-levelup stats from playerStats.txt
		}
		leveledStatsArray[0] = previousStatStorage[0]; // repopulate pokemonID as it will not be updated
		leveledStatsArray[2] = previousStatStorage[2] + experience; // update total XP by adding new gain to previous value
		leveledStatsArray[1] = (int)(leveledStatsArray[2]/1000); // truncate new level to int and update 
		
		for(i = 3; i < 9; i++)
		{
			leveledStatsArray[i] = previousStatStorage[i] + (getStatGrowth(pokemonID, i-3) * (leveledStatsArray[1]-1)); // traverse each stat element and add calculated growth
		}
		createPlayerFile(leveledStatsArray); // generate new playerStats.txt with the new levelup stats
	}
	else if (strcmp(who, "npc")==0)
	{
		for (i = 0; i < 9; i++)
		{
			previousStatStorage[i]=readPokemonStats("npc", i); // store pre-levelup stats from npcStats.txt
		}
		leveledStatsArray[0] = previousStatStorage[0]; // repopulate pokemonID as it will not be updated
		leveledStatsArray[2] = previousStatStorage[2] + experience; // update total XP by adding new gain to previous value
		leveledStatsArray[1] = (int)(leveledStatsArray[2]/1000); // truncate new level to int and update 
		
		for(i = 3; i < 9; i++)
		{
			leveledStatsArray[i] = previousStatStorage[i] + (getStatGrowth(3+pokemonID, i-3) * (leveledStatsArray[1]-1)); // traverse each stat element and add calculated growth
		}
		createNPCFile(leveledStatsArray); // generate new npcStats.txt with the new levelup stats
	}
	else
		printf("ERROR: levelupPokemonStats() 'if' defaulted; debug"); // only occurs from developer error in implementation code

}

float getStatGrowth(int pokemonID, int stat) // pulls stat growth values for each Pokemon
{
	if (pokemonID == 1) // Bulbasaur
	{
		float statGrowth[6]={1.55, 0.43, 0.43, 0.56, 0.56, 0.4};
		return statGrowth[stat];
	}
	else if (pokemonID == 2) // Charmander
	{
		float statGrowth[6]={1.49, 0.46, 0.38, 0.52, 0.44, 0.56};
		return statGrowth[stat];
	}
	else if (pokemonID == 3) // Squirtle
	{
		float statGrowth[6]={1.54, 0.42, 0.56, 0.44, 0.55, 0.38};
		return statGrowth[stat];
	}
	else // NPC
	{
		float statGrowth[6]={1.53, 0.44, 0.45, 0.51, 0.52, 0.45};
		return statGrowth[stat];
	}
}