/*	CS125 Group Project
	File: combat.h
	Description: Header file to include combat.c functions
	Authors: Colton Van Orsdel
	References: N/A
*/
#ifndef COMBAT
#define COMBAT
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
	float p_consumableCount;
	float p_abilityCount;
	float p_abilityStatus;
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
	float n_consumableCount;
	float n_abilityCount;
	float n_abilityStatus;
} statStruct;

// Global variables
statStruct statStorage; 
char type[6];
char moveSelected[15];
char pokemonName[20];
char effectiveness[30];
char potionSelected[15];

// Function prototypes
float readCombatStats(char who[7], int stat);
char *getType(int pokemonID, char type[6]);
float createTypeModifier(char who[7]);
char* checkEffectiveness(float typeModifier, char effectiveness[30]);
float createLevelModifier(char who[7]);
float damageCalculation(int moveType, float power, float level, float attack, float spAttack, float defense, float spDefense, float abilityModifier, float typeModifier, float levelModifier);
void combatScenario();
void playerTurn();
int playerTurnCheck(int playerChoice);
void npcTurn(int npcChoice);
int npcAI();
void useMoveOne(char who[7]);
void useMoveTwo(char who[7]);
float useAbility(char who[7]);
char* useConsumable(char who[7], char potionSelected[15]);
statStruct initializeStats();
char *moveSelect(char who[7], int moveType, char moveSelected[15]);
#endif