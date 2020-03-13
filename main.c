/*  CS125_Pokemon
    CS125 Programming Project
    main.c
    Main program for the group project
*/
#include "intro.c"
#include "starter.c"
#include "battleUI2.c"


#include <string.h>
#include <stdio.h>


void intro();
char* starter(char *pokemonChoiceptr);
void battleUI();

int main(){
  // Initializing Vars
  char dummy;
  int count;
  char userName[50];
  char text1[]="Hi! Sorry to keep you waiting! Welcome to the world of Pokemon!\nMy name is Heather Marriot. But everyone calls me the\nCoding Professor. This world is widely inhabited by creatures known\nas Pokemon. We humans live alongside Pokemon, at times\nas friendly playmates, and at times as cooperative workmates.\nAnd sometimes, we band together and battle others like us.\nBut despite our closeness, we don't know everything about Pokemon.\nIn fact, there are many, many secrets surrounding Pokémon.\nTo unravel Pokemon mysteries, I've been undertaking research.\nThat's what I do.\n";
  char text2[]="\nAnd you are? ";
  char text3[]="\nAh, okay! You're ";
  char text4[]=" who's moving to my hometown of Prescott. I get it now!\nAll right, are you ready? Your very own adventure is\nabout to unfold. Take courage, and leap into the world of Pokemon\nwhere dreams, adventure and friendships await!\nFirst, let's choose a Pokemon companion!\n";
  char text5[]="Before you head out, I've created a simulator where you can practice working\nwith your Pokemon companion in battles! It's a series of battles\nsort of like the Champion's League. It's even VR!\nCheck it out!";
  // Structure for changing sleep times
  struct timespec tim, tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 50000000;

  // Running Start Screen & looking for Enter input
  intro();
  scanf("%c", &dummy);
  printf("\e[1;1H\e[2J");
  fflush(stdout);
  // Printing Intro Text
  sleep(3);
  for (count=0;count<strlen(text1);count++){
    printf("%c", text1[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }
  // Get user's name
  for (count=0;count<strlen(text2);count++){
    printf("\e[0;33m%c\e[0m", text2[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }
  fgets(userName, 50, stdin);
  userName[strcspn(userName, "\n")]=0;

  // Reacting to username
  for (count=0;count<strlen(text3);count++){
    printf("%c", text3[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }
  for (count=0;count<strlen(userName);count++){
    printf("\e[0;33m%c\e[0m", userName[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }
  for (count=0;count<strlen(text4);count++){
    printf("%c", text4[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }
  sleep(1);

  // Pokemon Choice
  char pokemonChoice[20];
  char* pokemonChoiceptr = pokemonChoice;
  pokemonChoiceptr = starter(pokemonChoiceptr);
  sleep(1);
  printf("\e[1;1H\e[2J");

  // Start of simulation
  for (count=0;count<strlen(text5);count++){
    printf("%c", text5[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }

  battleUI();
  return 0;
}
