/*  CS125_Pokemon
    CS125 Programming Project
    endSim.c
    Animations and menus after completing the sim or losing
*/
#include "endSim.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void delay(int);
void clear();
void readPrint();
void asciiart(int);

void endGame(int win){
  clear();
  int count;

  // Win Scenario
  if (win == 1){
    char text1[] = "Congratulations! You have completed the tutorial simulator! You win!\n";
    readPrint(count, text1, "standard");
    // Printing Trophy
    printf("\n");
    sleep(1);
    asciiart(6);
    printf("\n");
    sleep(1);
  }
  // Lose Scenario
  else if (win == 0){
    char text1[] = "Aww! That's too bad! You gave a good show though! I'm sure\nif you try again you'll win next time!\n";

    readPrint(count, text1, "standard");
    
  }

}
