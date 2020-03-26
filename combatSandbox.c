/*	CS125 Group Project
	File: combatSandbox.c
	Description: Dev-testing sandbox for combat functions
	Authors: Colton Van Orsdel
	References: N/A
*/
#include <stdio.h>

#include "generatePokemonStats.c"
#include "readPokemonStats.c"
#include "levelupPokemonStats.c"

int main()
{
	int pokemonChoice;
	printf("-Playable Pokemon-\n'1'-Bulbasaur\n'2'-Charmander\n'3'-Squirtle\n");
	printf("Choose your Pokemon: ");
	scanf("%d", &pokemonChoice);
	printf("\nYou choose %s!\n", generatePokemonStats(pokemonChoice));
	printf("Your Pokemon is Level %.0f\n", readPokemonStats("player", 1));
	printf("Your Pokemon has:\n%.2f XP\n", readPokemonStats("player", 2));
	printf("%.2f HP\n", readPokemonStats("player", 3));
	printf("%.2f Attack\n", readPokemonStats("player", 4));
	printf("%.2f Defense\n", readPokemonStats("player", 5));
	printf("%.2f Special Attack\n", readPokemonStats("player", 6));
	printf("%.2f Special Defense\n", readPokemonStats("player", 7));
	printf("%.2f Speed\n", readPokemonStats("player", 8));
	printf("\n\n-Opponent Type-\n'1'-Grass\n'2'-Fire\n'3'-Water\n");
	printf("Choose an opponent Pokemon: ");
	scanf("%d", &pokemonChoice);
	printf("\nYour opponent is %s!\n", generatePokemonStats(3+pokemonChoice));
	printf("Your opponent is Level %.0f\n", readPokemonStats("npc", 1));
	printf("Your opponent has:\n%.2f XP\n", readPokemonStats("npc", 2));
	printf("%.2f HP\n", readPokemonStats("npc", 3));
	printf("%.2f Attack\n", readPokemonStats("npc", 4));
	printf("%.2f Defense\n", readPokemonStats("npc", 5));
	printf("%.2f Special Attack\n", readPokemonStats("npc", 6));
	printf("%.2f Special Defense\n", readPokemonStats("npc", 7));
	printf("%.2f Speed\n", readPokemonStats("npc", 8));
	// Level-up testing below
	levelupPokemonStats("player", pokemonChoice, 5000);
	printf("\n\nYour Pokemon has gained 5000 xp\n");
	printf("Your Pokemon is now Level %.0f\n", readPokemonStats("player", 1));
	printf("Your Pokemon has:\n%.2f XP\n", readPokemonStats("player", 2));
	printf("%.2f HP\n", readPokemonStats("player", 3));
	printf("%.2f Attack\n", readPokemonStats("player", 4));
	printf("%.2f Defense\n", readPokemonStats("player", 5));
	printf("%.2f Special Attack\n", readPokemonStats("player", 6));
	printf("%.2f Special Defense\n", readPokemonStats("player", 7));
	printf("%.2f Speed\n", readPokemonStats("player", 8));
	// Clean up directory by deleting temporary files; will later implement an ask if player wants to "save" their game
	remove("playerStats.txt");
	remove("npcStats.txt"); 
	return 0;
} 