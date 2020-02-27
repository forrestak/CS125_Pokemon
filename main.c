/*  CS125_Pokemon
    CS125 Programming Project
    main.c
    Main program for the group project
*/
#include "intro.c"

#include <string.h>
#include <stdio.h>

/* Intro
    - Title Screen
      - Pokemon
      - Title of game (Eagle, Embry - Riddle)
      - Slides up like in real game
      - Press Enter to Start?
    - Intro Text
      - "Hi! Sorry to keep you waiting! Welcome to the world of Pokemon!
        My name is Heather Marriot. But everyone calls me the Coding Professor.
        This world is widely inhabited by creatures known as Pokemon.
        We humans live alongside Pokemon, at times as friendly playmates,
        and at times as cooperative workmates.
        And sometimes, we band together and battle others like us.
        But despite our closeness, we don't know everything about Pokemon.
        In fact, there are many, many secrets surrounding Pokémon.
        To unravel Pokemon mysteries, I've been undertaking research.
        That's what I do. And you are?"
      - Have user enter name <player>
      -"Ah, okay! You're <player> who's moving to my hometown of Prescott.
        I get it now! All right, are you ready? Your very own adventure is about
        to unfold. Take courage, and leap into the world of Pokemon where
        dreams, adventure and friendships await! First, let's choose a
        Pokemon companion!"
*/


void intro();

int main(){
  // Initializing Vars
  char dummy;
  int count;

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
  char text1[]="Hi! Sorry to keep you waiting! Welcome to the world of Pokemon!\nMy name is Heather Marriot. But everyone calls me the\nCoding Professor. This world is widely inhabited by creatures known\nas Pokemon. We humans live alongside Pokemon, at times\nas friendly playmates, and at times as cooperative workmates.\nAnd sometimes, we band together and battle others like us.\nBut despite our closeness, we don't know everything about Pokemon.\nIn fact, there are many, many secrets surrounding Pokémon.\nTo unravel Pokemon mysteries, I've been undertaking research.\nThat's what I do. And you are?\n";
  sleep(3);
  for (count=0;count<strlen(text1);count++){
    printf("%c", text1[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }
  return 0;
}
