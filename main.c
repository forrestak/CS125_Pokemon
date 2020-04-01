/*  CS125_Pokemon
    CS125 Programming Project
    main.c
    Main program for the group project
*/

// Included Header Files
#include "util.h"
#include "intro.h"
#include "starter.h"
//#include "battleUI2.c"
//#include "endSim.c"

// Standard Libraries
#include <string.h>
#include <stdio.h>
#include <unistd.h>

// Util
void delay(int);
void clear();
void readPrint(int, char [], char[]);
// Intro
void intro();
// Starter
char* starter(char*);
//char* starter(char *pokemonChoiceptr);
//void battleUI();
//void endGame(int);


int main(){
  // Initializing Vars
  char dummy; // Dummy var
  int count; // Count for printing
  char userName[50]; // Username
  int win = 1; // Win or lose variable; Set to 1 if the player wins

  char text1[]="Hi! Sorry to keep you waiting! Welcome to the world of Pokemon!\nMy name is Heather Marriot. But everyone calls me the\nCoding Professor. This world is widely inhabited by creatures known\nas Pokemon. We humans live alongside Pokemon, at times\nas friendly playmates, and at times as cooperative workmates.\nAnd sometimes, we band together and battle others like us.\nBut despite our closeness, we don't know everything about Pokemon.\nIn fact, there are many, many secrets surrounding Pokemon.\nTo unravel Pokemon mysteries, I've been undertaking research.\nThat's what I do.\n";
  char text2[]="\nAnd you are? ";
  char text3[]="\nAh, okay! You're ";
  char text4[]=" who's moving to my hometown of Prescott. I get it now!\nAll right, are you ready? Your very own adventure is\nabout to unfold. Take courage, and leap into the world of Pokemon\nwhere dreams, adventure and friendships await!\nFirst, let's choose a Pokemon companion!\n";
  char text5[]="Before you head out, I've created a simulator where you can practice working\nwith your Pokemon companion in battles! It's a series of battles\nsort of like the Champion's League. It's even VR!\nCheck it out!";

  // Running Start Screen & looking for Enter input
  intro();
  scanf("%c", &dummy);
  clear();
  fflush(stdout);

  // Printing Intro Text
  sleep(3);
  readPrint(count, text1, "standard");

  // Get user's name
  readPrint(count, text2, "standard");
  fgets(userName, 50, stdin);
  userName[strcspn(userName, "\n")]=0;

  // Reacting to username
  readPrint(count, text3, "standard");
  readPrint(count, userName, "yellow");
  readPrint(count, text4, "standard");
  sleep(1);

  // Pokemon Choice
  char pokemonChoice[20];
  char* pokemonChoiceptr = pokemonChoice;
  pokemonChoiceptr = starter(pokemonChoiceptr);
  sleep(1);
  clear();

  // Start of simulation
  readPrint(count, text5, "standard");

  //endGame(win);
  // battleUI();
  return 0;
}
