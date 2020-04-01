/*  CS125_Pokemon
    CS125 Programming Project
    endSim.c
    Animations and menus after completing the sim or losing
*/
#include "endSim.h"
#include "util.h"
#include "art.h"
#include <stdio.h>
#include <string.h>

void delay(int);
void clear();
void readPrint();
void asciiart(int);

void endGame(int win){
  clear();
  int count;

  // struct timespec tim, tim2;
  //   tim.tv_sec = 0;
  //   tim.tv_nsec = 50000000;
  // Win Scenario
  if (win == 1){
    char text1[] = "Congratulations! You have completed the tutorial simulator! You win!\n";
    readPrint(count, text1);
    // for (count=0;count<strlen(text1);count++){
    //   printf("%c", text1[count]);
    //   fflush(stdout);
    //   nanosleep(&tim , &tim2);
    // }
    // Printing Trophy
    printf("\n");
    sleep(1);
    asciiart(6);
    printf("\n");
    sleep(1);
  }
  // Lose Scenario

}
