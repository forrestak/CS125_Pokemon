#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "pokeFiles.c"

#define ROWS 33
#define COLS 65



void getPokemon(char holder[17][31],int pokemonIndex);
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
///////////////////////////////////

/*

void getPokemon(char holder[17][31],int pokemonIndex){
int increment=0;
char pokemon[17][31];
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



char ivysaur[17][31]=
{

 "                               ",
 "                               ",
 "                               ",
 "         ..----     ``         ",
 "         .:ol::++:.--ool-.     ",
 "   `    `l:o+l+++sososoool     ",
 " .+ll+:-+o+s+++osssss++o+.`    ",
 ":l+l+ooooosyssoyho++lll+sso:   ",
 ".l+++oossysssysyh+l::oo+o+lll  ",
 " `-l++ossyyyyssolll:-oo++++ls: ",
 "   `.:oyyyyhyollll+o+ooooool.  ",
 " :ooossoohh+:lll+oooooool.     ",
 ".ll-oll+l+o::o++sssssss:       ",
 "   osl+oss+lsysso+sssyy        ",
 " `ooos+:l++ooos` :ssoo`        ",
 " -ll:.   .ll+l.  .---`         ",


};




//https://stackoverflow.com/questions/12675800/how-to-copy-matrix-in-c
memcpy(holder,bulbasaur,sizeof(bulbasaur));
//memcpy(holder,ivysaur,sizeof(ivysaur));

}

*/

///////////////////////////////////////
void changeEnemy(char screen[ROWS][COLS],int pokemonIndex)
{
int count;
char enemyPokemon[17][31];
char cleanSpare[COLS-30];
char spare[COLS-30];
char completeSpare[COLS];
char cleanCompleteSpare[COLS];

getPokemon(enemyPokemon,pokemonIndex);

//printf("ur here \n%s\n%s\n%s\n%s\n",enemyPokemon[4],enemyPokemon[5],enemyPokemon[6],enemyPokemon[7]);

//strncpy(spare,putty,30);
//strncpy(completeSpare,screen[0],COLS-31);
//strcat(completeSpare,spare);
//strncpy(screen[0],completeSpare,COLS);


for(count=0;count<16;count++)
{
memcpy(spare,cleanSpare,sizeof(spare));
memcpy(completeSpare,cleanCompleteSpare,sizeof(completeSpare));
strncpy(spare,enemyPokemon[count],30);
strncpy(completeSpare,screen[count],COLS-31);
strcat(completeSpare,spare);
strncpy(screen[count],completeSpare,COLS);


}



//strncpy(spare,screen[0],COLS-31);

//printf("%s",completeSpare);

//printf("\nhere\n");

}
//////////////////////////////////////



/////////////////////////////////////
/////////////////////////////////////
/*

//https://www.text-image.com/convert/ascii.html
//30 width
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



https://bulbapedia.bulbagarden.net/wiki/File:Spr_b_g1_001.png
so bulbapedia, for the backs,gen 1, blue






        +
      :h ++
      N:h  yyN+o+:
      N:Ns:. .+:+:y:+   ++
    oNh.yhs::.    yy.+o+  N
  ohhh: :Ns+:::.   .h:N .y+
 N+hhs:  sNs+:::    N:N:yooN
 N.Nss:  :hhs+:::..:NNh+sNNho
 N.hhss+. +hhss+++hNNs+hhhhs+
  +y+hhhhhoyyNhhNNNhss++h+


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


int ice;
for(ice=1;ice<=9;ice++)
{


changeEnemy(screen,ice);
run(screen);
delay(2000);
clear();
}

return 0;

int i;
for(i=0;i<10;i++)
{
delay(500);
run(screen);

clear();
}





}
