/*	CS125 Group Project
	File: levelupPokemonStats.h
	Description: Header file to include levelupPokemonStats.c functions
	Authors: Colton Van Orsdel
	References: N/A
*/
#ifndef LEVELUPPOKEMONSTATS
#define LEVELUPPOKEMONSTATS
float getStatGrowth(int pokemonID, int stat);
void levelupPokemonStats(char who[7], int pokemonID, int experience);
#endif