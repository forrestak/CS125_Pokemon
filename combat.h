/*	CS125 Group Project
	File: combat.h
	Description: Header file to include combat.c functions
	Authors: Colton Van Orsdel
	References: N/A
*/
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