/*  CS125_Pokemon
    CS125 Programming Project
    starter.c
    File for choosing starter Pokemon
*/

#include <stdio.h>
#include <string.h>

int starter(){
  int pokemonChoice=0;
  int count;
  // Structure for changing sleep times
  struct timespec tim, tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 50000000;

  printf("\e[1;1H\e[2J");
  // Intro to starter Pokemon
  char text1[] = "There are many different types of Pokemon in the world.\nI won't go through all of them right now but the three\nyou should know about are ";
  char types1[] = "Fire";
  char types2[] = "Water";
  char types3[] = "Grass";
  char text2[] = "and ";
  char text3[] = "Each Pokemon type has its own strengths and weaknesses.\nFire is effective against Grass and weak against Water,\nWater is effective against Fire and weak against Grass,\nand Grass is effective against Water and weak against Fire.\n\nWe keep Pokemon in little homes called Pokeballs,\nlike this!\n";

  for (count=0;count<strlen(text1);count++){
    printf("%c", text1[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }
  for (count=0;count<=strlen(types1);count++){
    printf("\e[0;31m%c\e[0m", types1[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
    if (count == strlen(types1)){
      printf(", ");
    }
  }
  for (count=0;count<=strlen(types2);count++){
    printf("\e[0;34m%c\e[0m", types2[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
    if (count == strlen(types2)){
      printf(", ");
    }
  }
  for (count=0;count<strlen(text2);count++){
    printf("%c", text2[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }
  for (count=0;count<=strlen(types3);count++){
    printf("\e[0;32m%c\e[0m", types3[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
    if (count == strlen(types3)){
      printf(".\n\n");
    }
  }
  for (count=0;count<strlen(text3);count++){
    printf("%c", text3[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }

  return pokemonChoice;
}
