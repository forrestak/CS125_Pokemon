/*	CS125 Group Project
	File: combat.h
	Description: Header file to include combat.c functions and global variables
	Authors: Colton Van Orsdel
	References: N/A
*/

#ifndef COMBAT
#define COMBAT

// Global variables
typedef struct {
	// Player stat storage
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
	float p_damageDealt;
	float p_buffReceived;
	float p_consumableRestore;
	char p_type[6];
	char p_moveOne[15];
	char p_moveTwo[15];
	char p_ability[15];
	char p_consumable[15];
	// NPC stat storage
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
	float n_damageDealt;
	float n_buffReceived;
	float n_consumableRestore;
	char n_type[6];
	char n_moveOne[15];
	char n_moveTwo[15];
	char n_ability[15];
	char n_consumable[15];
} statStruct;
extern statStruct STATSTORAGE;
extern char TYPE[6];
extern char MOVESELECTED[15];
extern char POKEMONNAME[20];
extern char EFFECTIVENESS[30];
extern char POTIONSELECTED[15];
extern char USERNAME[50];
extern char PLAYERPOKEMONCHOICE[20];
extern char NPCPOKEMONCHOICE[20];
extern int NPCRANDOMIZE;
extern int WINORLOSE;

// Function prototypes
void combatScenario();
void playerTurn();
void npcTurn(int npcChoice);
int playerTurnCheck(int playerChoice);
int npcAI();
void checkVictory();
statStruct initializeStats();
char *getType(int pokemonID);
char typeToInt();
float createTypeModifier(char who[7]);
char* checkEffectiveness(float typeModifier);
float createLevelModifier(char who[7]);
float damageCalculation(int moveType, float power, float level, float attack, float spAttack, float defense, float spDefense, float abilityModifier, float typeModifier, float levelModifier);
char *moveSelect(char who[7], int moveType, int useOrCheck);
float useAbility(char who[7]);
char* useConsumable(char who[7], int useOrCheck);

#endif