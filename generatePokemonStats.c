/*	CS125 Group Project
	File: generatePokemonStats.h
	Description: Creates and fills Pokemon-specific stats to text files
	Authors: Colton Van Orsdel
	References: N/A
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "levelupPokemonStats.h"
#include "readPokemonStats.h"
#include "generatePokemonStats.h"

void createPlayerFile(float statsArray[9]);
void createNPCFile(float statsArray[9]);

char *generatePokemonStats(int pokemonChoice, char pokemonName[20]) // pokemonChoice = '1'-Bulbasaur; '2'-Charmander; '3'-Squirtle; '4'-GrassNPC; '5'-FireNPC; '6'-WaterNPC
{
	srand(time(NULL)); 
	int npcRandomize = rand()%2+1; // toggles between '1' and '2' to determine random opponent of given type
//	printf("Randomize Value: %d\n", npcRandomize); // debugging; remove to finalize
	switch(pokemonChoice)
	{
		case 1 : // Bulbasaur default stats
		{
			float statsArray[9]={1, 1, 1000, 45, 49, 49, 65, 65, 45};
			createPlayerFile(statsArray);
			strcpy(pokemonName, "Bulbasaur");
			return pokemonName;
		}
		case 2 : // Charmander default stats
		{
			float statsArray[9]={2, 1, 1000, 39, 52, 43, 60, 50, 65};
			createPlayerFile(statsArray);
			strcpy(pokemonName, "Charmander");
			return pokemonName;
		}
		case 3 : // Squirtle default stats
		{
			float statsArray[9]={3, 1, 1000, 44, 48, 65, 50, 64, 43};
			createPlayerFile(statsArray);
			strcpy(pokemonName, "Squirtle");
			return pokemonName;
		}
		case 4 : // Bellsprout/Oddish NPC default stats
		{
			if (npcRandomize == 1)
			{
				float statsArray[9]={4, 1, 1000, 50, 75, 35, 70, 30, 40}; // Bellsprout
				createNPCFile(statsArray);
				strcpy(pokemonName, "Bellsprout");
				return pokemonName;
			}
			else
			{
				float statsArray[9]={4, 1, 1000, 45, 50, 55, 75, 65, 30}; // Oddish
				createNPCFile(statsArray);
				strcpy(pokemonName, "Oddish");
				return pokemonName;
			}
		}
		case 5 : // Growlithe/Ponyta NPC default stats
		{
			if (npcRandomize == 1)
			{
				float statsArray[9]={5, 1, 1000, 55, 70, 45, 70, 50, 60}; // Growlithe
				createNPCFile(statsArray);
				strcpy(pokemonName, "Growlithe");
				return pokemonName;
			}
			else
			{
				float statsArray[9]={5, 1, 1000, 50, 85, 55, 65, 65, 90}; // Ponyta
				createNPCFile(statsArray);
				strcpy(pokemonName, "Ponyta");
				return pokemonName;
			}
		}
		case 6 : // Slowpoke/Seel NPC default stats
		{
			if (npcRandomize == 1)
			{
				float statsArray[9]={6, 1, 1000, 90, 65, 65, 40, 40, 15}; // Slowpoke
				createNPCFile(statsArray);
				strcpy(pokemonName, "Slowpoke");
				return pokemonName;
			}
			else
			{
				float statsArray[9]={6, 1, 1000, 65, 45, 55, 45, 70, 45}; // Seel
				createNPCFile(statsArray);
				strcpy(pokemonName, "Seel");
				return pokemonName;
			}
		}
		default :
		{
			printf("ERROR: generatePokemonStats() switch defaulted; debug"); // only occurs from developer error in implementation code
			return 0;
		}
		return pokemonName;
	}
}

void createPlayerFile(float statsArray[9])
{
	FILE* playerStats = fopen("playerStats.txt", "w+"); // creates playerStats.txt, wiping contents with write permissions
	fprintf(playerStats, "Pokemon ID: %.0f\n", statsArray[0]);
	fprintf(playerStats, "Level: %.0f\n", statsArray[1]);
	fprintf(playerStats, "Experience: %.2f\n", statsArray[2]);
	fprintf(playerStats, "HP: %.2f\n", statsArray[3]);
	fprintf(playerStats, "Attack: %.2f\n", statsArray[4]);
	fprintf(playerStats, "Defense: %.2f\n", statsArray[5]);
	fprintf(playerStats, "Sp. Attack: %.2f\n", statsArray[6]);
	fprintf(playerStats, "Sp. Defense: %.2f\n", statsArray[7]);
	fprintf(playerStats, "Speed: %.2f", statsArray[8]);
	fclose(playerStats);
}

void createNPCFile(float statsArray[9])
{
	FILE* npcStats = fopen("npcStats.txt", "w+"); // creates npcStats.txt, wiping contents with write permissions
	fprintf(npcStats, "Pokemon ID: %.0f\n", statsArray[0]);
	fprintf(npcStats, "Level: %.0f\n", statsArray[1]);
	fprintf(npcStats, "Experience: %.2f\n", statsArray[2]);
	fprintf(npcStats, "HP: %.2f\n", statsArray[3]);
	fprintf(npcStats, "Attack: %.2f\n", statsArray[4]);
	fprintf(npcStats, "Defense: %.2f\n", statsArray[5]);
	fprintf(npcStats, "Sp. Attack: %.2f\n", statsArray[6]);
	fprintf(npcStats, "Sp. Defense: %.2f\n", statsArray[7]);
	fprintf(npcStats, "Speed: %.2f", statsArray[8]);
	fclose(npcStats);
}