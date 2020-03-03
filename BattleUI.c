#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 33
#define COLS 65

//https://www.geeksforgeeks.org/time-delay-c/
void delay(int milliseconds)
{
    milliseconds*=1000;
    clock_t start_time =clock();
    while(clock()<start_time + milliseconds);
}
///////////////////////////////////
void clear()
{
    printf("\e[2J\e[H");
}
//////////////////////////////////
void run(char screen[ROWS][COLS])
{
    int x=0;
    for(x=0;x<ROWS;x++)
    printf("%s\n",screen[x]);
}
///////////////////////////////////////
void changeEnemy(char screen[ROWS][COLS],int pokemonIndex)
{

char enemyPokemon[17][31];






char spare[COLS-30];
strncpy(spare,screen[0],COLS-31);

char spare2[COLS];
strcat(spare2,spare);
//strcat(spare2, image[0]);
printf("%s",spare2);

printf("\nhere\n");

}
//////////////////////////////////////
char* getPokemon(int pokemonIndex,int lineNumber){
int increment=0;
char pokemon[17][31];
char returnStatement[31]={};
//you cant really return whole arrays, but you can return whole strings
//so do like a for loop to get all of the lines of a bulbasaur out there :D
//pokemonIndex is probably for choosing the pokemon
char bulbasaur[17][31]=
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
  "     -.--`   `::ll:`  -:::-   ",};



printf("location 1\n");
for(increment;increment<17;increment++)
{
//printf("%d",increment);
strncpy(pokemon[increment],bulbasaur[increment],31);
printf("%s\n",pokemon[increment]);
}

printf("location 2\n");


printf("you are here\n");
printf("%s\n",pokemon[4]);

printf("and here too\n");


strncpy(returnStatement,pokemon[5],31);

printf("location 3\n");


printf("%s\n",pokemon[5]);
printf("location 4\n");
printf("%s\n",returnStatement);

printf("location 5\n");

//printf("^^^^^^^^^^^^^^%s^^^^^^^^^^^^^^^\n",returnStatement);
return "sup bruh";

}


/////////////////////////////////////
/////////////////////////////////////
/*

//https://www.text-image.com/convert/ascii.html
//use this website cause theres no asterisks
//also replace all slashes with l

                      .l::`
            .--:lllllll+loo`
    ..`   `+llllo+llllllls+
   l::l::l++llll:++lllll+sol
  :l--loss+l:::::lo+++oooosol
 -lllo:lll:l:l+l:+oooooooosoo:
.:+ll:loo:l:.+:o+++osssoooooo+
l-ol:::ll::: sloo+++oyysysoool
:+ll::l::::l:l+oo++++ossoosol
 `-+soo++++osoo+++lll+++l++:
   .l+oooosooooo:++:lo+oso++`
    +os+++o+oss+oll:+oloso+o`
    `+++++. .+so+:l+:l+++++l
     -.--`   `::ll:`  -:::-




*/


/////////////////////////////////////
int main()
{
printf("\e[2J\e[H");
//32 rows, 64 columns
char screen[ROWS][COLS] ={
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
"0123456789012345678901234567890123456789012345678901234567890123"};


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
  "     -.--`   `::ll:`  -:::-   ",};



getPokemon(3,3);


////////////////
changeEnemy(screen,1);
run(screen);
return 0;
//////////////


int i;
for(i=0;i<10;i++)
{
delay(500);
run(screen);
printf("whas\n sup");

clear();
}





}
