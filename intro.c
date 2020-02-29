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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void intro(){
  // Structure for changing sleep times
  struct timespec tim, tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 250000000;


  //Printing the Pokemon Logo
  printf("\e[1;1H\e[2J");
  printf("                                     ,\'\\\n");
  nanosleep(&tim , &tim2);
  printf("       _.----.        ____         ,'  _\\   ___    ___     ____\n");
  nanosleep(&tim , &tim2);
  printf("   _,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n");
  nanosleep(&tim , &tim2);
  printf("   \\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n");
  nanosleep(&tim , &tim2);
  printf("    \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n");
  nanosleep(&tim , &tim2);
  printf("      \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n");
  nanosleep(&tim , &tim2);
  printf("       \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n");
  nanosleep(&tim , &tim2);
  printf("        \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n");
  nanosleep(&tim , &tim2);
  printf("         \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n");
  nanosleep(&tim , &tim2);
  printf("          \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n");
  nanosleep(&tim , &tim2);
  printf("           \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n");
  nanosleep(&tim , &tim2);
  printf("                                   `'                            '-._|\n");

  printf("\e[0;34m               ___           _ \e[0;33m     __   __          _          \n");
  nanosleep(&tim , &tim2);
  printf("\e[0;34m              | __|__ _ __ _| |___  \e[0;33m\\ \\ / /__ _ _ __(_)___ _ _\n");
  nanosleep(&tim , &tim2);
  printf("\e[0;34m              | _|/ _` / _` | / -_)  \e[0;33m\\ V / -_) '_(_-< / _ \\ ' \\ \n");
  nanosleep(&tim , &tim2);
  printf("\e[0;34m              |___\\__,_\\__, |_\\___|  \e[0;33m \\_/\\___|_| /__/_\\___/_||_|\n");
  nanosleep(&tim , &tim2);
  printf(" \e[0;34m                      |___/  \n");
  nanosleep(&tim , &tim2);
  printf("\n");
  nanosleep(&tim , &tim2);
  printf("\n");
  sleep(1);
  printf("\e[0m                            Press Enter to begin!\n");
}
