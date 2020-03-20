/*  CS125_Pokemon
    CS125 Programming Project
    battleui.c
    Retry at battle UI File
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "pokeFiles.c"

void getPokemon(char holder[17][31],int pokemonIndex);

void delay(int milliseconds);
void clear();
void run(char screen[33][65]);
void changeEnemy(char screen[33][65],int pokemonIndex);
//#define ROWS 33
//#define COLS 65

void battleUI(){
  clear();
  //32 rows, 64 columns
  char screen[33][65] =
  {
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123",
    "0123456789012345678901234567890123456789012345678901234567890123"
  };

  //test 16 lines height
  //30 char width
  char test[17][31]=
  {
    "                              ",
    "                              ",
    "                      .l::`   ",
    "            .--:lllllll+loo`  ",
    "    ..`   `+llllo+llllllls+   ",
    "   l::l::l++llll:++lllll+sol  ",
    "  :l--loss+l:::::lo+++oooosol ",
    " -lllo:lll:l:l+l:+oooooooosoo:",
    ".:+ll:loo:l:.+:o+++osssoooooo+",
    "l-ol:::ll::: sloo+++oyysysoool",
    ":+ll::l::::l:l+oo++++ossoosol ",
    " `-+soo++++osoo+++lll+++l++:  ",
    "   .l+oooosooooo:++:lo+oso++` ",
    "    +os+++o+oss+oll:+oloso+o` ",
    "    `+++++. .+so+:l+:l+++++l  ",
    "     -.--`   `::ll:`  -:::-   ",
  };

  int ice;
  for(ice=1;ice<=151;ice++){
    changeEnemy(screen,ice);
    run(screen);
    delay(500);
    clear();
  }

  int i;
  for(i=0;i<10;i++){
    delay(500);
    run(screen);
    clear();
  }

}

//https://www.geeksforgeeks.org/time-delay-c/
void delay(int milliseconds){
  milliseconds*=1000;
  clock_t start_time =clock();
  while(clock()<start_time + milliseconds);
}

void clear(){
  printf("\e[2J\e[H");
}

void run(char screen[33][65]){
  int x=0;
  for(x=0;x<33;x++)
  printf("%s\n",screen[x]);
}

void changeEnemy(char screen[33][65],int pokemonIndex){
  int count;
  char enemyPokemon[17][31];
  char cleanSpare[65-30];
  char spare[65-30];
  char completeSpare[65];
  char cleanCompleteSpare[65];

  getPokemon(enemyPokemon,pokemonIndex);

  for(count=0;count<16;count++){
    memcpy(spare,cleanSpare,sizeof(spare));
    memcpy(completeSpare,cleanCompleteSpare,sizeof(completeSpare));
    strncpy(spare,enemyPokemon[count],30);
    strncpy(completeSpare,screen[count],65-31);
    strcat(completeSpare,spare);
    strncpy(screen[count],completeSpare,65);
  }
}
