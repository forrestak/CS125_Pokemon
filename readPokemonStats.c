/*	CS125 Group Project
	File: readPokemonStats.c
	Description: Allows other functions to pull Pokemon stats directly from their file
	Authors: Colton Van Orsdel
	References: N/A
*/
#include <stdio.h>
#include <string.h>
float readPokemonStats(char who[100], int stat)
{
	float statResult[7];
	if (strcmp(who, "player")==0)
	{
		FILE* playerStats = fopen("playerStats.txt", "r");
		fscanf(playerStats, "Level: %f\n", &statResult[0]);
		fscanf(playerStats, "HP: %f\n", &statResult[1]);
		fscanf(playerStats, "Attack: %f\n", &statResult[2]);
		fscanf(playerStats, "Defense: %f\n", &statResult[3]);
		fscanf(playerStats, "Sp. Attack: %f\n", &statResult[4]);
		fscanf(playerStats, "Sp. Defense: %f\n", &statResult[5]);
		fscanf(playerStats, "Speed: %f", &statResult[6]);
		fclose(playerStats);
	}
	else if (strcmp(who, "npc")==0)
	{
		FILE* npcStats = fopen("npcStats.txt", "r");
		fscanf(npcStats, "Level: %f\n", &statResult[0]);
		fscanf(npcStats, "HP: %f\n", &statResult[1]);
		fscanf(npcStats, "Attack: %f\n", &statResult[2]);
		fscanf(npcStats, "Defense: %f\n", &statResult[3]);
		fscanf(npcStats, "Sp. Attack: %f\n", &statResult[4]);
		fscanf(npcStats, "Sp. Defense: %f\n", &statResult[5]);
		fscanf(npcStats, "Speed: %f", &statResult[6]);
		fclose(npcStats);
	}
	else
		printf("ERROR: readPokemonStats() 'if' defaulted; debug"); // only occurs from developer error in implementation code

	return statResult[stat];
}