#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
void getPokemon(char holder[17][31],int pokemonIndex);
/*
int main()
{
char hold[17][31];
int count;
int whichOne=1;
printf("which pokemon do you want?");
scanf("%d",&whichOne);
getPokemon(hold,whichOne);

for(count=0;count<17;count++)
{
    printf("%s\n",hold[count]);
}

}

*/
////////////////////////////////////////////////////////////////
void getPokemon(char holder[17][31],int pokemonIndex){
char pokemon[17][31];
//https://pokemondb.net/pokedex/national
//https://www.text-image.com/convert/ascii.html
//make the width 30
//replace all slashes with l
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
 "                              ",
 "                              ",
 "                              ",
 "         ..----     ``        ",
 "         .:ol::++:.--ool-.    ",
 "   `    `l:o+l+++sososoool    ",
 " .+ll+:-+o+s+++osssss++o+.`   ",
 ":l+l+ooooosyssoyho++lll+sso:  ",
 ".l+++oossysssysyh+l::oo+o+lll ",
 " `-l++ossyyyyssolll:-oo++++ls:",
 "   `.:oyyyyhyollll+o+ooooool. ",
 " :ooossoohh+:lll+oooooool.    ",
 ".ll-oll+l+o::o++sssssss:      ",
 "   osl+oss+lsysso+sssyy       ",
 " `ooos+:l++ooos` :ssoo`       ",
 " -ll:.   .ll+l.  .---`        ",};

char venusaur[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"       `.::lll::ll::-`        ",
"    .:lll::lll+o+lllllll-`    ",
"    --+++lll:hddh:lll+++:.    ",
"   ```-:+osoyyyhhoooo+l-``    ",
" -:+ossyyyyyysyssyysyysso+l.``",
"-l++ssyysolossooss+ooyyyss++l.",
" ``+sysolll+l+oo+++l+oysys+`` ",
"   ossoooo++l+++++oossssyss   ",
"   .syssssso++ll++ssssssys.   ",
"    ```+sss:-----osssso-``    ",
"        ```     `:l++:        ",}; 

char charmander[17][31]=
{
"    .--:::-.                  ",
"   .:----:::l:                ",
"   +:::-:::los-               ",
"  `y+::--::shy+               ",
"  -+l::::-:l+++.           `  ",
"  .l++llll++o+l          `-l` ",
"   `.:+o+ll+++.`         :ll-`",
" ``.--:l:::ll:::--..-`  .lll-.",
".:::::l-````-::::::ll- `--:-:-",
" .....:``````-lll-.``   `---:`",
"      .```````:-::`      `l-  ",
"    `-:````...-:-::-  `.:++`  ",
"   .--:l-...--:---:lo++++l`   ",
"   :llllll:---llllllo+l:.     ",
"  .:+++ll      .llll+`        ",
"  ...`          `::+:-        ",};

char charmeleon[17][31]=
{
"            .:+:              ",
"       .-:l+oo-               ",
"     `:+ll++ool               ",
"     `ol++y++oo:              ",
"     -+++ooooso:              ",
"     :+ossssss:       `.`     ",
"       `--+oss:`       -+:.   ",
"    ``-:+l::l++l:.``   .+ll:. ",
"  `-l+l--.`.-+lo+:ll:` `+:-:l.",
"`-ll+- ..`...l+oo--l+l `:-.:l.",
":-+..  ......:oooo:l+o:  .-:- ",
"`..   .l....-:o+++o::::` .+.  ",
"    .ll++:-::l+llloso+ll+o-   ",
"    +++oss+::lllllosooo+:`    ",
"    :osss:    :+ooos..`       ",
"  .-l+o+:`    `looso.         ",
"   ``         .`----          ",};
char charizard[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"         ``:l-:-              ",
"    .:l+l` -:/+l:.     :.     ",
" `l+oooys.   `:l:     .syo:`  ",
"`+o+++osool-` -:l. ``-ysyso+l ",
"oo.` `lso+yys::::llosyssyooos:",
"l`     -.--.+:---:+--::o- l-oo",
"       `-.--:.```.:. -:. `--.l",
"    `.:::-:::....--l.`   `-.` ",
"   .l++++::l:-----::::..--.   ",
"   `:+++lll:--..-:lllll-.     ",
"       .:-.         `..`      ",};
char squirtle[17][31]=
{
"                              ",
"       `..-::::-`             ",
"      -l::::lllll:`           ",
"     `s:::::ymy+++l           ",
"     :llll::+o++++o           ",
"     -+++++++++o++:           ",
"     `.l++++++++ol+-          ",
" `.--:l:-:lll+l:l+sol         ",
".++::l:..-:-ll::l+oo+-        ",
".-::-l-...:-l++l++:ol:        ",
"     -:---:-:l+ll+:o+l `.---. ",
"    `:l.--:---llll:so-:llll++-",
"    :-:l::l::ll::::oo+++o++++l",
"   .lll++l-::+l::::lo+++oo+++.",
"   :l++l:     .+ll++:--::::.  ",
"     `         ::/+:.         ",};
char wartortle[17][31]=
{
"                              ",
"     ..           `..         ",
"    -`-.        `---.         ",
"    ..::.-::--..-...`         ",
"    --:::::::::-....          ",
"    `::::::::l::..`    `....  ",
"     -ll:::ls-l+o:`  `.`---.- ",
"   ``-l+::::oloooll:::::-:::` ",
"`-l:::lol+oosslloll:::::l:--- ",
"`ll++++:``-+-```-+o+oo:--:.-..",
"     ``- ``-`````.::++l----..-",
"       `.`..-`..--:++ol---..-`",
"      .::-``-...-l+ooo+--.-.` ",
"     `+l++o+---::+:::lol.`    ",
"     .ssss+`   ` `:l++oo.     ",
"      `-.-        .l:ll--     ",};
char blastoise[17][31]=
{
"              .l-:l+ll..`     ",
"              .y+l+lll+oo     ",
"              .lllllll:-.     ",
"  `.-.`...-::lll++++::-.``    ",
"   .-lo++lll++lll+syo:```:+   ",
"   .oo+ll+++oo+++oyo+l:---:   ",
"  .ss+++o+oosyssssy+--o+ll-`  ",
"  +yooossssssysyyyy+`:+oollo: ",
"  :ssssssssssssssssl-looooooo.",
"  syyssyyyssssssso--:l-  `.`` ",
" :ysyyssyysssssl-`.:ll`       ",
":+ssyysyyyyss+...:+++ll`      ",
"lol::-l+so+l-..-+ooooo+l      ",
"-+o:l+o+l-::::+ssooooos-      ",
".lllooool-...`.ossssssl       ",
"-l++l:-`      `-:l+ll:-.      ",};


	











switch(pokemonIndex){

case 1:
memcpy(pokemon,bulbasaur,sizeof(pokemon));
break;
case 2:
memcpy(pokemon,ivysaur,sizeof(pokemon));
break;
case 3:
memcpy(pokemon,venusaur,sizeof(pokemon));
break;
case 4:
memcpy(pokemon,charmander,sizeof(pokemon));
break;
case 5:
memcpy(pokemon,charmeleon,sizeof(pokemon));
break;
case 6:
memcpy(pokemon,charizard,sizeof(pokemon));
break;
case 7:
memcpy(pokemon,squirtle,sizeof(pokemon));
break;
case 8:
memcpy(pokemon,wartortle,sizeof(pokemon));
break;
case 9:
memcpy(pokemon,blastoise,sizeof(pokemon));
break;




default:
break;
}
memcpy(holder,pokemon,sizeof(pokemon));
///end program
}

