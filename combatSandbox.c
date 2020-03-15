/*	CS125 Group Project
	File: combatSandbox.c
	Description: Dev-testing sandbox for combat functions
	Authors: Colton Van Orsdel
	References: N/A
*/
#include <stdio.h>

#include "generatePokemonStats.c"
#include "readPokemonStats.c"

int main()
{
	int pokemonChoice;
	printf("-Playable Pokemon-\n'1'-Bulbasaur\n'2'-Charmander\n'3'-Squirtle\n");
	printf("Choose your Pokemon: ");
	scanf("%d", &pokemonChoice);
	generatePokemonStats(pokemonChoice);
	printf("\nYou choose %s!\n", generatePokemonStats(pokemonChoice));
	printf("Your Pokemon is Level %.0f\n", readPokemonStats("player", 0));
	printf("Your Pokemon has %.2f HP\n", readPokemonStats("player", 1));
	printf("Your Pokemon has %.2f Attack\n", readPokemonStats("player", 2));
	printf("Your Pokemon has %.2f Defense\n", readPokemonStats("player", 3));
	printf("Your Pokemon has %.2f Special Attack\n", readPokemonStats("player", 4));
	printf("Your Pokemon has %.2f Special Defense\n", readPokemonStats("player", 5));
	printf("Your Pokemon has %.2f Speed\n", readPokemonStats("player", 6));
	printf("\n\n-Opponent Type-\n'1'-Grass\n'2'-Fire\n'3'-Water\n");
	printf("Choose an opponent Pokemon: ");
	scanf("%d", &pokemonChoice);
	generatePokemonStats(3+pokemonChoice);
	printf("\nYour opponent is %s!\n", generatePokemonStats(3+pokemonChoice));
	printf("Your opponent is Level %.0f\n", readPokemonStats("npc", 0));
	printf("Your opponent has %.2f HP\n", readPokemonStats("npc", 1));
	printf("Your opponent has %.2f Attack\n", readPokemonStats("npc", 2));
	printf("Your opponent has %.2f Defense\n", readPokemonStats("npc", 3));
	printf("Your opponent has %.2f Special Attack\n", readPokemonStats("npc", 4));
	printf("Your opponent has %.2f Special Defense\n", readPokemonStats("npc", 5));
	printf("Your opponent has %.2f Speed\n", readPokemonStats("npc", 6));
	// Clean up directory by deleting temporary files; will later implement an ask if player wants to "save" their game
	remove("playerStats.txt");
	remove("npcStats.txt"); 
	return 0;
} 