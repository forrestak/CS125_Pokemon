/*  CS125_Pokemon
    CS125 Programming Project
    starter.c
    File for choosing starter Pokemon
*/
#include "art.c"

#include <stdio.h>
#include <string.h>

void asciiart(int);

char starter(){
  char pokemonChoice[20];
  //char starterName[20];
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
  char text4[] = "To help you out with your adventure, I have 3 Pokemon\nfor you to choose from. One is a Fire type, one is a Water type,\nand one is a Grass type. Here is a picture of each one!\n\n";
  char text5[] = "Which would you like to choose? Charmander, Squirtle, or Bulbasaur\n";
  char text6[] = "Ah, so you've chosen ";
  char text7[] = "! A very good choice! Now you are ready\nto start your adventure! A wonderous world awaits you!\nI predict many amazing things to come from this. Good luck!\n";
  char text8[] = "Oops! I didn't get that. Please try again!\n";

  char text150[] = "! You cheater pants! Your adventure won't\neven be a challenge! Cheaters don't learn anything.\nBut it's your choice. Your 'adventure' awaits... Good luck,\nas if you need it.\n";

  // Text 1
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
  // Text 2
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
  // Text 3
  for (count=0;count<strlen(text3);count++){
    printf("%c", text3[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }

  // Printing Pokeball
  printf("\n");
  sleep(1);
  asciiart(2);
  printf("\n");
  sleep(1);

  // Starter Pokemon Printing
  for (count=0;count<strlen(text4);count++){
    printf("%c", text4[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }

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
  for (count=0;count<strlen(text5);count++){
    printf("%c", text5[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }
  printf("\nType your choice here: ");
  fgets(pokemonChoice, 20, stdin);
  pokemonChoice[strcspn(pokemonChoice, "\n")]=0;
  fflush(stdin);
  printf("\n");
  /*do{

    if ((strcmp(pokemonChoice, "Charmander")!=0) || (strcmp(pokemonChoice, "Squirtle")!=0) || (strcmp(pokemonChoice, "Bulbasaur")!=0) || (strcmp(pokemonChoice, "Mewtwo")!=0)){
      for (count=0;count<strlen(text8);count++){
        printf("%c", text8[count]);
        fflush(stdout);
        nanosleep(&tim , &tim2);
      }
      for (count=0;count<strlen(text5);count++){
        printf("%c", text5[count]);
        fflush(stdout);
        nanosleep(&tim , &tim2);
      }
    }
  } while ((strcmp(pokemonChoice, "Charmander")!=0) || (strcmp(pokemonChoice, "Squirtle")!=0) || (strcmp(pokemonChoice, "Bulbasaur")!=0) || (strcmp(pokemonChoice, "Mewtwo")!=0));*/

  for (count=0;count<strlen(text6);count++){
    printf("%c", text6[count]);
    fflush(stdout);
    nanosleep(&tim , &tim2);
  }
  // Result of Choice
  if (strcmp(pokemonChoice, "Charmander")==0){
    for (count=0;count<strlen(pokemonChoice);count++){
      printf("\e[0;31m%c", pokemonChoice[count]);
      fflush(stdout);
      nanosleep(&tim , &tim2);
    }
    for (count=0;count<strlen(text7);count++){
      printf("\e[0m%c", text7[count]);
      fflush(stdout);
      nanosleep(&tim , &tim2);
    }
  }
  else if (strcmp(pokemonChoice, "Squirtle")==0){
    for (count=0;count<strlen(pokemonChoice);count++){
      printf("\e[0;34m%c", pokemonChoice[count]);
      fflush(stdout);
      nanosleep(&tim , &tim2);
    }
    for (count=0;count<strlen(text7);count++){
      printf("\e[0m%c", text7[count]);
      fflush(stdout);
      nanosleep(&tim , &tim2);
    }
  }
  else if (strcmp(pokemonChoice, "Bulbasaur")==0){
    for (count=0;count<strlen(pokemonChoice);count++){
      printf("\e[0;32m%c", pokemonChoice[count]);
      fflush(stdout);
      nanosleep(&tim , &tim2);
    }
    for (count=0;count<strlen(text7);count++){
      printf("\e[0m%c", text7[count]);
      fflush(stdout);
      nanosleep(&tim , &tim2);
    }
  }
  else if (strcmp(pokemonChoice, "Mewtwo")==0){
    for (count=0;count<strlen(pokemonChoice);count++){
      printf("\e[0;35m%c", pokemonChoice[count]);
      fflush(stdout);
      nanosleep(&tim , &tim2);
    }
    for (count=0;count<strlen(text150);count++){
      printf("\e[0m%c", text150[count]);
      fflush(stdout);
      nanosleep(&tim , &tim2);
    }
  }
  return *pokemonChoice;
}
