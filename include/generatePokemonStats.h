/*	CS125 Group Project
	File: generatePokemonStats.h
	Description: Header file to include generatePokemonStats.c functions
	Authors: Colton Van Orsdel
	References: N/A
*/
#ifndef GENERATEPOKEMONSTATS
#define GENERATEPOKEMONSTATS
void createPlayerFile(float statsArray[9]);
void createNPCFile(float statsArray[9]);
char *generatePokemonStats(int pokemonChoice, int useOrCheck);
#endif