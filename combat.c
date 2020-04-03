/*	CS125 Group Project
	File: combat.c
	Description: Handles combat actions and related stat updating
	Authors: Colton Van Orsdel
	References: https://www.cplusplus.com/reference/cstdlib/atof/
				https://www.poftut.com/what-is-sleep-function-and-how-to-use-it-in-c-program/
*/
// Cross-Platform library solution for sleep() function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

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

void combatScenario() // combines primary combat functions to simulate combat until there is a victor
{
	initializeStats(); // populate statStorage struct with default values from files
	printf("\nThe tournament has begun!\n");
	if (statStorage.p_speed >= statStorage.n_speed)
	{
		do 
		{
			playerTurn();
			if ((statStorage.p_hp > 0) && (statStorage.n_hp > 0))
			{
				npcTurn(npcAI());
			}
		}
		while ((statStorage.p_hp > 0) && (statStorage.n_hp > 0));
	}
	else
	{
		do 
		{
			npcTurn(npcAI());
			if ((statStorage.p_hp > 0) && (statStorage.n_hp > 0))
			{
				playerTurn();
			}
		}
		while ((statStorage.p_hp > 0) && (statStorage.n_hp > 0));
	}
	if (statStorage.p_hp <= 0)
	{
		printf("%s has fainted...\n", generatePokemonStats(statStorage.p_pokemonID, pokemonName, 1));
		printf("%s is victorious!\n", generatePokemonStats(statStorage.n_pokemonID, pokemonName, 1));
	}
	else if (statStorage.n_hp <= 0)
	{
		printf("%s has fainted...\n", generatePokemonStats(statStorage.n_pokemonID, pokemonName, 1));
		printf("%s is victorious!\n", generatePokemonStats(statStorage.p_pokemonID, pokemonName, 1));
	}
	else
	{
		printf("ERROR: combatScenario() if defaulted; debug"); // only occurs from developer error in implementation code
	}
}


// --------------------------------------------------------DIRECT combatScenario() SUPPORT FUNCTIONS BELOW-------------------------------------------------------- //


void playerTurn() // handles choice implementation for each of the player's four actions
{	int playerChoice;
	printf("1-Physical | 2-Special\n3-Ability | 4-Consumable\n");
	printf("ACTION: ");
	scanf("%d", &playerChoice);
	switch(playerTurnCheck(playerChoice))
	{
		case 1 : // Move One
		{
			printf("%s uses %s!\n", generatePokemonStats(statStorage.p_pokemonID, pokemonName, 1), moveSelect("player", 1, moveSelected));
			printf("It's %s\n", checkEffectiveness(createTypeModifier("player"), effectiveness));
			printf("\n%s HP: %.2f\n\n", generatePokemonStats(statStorage.n_pokemonID, pokemonName, 1), statStorage.n_hp);
			break;
		}
		case 2 : // Move Two
		{
			printf("%s uses %s!\n", generatePokemonStats(statStorage.p_pokemonID, pokemonName, 1), moveSelect("player", 2, moveSelected));
			break;
		}
		case 3 : // Ability
		{
			printf("%s activates Overgrowth!\n", generatePokemonStats(statStorage.p_pokemonID, pokemonName, 1));
			printf("%s now deals %.0f%% move damage.\n", generatePokemonStats(statStorage.p_pokemonID, pokemonName, 1), useAbility("player")*100);
			break;
		}
		case 4 : // Consumable
		{
			printf("%s consumed %s!\n", generatePokemonStats(statStorage.p_pokemonID, pokemonName, 1), useConsumable("player", potionSelected));
			printf("\n%s HP: %.2f\n\n", generatePokemonStats(statStorage.p_pokemonID, pokemonName, 1), statStorage.p_hp);
			break;
		}
		default :
		{
			printf("ERROR: playerTurn() switch defaulted; debug"); // only occurs from developer error in implementation code
			break;
		}
	}
}

void npcTurn(int npcChoice) // handles choice implementation for each of the NPC's four actions
{
	printf("\nWaiting for opponent...\n");
	sleep(2);
	switch(npcChoice)
	{
		case 1 : // Move One
		{
			printf("%s uses %s!\n", generatePokemonStats(statStorage.n_pokemonID, pokemonName, 1), moveSelect("npc", 1, moveSelected));
			printf("It's %s\n", checkEffectiveness(createTypeModifier("npc"), effectiveness));
			printf("\n%s HP: %.2f\n\n", generatePokemonStats(statStorage.p_pokemonID, pokemonName, 1), statStorage.p_hp);
			break;
		}
		case 2 : // Move Two
		{
			printf("%s uses %s!\n", generatePokemonStats(statStorage.n_pokemonID, pokemonName, 1), moveSelect("npc", 2, moveSelected));
			break;
		}
		case 3 : // Ability
		{
			printf("%s activates Overgrowth!\n", generatePokemonStats(statStorage.n_pokemonID, pokemonName, 1));
			printf("%s now deals %.0f%% move damage.\n", generatePokemonStats(statStorage.n_pokemonID, pokemonName, 1), useAbility("npc")*100);
			break;
		}
		case 4 : // Consumable
		{
			printf("%s consumed %s!\n", generatePokemonStats(statStorage.n_pokemonID, pokemonName, 1), useConsumable("npc", potionSelected));
			printf("\n%s HP: %.2f\n\n", generatePokemonStats(statStorage.n_pokemonID, pokemonName, 1), statStorage.n_hp);
			break;
		}
		default :
		{
			printf("ERROR: playerTurn() switch defaulted; debug"); // only occurs from developer error in implementation code
			break;
		}
	}
}


// --------------------------------------------------------DIRECT *turn() SUPPORT FUNCTIONS BELOW-------------------------------------------------------- //


int playerTurnCheck(int playerChoice) // checks whether player chose a valid move before attempting to execute it
{
	switch(playerChoice)
	{
		case 1 : 
		{
			return 1;
		}
		case 2 :
		{
			return 2;
		}
		case 3 : 
		{
			if (statStorage.p_hp <= ((readPokemonStats("player", 3) / 3)) && (statStorage.n_abilityCount >= 1))
			{
				return 3;
			}
			else
			{
				printf("You must be below 30%% HP to use Overgrowth.\n");
				playerTurn();
				break;
			}
		}
		case 4: 
		{
			if (statStorage.p_consumableCount > 0)
			{
				return 4;
			}
			else
			{
				printf("You do not have any consumables to use.\n");
				playerTurn();
				break;
			}
		}
		default :
		{
			printf("ERROR: playerTurnCheck() switch defaulted; debug"); // only occurs from developer error in implementation code
			break;
		}
	}
	return 0;
}


int npcAI() // creates psuedo-random choice weights for npcTurn() and checks whether a move is valid before attempting to execute it
{
	int npcChoice;
	int weightedRandomKey;
	srand(time(NULL)); // seed rand() based on current time
	weightedRandomKey = rand()%100+1; // random value between 100 and 1
	if ((weightedRandomKey <= 75) && (statStorage.n_hp > ((readPokemonStats("npc", 3) / 3)))) // 75% chance to use Move One while above 1/3 HP
	{
		npcChoice = 1;
	}
	else if ((weightedRandomKey > 75) && (statStorage.n_hp > ((readPokemonStats("npc", 3) / 3)))) // 25% chance to use Move Two while above 1/3 HP
	{
		npcChoice = 2;
	}
	else if ((weightedRandomKey <= 90) && (statStorage.n_hp <= ((readPokemonStats("npc", 3) / 3))) && (statStorage.n_abilityStatus == 0)) // 80% chance to use Ability while below 1/3 HP
	{
		npcChoice = 3;
	}
	else if ((weightedRandomKey <= 60) && (statStorage.n_hp < ((readPokemonStats("npc", 3) / 2))) && (statStorage.n_consumableCount > 0)) // 60% chance to use Consumable (if available) while below 1/2 HP 
	{
		npcChoice = 4;
	}
	else 
	{
		if (weightedRandomKey <= 75)
		{
			npcChoice = 1;
		}
		else
		{
			npcChoice = 2;
		}
		
	}
	return npcChoice;
}


// --------------------------------------------------------STAT-RELATED UTILITY FUNCTIONS BELOW-------------------------------------------------------- //

statStruct initializeStats() // populate statStorage struct with default values from files
{
	// Assign player stat defaults from files
	strcpy(statStorage.p_type, getType(readPokemonStats("player", 0), type));
	statStorage.p_pokemonID = readPokemonStats("player", 0);
	statStorage.p_level = readPokemonStats("player", 1);
	statStorage.p_experience = readPokemonStats("player", 2);
	statStorage.p_hp = readPokemonStats("player", 3);
	statStorage.p_attack = readPokemonStats("player", 4);
	statStorage.p_defense = readPokemonStats("player", 5);
	statStorage.p_spAttack = readPokemonStats("player", 6);
	statStorage.p_spDefense = readPokemonStats("player", 7);
	statStorage.p_speed = readPokemonStats("player", 8);
	statStorage.p_consumableCount = 1; // tracks remaining potions
	statStorage.p_abilityCount = 1; // tracks remianing ability uses
	statStorage.p_abilityStatus = 0; // tracks whether ability is currently active
	// Assign NPC stat defaults from files
	strcpy(statStorage.n_type, getType(readPokemonStats("npc", 0), type));
	statStorage.n_pokemonID = readPokemonStats("npc", 0);
	statStorage.n_level = readPokemonStats("npc", 1);
	statStorage.n_experience = readPokemonStats("npc", 2);
	statStorage.n_hp = readPokemonStats("npc", 3);
	statStorage.n_attack = readPokemonStats("npc", 4);
	statStorage.n_defense = readPokemonStats("npc", 5);
	statStorage.n_spAttack = readPokemonStats("npc", 6);
	statStorage.n_spDefense = readPokemonStats("npc", 7);
	statStorage.n_speed = readPokemonStats("npc", 8);
	statStorage.n_consumableCount = 1; // tracks remaining potions
	statStorage.n_abilityCount = 1; // tracks remianing ability uses
	statStorage.n_abilityStatus = 0; // tracks whether ability is currently active

	return statStorage;
}

float readCombatStats(char who[7], int stat) // used by other functions to pull updated combat stats during combatScenario() runtime 
{
	char statResult[12];
	if (strcmp(who, "player")==0)
	{
		statResult[0] = statStorage.p_pokemonID;
		statResult[1] = statStorage.p_level;
		statResult[2] = statStorage.p_experience;
		statResult[3] = statStorage.p_hp;
		statResult[4] = statStorage.p_attack;
		statResult[5] = statStorage.p_defense;
		statResult[6] = statStorage.p_spAttack;
		statResult[7] = statStorage.p_spDefense;
		statResult[8] = statStorage.p_speed;
		statResult[9] = statStorage.p_consumableCount;
		statResult[10] = statStorage.p_abilityCount;
		statResult[11] = statStorage.p_abilityStatus;
	}
	else if (strcmp(who, "npc")==0)
	{
		statResult[0] = statStorage.n_pokemonID;
		statResult[1] = statStorage.n_level;
		statResult[2] = statStorage.n_experience;
		statResult[3] = statStorage.n_hp;
		statResult[4] = statStorage.n_attack;
		statResult[5] = statStorage.n_defense;
		statResult[6] = statStorage.n_spAttack;
		statResult[7] = statStorage.n_spDefense;
		statResult[8] = statStorage.n_speed;
		statResult[9] = statStorage.n_consumableCount;
		statResult[10] = statStorage.n_abilityCount;
		statResult[11] = statStorage.n_abilityStatus;
	}
	else
	{
		printf("ERROR: readCombatStats() if defaulted; debug"); // only occurs from developer error in implementation code
	}
	return statResult[stat];
}

char *getType(int pokemonID, char type[6]) // converts PokemonID to type string for use in printing and typeToInt()
{
	if ((pokemonID == 1) || (pokemonID == 4))
	{
		strcpy(type, "Grass");
	}
	else if ((pokemonID == 2) || (pokemonID == 5))
	{
		strcpy(type, "Fire");
	}
	else if ((pokemonID == 3) || (pokemonID == 6))
	{
		strcpy(type, "Water");
	}
	else
	{
		printf("ERROR: getType() if defaulted; debug"); // only occurs from developer error in implementation code
	}
	return type;
}

char typeToInt(char type[6]) // converts string from getType() into switch-usable integers
{
	int typeInt;
	if (strcmp(type, "Grass")==0)
	{
		typeInt = 1;
	}
	else if (strcmp(type, "Fire")==0)
	{
		typeInt = 2;
	}
	else if (strcmp(type, "Water")==0)
	{
		typeInt = 3;
	}
	else
	{
		printf("ERROR: typeToInt() if defaulted; debug"); // only occurs from developer error in implementation code
	}
	return typeInt;
}


// --------------------------------------------------------COMBAT RETURN-UTILITY FUNCTIONS BELOW-------------------------------------------------------- //


float createTypeModifier(char who[7]) // determines a half-damage/double-damage modifier based on attacking/defending Pokemon types
{
	float typeModifier[3][3]={{2, 2, .5}, // chart system to determine modifier; rows/column key: 1-Grass, 2-Fire, 3-Water 
							 {.5, 2, 2},
							 {2, .5, 2}};
	if (strcmp(who, "player")==0)
		return typeModifier[(int)statStorage.p_pokemonID-1][(int)statStorage.n_pokemonID-4]; 
	else if (strcmp(who, "npc")==0)
		return typeModifier[(int)statStorage.n_pokemonID-4][(int)statStorage.p_pokemonID-1];
	else
	{
		printf("ERROR: createTypeModifier() if defaulted; debug"); // only occurs from developer error in implementation code
		return 0;
	}
}

char* checkEffectiveness(float typeModifier, char effectiveness[30]) // prints effectiveness string based on createTypeModifier() input
{
	if (typeModifier == .5) // double damage
	{
		strcpy(effectiveness, "super effective!");
	}
	else if (typeModifier == 2) // half damage
	{
		strcpy(effectiveness, "not very effective...");
	}
	else
	{
		printf("ERROR: checkEffectiveness() if defaulted; debug"); // only occurs from developer error in implementation code
	}
	return effectiveness;
}

float createLevelModifier(char who[7]) // calculates a 10%-per-level boost for use in damageCalculation()
{
	float levelModifier;
	if (strcmp(who, "player")==0)
	{
		if (statStorage.p_level == statStorage.n_level)
		{
			levelModifier = 1;
		}
		else if (statStorage.p_level > statStorage.n_level)
		{
			levelModifier = 1 + ((statStorage.p_level - statStorage.n_level) / 10);
		}
		else if (statStorage.p_level < statStorage.n_level)
		{
			levelModifier = ((statStorage.n_level - statStorage.p_level) / 10);
		}
		else
		{
			printf("ERROR: createLevelModifier() if defaulted; debug"); // only occurs from developer error in implementation code
		}
	}
	else if (strcmp(who, "npc")==0)
	{
		if (statStorage.p_level == statStorage.n_level)
		{
			levelModifier = 1;
		}
		else if (statStorage.n_level > statStorage.p_level)
		{
			levelModifier = 1 + ((statStorage.n_level - statStorage.p_level) / 10);
		}
		else if (statStorage.n_level < statStorage.p_level)
		{
			levelModifier = ((statStorage.p_level - statStorage.n_level) / 10);
		}
		else
		{
			printf("ERROR: createLevelModifier() if defaulted; debug"); // only occurs from developer error in implementation code
		}
	}
	return levelModifier;
}

float damageCalculation(int moveType, float power, float level, float attack, float spAttack, float defense, float spDefense, float abilityModifier, float typeModifier, float levelModifier) // calculates damage value based on Pokemon formula
{
	float damage;
	if (moveType == 1)
	{
		damage = (((((((((2.00 * level)/5)+2)) * power * (spAttack / spDefense))/50)+2) * abilityModifier) / typeModifier) * levelModifier; 
	}
	
	else if (moveType == 2)
	{
		damage = (((((((((2.00 * level)/5)+2)) * power * (spAttack / spDefense))/50)+2) * abilityModifier) / typeModifier) * levelModifier;
	}

	else
	{
		printf("ERROR: damageCalculation() if defaulted; debug"); // only occurs from developer error in implementation code
	}
	return damage;
}


// --------------------------------------------------------COMBAT ACTION FUNCTIONS BELOW-------------------------------------------------------- //


char *moveSelect(char who[7], int moveType, char moveSelected[15])
{
	if (moveType == 1)
	{
		if (strcmp(who, "player")==0)
		{
			switch(typeToInt(getType((int)statStorage.p_pokemonID, statStorage.p_type)))
			{
				case 1 : // Grass-type physical moves
				{
					if ((statStorage.p_level >= 1) && (statStorage.p_level < 20)) // Levels 1-20: Tackle
					{	
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 50, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Tackle");
					}
					else if ((statStorage.p_level >= 20) && (statStorage.p_level < 40)) // Levels 21-40: Vine Whip
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 55, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Vine Whip");
					}
					else if ((statStorage.p_level >= 40) && (statStorage.p_level < 60)) // Levels 41-60: Razor Leaf
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 60, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Razor Leaf");
					}
					else if ((statStorage.p_level >= 60) && (statStorage.p_level < 80)) // Levels 61-80: Bullet Seed
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 65, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Bullet Seed");
					}
					else if ((statStorage.p_level >= 80) && (statStorage.p_level <= 100)) // Levels 81-100: Seed Bomb
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 70, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Seed Bomb");
					}
					return moveSelected;
				}
				case 2 : // Fire-type physical moves
				{
					if ((statStorage.p_level >= 1) && (statStorage.p_level < 20)) // Levels 1-20: Scratch
					{	
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 50, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Scratch");
					}
					else if ((statStorage.p_level >= 20) && (statStorage.p_level < 40)) // Levels 21-40: Slash
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 55, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Slash");
					}
					else if ((statStorage.p_level >= 40) && (statStorage.p_level < 60)) // Levels 41-60: Fire Fang
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 60, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Fire Fang");
					}
					else if ((statStorage.p_level >= 60) && (statStorage.p_level < 80)) // Levels 61-80: Flare Blitz
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 65, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Flare Blitz");
					}
					else if ((statStorage.p_level >= 80) && (statStorage.p_level <= 100)) // Levels 81-100: Flamethrower
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 70, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Flamethrower");
					}
					return moveSelected;
				}
				case 3 : // Water-type physical moves
				{
					if ((statStorage.p_level >= 1) && (statStorage.p_level < 20)) // Levels 1-20: Headbutt
					{	
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 50, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Headbutt");
					}
					else if ((statStorage.p_level >= 20) && (statStorage.p_level < 40)) // Levels 21-40: Water Gun
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 55, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Water Gun");
					}
					else if ((statStorage.p_level >= 40) && (statStorage.p_level < 60)) // Levels 41-60: Aqua Tail
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 60, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Aqua Tail");
					}
					else if ((statStorage.p_level >= 60) && (statStorage.p_level < 80)) // Levels 61-80: Water Spout
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 65, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Water Spout");
					}
					else if ((statStorage.p_level >= 80) && (statStorage.p_level <= 100)) // Levels 81-100: Waterfall
					{
						statStorage.n_hp = statStorage.n_hp - damageCalculation(1, 70, statStorage.p_level, statStorage.p_attack, statStorage.p_spAttack, statStorage.p_defense, statStorage.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(moveSelected, "Waterfall");
					}
					return moveSelected;
				}
				default :
				{
					printf("ERROR: moveSelect() switch-1-1 defaulted; debug"); // only occurs from developer error in implementation code
				}
			}
		}
		else if (strcmp(who, "npc")==0)
		{
			switch(typeToInt(getType((int)statStorage.n_pokemonID, statStorage.n_type)))
			{
				case 1 : // Grass-type physical moves
				{
					if ((statStorage.n_level >= 1) && (statStorage.n_level < 20)) // Levels 1-20: Tackle
					{	
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 50, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Tackle");
					}
					else if ((statStorage.n_level >= 20) && (statStorage.n_level < 40)) // Levels 21-40: Vine Whip
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 55, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Vine Whip");
					}
					else if ((statStorage.n_level >= 40) && (statStorage.n_level < 60)) // Levels 41-60: Razor Leaf
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 60, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Razor Leaf");
					}
					else if ((statStorage.n_level >= 60) && (statStorage.n_level < 80)) // Levels 61-80: Bullet Seed
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 65, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Bullet Seed");
					}
					else if ((statStorage.n_level >= 80) && (statStorage.n_level <= 100)) // Levels 81-100: Seed Bomb
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 70, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Seed Bomb");
					}
					return moveSelected;
				}
				case 2 : // Fire-type physical moves
				{
					if ((statStorage.n_level >= 1) && (statStorage.n_level < 20)) // Levels 1-20: Scratch
					{	
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 50, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Scratch");
					}
					else if ((statStorage.n_level >= 20) && (statStorage.n_level < 40)) // Levels 21-40: Slash
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 55, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Slash");
					}
					else if ((statStorage.n_level >= 40) && (statStorage.n_level < 60)) // Levels 41-60: Fire Fang
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 60, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Fire Fang");
					}
					else if ((statStorage.n_level >= 60) && (statStorage.n_level < 80)) // Levels 61-80: Flare Blitz
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 65, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Flare Blitz");
					}
					else if ((statStorage.n_level >= 80) && (statStorage.n_level <= 100)) // Levels 81-100: Flamethrower
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 70, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Flamethrower");
					}
					return moveSelected;
				}
				case 3 : // Water-type physical moves
				{
					if ((statStorage.n_level >= 1) && (statStorage.n_level < 20)) // Levels 1-20: Headbutt
					{	
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 50, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Headbutt");
					}
					else if ((statStorage.n_level >= 20) && (statStorage.n_level < 40)) // Levels 21-40: Water Gun
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 55, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Water Gun");
					}
					else if ((statStorage.n_level >= 40) && (statStorage.n_level < 60)) // Levels 41-60: Aqua Tail
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 60, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Aqua Tail");
					}
					else if ((statStorage.n_level >= 60) && (statStorage.n_level < 80)) // Levels 61-80: Water Spout
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 65, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Water Spout");
					}
					else if ((statStorage.n_level >= 80) && (statStorage.n_level <= 100)) // Levels 81-100: Waterfall
					{
						statStorage.p_hp = statStorage.p_hp - damageCalculation(1, 70, statStorage.n_level, statStorage.n_attack, statStorage.n_spAttack, statStorage.n_defense, statStorage.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(moveSelected, "Waterfall");
					}
					return moveSelected;	
				}
				default :
				{
					printf("ERROR: moveSelect() switch-1-2 defaulted; debug"); // only occurs from developer error in implementation code
				}
			}
		}
		else
		{
			printf("ERROR: moveSelect() if-2-1 defaulted; debug"); // only occurs from developer error in implementation code
		}
	}
	
	else if (moveType == 2)
	{
		if (strcmp(who, "player")==0)
		{
			switch(typeToInt(getType((int)statStorage.p_pokemonID, statStorage.p_type)))
			{
				case 1 : // Grass-type special moves
				{
					if ((statStorage.p_level >= 1) && (statStorage.p_level < 20)) // Levels 1-20: Growth
					{	
						statStorage.p_attack = statStorage.p_attack + (0.45 * 2);
						statStorage.p_spAttack = statStorage.p_spAttack + (0.51 * 2);
						strcpy(moveSelected, "Growth");
					}
					else if ((statStorage.p_level >= 20) && (statStorage.p_level < 40)) // Levels 21-40: Swell
					{
						statStorage.p_attack = statStorage.p_attack + (0.45 * 4);
						statStorage.p_spAttack = statStorage.p_spAttack + (0.51 * 4);
						strcpy(moveSelected, "Swell");
					}
					else if ((statStorage.p_level >= 40) && (statStorage.p_level < 60)) // Levels 41-60: Engorge
					{
						statStorage.p_attack = statStorage.p_attack + (0.45 * 6);
						statStorage.p_spAttack = statStorage.p_spAttack + (0.51 * 6);
						strcpy(moveSelected, "Engorge");
					}
					else if ((statStorage.p_level >= 60) && (statStorage.p_level < 80)) // Levels 61-80: Sprout
					{
						statStorage.p_attack = statStorage.p_attack + (0.45 * 8);
						statStorage.p_spAttack = statStorage.p_spAttack + (0.51 * 8);
						strcpy(moveSelected, "Sprout");
					}
					else if ((statStorage.p_level >= 80) && (statStorage.p_level <= 100)) // Levels 81-100: Bloom
					{
						statStorage.p_attack = statStorage.p_attack + (0.45 * 10);
						statStorage.p_spAttack = statStorage.p_spAttack + (0.51 * 10);
						strcpy(moveSelected, "Bloom");
					}
					return moveSelected;
				}
				case 2 : // Fire-type special moves
				{
					if ((statStorage.p_level >= 1) && (statStorage.p_level < 20)) // Levels 1-20: Growl
					{	
						statStorage.n_attack = statStorage.n_attack - (0.45 * 2);
						statStorage.n_spAttack = statStorage.n_spAttack - (0.51 * 2);
						strcpy(moveSelected, "Growl");
					}
					else if ((statStorage.p_level >= 20) && (statStorage.p_level < 40)) // Levels 21-40: Snarl
					{
						statStorage.n_attack = statStorage.n_attack - (0.45 * 4);
						statStorage.n_spAttack = statStorage.n_spAttack - (0.51 * 4);
						strcpy(moveSelected, "Snarl");
					}
					else if ((statStorage.p_level >= 40) && (statStorage.p_level < 60)) // Levels 41-60: Howl
					{
						statStorage.n_attack = statStorage.n_attack - (0.45 * 6);
						statStorage.n_spAttack = statStorage.n_spAttack - (0.51 * 6);
						strcpy(moveSelected, "Howl");
					}
					else if ((statStorage.p_level >= 60) && (statStorage.p_level < 80)) // Levels 61-80: Roar
					{
						statStorage.n_attack = statStorage.n_attack - (0.45 * 8);
						statStorage.n_spAttack = statStorage.n_spAttack - (0.51 * 8);
						strcpy(moveSelected, "Roar");
					}
					else if ((statStorage.p_level >= 80) && (statStorage.p_level <= 100)) // Levels 81-100: Initimidate
					{
						statStorage.n_attack = statStorage.n_attack - (0.45 * 10);
						statStorage.n_spAttack = statStorage.n_spAttack - (0.51 * 10);
						strcpy(moveSelected, "Initimidate");
					}
					return moveSelected;
				}
				case 3 : // Water-type special moves
				{
					if ((statStorage.p_level >= 1) && (statStorage.p_level < 20)) // Levels 1-20: Tail Wag
					{	
						statStorage.n_defense = statStorage.n_defense - (0.45 * 2);
						statStorage.n_spDefense = statStorage.n_spDefense - (0.52 * 2);
						strcpy(moveSelected, "Tail Wag");
					}
					else if ((statStorage.p_level >= 20) && (statStorage.p_level < 40)) // Levels 21-40: Confusion
					{
						statStorage.n_defense = statStorage.n_defense - (0.45 * 4);
						statStorage.n_spDefense = statStorage.n_spDefense - (0.52 * 4);
						strcpy(moveSelected, "Confusion");
					}
					else if ((statStorage.p_level >= 40) && (statStorage.p_level < 60)) // Levels 41-60: Spit
					{
						statStorage.n_defense = statStorage.n_defense - (0.45 * 6);
						statStorage.n_spDefense = statStorage.n_spDefense - (0.52 * 6);
						strcpy(moveSelected, "Spit");
					}
					else if ((statStorage.p_level >= 60) && (statStorage.p_level < 80)) // Levels 61-80: Cold Front
					{
						statStorage.n_defense = statStorage.n_defense - (0.45 * 8);
						statStorage.n_spDefense = statStorage.n_spDefense - (0.52 * 8);
						strcpy(moveSelected, "Cold Front");
					}
					else if ((statStorage.p_level >= 80) && (statStorage.p_level <= 100)) // Levels 81-100: Rainstorm
					{
						statStorage.n_defense = statStorage.n_defense - (0.45 * 10);
						statStorage.n_spDefense = statStorage.n_spDefense - (0.52 * 10);
						strcpy(moveSelected, "Rainstorm");
					}
					return moveSelected;
				}
				default :
				{
					printf("ERROR: moveSelect() switch-2-1 defaulted; debug"); // only occurs from developer error in implementation code
				}
			}
		}
		else if (strcmp(who, "npc")==0)
		{
			switch(typeToInt(getType((int)statStorage.n_pokemonID, statStorage.n_type)))
			{
				case 1 : // Grass-type special moves
				{
					if ((statStorage.n_level >= 1) && (statStorage.n_level < 20)) // Levels 1-20: Growth
					{	
						statStorage.n_attack = statStorage.n_attack + (0.45 * 2);
						statStorage.n_spAttack = statStorage.n_spAttack + (0.51 * 2);
						strcpy(moveSelected, "Growth");
					}
					else if ((statStorage.n_level >= 20) && (statStorage.n_level < 40)) // Levels 21-40: Swell
					{
						statStorage.n_attack = statStorage.n_attack + (0.45 * 4);
						statStorage.n_spAttack = statStorage.n_spAttack + (0.51 * 4);
						strcpy(moveSelected, "Swell");
					}
					else if ((statStorage.n_level >= 40) && (statStorage.n_level < 60)) // Levels 41-60: Engorge
					{
						statStorage.n_attack = statStorage.n_attack + (0.45 * 6);
						statStorage.n_spAttack = statStorage.n_spAttack + (0.51 * 6);
						strcpy(moveSelected, "Engorge");
					}
					else if ((statStorage.n_level >= 60) && (statStorage.n_level < 80)) // Levels 61-80: Sprout
					{
						statStorage.n_attack = statStorage.n_attack + (0.45 * 8);
						statStorage.n_spAttack = statStorage.n_spAttack + (0.51 * 8);
						strcpy(moveSelected, "Sprout");
					}
					else if ((statStorage.n_level >= 80) && (statStorage.n_level <= 100)) // Levels 81-100: Bloom
					{
						statStorage.n_attack = statStorage.n_attack + (0.45 * 10);
						statStorage.n_spAttack = statStorage.n_spAttack + (0.51 * 10);
						strcpy(moveSelected, "Bloom");
					}
					return moveSelected;
				}
				case 2 : // Fire-type special moves
				{
					if ((statStorage.n_level >= 1) && (statStorage.n_level < 20)) // Levels 1-20: Growl
					{	
						statStorage.p_attack = statStorage.p_attack - (0.45 * 2);
						statStorage.p_spAttack = statStorage.p_spAttack - (0.51 * 2);
						strcpy(moveSelected, "Growl");
					}
					else if ((statStorage.n_level >= 20) && (statStorage.n_level < 40)) // Levels 21-40: Snarl
					{
						statStorage.p_attack = statStorage.p_attack - (0.45 * 4);
						statStorage.p_spAttack = statStorage.p_spAttack - (0.51 * 4);
						strcpy(moveSelected, "Snarl");
					}
					else if ((statStorage.n_level >= 40) && (statStorage.n_level < 60)) // Levels 41-60: Howl
					{
						statStorage.p_attack = statStorage.p_attack - (0.45 * 6);
						statStorage.p_spAttack = statStorage.p_spAttack - (0.51 * 6);
						strcpy(moveSelected, "Howl");
					}
					else if ((statStorage.n_level >= 60) && (statStorage.n_level < 80)) // Levels 61-80: Roar
					{
						statStorage.p_attack = statStorage.p_attack - (0.45 * 8);
						statStorage.p_spAttack = statStorage.p_spAttack - (0.51 * 8);
						strcpy(moveSelected, "Roar");
					}
					else if ((statStorage.n_level >= 80) && (statStorage.n_level <= 100)) // Levels 81-100: Initimidate
					{
						statStorage.p_attack = statStorage.p_attack - (0.45 * 10);
						statStorage.p_spAttack = statStorage.p_spAttack - (0.51 * 10);
						strcpy(moveSelected, "Initimidate");
					}
					return moveSelected;
				}
				case 3 : // Water-type special moves
				{
					if ((statStorage.n_level >= 1) && (statStorage.n_level < 20)) // Levels 1-20: Tail Wag
					{	
						statStorage.p_defense = statStorage.p_defense - (0.45 * 2);
						statStorage.p_spDefense = statStorage.p_spDefense - (0.52 * 2);
						strcpy(moveSelected, "Tail Wag");
					}
					else if ((statStorage.n_level >= 20) && (statStorage.n_level < 40)) // Levels 21-40: Confusion
					{
						statStorage.p_defense = statStorage.p_defense - (0.45 * 4);
						statStorage.p_spDefense = statStorage.p_spDefense - (0.52 * 4);
						strcpy(moveSelected, "Confusion");
					}
					else if ((statStorage.n_level >= 40) && (statStorage.n_level < 60)) // Levels 41-60: Spit
					{
						statStorage.p_defense = statStorage.p_defense - (0.45 * 6);
						statStorage.p_spDefense = statStorage.p_spDefense - (0.52 * 6);
						strcpy(moveSelected, "Spit");
					}
					else if ((statStorage.n_level >= 60) && (statStorage.n_level < 80)) // Levels 61-80: Cold Front
					{
						statStorage.p_defense = statStorage.p_defense - (0.45 * 8);
						statStorage.p_spDefense = statStorage.p_spDefense - (0.52 * 8);
						strcpy(moveSelected, "Cold Front");
					}
					else if ((statStorage.n_level >= 80) && (statStorage.n_level <= 100)) // Levels 81-100: Rainstorm
					{
						statStorage.p_defense = statStorage.p_defense - (0.45 * 10);
						statStorage.p_spDefense = statStorage.p_spDefense - (0.52 * 10);
						strcpy(moveSelected, "Rainstorm");
					}
					return moveSelected;
				}
				default :
				{
					printf("ERROR: moveSelect() switch-2-2 defaulted; debug"); // only occurs from developer error in implementation code
				}
			}
		}
		else
		{
			printf("ERROR: moveSelect() if-2-2 defaulted; debug"); // only occurs from developer error in implementation code
		}
	}
	else
	{
		printf("ERROR: moveSelect() if-1 defaulted; debug"); // only occurs from developer error in implementation code
	}
	return moveSelected;
}

float useAbility(char who[7])
{
	float abilityModifier = 1; // initialize as '1' so damage calculation is unchanged in default state
	if (strcmp(who, "player")==0)
	{
		if (statStorage.p_hp <= ((readPokemonStats("player", 3) / 3)) && (statStorage.n_abilityCount >= 1)) // runs if player HP ~1/3 of max HP
		{
			abilityModifier = 1.5;
			statStorage.p_abilityStatus = 1;
			statStorage.p_abilityCount = 0;
		}
		else
		{
			abilityModifier = 1;
		}
	}
	else if (strcmp(who, "npc")==0)
	{
		if ((statStorage.n_hp <= (readPokemonStats("npc", 3) / 3)) && (statStorage.n_abilityCount >= 1)) // runs if NPC HP ~1/3 of max HP
		{
			abilityModifier = 1.5;
			statStorage.n_abilityStatus = 1;
			statStorage.n_abilityCount = 0;
		}
		else
		{
			abilityModifier = 1;
		}
	}
	else
	{
		printf("ERROR: useAbilityn() if defaulted; debug"); // only occurs from developer error in implementation code
	}
	return abilityModifier;
}

char* useConsumable(char who[7], char potionSelected[15]) 
{
	if (strcmp(who, "player")==0)
	{
		if ((statStorage.p_level >= 1) && (statStorage.p_level < 20) && (statStorage.p_consumableCount > 0)) // Levels 1-20: Potion
		{
			statStorage.p_hp += 20;
			statStorage.p_consumableCount = statStorage.p_consumableCount - 1;
			strcpy(potionSelected, "Potion");
		}
		else if ((statStorage.p_level >= 20) && (statStorage.p_level < 40) && (statStorage.p_consumableCount > 0)) // Levels 21-40: Super Potion
		{
			statStorage.p_hp += 60;
			statStorage.p_consumableCount = statStorage.p_consumableCount - 1;
			strcpy(potionSelected, "Super Potion");
		}
		else if ((statStorage.p_level >= 40) && (statStorage.p_level < 60) && (statStorage.p_consumableCount > 0)) // Levels 41-60: Hyper Potion
		{
			statStorage.p_hp += 100;
			statStorage.p_consumableCount = statStorage.p_consumableCount - 1;
			strcpy(potionSelected, "Hyper Potion");
		}
		else if ((statStorage.p_level >= 60) && (statStorage.p_level < 80) && (statStorage.p_consumableCount > 0)) // Levels 61-80: Max Potion
		{
			statStorage.p_hp += 140;
			statStorage.p_consumableCount = statStorage.p_consumableCount - 1;
			strcpy(potionSelected, "Max Potion");
		}
		else if ((statStorage.p_level >= 80) && (statStorage.p_level <= 100) && (statStorage.p_consumableCount > 0)) // Levels 81-100: Full Restore
		{
			statStorage.p_hp = readPokemonStats("player", 3);
			statStorage.p_consumableCount = statStorage.p_consumableCount - 1;
			strcpy(potionSelected, "Full Restore");
		}
		else
		{
			printf("ERROR: useConsumable() if-1-1 defaulted; debug"); // only occurs from developer error in implementation code
		}
		if (statStorage.p_hp > readPokemonStats("player", 3)) // Prevents healing over maximum default HP
		{
			statStorage.p_hp = readPokemonStats("npc", 3);
		}
	}
	else if (strcmp(who, "npc")==0)
	{
		if ((statStorage.n_level >= 1) && (statStorage.n_level < 20) && (statStorage.n_consumableCount > 0)) // Levels 1-20: Potion
		{
			statStorage.n_hp += 20;
			statStorage.n_consumableCount = statStorage.n_consumableCount - 1;
			strcpy(potionSelected, "Potion");
		}
		else if ((statStorage.n_level >= 20) && (statStorage.n_level < 40) && (statStorage.n_consumableCount > 0)) // Levels 21-40: Super Potion
		{
			statStorage.n_hp += 60;
			statStorage.n_consumableCount = statStorage.n_consumableCount - 1;
			strcpy(potionSelected, "Super Potion");
		}
		else if ((statStorage.n_level >= 40) && (statStorage.n_level < 60) && (statStorage.n_consumableCount > 0)) // Levels 41-60: Hyper Potion
		{
			statStorage.n_hp += 100;
			statStorage.n_consumableCount = statStorage.n_consumableCount - 1;
			strcpy(potionSelected, "Hyper Potion");
		}
		else if ((statStorage.n_level >= 60) && (statStorage.n_level < 80) && (statStorage.n_consumableCount > 0)) // Levels 61-80: Max Potion
		{
			statStorage.n_hp += 140;
			statStorage.n_consumableCount = statStorage.n_consumableCount - 1;
			strcpy(potionSelected, "Max Potion");
		}
		else if ((statStorage.n_level >= 80) && (statStorage.n_level <= 100) && (statStorage.n_consumableCount > 0)) // Levels 81-100: Full Restore
		{
			statStorage.n_hp = readPokemonStats("npc", 3);
			statStorage.n_consumableCount = statStorage.n_consumableCount - 1;
			strcpy(potionSelected, "Full Restore");
		}
		else
		{
			printf("ERROR: useConsumable() if-1-2 defaulted; debug"); // only occurs from developer error in implementation code
		}
	}
	else
	{
		printf("ERROR: useConsumable() if-1 defaulted; debug"); // only occurs from developer error in implementation code
	}
	if (statStorage.n_hp > readPokemonStats("npc", 3)) // Prevents healing over maximum default HP
	{
		statStorage.n_hp = readPokemonStats("npc", 3);
	}
	return potionSelected;
}