/*  CS125 Group Project
    File: starter.c
    Description: File for choosing starter Pokemon
    Authors: Forrest Mobley, Colton Van Orsdel
    References: N/A
*/

// Utilized libraries
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

// Header files
#include "starter.h"
#include "battleUI.h"

void delay(int);
void clear();
void readPrint(int, char [], char []);

void asciiart(int);

char* starter(){
  int count;
  clear();

  // Intro to starter Pokemon
  char text1[] = "There are many different types of Pokemon in the world.\nI won't go through all of them right now but the three\nyou should know about are ";
  char types1[] = "Grass";
  char types2[] = "Fire";
  char types3[] = "Water";
  char text2[] = "and ";
  char text3[] = "Each Pokemon type has its own strengths and weaknesses:\nGrass is effective against Water and weak against Fire,\nFire is effective against Grass and weak against Water,\nand Water is effective against Fire and weak against Grass.\n\nWe keep Pokemon in little homes called Pokeballs, like this!\n";
  char text4[] = "To help you out with your adventure, I have 3 Pokemon\nfor you to choose from. One is a Grass type, one is a Fire type,\nand one is a Water type. Here is a picture of each one!\n\n";
  char text5[] = "Which would you like to choose? ";
  char text6[] = "Ah, you've chosen ";
  char text7[] = "! A very good choice! That is a strong Pokemon!\nI'm sure you two will make an amazing team!\n";
  char text8[] = "Oops! I didn't get that. Please try again.\n";
  char text9[] = ", ";
  char text10[] = ".\n\n";
  char text11[] = "\nNow, one last thing, what type of opponent would you like to practice against - ";
  char text12[] = ", ok! Watch out for this opponent type's attack-stat stacking.\n";
  char text13[] = ", ok! Beware, this opponent type can reduce your attack stats.\n";
  char text14[] = ", ok! Keep your guard up, this opponent type can weaken your defenses.\n";
  char text15[] = "or ";
  char text16[] = "?\n";
  char text17[] = "Bulbasaur";
  char text18[] = "Charmander";
  char text19[] = "Squirtle";
  char text150[] = "! You cheater pants! Your adventure won't\neven be a challenge! Cheaters don't learn anything.\nBut it's your choice. Your 'adventure' awaits... Good luck,\nas if you need it.\n";

  // Text 1 & 2
  readPrint(count, text1, "standard");
  readPrint(count, types1, "green");
  readPrint(count, text9, "standard");
  readPrint(count, types2, "red");
  readPrint(count, text9, "standard");
  readPrint(count, text2, "standard");
  readPrint(count, types3, "blue");
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
  asciiart(5); // Bulbasaur
  printf("\n");
  sleep(1);
  asciiart(3); // Charmander
  printf("\n");
  sleep(1);
  asciiart(4); // Squirtle
  printf("\n");
  sleep(1);

  // Player's Pokemon Choice
  readPrint(count, text5, "standard");
  readPrint(count, text17, "green");
  readPrint(count, text9, "standard");
  readPrint(count, text18, "red");
  readPrint(count, text9, "standard");
  readPrint(count, text15, "standard");
  readPrint(count, text19, "blue");
  readPrint(count, text16, "standard");

  // Do while to catch fat fingering
  do{
    printf("Enter your choice here: ");
    fgets(PLAYERPOKEMONCHOICE, 20, stdin);
    PLAYERPOKEMONCHOICE[strcspn(PLAYERPOKEMONCHOICE, "\n")]=0;
    for (count=0; count<=strlen(PLAYERPOKEMONCHOICE); count++){
      PLAYERPOKEMONCHOICE[count] = tolower(PLAYERPOKEMONCHOICE[count]);
    }
    fflush(stdin);
    printf("\n");
    if ((strcmp(PLAYERPOKEMONCHOICE, "charmander")!=0) && (strcmp(PLAYERPOKEMONCHOICE, "squirtle")!=0) && (strcmp(PLAYERPOKEMONCHOICE, "bulbasaur")!=0) && (strcmp(PLAYERPOKEMONCHOICE, "mewtwo")!=0)){
      readPrint(count, text8, "standard");
      readPrint(count, text5, "standard");
    }
  }while ((strcmp(PLAYERPOKEMONCHOICE, "charmander")!=0) && (strcmp(PLAYERPOKEMONCHOICE, "squirtle")!=0) && (strcmp(PLAYERPOKEMONCHOICE, "bulbasaur")!=0) && (strcmp(PLAYERPOKEMONCHOICE, "mewtwo")!=0));

  readPrint(count, text6, "standard");
  


  // Result of Choice
  if (strcmp(PLAYERPOKEMONCHOICE, "charmander")==0){
    readPrint(count, "Charmander", "red");
    readPrint(count, text7, "standard");
  }
  else if (strcmp(PLAYERPOKEMONCHOICE, "squirtle")==0){
    readPrint(count, "Squirtle", "blue");
    readPrint(count, text7, "standard");
  }
  else if (strcmp(PLAYERPOKEMONCHOICE, "bulbasaur")==0){
    readPrint(count, "Bulbasaur", "green");
    readPrint(count, text7, "standard");
  }
  else if (strcmp(PLAYERPOKEMONCHOICE, "mewtwo")==0){
    readPrint(count, "Mewtwo", "purple");
    readPrint(count, text150, "standard");
  }

  // Player's Opponent-Type Choice
  readPrint(count, text11, "standard");
  readPrint(count, types1, "green");
  readPrint(count, text9, "standard");
  readPrint(count, types2, "red");
  readPrint(count, text9, "standard");
  readPrint(count, text15, "standard");
  readPrint(count, types3, "blue");
  readPrint(count, text16, "standard");

  do{
      printf("Enter your choice here: ");
      fgets(NPCPOKEMONCHOICE, 20, stdin);
      NPCPOKEMONCHOICE[strcspn(NPCPOKEMONCHOICE, "\n")]=0;
      for (count=0; count<=strlen(NPCPOKEMONCHOICE); count++){
        NPCPOKEMONCHOICE[count] = tolower(NPCPOKEMONCHOICE[count]);
      }
      fflush(stdin);
      printf("\n");
      if ((strcmp(NPCPOKEMONCHOICE, "grass")!=0) && (strcmp(NPCPOKEMONCHOICE, "fire")!=0) && (strcmp(NPCPOKEMONCHOICE, "water")!=0)){
        readPrint(count, text8, "standard");
        readPrint(count, types1, "green");
        readPrint(count, text9, "standard");
        readPrint(count, types2, "red");
        readPrint(count, text9, "standard");
        readPrint(count, text15, "standard");
        readPrint(count, types3, "blue");
        readPrint(count, text16, "standard");
      }
    }while ((strcmp(NPCPOKEMONCHOICE, "grass")!=0) && (strcmp(NPCPOKEMONCHOICE, "fire")!=0) && (strcmp(NPCPOKEMONCHOICE, "water")!=0));

    // Result of Choice
    if (strcmp(NPCPOKEMONCHOICE, "grass")==0){
      readPrint(count, "Grass", "green");
      readPrint(count, text12, "standard");
    }
    else if (strcmp(NPCPOKEMONCHOICE, "fire")==0){
      readPrint(count, "Fire", "red");
      readPrint(count, text13, "standard");
    }
    else if (strcmp(NPCPOKEMONCHOICE, "water")==0){
      readPrint(count, "Water", "blue");
      readPrint(count, text14, "standard");
    }

    return NPCPOKEMONCHOICE;
}
