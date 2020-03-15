/*	CS125 Group Project
	File: generatePokemonStats.c
	Description: Creates and fills Pokemon-specific stats to text files
	Authors: Colton Van Orsdel
	References: N/A
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void createPlayerFile(float statsArray[7]);
void createNPCFile(float statsArray[7]);

char *generatePokemonStats(int pokemonChoice) // pokemonChoice = '1'-Bulbasaur; '2'-Charmander; '3'-Squirtle; '4'-GrassNPC; '5'-FireNPC; '6'-WaterNPC
{
	srand(time(NULL)); 
	int npcRandomize = rand()%2+1; // toggles between '1' and '2' to determine random opponent of given type
	char pokemonName[10];
//	printf("Randomize Value: %d\n", npcRandomize); // debugging; remove to finalize
	switch(pokemonChoice)
	{
		case 1 : // Bulbasaur default stats
		{
			float statsArray[7]={1, 45, 49, 49, 65, 65, 45};
			createPlayerFile(statsArray);
			char pokemonName[10]="Bulbasaur";
			return pokemonName;
			break;
		}
		case 2 : // Charmander default stats
		{
			float statsArray[7]={1, 39, 52, 43, 60, 50, 65};
			createPlayerFile(statsArray);
			char pokemonName[10]="Charmander";
			return pokemonName;
			break;
		}
		case 3 : // Squirtle default stats
		{
			float statsArray[7]={1, 44, 48, 65, 50, 64, 43};
			createPlayerFile(statsArray);
			char pokemonName[10]="Squirtle";
			return pokemonName;
			break;
		}
		case 4 : // Bellsprout/Oddish NPC default stats
		{
			if (npcRandomize == 1)
			{
				float statsArray[7]={1, 50, 75, 35, 70, 30, 40}; // Bellsprout
				createNPCFile(statsArray);
				char pokemonName[10]="Bellsprout";
				return pokemonName;
			}
			else
			{
				float statsArray[7]={1, 45, 50, 55, 75, 65, 30}; // Oddish
				createNPCFile(statsArray);
				char pokemonName[10]="Oddish";
				return pokemonName;
			}
			break;
		}
		case 5 : // Growlithe/Ponyta NPC default stats
		{
			if (npcRandomize == 1)
			{
				float statsArray[7]={1, 55, 70, 45, 70, 50, 60}; // Growlithe
				createNPCFile(statsArray);
				char pokemonName[10]="Growlithe";
				return pokemonName;
			}
			else
			{
				float statsArray[7]={1, 50, 85, 55, 65, 65, 90}; // Ponyta
				createNPCFile(statsArray);
				char pokemonName[10]="Ponyta";
				return pokemonName;
			}
			break;
		}
		case 6 : // Slowpoke/Seel NPC default stats
		{
			if (npcRandomize == 1)
			{
				float statsArray[7]={1, 90, 65, 65, 40, 40, 15}; // Slowpoke
				createNPCFile(statsArray);
				char pokemonName[10]="Slowpoke";
				return pokemonName;
			}
			else
			{
				float statsArray[7]={1, 65, 45, 55, 45, 70, 45}; // Seel
				createNPCFile(statsArray);
				char pokemonName[10]="Seel";
				return pokemonName;
			}

			break;
		}
		default :
			printf("ERROR: generatePokemonStats() switch defaulted; debug"); // only occurs from developer error in implementation code
			break;
	}
}

void createPlayerFile(float statsArray[7])
{
	FILE* playerStats = fopen("playerStats.txt", "w+"); // creates playerStats.txt, wiping contents with write permissions
	fprintf(playerStats, "Level: %.0f\n", statsArray[0]);
	fprintf(playerStats, "HP: %.2f\n", statsArray[1]);
	fprintf(playerStats, "Attack: %.2f\n", statsArray[2]);
	fprintf(playerStats, "Defense: %.2f\n", statsArray[3]);
	fprintf(playerStats, "Sp. Attack: %.2f\n", statsArray[4]);
	fprintf(playerStats, "Sp. Defense: %.2f\n", statsArray[5]);
	fprintf(playerStats, "Speed: %.2f", statsArray[6]);
	fclose(playerStats);
}

void createNPCFile(float statsArray[7])
{
	FILE* npcStats = fopen("npcStats.txt", "w+"); // creates npcStats.txt, wiping contents with write permissions
	fprintf(npcStats, "Level: %.0f\n", statsArray[0]);
	fprintf(npcStats, "HP: %.2f\n", statsArray[1]);
	fprintf(npcStats, "Attack: %.2f\n", statsArray[2]);
	fprintf(npcStats, "Defense: %.2f\n", statsArray[3]);
	fprintf(npcStats, "Sp. Attack: %.2f\n", statsArray[4]);
	fprintf(npcStats, "Sp. Defense: %.2f\n", statsArray[5]);
	fprintf(npcStats, "Speed: %.2f", statsArray[6]);
	fclose(npcStats);
}