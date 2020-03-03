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
///////////////////////////////////
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

//https://stackoverflow.com/questions/12675800/how-to-copy-matrix-in-c
memcpy(holder,bulbasaur,sizeof(bulbasaur));

}
///////////////////////////////////////
void changeEnemy(char screen[ROWS][COLS],int pokemonIndex)
{
int count;
char enemyPokemon[17][31];
char cleanSpare[COLS-30];
char spare[COLS-30];
char completeSpare[COLS];
char cleanCompleteSpare[COLS];

getPokemon(enemyPokemon,4);

//printf("ur here \n%s\n%s\n%s\n%s\n",enemyPokemon[4],enemyPokemon[5],enemyPokemon[6],enemyPokemon[7]);

//strncpy(spare,putty,30);
//strncpy(completeSpare,screen[0],COLS-31);
//strcat(completeSpare,spare);
//strncpy(screen[0],completeSpare,COLS);


for(count=0;count<17;count++)
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
