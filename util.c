/*  CS125_Pokemon
    CS125 Programming project
    util.c
    Utility File for useful functions
    Author: Forrest Mobley
*/

// Header File
#include "util.h"

// Standard libraries
#include <stdio.h>
#include <time.h>
#include <string.h>

void delay(int milliseconds){
  milliseconds*=1000;
  clock_t start_time =clock();
  while(clock()<start_time + milliseconds);
}

void clear(){
  printf("\e[2J\e[H");
}

void readPrint(int count, char text[], char color[]){
  if (strcmp(color, "standard")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
  else if (strcmp(color, "red")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0;31m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
  else if (strcmp(color, "blue")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0;34m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
  else if (strcmp(color, "green")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0;32m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
  else if (strcmp(color, "yellow")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0;33m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
  else if (strcmp(color, "purple")==0){
    for (count=0;count<strlen(text);count++){
      printf("\e[0;35m%c", text[count]);
      fflush(stdout);
      delay(50);
    }
  }
}
