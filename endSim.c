/*  CS125 Group Project
    File: endSim.c
    Description: Animations and menus to play after sim win/loss
    Authors: Forrest Mobley
    References: N/A
*/

// Utilized libraries
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Header files
#include "endSim.h"
#include "battleUI.h"

void delay(int);
void clear();
void readPrint();
void asciiart(int);

void endSim(){
  clear();
  int count;
  
  if (WINORLOSE == 1){ // Win scenario
    char text1[] = "Congratulations! You have completed the tutorial simulator! You win!\n";
    char text2[] = "This is the end of the tutorial simulator. I hope you enjoyed it\nand learned the basics for your upcoming adventure. I look forward to\nhearing all of the amazing stories about you and your companions!\nSee ya!\n";
    readPrint(count, text1, "standard");
    // Printing Trophy
    printf("\n");
    sleep(1);
    asciiart(6);
    printf("\n");
    sleep(1);
    readPrint(count, text2, "standard");
  }
  
  else if (WINORLOSE == 0){ // Lose Scenario
    char text1[] = "Aww! That's too bad! You gave a good show though! I'm sure\nif you try again you'll win next time! Try again soon!\n";
    readPrint(count, text1, "standard");
    printf("\n");
    sleep(1);
    asciiart(7);
    printf("\n");
    sleep(1);
  }

}
