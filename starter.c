/*  CS125_Pokemon
    CS125 Programming Project
    starter.c
    File for choosing starter Pokemon
*/
#include "starter.h"
#include "util.h"
#include "art.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void delay(int);
void clear();
void readPrint(int, char [], char []);

void asciiart(int);

char* starter(char *pokemonChoiceptr){
  int count;
  clear();

  // Intro to starter Pokemon
  char text1[] = "There are many different types of Pokemon in the world.\nI won't go through all of them right now but the three\nyou should know about are ";
  char types1[] = "Fire";
  char types2[] = "Water";
  char types3[] = "Grass";
  char text2[] = "and ";
  char text3[] = "Each Pokemon type has its own strengths and weaknesses.\nFire is effective against Grass and weak against Water,\nWater is effective against Fire and weak against Grass,\nand Grass is effective against Water and weak against Fire.\n\nWe keep Pokemon in little homes called Pokeballs,\nlike this!\n";
  char text4[] = "To help you out with your adventure, I have 3 Pokemon\nfor you to choose from. One is a Fire type, one is a Water type,\nand one is a Grass type. Here is a picture of each one!\n\n";
  char text5[] = "Which would you like to choose? Charmander, Squirtle, or Bulbasaur\n";
  char text6[] = "Ah, so you've chosen ";
  char text7[] = "! A very good choice! That is a strong\nPokemon! I'm sure you two will make a strong team!\nI predict many amazing things to come from this.\n";
  char text8[] = "Oops! I didn't get that. Please try again!\n";
  char text9[] = ", ";
  char text10[] = ".\n\n";
  char text150[] = "! You cheater pants! Your adventure won't\neven be a challenge! Cheaters don't learn anything.\nBut it's your choice. Your 'adventure' awaits... Good luck,\nas if you need it.\n";

  // Text 1 & 2
  readPrint(count, text1, "standard");
  readPrint(count, types1, "red");
  readPrint(count, text9, "standard");
  readPrint(count, types2, "blue");
  readPrint(count, text9, "standard");
  readPrint(count, text2, "standard");
  readPrint(count, types3, "green");
  readPrint(count, text10, "standard");

  // Text 3
  readPrint(count, text3, "standard");

  // Printing Pokeball
  printf("\n");
  sleep(1);
  asciiart(2);
  printf("\n");
  sleep(1);

  // Starter Pokemon Printing
  readPrint(count, text4, "standard");

  // Printing Starter Pokemon
  asciiart(3);
  printf("\n");
  sleep(1);
  asciiart(4);
  printf("\n");
  sleep(1);
  asciiart(5);
  printf("\n");
  sleep(1);

  // User Choice
  readPrint(count, text5, "standard");

  // Do while to catch fat fingering
  do{
    printf("\nType your choice here: ");
    fgets(pokemonChoiceptr, 20, stdin);
    pokemonChoiceptr[strcspn(pokemonChoiceptr, "\n")]=0;
    fflush(stdin);
    printf("\n");
    if ((strcmp(pokemonChoiceptr, "Charmander")!=0) && (strcmp(pokemonChoiceptr, "Squirtle")!=0) && (strcmp(pokemonChoiceptr, "Bulbasaur")!=0) && (strcmp(pokemonChoiceptr, "Mewtwo")!=0) && (strcmp(pokemonChoiceptr, "charmander")!=0) && (strcmp(pokemonChoiceptr, "squirtle")!=0) && (strcmp(pokemonChoiceptr, "bulbasaur")!=0) && (strcmp(pokemonChoiceptr, "mewtwo")!=0)){
      readPrint(count, text8, "standard");
      readPrint(count, text5, "standard");
    }
  }while ((strcmp(pokemonChoiceptr, "Charmander")!=0) && (strcmp(pokemonChoiceptr, "Squirtle")!=0) && (strcmp(pokemonChoiceptr, "Bulbasaur")!=0) && (strcmp(pokemonChoiceptr, "Mewtwo")!=0) && (strcmp(pokemonChoiceptr, "charmander")!=0) && (strcmp(pokemonChoiceptr, "squirtle")!=0) && (strcmp(pokemonChoiceptr, "bulbasaur")!=0) && (strcmp(pokemonChoiceptr, "mewtwo")!=0));

  readPrint(count, text6, "standard");

  // Result of Choice
  if ((strcmp(pokemonChoiceptr, "Charmander")==0) || (strcmp(pokemonChoiceptr, "charmander")==0)){
    readPrint(count, "Charmander", "red");
    readPrint(count, text7, "standard");
  }
  else if ((strcmp(pokemonChoiceptr, "Squirtle")==0) || (strcmp(pokemonChoiceptr, "squirtle")==0)){
    readPrint(count, "Squirtle", "blue");
    readPrint(count, text7, "standard");
  }
  else if ((strcmp(pokemonChoiceptr, "Bulbasaur")==0) || (strcmp(pokemonChoiceptr, "bulbasaur")==0)){
    readPrint(count, "Bulbasaur", "green");
    readPrint(count, text7, "standard");
  }
  else if ((strcmp(pokemonChoiceptr, "Mewtwo")==0) || (strcmp(pokemonChoiceptr, "mewtwo")==0)){
    readPrint(count, "Mewtwo", "purple");
    readPrint(count, text150, "standard");
  }
  return pokemonChoiceptr;
}
