/*	CS125 Group Project
	File: combat.c
	Description: Handles combat actions and related stat updating
	Authors: Colton Van Orsdel
	References: N/A
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function prototypes
char *getType(float pokemonID);
int checkType(char type[6]);
float createTypeModifier(char who[7], statStruct statStorage);
float damageCalculation(float power, float level, float attack, float spAttack, float defense, float spDefense, float abilityModifier, float typeModifier);
void playerTurn(statStruct statStorage);
void npcTurn();
void useMoveOne(char who[7], statStruct statStorage);
void useMoveTwo(char who[7], statStruct statStorage);
float useAbility(char who[7], statStruct statStorage);
void useConsumable(char who[7], statStruct statStorage);
statStruct initializeStats();

typedef struct {
	// Player stat storage
	char p_type[6];
	float p_pokemonID;
	float p_level;
	float p_experience;
	float p_hp;
	float p_attack;
	float p_defense;
	float p_spAttack;
	float p_spDefense;
	float p_speed;
	// NPC stat storage
	char n_type[6];
	float n_pokemonID;
	float n_level;
	float n_experience;
	float n_hp;
	float n_attack;
	float n_defense;
	float n_spAttack;
	float n_spDefense;
	float n_speed;
} statStruct;

char *getType(float pokemonID)
{
	if ((pokemonID == 1) || (pokemonID == 4))
	{
		char type[6] = "Grass";
		return type;
	}
	else if ((pokemonID == 2) || (pokemonID == 5))
	{
		char type[6] = "Fire";
		return type;
	}
	else if ((pokemonID == 3) || (pokemonID == 6))
	{
		char type[6] = "Water";
		return type;
	}
	else
		return "";
}

int checkType(char type[6])
{
	if (strcmp(type, "Grass")==0)
		return 1;
	else if (strcmp(type, "Fire")==0)
		return 2;
	else if (strcmp(type, "Water")==0)
		return 3;
	else
		return 0;
}

statStruct statStorage; // declare global structure

statStruct initializeStats()
{
	// Assign player stat defaults from files
	statStorage.p_type[6] = getType(readPokemonStats("player", 0));
	statStorage.p_pokemonID = readPokemonStats("player", 0);
	statStorage.p_level = readPokemonStats("player", 1);
	statStorage.p_experience = readPokemonStats("player", 2);
	statStorage.p_hp = readPokemonStats("player", 3);
	statStorage.p_attack = readPokemonStats("player", 4);
	statStorage.p_defense = readPokemonStats("player", 5);
	statStorage.p_spAttack = readPokemonStats("player", 6);
	statStorage.p_spDefense = readPokemonStats("player", 7);
	statStorage.p_speed = readPokemonStats("player", 8);
	// Assign NPC stat defaults from files
	statStorage.n_type[6] = getType(readPokemonStats("npc", 0));
	statStorage.n_pokemonID = readPokemonStats("npc", 0);
	statStorage.n_level = readPokemonStats("npc", 1);
	statStorage.n_experience = readPokemonStats("npc", 2);
	statStorage.n_hp = readPokemonStats("npc", 3);
	statStorage.n_attack = readPokemonStats("npc", 4);
	statStorage.n_defense = readPokemonStats("npc", 5);
	statStorage.n_spAttack = readPokemonStats("npc", 6);
	statStorage.n_spDefense = readPokemonStats("npc", 7);
	statStorage.n_speed = readPokemonStats("npc", 8);

	return statStorage;
}


float createTypeModifier(char who[7], statStruct statStorage)
{
	float typeModifier[3][3]={{2, 2, .5},
							 {.5, 2, 2},
							 {2, .5, 2}};
	if (strcmp(who, "player")==0)
		return &typeModifier[(int)statStorage->p_pokemonID][(int)statStorage->n_pokemonID];
	else if (strcmp(who, "npc")==0)
		return &typeModifier[(int)statStorage->n_pokemonID][(int)statStorage->p_pokemonID];
	else
		return 1;
}

float damageCalculation(float power, float level, float attack, float spAttack, float defense, float spDefense, float abilityModifier, float typeModifier)
{
	float damage = ((((((((2.00 * level)/5)+2)) * power * (attack / defense))/50)+2) * abilityModifier) / typeModifier;
	return damage;
}

void playerTurn(statStruct statStorage)
{
	int playerChoice;
	printf("Make a move: ");
	scanf("%d", &playerChoice);
	switch(playerChoice)
	{
		case 1 : // Move One
		{
			useMoveOne("player", statStorage);
			printf("%.2f\n", statStorage->n_hp);
			break;
		}
		case 2 : // Move Two
		{
			break;
		}
		case 3 : // Ability
		{
			break;
		}
		case 4 : // Consumable
		{
			break;
		}
		default :
		{
			break;
		}
	}
}

void npcTurn()
{

}

void useMoveOne(char who[7], statStruct statStorage)
{
	if (strcmp(who, "player")==0)
	{
		switch((int)&statStorage->p_pokemonID)
		{
			case 1 : // Bulbasaur "Tackle"
			{
				&statStorage->n_hp = &statStorage->n_hp - damageCalculation(40, &statStorage->p_level, &statStorage->p_attack, &statStorage->p_spAttack, &statStorage->p_defense, &statStorage->p_spDefense, useAbility("player", statStorage), createTypeModifier("player", statStorage));
				break;
			}
			case 2 : // Charmander "Scratch"
			{

				break;
			}
			case 3 : // Squirtle "Tackle"
			{

				break;
			}
			default :
				break;
		}
	}
	else if (strcmp(who, "npc")==0);
	{
		srand(time(NULL)); 
		switch((int)statStorage->p_pokemonID)
		{
			case 4 : // Bellsprout/Oddish "Vine Whip"/"Absorb"
			{
				break;
			}
			case 5 : // Growlithe/Ponyta "Ember"/"Tackle"
			{
				break;
			}
			case 6 : // Slowpoke/Seel "Tackle"/"Headbutt"
			{
				break;
			}
		}
	}
}
/*
void useMoveTwo(char who[7], statStruct statStorage)
{
	if (strcmp(who, "player")==0)
	{
		switch((int)statStorage.p_pokemonID)
		{
			case 1 : 
			{

			}
			case 2 : 
			{
				
			}
			case 3 : 
			{
				
			}
		}
	}
	else if (strcmp(who, "npc")==0);
	{
		srand(time(NULL)); 
		switch((int)statStorage.p_pokemonID)
		{
			case 4 : 
			{

			}
			case 5 : 
			{
				
			}
			case 6 : 
			{
				
			}
	}
}
*/
float useAbility(char who[7], statStruct statStorage)
{
	int movesRemaining;
	float pointerDebugFix; // utilized so that damageCalculation() uses only pointers
	while (movesRemaining >= 1)
	{
		if (strcmp(who, "player")==0)
		{
			if (statStorage->p_hp <= (readPokemonStats("player", 3) / 3))
			{
				pointerDebugFix = 1.5;
				return &pointerDebugFix;
			}
			else
			{
				pointerDebugFix = 1;
				return &pointerDebugFix;
			}
		}
		else if (strcmp(who, "npc")==0);
		{
			if (statStorage->n_hp <= (readPokemonStats("npc", 3) / 3))
			{
				pointerDebugFix = 1.5;
				return &pointerDebugFix;
			}
			else
			{
				pointerDebugFix = 1;
				return &pointerDebugFix;
			}
		}
	}
}


void useConsumable(char who[7], statStruct statStorage)
{
	if (strcmp(who, "player")==0)
	{
		if ((statStorage.p_level >= 1) && (statStorage.p_level <= 20)) // Levels 1-20: Potion
		{
			statStorage.p_hp += 20;
		}
		else if ((statStorage.p_level > 20) && (statStorage.p_level <= 40)) // Levels 21-40: Super Potion
		{
			statStorage.p_hp += 60;
		}
		else if ((statStorage.p_level > 40) && (statStorage.p_level <= 60)) // Levels 41-60: Hyper Potion
		{
			statStorage.p_hp += 100;
		}
		else if ((statStorage.p_level > 61) && (statStorage.p_level <= 80)) // Levels 61-80: Max Potion
		{
			statStorage.p_hp += 140;
		}
		else if ((statStorage.p_level > 80) && (statStorage.p_level <= 100)) // Levels 81-100: Full Restore
		{
			statStorage.p_hp = readPokemonStats("player", 3);
		}
	}
	else if (strcmp(who, "npc")==0)
	{
		if ((statStorage.n_level >= 1) && (statStorage.n_level <= 20)) // Levels 1-20: Potion
		{
			statStorage.n_hp += 20;
		}
		else if ((statStorage.n_level > 20) && (statStorage.n_level <= 40)) // Levels 21-40: Super Potion
		{
			statStorage.n_hp += 60;
		}
		else if ((statStorage.n_level > 40) && (statStorage.n_level <= 60)) // Levels 41-60: Hyper Potion
		{
			statStorage.n_hp += 100;
		}
		else if ((statStorage.n_level > 61) && (statStorage.n_level <= 80)) // Levels 61-80: Max Potion
		{
			statStorage.n_hp += 140;
		}
		else if ((statStorage.n_level > 80) && (statStorage.n_level <= 100)) // Levels 81-100: Full Restore
		{
			statStorage.n_hp = readPokemonStats("npc", 3);
		}
	}
}