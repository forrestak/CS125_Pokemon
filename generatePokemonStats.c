/*	CS125 Group Project
	File: generatePokemonStats.c
	Description: Creates and fills Pokemon-specific stats to text files
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

void createPlayerFile(float statsArray[9]);
void createNPCFile(float statsArray[9]);

char *generatePokemonStats(int pokemonChoiceInt, int useOrCheck) // pokemonChoiceInt -> POKEMONCHOICE = '1'-Bulbasaur; '2'-Charmander; '3'-Squirtle; '4'-GrassNPC; '5'-FireNPC; '6'-WaterNPC // useOrCheck = '0'-Use; '1'-Check; '2'-Randomize
{
	srand(time(NULL)); 
	if (useOrCheck == 2)
	{
		NPCRANDOMIZE = rand()%2+1; // toggles between '1' and '2' to determine random opponent of given type
	}
	switch(pokemonChoiceInt)
	{
		case 1 : // Bulbasaur default stats
		{
			if (useOrCheck == 1)
			{
				strcpy(PLAYERPOKEMONCHOICE, "Bulbasaur");
				return PLAYERPOKEMONCHOICE;
			}
			else
			{
				float statsArray[9]={1, 1, 1000, 45, 49, 49, 65, 65, 45};
				createPlayerFile(statsArray);
				strcpy(PLAYERPOKEMONCHOICE, "Bulbasaur");
				break;
			}
		}
		case 2 : // Charmander default stats
		{
			if (useOrCheck == 1)
			{
				strcpy(PLAYERPOKEMONCHOICE, "Charmander");
				return PLAYERPOKEMONCHOICE;
			}
			else
			{
				float statsArray[9]={2, 1, 1000, 39, 52, 43, 60, 50, 65};
				createPlayerFile(statsArray);
				strcpy(PLAYERPOKEMONCHOICE, "Charmander");
				break;
			}
		}
		case 3 : // Squirtle default stats
		{
			if (useOrCheck == 1)
			{
				strcpy(PLAYERPOKEMONCHOICE, "Squirtle");
				return PLAYERPOKEMONCHOICE;
			}
			else
			{
				float statsArray[9]={3, 1, 1000, 44, 48, 65, 50, 64, 43};
				createPlayerFile(statsArray);
				strcpy(PLAYERPOKEMONCHOICE, "Squirtle");
				break;
			}
		}
		case 4 : // Bellsprout/Oddish NPC default stats
		{
			if (NPCRANDOMIZE == 1)
			{
				if (useOrCheck == 1)
				{
					strcpy(NPCPOKEMONCHOICE, "Bellsprout");
					return NPCPOKEMONCHOICE;
				}
				else
				{
					float statsArray[9]={4, 1, 1000, 50, 75, 35, 70, 30, 40}; // Bellsprout
					createNPCFile(statsArray);
					strcpy(NPCPOKEMONCHOICE, "Bellsprout");
					break;
				}
			}
			else
			{
				if (useOrCheck == 1)
				{
					strcpy(NPCPOKEMONCHOICE, "Oddish");
					return NPCPOKEMONCHOICE;
				}
				else
				{
					float statsArray[9]={4, 1, 1000, 45, 50, 55, 75, 65, 30}; // Oddish
					createNPCFile(statsArray);
					strcpy(NPCPOKEMONCHOICE, "Oddish");
					break;
				}
			}
		}
		case 5 : // Growlithe/Ponyta NPC default stats
		{
			if (NPCRANDOMIZE == 1)
			{
				if (useOrCheck == 1)
				{
					strcpy(NPCPOKEMONCHOICE, "Growlithe");
					return NPCPOKEMONCHOICE;
				}
				else
				{
					float statsArray[9]={5, 1, 1000, 55, 70, 45, 70, 50, 60}; // Growlithe
					createNPCFile(statsArray);
					strcpy(NPCPOKEMONCHOICE, "Growlithe");
					break;
				}
			}
			else
			{
				if (useOrCheck == 1)
				{
					strcpy(NPCPOKEMONCHOICE, "Ponyta");
					return NPCPOKEMONCHOICE;
				}
				else
				{
					float statsArray[9]={5, 1, 1000, 50, 85, 55, 65, 65, 90}; // Ponyta
					createNPCFile(statsArray);
					strcpy(NPCPOKEMONCHOICE, "Ponyta");
					break;
				}
			}
		}
		case 6 : // Slowpoke/Seel NPC default stats
		{
			if (NPCRANDOMIZE == 1)
			{
				if (useOrCheck == 1)
				{
					strcpy(NPCPOKEMONCHOICE, "Slowpoke");
					return NPCPOKEMONCHOICE;
				}
				else
				{
					float statsArray[9]={6, 1, 1000, 90, 65, 65, 40, 40, 15}; // Slowpoke
					createNPCFile(statsArray);
					strcpy(NPCPOKEMONCHOICE, "Slowpoke");
					break;
				}
			}
			else
			{
				if (useOrCheck == 1)
				{
					strcpy(NPCPOKEMONCHOICE, "Seel");
					return NPCPOKEMONCHOICE;
				}
				else
				{
					float statsArray[9]={6, 1, 1000, 65, 45, 55, 45, 70, 45}; // Seel
					createNPCFile(statsArray);
					strcpy(NPCPOKEMONCHOICE, "Seel");
					break;
				}
			}
		}
		default :
		{
			printf("ERROR: generatePokemonStats() switch defaulted; debug"); // only occurs from developer error in implementation code
			return PLAYERPOKEMONCHOICE;
		}
	}
	return PLAYERPOKEMONCHOICE;
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