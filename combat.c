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
	printf("\nThe tournament has begun!\n");
	if (STATSTORAGE.p_speed >= STATSTORAGE.n_speed)
	{
		do 
		{
			playerTurn();
			if ((STATSTORAGE.p_hp > 0) && (STATSTORAGE.n_hp > 0))
			{
				npcTurn(npcAI());
			}
		}
		while ((STATSTORAGE.p_hp > 0) && (STATSTORAGE.n_hp > 0));
	}
	else
	{
		do 
		{
			npcTurn(npcAI());
			if ((STATSTORAGE.p_hp > 0) && (STATSTORAGE.n_hp > 0))
			{
				playerTurn();
			}
		}
		while ((STATSTORAGE.p_hp > 0) && (STATSTORAGE.n_hp > 0));
	}
	if (STATSTORAGE.p_hp <= 0)
	{
		printf("%s has fainted...\n", PLAYERPOKEMONCHOICE);
		printf("%s is victorious!\n", NPCPOKEMONCHOICE);
	}
	else if (STATSTORAGE.n_hp <= 0)
	{
		printf("%s has fainted...\n", NPCPOKEMONCHOICE);
		printf("%s is victorious!\n", PLAYERPOKEMONCHOICE);
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
			printf("%s uses %s!\n", PLAYERPOKEMONCHOICE, moveSelect("player", 1));
			printf("It's %s\n", checkEffectiveness(createTypeModifier("player")));
			printf("\n%s HP: %.2f\n\n", NPCPOKEMONCHOICE, STATSTORAGE.n_hp);
			break;
		}
		case 2 : // Move Two
		{
			printf("%s uses %s!\n", PLAYERPOKEMONCHOICE, moveSelect("player", 2));
			break;
		}
		case 3 : // Ability
		{
			printf("%s activates Overgrowth!\n", PLAYERPOKEMONCHOICE);
			printf("%s now deals %.0f%% move damage.\n", PLAYERPOKEMONCHOICE, useAbility("player")*100);
			break;
		}
		case 4 : // Consumable
		{
			printf("%s consumed %s!\n", PLAYERPOKEMONCHOICE, useConsumable("player"));
			printf("\n%s HP: %.2f\n\n", PLAYERPOKEMONCHOICE, STATSTORAGE.p_hp);
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
			printf("%s uses %s!\n", NPCPOKEMONCHOICE, moveSelect("npc", 1));
			printf("It's %s\n", checkEffectiveness(createTypeModifier("npc")));
			printf("\n%s HP: %.2f\n\n", PLAYERPOKEMONCHOICE, STATSTORAGE.p_hp);
			break;
		}
		case 2 : // Move Two
		{
			printf("%s uses %s!\n", NPCPOKEMONCHOICE, moveSelect("npc", 2));
			break;
		}
		case 3 : // Ability
		{
			printf("%s activates Overgrowth!\n", NPCPOKEMONCHOICE);
			printf("%s now deals %.0f%% move damage.\n", NPCPOKEMONCHOICE, useAbility("npc")*100);
			break;
		}
		case 4 : // Consumable
		{
			printf("%s consumed %s!\n", NPCPOKEMONCHOICE, useConsumable("npc"));
			printf("\n%s HP: %.2f\n\n", NPCPOKEMONCHOICE, STATSTORAGE.n_hp);
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
			if (STATSTORAGE.p_hp <= ((readPokemonStats("player", 3) / 3)) && (STATSTORAGE.n_abilityCount >= 1))
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
			if (STATSTORAGE.p_consumableCount > 0)
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
	if ((weightedRandomKey <= 75) && (STATSTORAGE.n_hp > ((readPokemonStats("npc", 3) / 3)))) // 75% chance to use Move One while above 1/3 HP
	{
		npcChoice = 1;
	}
	else if ((weightedRandomKey > 75) && (STATSTORAGE.n_hp > ((readPokemonStats("npc", 3) / 3)))) // 25% chance to use Move Two while above 1/3 HP
	{
		npcChoice = 2;
	}
	else if ((weightedRandomKey <= 90) && (STATSTORAGE.n_hp <= ((readPokemonStats("npc", 3) / 3))) && (STATSTORAGE.n_abilityStatus == 0)) // 80% chance to use Ability while below 1/3 HP
	{
		npcChoice = 3;
	}
	else if ((weightedRandomKey <= 60) && (STATSTORAGE.n_hp < ((readPokemonStats("npc", 3) / 2))) && (STATSTORAGE.n_consumableCount > 0)) // 60% chance to use Consumable (if available) while below 1/2 HP 
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

statStruct initializeStats() // populate STATSTORAGE struct with default values from files
{
	// Assign player stat defaults from files
	strcpy(STATSTORAGE.p_type, getType(readPokemonStats("player", 0)));
	STATSTORAGE.p_pokemonID = readPokemonStats("player", 0);
	STATSTORAGE.p_level = readPokemonStats("player", 1);
	STATSTORAGE.p_experience = readPokemonStats("player", 2);
	STATSTORAGE.p_hp = readPokemonStats("player", 3);
	STATSTORAGE.p_attack = readPokemonStats("player", 4);
	STATSTORAGE.p_defense = readPokemonStats("player", 5);
	STATSTORAGE.p_spAttack = readPokemonStats("player", 6);
	STATSTORAGE.p_spDefense = readPokemonStats("player", 7);
	STATSTORAGE.p_speed = readPokemonStats("player", 8);
	STATSTORAGE.p_consumableCount = 1; // tracks remaining potions
	STATSTORAGE.p_abilityCount = 1; // tracks remianing ability uses
	STATSTORAGE.p_abilityStatus = 0; // tracks whether ability is currently active
	// Assign NPC stat defaults from files
	strcpy(STATSTORAGE.n_type, getType(readPokemonStats("npc", 0)));
	STATSTORAGE.n_pokemonID = readPokemonStats("npc", 0);
	STATSTORAGE.n_level = readPokemonStats("npc", 1);
	STATSTORAGE.n_experience = readPokemonStats("npc", 2);
	STATSTORAGE.n_hp = readPokemonStats("npc", 3);
	STATSTORAGE.n_attack = readPokemonStats("npc", 4);
	STATSTORAGE.n_defense = readPokemonStats("npc", 5);
	STATSTORAGE.n_spAttack = readPokemonStats("npc", 6);
	STATSTORAGE.n_spDefense = readPokemonStats("npc", 7);
	STATSTORAGE.n_speed = readPokemonStats("npc", 8);
	STATSTORAGE.n_consumableCount = 1; // tracks remaining potions
	STATSTORAGE.n_abilityCount = 1; // tracks remianing ability uses
	STATSTORAGE.n_abilityStatus = 0; // tracks whether ability is currently active

	return STATSTORAGE;
}

/*float readCombatStats(char who[7], int stat) // used by other functions to pull updated combat stats during combatScenario() runtime 
{
	char statResult[12];
	if (strcmp(who, "player")==0)
	{
		statResult[0] = STATSTORAGE.p_pokemonID;
		statResult[1] = STATSTORAGE.p_level;
		statResult[2] = STATSTORAGE.p_experience;
		statResult[3] = STATSTORAGE.p_hp;
		statResult[4] = STATSTORAGE.p_attack;
		statResult[5] = STATSTORAGE.p_defense;
		statResult[6] = STATSTORAGE.p_spAttack;
		statResult[7] = STATSTORAGE.p_spDefense;
		statResult[8] = STATSTORAGE.p_speed;
		statResult[9] = STATSTORAGE.p_consumableCount;
		statResult[10] = STATSTORAGE.p_abilityCount;
		statResult[11] = STATSTORAGE.p_abilityStatus;
	}
	else if (strcmp(who, "npc")==0)
	{
		statResult[0] = STATSTORAGE.n_pokemonID;
		statResult[1] = STATSTORAGE.n_level;
		statResult[2] = STATSTORAGE.n_experience;
		statResult[3] = STATSTORAGE.n_hp;
		statResult[4] = STATSTORAGE.n_attack;
		statResult[5] = STATSTORAGE.n_defense;
		statResult[6] = STATSTORAGE.n_spAttack;
		statResult[7] = STATSTORAGE.n_spDefense;
		statResult[8] = STATSTORAGE.n_speed;
		statResult[9] = STATSTORAGE.n_consumableCount;
		statResult[10] = STATSTORAGE.n_abilityCount;
		statResult[11] = STATSTORAGE.n_abilityStatus;
	}
	else
	{
		printf("ERROR: readCombatStats() if defaulted; debug"); // only occurs from developer error in implementation code
	}
	return statResult[stat];
}*/

char *getType(int pokemonID) // converts PokemonID to type string for use in printing and typeToInt()
{
	if ((pokemonID == 1) || (pokemonID == 4))
	{
		strcpy(TYPE, "Grass");
	}
	else if ((pokemonID == 2) || (pokemonID == 5))
	{
		strcpy(TYPE, "Fire");
	}
	else if ((pokemonID == 3) || (pokemonID == 6))
	{
		strcpy(TYPE, "Water");
	}
	else
	{
		printf("ERROR: getType() if defaulted; debug"); // only occurs from developer error in implementation code
	}
	return TYPE;
}

char typeToInt() // converts string from getType() into switch-usable integers
{
	int typeInt;
	if (strcmp(TYPE, "Grass")==0)
	{
		typeInt = 1;
	}
	else if (strcmp(TYPE, "Fire")==0)
	{
		typeInt = 2;
	}
	else if (strcmp(TYPE, "Water")==0)
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
		return typeModifier[(int)STATSTORAGE.p_pokemonID-1][(int)STATSTORAGE.n_pokemonID-4]; 
	else if (strcmp(who, "npc")==0)
		return typeModifier[(int)STATSTORAGE.n_pokemonID-4][(int)STATSTORAGE.p_pokemonID-1];
	else
	{
		printf("ERROR: createTypeModifier() if defaulted; debug"); // only occurs from developer error in implementation code
		return 0;
	}
}

char* checkEffectiveness(float typeModifier) // prints EFFECTIVENESS string based on createTypeModifier() input
{
	if (typeModifier == .5) // double damage
	{
		strcpy(EFFECTIVENESS, "super effective!");
	}
	else if (typeModifier == 2) // half damage
	{
		strcpy(EFFECTIVENESS, "not very effective...");
	}
	else
	{
		printf("ERROR: checkEffectiveness() if defaulted; debug"); // only occurs from developer error in implementation code
	}
	return EFFECTIVENESS;
}

float createLevelModifier(char who[7]) // calculates a 10%-per-level boost for use in damageCalculation()
{
	float levelModifier;
	if (strcmp(who, "player")==0)
	{
		if (STATSTORAGE.p_level == STATSTORAGE.n_level)
		{
			levelModifier = 1;
		}
		else if (STATSTORAGE.p_level > STATSTORAGE.n_level)
		{
			levelModifier = 1 + ((STATSTORAGE.p_level - STATSTORAGE.n_level) / 10);
		}
		else if (STATSTORAGE.p_level < STATSTORAGE.n_level)
		{
			levelModifier = ((STATSTORAGE.n_level - STATSTORAGE.p_level) / 10);
		}
		else
		{
			printf("ERROR: createLevelModifier() if defaulted; debug"); // only occurs from developer error in implementation code
		}
	}
	else if (strcmp(who, "npc")==0)
	{
		if (STATSTORAGE.p_level == STATSTORAGE.n_level)
		{
			levelModifier = 1;
		}
		else if (STATSTORAGE.n_level > STATSTORAGE.p_level)
		{
			levelModifier = 1 + ((STATSTORAGE.n_level - STATSTORAGE.p_level) / 10);
		}
		else if (STATSTORAGE.n_level < STATSTORAGE.p_level)
		{
			levelModifier = ((STATSTORAGE.p_level - STATSTORAGE.n_level) / 10);
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


char *moveSelect(char who[7], int moveType)
{
	if (moveType == 1)
	{
		if (strcmp(who, "player")==0)
		{
			switch(typeToInt(getType((int)STATSTORAGE.p_pokemonID)))
			{
				case 1 : // Grass-type physical moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Tackle
					{	
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 50, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Tackle");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Vine Whip
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 55, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Vine Whip");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Razor Leaf
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 60, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Razor Leaf");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Bullet Seed
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 65, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Bullet Seed");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Seed Bomb
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 70, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Seed Bomb");
					}
					return MOVESELECTED;
				}
				case 2 : // Fire-type physical moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Scratch
					{	
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 50, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Scratch");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Slash
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 55, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Slash");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Fire Fang
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 60, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Fire Fang");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Flare Blitz
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 65, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Flare Blitz");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Flamethrower
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 70, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Flamethrower");
					}
					return MOVESELECTED;
				}
				case 3 : // Water-type physical moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Headbutt
					{	
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 50, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Headbutt");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Water Gun
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 55, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Water Gun");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Aqua Tail
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 60, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Aqua Tail");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Water Spout
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 65, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Water Spout");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Waterfall
					{
						STATSTORAGE.n_hp = STATSTORAGE.n_hp - damageCalculation(1, 70, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						strcpy(MOVESELECTED, "Waterfall");
					}
					return MOVESELECTED;
				}
				default :
				{
					printf("ERROR: moveSelect() switch-1-1 defaulted; debug"); // only occurs from developer error in implementation code
				}
			}
		}
		else if (strcmp(who, "npc")==0)
		{
			switch(typeToInt(getType((int)STATSTORAGE.n_pokemonID)))
			{
				case 1 : // Grass-type physical moves
				{
					if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20)) // Levels 1-20: Tackle
					{	
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 50, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Tackle");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Vine Whip
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 55, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Vine Whip");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Razor Leaf
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 60, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Razor Leaf");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Bullet Seed
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 65, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Bullet Seed");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Seed Bomb
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 70, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Seed Bomb");
					}
					return MOVESELECTED;
				}
				case 2 : // Fire-type physical moves
				{
					if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20)) // Levels 1-20: Scratch
					{	
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 50, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Scratch");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Slash
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 55, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Slash");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Fire Fang
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 60, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Fire Fang");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Flare Blitz
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 65, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Flare Blitz");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Flamethrower
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 70, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Flamethrower");
					}
					return MOVESELECTED;
				}
				case 3 : // Water-type physical moves
				{
					if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20)) // Levels 1-20: Headbutt
					{	
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 50, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Headbutt");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Water Gun
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 55, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Water Gun");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Aqua Tail
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 60, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Aqua Tail");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Water Spout
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 65, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Water Spout");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Waterfall
					{
						STATSTORAGE.p_hp = STATSTORAGE.p_hp - damageCalculation(1, 70, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						strcpy(MOVESELECTED, "Waterfall");
					}
					return MOVESELECTED;	
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
			switch(typeToInt(getType((int)STATSTORAGE.p_pokemonID)))
			{
				case 1 : // Grass-type special moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Growth
					{	
						STATSTORAGE.p_attack = STATSTORAGE.p_attack + (0.45 * 2);
						STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack + (0.51 * 2);
						strcpy(MOVESELECTED, "Growth");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Swell
					{
						STATSTORAGE.p_attack = STATSTORAGE.p_attack + (0.45 * 4);
						STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack + (0.51 * 4);
						strcpy(MOVESELECTED, "Swell");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Engorge
					{
						STATSTORAGE.p_attack = STATSTORAGE.p_attack + (0.45 * 6);
						STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack + (0.51 * 6);
						strcpy(MOVESELECTED, "Engorge");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Sprout
					{
						STATSTORAGE.p_attack = STATSTORAGE.p_attack + (0.45 * 8);
						STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack + (0.51 * 8);
						strcpy(MOVESELECTED, "Sprout");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Bloom
					{
						STATSTORAGE.p_attack = STATSTORAGE.p_attack + (0.45 * 10);
						STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack + (0.51 * 10);
						strcpy(MOVESELECTED, "Bloom");
					}
					return MOVESELECTED;
				}
				case 2 : // Fire-type special moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Growl
					{	
						STATSTORAGE.n_attack = STATSTORAGE.n_attack - (0.45 * 2);
						STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack - (0.51 * 2);
						strcpy(MOVESELECTED, "Growl");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Snarl
					{
						STATSTORAGE.n_attack = STATSTORAGE.n_attack - (0.45 * 4);
						STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack - (0.51 * 4);
						strcpy(MOVESELECTED, "Snarl");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Howl
					{
						STATSTORAGE.n_attack = STATSTORAGE.n_attack - (0.45 * 6);
						STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack - (0.51 * 6);
						strcpy(MOVESELECTED, "Howl");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Roar
					{
						STATSTORAGE.n_attack = STATSTORAGE.n_attack - (0.45 * 8);
						STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack - (0.51 * 8);
						strcpy(MOVESELECTED, "Roar");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Initimidate
					{
						STATSTORAGE.n_attack = STATSTORAGE.n_attack - (0.45 * 10);
						STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack - (0.51 * 10);
						strcpy(MOVESELECTED, "Initimidate");
					}
					return MOVESELECTED;
				}
				case 3 : // Water-type special moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Tail Wag
					{	
						STATSTORAGE.n_defense = STATSTORAGE.n_defense - (0.45 * 2);
						STATSTORAGE.n_spDefense = STATSTORAGE.n_spDefense - (0.52 * 2);
						strcpy(MOVESELECTED, "Tail Wag");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Confusion
					{
						STATSTORAGE.n_defense = STATSTORAGE.n_defense - (0.45 * 4);
						STATSTORAGE.n_spDefense = STATSTORAGE.n_spDefense - (0.52 * 4);
						strcpy(MOVESELECTED, "Confusion");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Spit
					{
						STATSTORAGE.n_defense = STATSTORAGE.n_defense - (0.45 * 6);
						STATSTORAGE.n_spDefense = STATSTORAGE.n_spDefense - (0.52 * 6);
						strcpy(MOVESELECTED, "Spit");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Cold Front
					{
						STATSTORAGE.n_defense = STATSTORAGE.n_defense - (0.45 * 8);
						STATSTORAGE.n_spDefense = STATSTORAGE.n_spDefense - (0.52 * 8);
						strcpy(MOVESELECTED, "Cold Front");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Rainstorm
					{
						STATSTORAGE.n_defense = STATSTORAGE.n_defense - (0.45 * 10);
						STATSTORAGE.n_spDefense = STATSTORAGE.n_spDefense - (0.52 * 10);
						strcpy(MOVESELECTED, "Rainstorm");
					}
					return MOVESELECTED;
				}
				default :
				{
					printf("ERROR: moveSelect() switch-2-1 defaulted; debug"); // only occurs from developer error in implementation code
				}
			}
		}
		else if (strcmp(who, "npc")==0)
		{
			switch(typeToInt(getType((int)STATSTORAGE.n_pokemonID)))
			{
				case 1 : // Grass-type special moves
				{
					if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20)) // Levels 1-20: Growth
					{	
						STATSTORAGE.n_attack = STATSTORAGE.n_attack + (0.45 * 2);
						STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack + (0.51 * 2);
						strcpy(MOVESELECTED, "Growth");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Swell
					{
						STATSTORAGE.n_attack = STATSTORAGE.n_attack + (0.45 * 4);
						STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack + (0.51 * 4);
						strcpy(MOVESELECTED, "Swell");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Engorge
					{
						STATSTORAGE.n_attack = STATSTORAGE.n_attack + (0.45 * 6);
						STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack + (0.51 * 6);
						strcpy(MOVESELECTED, "Engorge");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Sprout
					{
						STATSTORAGE.n_attack = STATSTORAGE.n_attack + (0.45 * 8);
						STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack + (0.51 * 8);
						strcpy(MOVESELECTED, "Sprout");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Bloom
					{
						STATSTORAGE.n_attack = STATSTORAGE.n_attack + (0.45 * 10);
						STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack + (0.51 * 10);
						strcpy(MOVESELECTED, "Bloom");
					}
					return MOVESELECTED;
				}
				case 2 : // Fire-type special moves
				{
					if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20)) // Levels 1-20: Growl
					{	
						STATSTORAGE.p_attack = STATSTORAGE.p_attack - (0.45 * 2);
						STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack - (0.51 * 2);
						strcpy(MOVESELECTED, "Growl");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Snarl
					{
						STATSTORAGE.p_attack = STATSTORAGE.p_attack - (0.45 * 4);
						STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack - (0.51 * 4);
						strcpy(MOVESELECTED, "Snarl");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Howl
					{
						STATSTORAGE.p_attack = STATSTORAGE.p_attack - (0.45 * 6);
						STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack - (0.51 * 6);
						strcpy(MOVESELECTED, "Howl");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Roar
					{
						STATSTORAGE.p_attack = STATSTORAGE.p_attack - (0.45 * 8);
						STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack - (0.51 * 8);
						strcpy(MOVESELECTED, "Roar");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Initimidate
					{
						STATSTORAGE.p_attack = STATSTORAGE.p_attack - (0.45 * 10);
						STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack - (0.51 * 10);
						strcpy(MOVESELECTED, "Initimidate");
					}
					return MOVESELECTED;
				}
				case 3 : // Water-type special moves
				{
					if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20)) // Levels 1-20: Tail Wag
					{	
						STATSTORAGE.p_defense = STATSTORAGE.p_defense - (0.45 * 2);
						STATSTORAGE.p_spDefense = STATSTORAGE.p_spDefense - (0.52 * 2);
						strcpy(MOVESELECTED, "Tail Wag");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Confusion
					{
						STATSTORAGE.p_defense = STATSTORAGE.p_defense - (0.45 * 4);
						STATSTORAGE.p_spDefense = STATSTORAGE.p_spDefense - (0.52 * 4);
						strcpy(MOVESELECTED, "Confusion");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Spit
					{
						STATSTORAGE.p_defense = STATSTORAGE.p_defense - (0.45 * 6);
						STATSTORAGE.p_spDefense = STATSTORAGE.p_spDefense - (0.52 * 6);
						strcpy(MOVESELECTED, "Spit");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Cold Front
					{
						STATSTORAGE.p_defense = STATSTORAGE.p_defense - (0.45 * 8);
						STATSTORAGE.p_spDefense = STATSTORAGE.p_spDefense - (0.52 * 8);
						strcpy(MOVESELECTED, "Cold Front");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Rainstorm
					{
						STATSTORAGE.p_defense = STATSTORAGE.p_defense - (0.45 * 10);
						STATSTORAGE.p_spDefense = STATSTORAGE.p_spDefense - (0.52 * 10);
						strcpy(MOVESELECTED, "Rainstorm");
					}
					return MOVESELECTED;
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
	return MOVESELECTED;
}

float useAbility(char who[7])
{
	float abilityModifier = 1; // initialize as '1' so damage calculation is unchanged in default state
	if (strcmp(who, "player")==0)
	{
		if (STATSTORAGE.p_hp <= ((readPokemonStats("player", 3) / 3)) && (STATSTORAGE.n_abilityCount >= 1)) // runs if player HP ~1/3 of max HP
		{
			abilityModifier = 1.5;
			STATSTORAGE.p_abilityStatus = 1;
			STATSTORAGE.p_abilityCount = 0;
		}
		else
		{
			abilityModifier = 1;
		}
	}
	else if (strcmp(who, "npc")==0)
	{
		if ((STATSTORAGE.n_hp <= (readPokemonStats("npc", 3) / 3)) && (STATSTORAGE.n_abilityCount >= 1)) // runs if NPC HP ~1/3 of max HP
		{
			abilityModifier = 1.5;
			STATSTORAGE.n_abilityStatus = 1;
			STATSTORAGE.n_abilityCount = 0;
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

char* useConsumable(char who[7]) 
{
	if (strcmp(who, "player")==0)
	{
		if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20) && (STATSTORAGE.p_consumableCount > 0)) // Levels 1-20: Potion
		{
			STATSTORAGE.p_hp += 20;
			STATSTORAGE.p_consumableCount = STATSTORAGE.p_consumableCount - 1;
			strcpy(POTIONSELECTED, "Potion");
		}
		else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40) && (STATSTORAGE.p_consumableCount > 0)) // Levels 21-40: Super Potion
		{
			STATSTORAGE.p_hp += 60;
			STATSTORAGE.p_consumableCount = STATSTORAGE.p_consumableCount - 1;
			strcpy(POTIONSELECTED, "Super Potion");
		}
		else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60) && (STATSTORAGE.p_consumableCount > 0)) // Levels 41-60: Hyper Potion
		{
			STATSTORAGE.p_hp += 100;
			STATSTORAGE.p_consumableCount = STATSTORAGE.p_consumableCount - 1;
			strcpy(POTIONSELECTED, "Hyper Potion");
		}
		else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80) && (STATSTORAGE.p_consumableCount > 0)) // Levels 61-80: Max Potion
		{
			STATSTORAGE.p_hp += 140;
			STATSTORAGE.p_consumableCount = STATSTORAGE.p_consumableCount - 1;
			strcpy(POTIONSELECTED, "Max Potion");
		}
		else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100) && (STATSTORAGE.p_consumableCount > 0)) // Levels 81-100: Full Restore
		{
			STATSTORAGE.p_hp = readPokemonStats("player", 3);
			STATSTORAGE.p_consumableCount = STATSTORAGE.p_consumableCount - 1;
			strcpy(POTIONSELECTED, "Full Restore");
		}
		else
		{
			printf("ERROR: useConsumable() if-1-1 defaulted; debug"); // only occurs from developer error in implementation code
		}
		if (STATSTORAGE.p_hp > readPokemonStats("player", 3)) // Prevents healing over maximum default HP
		{
			STATSTORAGE.p_hp = readPokemonStats("npc", 3);
		}
	}
	else if (strcmp(who, "npc")==0)
	{
		if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20) && (STATSTORAGE.n_consumableCount > 0)) // Levels 1-20: Potion
		{
			STATSTORAGE.n_hp += 20;
			STATSTORAGE.n_consumableCount = STATSTORAGE.n_consumableCount - 1;
			strcpy(POTIONSELECTED, "Potion");
		}
		else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40) && (STATSTORAGE.n_consumableCount > 0)) // Levels 21-40: Super Potion
		{
			STATSTORAGE.n_hp += 60;
			STATSTORAGE.n_consumableCount = STATSTORAGE.n_consumableCount - 1;
			strcpy(POTIONSELECTED, "Super Potion");
		}
		else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60) && (STATSTORAGE.n_consumableCount > 0)) // Levels 41-60: Hyper Potion
		{
			STATSTORAGE.n_hp += 100;
			STATSTORAGE.n_consumableCount = STATSTORAGE.n_consumableCount - 1;
			strcpy(POTIONSELECTED, "Hyper Potion");
		}
		else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80) && (STATSTORAGE.n_consumableCount > 0)) // Levels 61-80: Max Potion
		{
			STATSTORAGE.n_hp += 140;
			STATSTORAGE.n_consumableCount = STATSTORAGE.n_consumableCount - 1;
			strcpy(POTIONSELECTED, "Max Potion");
		}
		else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100) && (STATSTORAGE.n_consumableCount > 0)) // Levels 81-100: Full Restore
		{
			STATSTORAGE.n_hp = readPokemonStats("npc", 3);
			STATSTORAGE.n_consumableCount = STATSTORAGE.n_consumableCount - 1;
			strcpy(POTIONSELECTED, "Full Restore");
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
	if (STATSTORAGE.n_hp > readPokemonStats("npc", 3)) // Prevents healing over maximum default HP
	{
		STATSTORAGE.n_hp = readPokemonStats("npc", 3);
	}
	return POTIONSELECTED;
}