/*  CS125_Pokemon
    CS125 Programming project
    intro.c
    Introduction graphics and starting menu for the group project.
    Author: Forrest Mobley
    Sources:
            - https://www.asciiart.eu/video-games/pokemon
            - http://patorjk.com/software/taag/#p=testall&f=Graffiti&t=Eagle%20Version
            - https://stackoverflow.com/questions/26063754/nanosleep-does-not-work-for-values-less-than-a-second
*/

// Header File
#include "intro.h"

// Included standard libraries
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// utils functions
void delay(int);
void clear();

void intro(){
  //Printing the Pokemon Logo
  clear();
  printf("                                     ,\'\\\n");
  delay(200);
  printf("       _.----.        ____         ,'  _\\   ___    ___     ____\n");
  delay(200);
  printf("   _,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n");
  delay(200);
  printf("   \\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n");
  delay(200);
  printf("    \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n");
  delay(200);
  printf("      \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n");
  delay(200);
  printf("       \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n");
  delay(200);
  printf("        \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n");
  delay(200);
  printf("         \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n");
  delay(200);
  printf("          \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n");
  delay(200);
  printf("           \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n");
  delay(200);
  printf("                                   `'                            '-._|\n");

  printf("\e[0;34m               ___           _ \e[0;33m     __   __          _          \n");
  delay(200);
  printf("\e[0;34m              | __|__ _ __ _| |___  \e[0;33m\\ \\ / /__ _ _ __(_)___ _ _\n");
  delay(200);
  printf("\e[0;34m              | _|/ _` / _` | / -_)  \e[0;33m\\ V / -_) '_(_-< / _ \\ ' \\ \n");
  delay(200);
  printf("\e[0;34m              |___\\__,_\\__, |_\\___|  \e[0;33m \\_/\\___|_| /__/_\\___/_||_|\n");
  delay(200);
  printf(" \e[0;34m                      |___/  \n");
  delay(200);
  printf("\n");
  delay(200);
  printf("\n");
  sleep(1);
  printf("\e[0m                            Press Enter to begin!\n");
}
