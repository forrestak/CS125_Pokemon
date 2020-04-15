/*	CS125 Group Project
	File: combat.c
	Description: Handles combat actions and related stat updating
	Authors: Colton Van Orsdel
	References: https://www.cplusplus.com/reference/cstdlib/atof/
				https://www.poftut.com/what-is-sleep-function-and-how-to-use-it-in-c-program/
				https://en.cppreference.com/w/c/string/byte/strtol
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
#include "battleUI.h"

void combatScenario() // combines primary combat functions to simulate combat until there is a victor
{
	printf("\n\nThe tournament has begun!\n");
	displayScreen();
	if (STATSTORAGE.p_speed >= STATSTORAGE.n_speed) // checks which Pokemon goes first based off their speed stat
	{
		do
		{
			playerTurn();
			displayScreen(); // updates screen with new HP values and clears combat text readout
			if ((STATSTORAGE.p_hp > 0) && (STATSTORAGE.n_hp > 0)) // checks if either Pokemon has fainted before prompting another turn
			{
				npcTurn(npcAI());
				displayScreen(); // updates screen with new HP values and clears combat text readout
			}
		}
		while ((STATSTORAGE.p_hp > 0) && (STATSTORAGE.n_hp > 0)); // checks if either Pokemon has fainted before prompting another turn
	}
	else
	{
		do
		{
			npcTurn(npcAI());
			displayScreen(); // updates screen with new HP values and clears combat text readout
			if ((STATSTORAGE.p_hp > 0) && (STATSTORAGE.n_hp > 0)) // checks if either Pokemon has fainted before prompting another turn
			{
				playerTurn();
				displayScreen(); // updates screen with new HP values and clears combat text readout
			}
		}
		while ((STATSTORAGE.p_hp > 0) && (STATSTORAGE.n_hp > 0)); // checks if either Pokemon has fainted before prompting another turn
	}
}


// --------------------------------------------------------DIRECT combatScenario() SUPPORT FUNCTIONS BELOW-------------------------------------------------------- //


void playerTurn() // handles choice implementation for each of the player's four actions
{	char playerChoiceString[20];
	char* playerChoiceStringEndPtr;
	long playerChoice;
	// printf("1-Physical    |      2-Special\n3-Ability     |   4-Consumable\n"); // made obsolete by including prompts in battleUI(); uncomment to implement standalone combatScenario()
	printf("ACTION: ");
	fgets(playerChoiceString, 20, stdin);
	playerChoice = strtol(playerChoiceString, &playerChoiceStringEndPtr, 10); // error-handling for non-string input
	switch(playerTurnCheck(playerChoice))
	{
		case 1 : // Move One
		{
            battleUI(2); // "flash" animation on NPC Pokemon ASCII-art
			moveSelect("player", 1, 2);
			printf("It's %s\n", checkEffectiveness(createTypeModifier("player")));
			break;
		}
		case 2 : // Move Two
		{
			battleUI(1); // "flash" animation on player Pokemon ASCII-art
			moveSelect("player", 2, 2);
			break;
		}
		case 3 : // Ability
		{
			battleUI(1); // "flash" animation on player Pokemon ASCII-art
			printf("%s activates Overgrowth!\n", PLAYERPOKEMONCHOICE);
			printf("%s now deals %.0f%% move damage.\n", PLAYERPOKEMONCHOICE, useAbility("player")*100);
			break;
		}
		case 4 : // Consumable
		{
			battleUI(1); // "flash" animation on player Pokemon ASCII-art
			useConsumable("player", 2);
			break;
		}
		default :
		{
			printf("ERROR: playerTurn() switch defaulted; debug"); // only occurs from developer error in implementation code
			break;
		}
	}
	checkVictory();
	sleep(2);
}

void npcTurn(int npcChoice) // handles choice implementation for each of the NPC's four actions
{
	printf("Waiting for opponent...\n\n");
	sleep(1);
	switch(npcChoice)
	{
		case 1 : // Move One
		{
            battleUI(1); // "flash" animation on player Pokemon ASCII-art
			moveSelect("npc", 1, 2);
			printf("It's %s\n", checkEffectiveness(createTypeModifier("npc")));
			break;
		}
		case 2 : // Move Two
		{
			battleUI(2); // "flash" animation on NPC Pokemon ASCII-art
			moveSelect("npc", 2, 2);
			break;
		}
		case 3 : // Ability
		{
			battleUI(2); // "flash" animation on NPC Pokemon ASCII-art
			printf("%s activates Overgrowth!\n", NPCPOKEMONCHOICE);
			printf("%s now deals %.0f%% move damage.\n", NPCPOKEMONCHOICE, useAbility("npc")*100);
			break;
		}
		case 4 : // Consumable
		{
			battleUI(2); // "flash" animation on NPC Pokemon ASCII-art
			useConsumable("npc", 2);
			break;
		}
		default :
		{
			printf("ERROR: npcTurn() switch defaulted; debug"); // only occurs from developer error in implementation code
			break;
		}
	}
	checkVictory();
	sleep(2);
}


// --------------------------------------------------------DIRECT *turn() SUPPORT FUNCTIONS BELOW-------------------------------------------------------- //


int playerTurnCheck(int playerChoice) // checks whether player chose a valid move before attempting to execute it
{
	switch(playerChoice)
	{
		case 1 : // Move One
			return 1;
		case 2 : // Move Two
			return 2;
		case 3 : // Ability
		{
			if (STATSTORAGE.p_hp <= ((readPokemonStats("player", 3) / 3)) && (STATSTORAGE.n_abilityCount >= 1)) // checks if Pokemon is below 33% HP and that they haven't used the ability already
				return 3;
			else
			{
				printf("You must be below 33%% HP to use Overgrowth.\n");
				playerTurn();
				break;
			}
		}
		case 4: // Consumable
		{
			if (STATSTORAGE.p_consumableCount > 0) // checks if Pokemon still has consumables to use
				return 4;
			else
			{
				printf("You do not have any consumables to use.\n");
				playerTurn();
				break;
			}
		}
		default :
		{
			{
				printf("Invalid entry - Choose an action 1-4:\n");
				playerTurn();
			}
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
		npcChoice = 1; // Move One
	else if ((weightedRandomKey > 75) && (STATSTORAGE.n_hp > ((readPokemonStats("npc", 3) / 3)))) // 25% chance to use Move Two while above 1/3 HP
		npcChoice = 2; // Move Two
	else if ((weightedRandomKey <= 90) && (STATSTORAGE.n_hp <= ((readPokemonStats("npc", 3) / 3))) && (STATSTORAGE.n_abilityStatus == 0)) // 90% chance to use Ability while below 1/3 HP
		npcChoice = 3; // Ability
	else if ((weightedRandomKey <= 75) && (STATSTORAGE.n_hp < ((readPokemonStats("npc", 3) / 2))) && (STATSTORAGE.n_consumableCount > 0)) // 75% chance to use Consumable (if available) while below 1/2 HP
		npcChoice = 4; // Consumable
	else
	{
		if (weightedRandomKey <= 75) // 75% chance to use Move One when other cases are not met 
			npcChoice = 1; // Move One
		else // 25% chance to use Move Two when other cases are not met 
			npcChoice = 2; // Move Two
	}

	return npcChoice;
}

void checkVictory() // compares Pokemon HP to check for a victor and set the condition for endSim()
{
	if (STATSTORAGE.p_hp <= 0)
	{
		STATSTORAGE.p_hp = 0;
		printf("\n%s has fainted...\n", PLAYERPOKEMONCHOICE);
		printf("%s is victorious!\n", NPCPOKEMONCHOICE);
		WINORLOSE = 0; // set NPC win case for use in endSim()
		sleep(2);
	}
	else if (STATSTORAGE.n_hp <= 0)
	{
		STATSTORAGE.n_hp = 0;
		printf("\n%s has fainted...\n", NPCPOKEMONCHOICE);
		printf("%s is victorious!\n", PLAYERPOKEMONCHOICE);
		WINORLOSE = 1; // set player win case for use in endSim()
		sleep(2);
	}
}


// --------------------------------------------------------STAT-RELATED UTILITY FUNCTIONS BELOW-------------------------------------------------------- //

statStruct initializeStats() // populate STATSTORAGE struct with default values from files
{
	// Assign player stat defaults from files
	STATSTORAGE.p_pokemonID = readPokemonStats("player", 0);
	STATSTORAGE.p_level = readPokemonStats("player", 1);
	STATSTORAGE.p_experience = readPokemonStats("player", 2);
	STATSTORAGE.p_hp = readPokemonStats("player", 3);
	STATSTORAGE.p_attack = readPokemonStats("player", 4);
	STATSTORAGE.p_defense = readPokemonStats("player", 5);
	STATSTORAGE.p_spAttack = readPokemonStats("player", 6);
	STATSTORAGE.p_spDefense = readPokemonStats("player", 7);
	STATSTORAGE.p_speed = readPokemonStats("player", 8);
	STATSTORAGE.p_consumableCount = 1; // tracks remaining potions from useConsumable()
	STATSTORAGE.p_abilityCount = 1; // tracks remaining ability uses from useAbility()
	STATSTORAGE.p_abilityStatus = 0; // tracks whether ability is currently active from useAbility()
	STATSTORAGE.p_damageDealt = 0; // tracks damage dealt by most recent damageCalculation() call
	STATSTORAGE.p_buffReceived = 0; // tracks buff received by most recent moveSelect() call
	STATSTORAGE.p_consumableRestore = 0; // tracks HP restored by most recent useConsumable() call
	strcpy(STATSTORAGE.p_type, getType(readPokemonStats("player", 0)));
	strcpy(STATSTORAGE.p_moveOne, moveSelect("player", 1, 1));
	strcpy(STATSTORAGE.p_moveTwo, moveSelect("player", 2, 1));
	strcpy(STATSTORAGE.p_ability, "Overgrowth");
	strcpy(STATSTORAGE.p_consumable, useConsumable("player", 1));

	// Assign NPC stat defaults from files
	STATSTORAGE.n_pokemonID = readPokemonStats("npc", 0);
	STATSTORAGE.n_level = readPokemonStats("npc", 1);
	STATSTORAGE.n_experience = readPokemonStats("npc", 2);
	STATSTORAGE.n_hp = readPokemonStats("npc", 3);
	STATSTORAGE.n_attack = readPokemonStats("npc", 4);
	STATSTORAGE.n_defense = readPokemonStats("npc", 5);
	STATSTORAGE.n_spAttack = readPokemonStats("npc", 6);
	STATSTORAGE.n_spDefense = readPokemonStats("npc", 7);
	STATSTORAGE.n_speed = readPokemonStats("npc", 8);
	STATSTORAGE.n_consumableCount = 1; // tracks remaining potions from useConsumable()
	STATSTORAGE.n_abilityCount = 1; // tracks remaining ability uses from useAbility()
	STATSTORAGE.n_abilityStatus = 0; // tracks whether ability is currently active from useAbility()
	STATSTORAGE.n_damageDealt = 0; // tracks damage dealt by most recent damageCalculation() call
	STATSTORAGE.n_buffReceived = 0; // tracks buff received by most recent moveSelect() call
	STATSTORAGE.n_consumableRestore = 0; // tracks HP restored by most recent useConsumable() call
	strcpy(STATSTORAGE.n_type, getType(readPokemonStats("npc", 0)));
	strcpy(STATSTORAGE.n_moveOne, moveSelect("npc", 1, 1));
	strcpy(STATSTORAGE.n_moveTwo, moveSelect("npc", 2, 1));
	strcpy(STATSTORAGE.n_ability, "Overgrowth");
	strcpy(STATSTORAGE.n_consumable, useConsumable("npc", 1));

	return STATSTORAGE;
}

char *getType(int pokemonID) // converts PokemonID to type string for use in printing and typeToInt()
{
	if ((pokemonID == 1) || (pokemonID == 4))
		strcpy(TYPE, "Grass");
	else if ((pokemonID == 2) || (pokemonID == 5))
		strcpy(TYPE, "Fire");
	else if ((pokemonID == 3) || (pokemonID == 6))
		strcpy(TYPE, "Water");
	else
		printf("ERROR: getType() if defaulted; debug"); // only occurs from developer error in implementation code

	return TYPE;
}

char typeToInt() // converts string from getType() into switch-usable integers
{
	int typeInt;
	if (strcmp(TYPE, "Grass")==0)
		typeInt = 1;
	else if (strcmp(TYPE, "Fire")==0)
		typeInt = 2;
	else if (strcmp(TYPE, "Water")==0)
		typeInt = 3;
	else
		printf("ERROR: typeToInt() if defaulted; debug"); // only occurs from developer error in implementation code

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
		strcpy(EFFECTIVENESS, "super effective!");
	else if (typeModifier == 2) // half damage
		strcpy(EFFECTIVENESS, "not very effective...");
	else
		printf("ERROR: checkEffectiveness() if defaulted; debug"); // only occurs from developer error in implementation code

	return EFFECTIVENESS;
}

float createLevelModifier(char who[7]) // calculates a 10%-per-level boost for use in damageCalculation()
{
	float levelModifier;

	if (strcmp(who, "player")==0)
	{
		if (STATSTORAGE.p_level == STATSTORAGE.n_level)
			levelModifier = 1;
		else if (STATSTORAGE.p_level > STATSTORAGE.n_level)
			levelModifier = 1 + ((STATSTORAGE.p_level - STATSTORAGE.n_level) / 10); 
		else if (STATSTORAGE.p_level < STATSTORAGE.n_level)
			levelModifier = ((STATSTORAGE.n_level - STATSTORAGE.p_level) / 10);
		else
			printf("ERROR: createLevelModifier() if defaulted; debug"); // only occurs from developer error in implementation code
	}
	else if (strcmp(who, "npc")==0)
	{
		if (STATSTORAGE.p_level == STATSTORAGE.n_level)
			levelModifier = 1;
		else if (STATSTORAGE.n_level > STATSTORAGE.p_level)
			levelModifier = 1 + ((STATSTORAGE.n_level - STATSTORAGE.p_level) / 10);
		else if (STATSTORAGE.n_level < STATSTORAGE.p_level)
			levelModifier = ((STATSTORAGE.p_level - STATSTORAGE.n_level) / 10);
		else
			printf("ERROR: createLevelModifier() if defaulted; debug"); // only occurs from developer error in implementation code
	}

	return levelModifier;
}

float damageCalculation(int moveType, float power, float level, float attack, float spAttack, float defense, float spDefense, float abilityModifier, float typeModifier, float levelModifier) // calculates damage value based on Pokemon formula
{
	float damage;

	if (moveType == 1)
		damage = (((((((((2.00 * level)/5)+2)) * power * (attack / defense))/50)+2) * abilityModifier) / typeModifier) * levelModifier;
	// originally intended another else-if here for moveTwo to deal damage, using spAttack and spDefense stats - but never implemented functionality
	else
		printf("ERROR: damageCalculation() if defaulted; debug"); // only occurs from developer error in implementation code

	return damage;
}


// --------------------------------------------------------COMBAT ACTION FUNCTIONS BELOW-------------------------------------------------------- //


char *moveSelect(char who[7], int moveType, int useOrCheck) // performs Pokemon moves using damageCalculation() and STATSTORAGE altering; also used to check for the name of the move to populate battleUI()
{
	if (moveType == 1) // physical moves that alter Pokemon STATSTORAGE HP
	{
		if (strcmp(who, "player")==0)
		{
			switch(typeToInt(getType((int)STATSTORAGE.p_pokemonID)))
			{
				case 1 : // Grass-type physical moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Tackle
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 50, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1) 
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Tackle");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Vine Whip
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 52, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1) 
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Vine Whip");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Razor Leaf
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 54, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Razor Leaf");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Bullet Seed
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 56, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Bullet Seed");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Seed Bomb
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 58, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Seed Bomb");
					}

					if (useOrCheck == 2)
						printf("%s uses %s, dealing %.2f damage!\n", PLAYERPOKEMONCHOICE, STATSTORAGE.p_moveOne, STATSTORAGE.p_damageDealt);

					return STATSTORAGE.p_moveOne;
				}
				case 2 : // Fire-type physical moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Scratch
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 50, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Scratch");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Slash
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 52, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Slash");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Fire Fang
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 54, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Fire Fang");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Flare Blitz
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 56, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Flare Blitz");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Flamethrower
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 58, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Flamethrower");
					}

					if (useOrCheck == 2)
						printf("%s uses %s, dealing %.2f damage!\n", PLAYERPOKEMONCHOICE, STATSTORAGE.p_moveOne, STATSTORAGE.p_damageDealt);

					return STATSTORAGE.p_moveOne;
				}
				case 3 : // Water-type physical moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Headbutt
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 50, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Headbutt");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Water Gun
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 52, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Water Gun");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Aqua Tail
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 54, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Aqua Tail");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Water Spout
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 56, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Water Spout");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Waterfall
					{
						STATSTORAGE.p_damageDealt = damageCalculation(1, 58, STATSTORAGE.p_level, STATSTORAGE.p_attack, STATSTORAGE.p_spAttack, STATSTORAGE.p_defense, STATSTORAGE.p_spDefense, useAbility("player"), createTypeModifier("player"), createLevelModifier("player"));
						if (useOrCheck != 1)
							STATSTORAGE.n_hp = STATSTORAGE.n_hp - STATSTORAGE.p_damageDealt;
						strcpy(STATSTORAGE.p_moveOne, "Waterfall");
					}

					if (useOrCheck == 2)
						printf("%s uses %s, dealing %.2f damage!\n", PLAYERPOKEMONCHOICE, STATSTORAGE.p_moveOne, STATSTORAGE.p_damageDealt);

					return STATSTORAGE.p_moveOne;
				}
				default :
					printf("ERROR: moveSelect() switch-1-1 defaulted; debug"); // only occurs from developer error in implementation code
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
						STATSTORAGE.n_damageDealt = damageCalculation(1, 50, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Tackle");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Vine Whip
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 52, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Vine Whip");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Razor Leaf
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 54, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Razor Leaf");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Bullet Seed
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 56, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Bullet Seed");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Seed Bomb
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 58, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Seed Bomb");
					}
					if (useOrCheck == 2)
						printf("%s uses %s, dealing %.2f damage!\n", NPCPOKEMONCHOICE, STATSTORAGE.n_moveOne, STATSTORAGE.n_damageDealt);

					return STATSTORAGE.n_moveOne;
				}
				case 2 : // Fire-type physical moves
				{
					if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20)) // Levels 1-20: Scratch
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 50, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Scratch");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Slash
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 52, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Slash");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Fire Fang
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 54, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Fire Fang");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Flare Blitz
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 56, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Flare Blitz");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Flamethrower
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 58, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Flamethrower");
					}
					if (useOrCheck == 2)
					{
						printf("%s uses %s, dealing %.2f damage!\n", NPCPOKEMONCHOICE, STATSTORAGE.n_moveOne, STATSTORAGE.n_damageDealt);
					}

					return STATSTORAGE.n_moveOne;
				}
				case 3 : // Water-type physical moves
				{
					if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20)) // Levels 1-20: Headbutt
					{	
						STATSTORAGE.n_damageDealt = damageCalculation(1, 50, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Headbutt");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Water Gun
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 52, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Water Gun");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Aqua Tail
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 54, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Aqua Tail");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Water Spout
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 56, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Water Spout");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Waterfall
					{
						STATSTORAGE.n_damageDealt = damageCalculation(1, 58, STATSTORAGE.n_level, STATSTORAGE.n_attack, STATSTORAGE.n_spAttack, STATSTORAGE.n_defense, STATSTORAGE.n_spDefense, useAbility("npc"), createTypeModifier("npc"), createLevelModifier("npc"));
						if (useOrCheck != 1)
							STATSTORAGE.p_hp = STATSTORAGE.p_hp - STATSTORAGE.n_damageDealt;
						strcpy(STATSTORAGE.n_moveOne, "Waterfall");
					}

					if (useOrCheck == 2)
						printf("%s uses %s, dealing %.2f damage!\n", NPCPOKEMONCHOICE, STATSTORAGE.n_moveOne, STATSTORAGE.n_damageDealt);

					return STATSTORAGE.n_moveOne;
				}
				default :
					printf("ERROR: moveSelect() switch-1-2 defaulted; debug"); // only occurs from developer error in implementation code
			}
		}
		else
			printf("ERROR: moveSelect() if-2-1 defaulted; debug"); // only occurs from developer error in implementation code
	}

	else if (moveType == 2) // special moves that alter Pokemon STATSTORAGE attack and defense values
	{
		if (strcmp(who, "player")==0)
		{
			switch(typeToInt(getType((int)STATSTORAGE.p_pokemonID)))
			{
				case 1 : // Grass-type special moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Growth
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.p_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_attack = STATSTORAGE.p_attack + (0.45 * 2);
							STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack + (0.51 * 2);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Growth");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Swell
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.p_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_attack = STATSTORAGE.p_attack + (0.45 * 4);
							STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack + (0.51 * 4);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Swell");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Engorge
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.p_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_attack = STATSTORAGE.p_attack + (0.45 * 6);
							STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack + (0.51 * 6);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Engorge");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Sprout
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.p_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_attack = STATSTORAGE.p_attack + (0.45 * 8);
							STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack + (0.51 * 8);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Sprout");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Bloom
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.p_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_attack = STATSTORAGE.p_attack + (0.45 * 10);
							STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack + (0.51 * 10);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Bloom");
					}

					if (useOrCheck == 2)
						printf("%s uses %s, boosting their attack power by %.2f!\n", PLAYERPOKEMONCHOICE, STATSTORAGE.p_moveTwo, STATSTORAGE.p_attack - STATSTORAGE.p_buffReceived);

					return STATSTORAGE.p_moveTwo;
				}
				case 2 : // Fire-type special moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Growl
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.n_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_attack = STATSTORAGE.n_attack - (0.45 * 2);
							STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack - (0.51 * 2);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Growl");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Snarl
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.n_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_attack = STATSTORAGE.n_attack - (0.45 * 4);
							STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack - (0.51 * 4);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Snarl");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Howl
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.n_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_attack = STATSTORAGE.n_attack - (0.45 * 6);
							STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack - (0.51 * 6);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Howl");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Roar
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.n_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_attack = STATSTORAGE.n_attack - (0.45 * 8);
							STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack - (0.51 * 8);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Roar");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Initimidate
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.n_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_attack = STATSTORAGE.n_attack - (0.45 * 10);
							STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack - (0.51 * 10);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Initimidate");
					}

					if (useOrCheck == 2)
						printf("%s uses %s, reducing %s's attack power by %.2f!\n", PLAYERPOKEMONCHOICE, STATSTORAGE.p_moveTwo, NPCPOKEMONCHOICE, (STATSTORAGE.n_attack - STATSTORAGE.p_buffReceived)*(-1));

					return STATSTORAGE.p_moveTwo;
				}
				case 3 : // Water-type special moves
				{
					if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20)) // Levels 1-20: Tail Wag
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.n_defense; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_defense = STATSTORAGE.n_defense - (0.45 * 2);
							STATSTORAGE.n_spDefense = STATSTORAGE.n_spDefense - (0.52 * 2);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Tail Wag");
					}
					else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40)) // Levels 21-40: Confusion
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.n_defense; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_defense = STATSTORAGE.n_defense - (0.45 * 4);
							STATSTORAGE.n_spDefense = STATSTORAGE.n_spDefense - (0.52 * 4);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Confusion");
					}
					else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60)) // Levels 41-60: Spit
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.n_defense; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_defense = STATSTORAGE.n_defense - (0.45 * 6);
							STATSTORAGE.n_spDefense = STATSTORAGE.n_spDefense - (0.52 * 6);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Spit");
					}
					else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80)) // Levels 61-80: Cold Front
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.n_defense; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_defense = STATSTORAGE.n_defense - (0.45 * 8);
							STATSTORAGE.n_spDefense = STATSTORAGE.n_spDefense - (0.52 * 8);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Cold Front");
					}
					else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100)) // Levels 81-100: Rainstorm
					{
						STATSTORAGE.p_buffReceived = STATSTORAGE.n_defense; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_defense = STATSTORAGE.n_defense - (0.45 * 10);
							STATSTORAGE.n_spDefense = STATSTORAGE.n_spDefense - (0.52 * 10);
						}
						strcpy(STATSTORAGE.p_moveTwo, "Rainstorm");
					}
					if (useOrCheck == 2)
					{
						printf("%s uses %s, weakening %s's defenses by %.2f!\n", PLAYERPOKEMONCHOICE, STATSTORAGE.p_moveTwo, NPCPOKEMONCHOICE, (STATSTORAGE.n_defense - STATSTORAGE.p_buffReceived)*(-1));
					}
					return STATSTORAGE.p_moveTwo;
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
						STATSTORAGE.n_buffReceived = STATSTORAGE.n_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_attack = STATSTORAGE.n_attack + (0.45 * 2);
							STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack + (0.51 * 2);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Growth");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Swell
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.n_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_attack = STATSTORAGE.n_attack + (0.45 * 4);
							STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack + (0.51 * 4);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Swell");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Engorge
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.n_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_attack = STATSTORAGE.n_attack + (0.45 * 6);
							STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack + (0.51 * 6);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Engorge");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Sprout
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.n_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_attack = STATSTORAGE.n_attack + (0.45 * 8);
							STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack + (0.51 * 8);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Sprout");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Bloom
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.n_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.n_attack = STATSTORAGE.n_attack + (0.45 * 10);
							STATSTORAGE.n_spAttack = STATSTORAGE.n_spAttack + (0.51 * 10);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Bloom");
					}

					if (useOrCheck == 2)
						printf("%s uses %s, boosting their attack power by %.2f!\n", NPCPOKEMONCHOICE, STATSTORAGE.n_moveTwo, STATSTORAGE.n_attack - STATSTORAGE.n_buffReceived);

					return STATSTORAGE.n_moveTwo;
				}
				case 2 : // Fire-type special moves
				{
					if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20)) // Levels 1-20: Growl
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.p_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_attack = STATSTORAGE.p_attack - (0.45 * 2);
							STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack - (0.51 * 2);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Growl");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Snarl
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.p_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_attack = STATSTORAGE.p_attack - (0.45 * 4);
							STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack - (0.51 * 4);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Snarl");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Howl
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.p_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_attack = STATSTORAGE.p_attack - (0.45 * 6);
							STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack - (0.51 * 6);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Howl");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Roar
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.p_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_attack = STATSTORAGE.p_attack - (0.45 * 8);
							STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack - (0.51 * 8);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Roar");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Initimidate
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.p_attack; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_attack = STATSTORAGE.p_attack - (0.45 * 10);
							STATSTORAGE.p_spAttack = STATSTORAGE.p_spAttack - (0.51 * 10);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Initimidate");
					}

					if (useOrCheck == 2)
						printf("%s uses %s, reducing %s's attack power by %.2f!\n", NPCPOKEMONCHOICE, STATSTORAGE.n_moveTwo, PLAYERPOKEMONCHOICE, (STATSTORAGE.p_attack - STATSTORAGE.n_buffReceived)*(-1));

					return STATSTORAGE.n_moveTwo;
				}
				case 3 : // Water-type special moves
				{
					if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20)) // Levels 1-20: Tail Wag
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.p_defense; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_defense = STATSTORAGE.p_defense - (0.45 * 2);
							STATSTORAGE.p_spDefense = STATSTORAGE.p_spDefense - (0.52 * 2);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Tail Wag");
					}
					else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40)) // Levels 21-40: Confusion
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.p_defense; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_defense = STATSTORAGE.p_defense - (0.45 * 4);
							STATSTORAGE.p_spDefense = STATSTORAGE.p_spDefense - (0.52 * 4);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Confusion");
					}
					else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60)) // Levels 41-60: Spit
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.p_defense; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_defense = STATSTORAGE.p_defense - (0.45 * 6);
							STATSTORAGE.p_spDefense = STATSTORAGE.p_spDefense - (0.52 * 6);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Spit");
					}
					else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80)) // Levels 61-80: Cold Front
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.p_defense; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_defense = STATSTORAGE.p_defense - (0.45 * 8);
							STATSTORAGE.p_spDefense = STATSTORAGE.p_spDefense - (0.52 * 8);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Cold Front");
					}
					else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100)) // Levels 81-100: Rainstorm
					{
						STATSTORAGE.n_buffReceived = STATSTORAGE.p_defense; // saves stat prior to buff; subtract buffReceived from stat to calculate change in value
						if (useOrCheck != 1)
						{
							STATSTORAGE.p_defense = STATSTORAGE.p_defense - (0.45 * 10);
							STATSTORAGE.p_spDefense = STATSTORAGE.p_spDefense - (0.52 * 10);
						}
						strcpy(STATSTORAGE.n_moveTwo, "Rainstorm");
					}

					if (useOrCheck == 2)
					{
						printf("%s uses %s, weakening %s's defenses by %.2f!\n", NPCPOKEMONCHOICE, STATSTORAGE.n_moveTwo, PLAYERPOKEMONCHOICE, (STATSTORAGE.p_defense - STATSTORAGE.n_buffReceived)*(-1));
					}

					return STATSTORAGE.n_moveTwo;
				}
				default :
					printf("ERROR: moveSelect() switch-2-2 defaulted; debug"); // only occurs from developer error in implementation code
			}
		}
		else
			printf("ERROR: moveSelect() if-2-2 defaulted; debug"); // only occurs from developer error in implementation code
	}
	else
		printf("ERROR: moveSelect() if-1 defaulted; debug"); // only occurs from developer error in implementation code

	return "ERROR: moveSelected() return defaulted; debug"; // only occurs from developer error in implementation code
}

float useAbility(char who[7]) // buffs Pokemon with 150% damage when used - only usable below 33% HP
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
			abilityModifier = 1;
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
			abilityModifier = 1;
	}
	else
		printf("ERROR: useAbilityn() if defaulted; debug"); // only occurs from developer error in implementation code

	return abilityModifier;
}

char* useConsumable(char who[7], int useOrCheck) // consumes a potion, strength varied by level, to restore HP to the Pokemon
{
	if (strcmp(who, "player")==0)
	{
		if ((STATSTORAGE.p_level >= 1) && (STATSTORAGE.p_level < 20) && (STATSTORAGE.p_consumableCount > 0)) // Levels 1-20: Potion
		{
			STATSTORAGE.p_consumableRestore = 20;
			if (useOrCheck != 1)
			{
				STATSTORAGE.p_hp += STATSTORAGE.p_consumableRestore;
				STATSTORAGE.p_consumableCount = STATSTORAGE.p_consumableCount - 1;
			}
			strcpy(STATSTORAGE.p_consumable, "Potion");
		}
		else if ((STATSTORAGE.p_level >= 20) && (STATSTORAGE.p_level < 40) && (STATSTORAGE.p_consumableCount > 0)) // Levels 21-40: Super Potion
		{
			STATSTORAGE.p_consumableRestore = 60;
			if (useOrCheck != 1)
			{
				STATSTORAGE.p_hp += STATSTORAGE.p_consumableRestore;
				STATSTORAGE.p_consumableCount = STATSTORAGE.p_consumableCount - 1;
			}
			strcpy(STATSTORAGE.p_consumable, "Super Potion");
		}
		else if ((STATSTORAGE.p_level >= 40) && (STATSTORAGE.p_level < 60) && (STATSTORAGE.p_consumableCount > 0)) // Levels 41-60: Hyper Potion
		{
			STATSTORAGE.p_consumableRestore = 100;
			if (useOrCheck != 1)
			{
				STATSTORAGE.p_hp += STATSTORAGE.p_consumableRestore;
				STATSTORAGE.p_consumableCount = STATSTORAGE.p_consumableCount - 1;
			}
			strcpy(STATSTORAGE.p_consumable, "Hyper Potion");
		}
		else if ((STATSTORAGE.p_level >= 60) && (STATSTORAGE.p_level < 80) && (STATSTORAGE.p_consumableCount > 0)) // Levels 61-80: Max Potion
		{
			STATSTORAGE.p_consumableRestore = 140;
			if (useOrCheck != 1)
			{
				STATSTORAGE.p_hp += STATSTORAGE.p_consumableRestore;
				STATSTORAGE.p_consumableCount = STATSTORAGE.p_consumableCount - 1;
			}
			strcpy(STATSTORAGE.p_consumable, "Max Potion");
		}
		else if ((STATSTORAGE.p_level >= 80) && (STATSTORAGE.p_level <= 100) && (STATSTORAGE.p_consumableCount > 0)) // Levels 81-100: Full Restore
		{
			STATSTORAGE.p_consumableRestore = -1;
			if (useOrCheck != 1)
			{
				STATSTORAGE.p_hp = readPokemonStats("player", 3);
				STATSTORAGE.p_consumableCount = STATSTORAGE.p_consumableCount - 1;
			}
			strcpy(STATSTORAGE.p_consumable, "Full Restore");
		}
		else
			printf("ERROR: useConsumable() if-1-1 defaulted; debug"); // only occurs from developer error in implementation code

		if (STATSTORAGE.p_hp > readPokemonStats("player", 3)) // Prevents healing over maximum default HP
			STATSTORAGE.p_hp = readPokemonStats("player", 3);

		if (useOrCheck == 2)
		{
			if (STATSTORAGE.p_consumableRestore != -1)
				printf("%s consumed %s, restoring %.2f HP!\n", PLAYERPOKEMONCHOICE, STATSTORAGE.p_consumable, STATSTORAGE.p_consumableRestore);
			else
				printf("%s consumed %s, restoring their HP to maximum!\n", PLAYERPOKEMONCHOICE, STATSTORAGE.p_consumable);
		}

		return STATSTORAGE.p_consumable;
	}
	else if (strcmp(who, "npc")==0)
	{
		if ((STATSTORAGE.n_level >= 1) && (STATSTORAGE.n_level < 20) && (STATSTORAGE.n_consumableCount > 0)) // Levels 1-20: Potion
		{
			STATSTORAGE.n_consumableRestore = 20;
			if (useOrCheck != 1)
			{
				STATSTORAGE.n_hp += STATSTORAGE.n_consumableRestore;
				STATSTORAGE.n_consumableCount = STATSTORAGE.n_consumableCount - 1;
			}
			strcpy(STATSTORAGE.n_consumable, "Potion");
		}
		else if ((STATSTORAGE.n_level >= 20) && (STATSTORAGE.n_level < 40) && (STATSTORAGE.n_consumableCount > 0)) // Levels 21-40: Super Potion
		{
			STATSTORAGE.n_consumableRestore = 60;
			if (useOrCheck != 1)
			{
				STATSTORAGE.n_hp += STATSTORAGE.n_consumableRestore;
				STATSTORAGE.n_consumableCount = STATSTORAGE.n_consumableCount - 1;
			}
			strcpy(STATSTORAGE.n_consumable, "Super Potion");
		}
		else if ((STATSTORAGE.n_level >= 40) && (STATSTORAGE.n_level < 60) && (STATSTORAGE.n_consumableCount > 0)) // Levels 41-60: Hyper Potion
		{
			STATSTORAGE.n_consumableRestore = 100;
			if (useOrCheck != 1)
			{
				STATSTORAGE.n_hp += STATSTORAGE.n_consumableRestore;
				STATSTORAGE.n_consumableCount = STATSTORAGE.n_consumableCount - 1;
			}
			strcpy(STATSTORAGE.n_consumable, "Hyper Potion");
		}
		else if ((STATSTORAGE.n_level >= 60) && (STATSTORAGE.n_level < 80) && (STATSTORAGE.n_consumableCount > 0)) // Levels 61-80: Max Potion
		{
			STATSTORAGE.n_consumableRestore = 140;
			if (useOrCheck != 1)
			{
				STATSTORAGE.n_hp += STATSTORAGE.n_consumableRestore;
				STATSTORAGE.n_consumableCount = STATSTORAGE.n_consumableCount - 1;
			}
			strcpy(STATSTORAGE.n_consumable, "Max Potion");
		}
		else if ((STATSTORAGE.n_level >= 80) && (STATSTORAGE.n_level <= 100) && (STATSTORAGE.n_consumableCount > 0)) // Levels 81-100: Full Restore
		{
			STATSTORAGE.n_consumableRestore = -1;
			if (useOrCheck != 1)
			{
				STATSTORAGE.n_hp = readPokemonStats("npc", 3);
				STATSTORAGE.n_consumableCount = STATSTORAGE.n_consumableCount - 1;
			}
			strcpy(STATSTORAGE.n_consumable, "Full Restore");
		}
		else
			printf("ERROR: useConsumable() if-1-2 defaulted; debug"); // only occurs from developer error in implementation code

		if (STATSTORAGE.n_hp > readPokemonStats("npc", 3)) // Prevents healing over maximum default HP
			STATSTORAGE.n_hp = readPokemonStats("npc", 3);

		if (useOrCheck == 2)
		{
			if (STATSTORAGE.n_consumableRestore != -1)
				printf("%s consumed %s, restoring %.2f HP!\n", NPCPOKEMONCHOICE, STATSTORAGE.n_consumable, STATSTORAGE.n_consumableRestore);
			else
				printf("%s consumed %s, restoring their HP to maximum!\n", NPCPOKEMONCHOICE, STATSTORAGE.n_consumable);
		}

		return STATSTORAGE.n_consumable;
	}
	else
		printf("ERROR: useConsumable() if-1 defaulted; debug"); // only occurs from developer error in implementation code

	return "ERROR: useConsumable() return defaulted; debug"; // only occurs from developer error in implementation code
}
