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
//height has to be 16
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

char caterpie[17][31]=
{
"                              ",
"`..   .---:l++l-.             ",
"l++ll+lll++l+oolll-           ",
" `:++o+ooo++ll:hso++          ",
"  :ll+oollllll+NNmh+-         ",
"  :l+ll++++lll:+sy++:         ",
"  `+:::l+lloo++++++ol-        ",
"   -+:lll+oodhsoooolll.       ",
"    -:++oooosdooll:::--       ",
"     --.....-+o+l::l::`    --:",
"     -.l...-..:oll:l:`    ---:",
"     `-l:--lllloo++-      -:l`",
"       :...-lllo+lol`     -+` ",
"       -lllll-looo+++ol:l+o-  ",
"          `-:lll+oooosooos-   ",
"             .-:ll++++l-.     ",};

char metapod[17][31]=
{
"    .-:-                      ",
"   `l::::l`                   ",
"  `l:::::+o.                  ",
" `::::::ll+ol`                ",
" lll:::l+`soo+:.              ",
".ll+llllll:lo+++l-.           ",
":ll:l+l+:l++++++++ll:.        ",
"+:::l:::+oo+++++++++-         ",
"lll+:::::ls++++++oo.          ",
"`lys++ll+oo+++++oo+           ",
"  `:sososo+++++++++o-         ",
"    .+++oo++++++++++++`       ",
"      -ll+o+lllll++oos+l.     ",
"        .:+osoo+oooosyoos+:`  ",
"             .-:osyyssyyysyo+:",
"                  .-:oossso+l`",};

char butterfree[17][31]=
{
"                              ",
"                              ",
"                              ",
"      :l      `.       ``.:-  ",
" ```` +`     :+.   ```` `.:oy-",
":-````l    `:`   `.-l++..```+h",
"l`.s:.:.  `-   `...``:m-.```os",
":..o``.l``:` `..````.-.```.lh.",
"`-``...:++y++l.`....``````.m+ ",
" `-``.losyy+os+..`````````:h  ",
"  .``.+syssyyy:``````````.m:  ",
"   `.`.:lsyyyso:--...````-y   ",
"    ..``.ossssyo:::::--+hs`   ",
"       `o::oysss:-.::lml.     ",
"        o+--sol+o:--.od       ",
"         ls+l:.-:.l++:        ",};

char weedle[17][31]=
{
"           ``.`               ",
"        ``.` `.               ",
"   `---:l-.`..l`              ",
" .ls+::::ll+++++l`            ",
"+l:ll+++++yoo++++l            ",
".o+++++o++oo+++++o            ",
" -++oo+++++++++ll:            ",
"  `l++++++++llll-             ",
" `:ll+oooooo+l.               ",
" .l:l+++o++++l              ` ",
"   .:l++o+o++-             ---",
"    llooooo+++`          .-.-l",
"    .-:+oooso++:.`  ```--+--:.",
"       +ll+++osoosooooosoos.  ",
"        `.+oosoossoosoos++:`  ",
"           `.--l+o+l:-.`      ",};

char kakuna[17][31]=
{
"                              ",
"       `..-----:------.`      ",
"   ..-....-------------:::-`  ",
" l:...---------::::::------l- ",
"ldl...------::+hdmmdy+----::l`",
"`ll:-.-----l+:+yysoo++::l+l-` ",
"   -+:-llll++lll+++++++lll:-. ",
"  `+-ll:l+osoooo++llllllll+l+.",
"  ----:.++looo+++++llllll+++- ",
"  -l-+..+lllos+++lllllllll+.  ",
"   :-l:.+lll+slllll+ll:::l:   ",
"   `+:o:+l++++++ll+l::::l:    ",
"    .lo:+o++++ll+o+:::l:.     ",
"      -+.:llll+++l+o:-`       ",
"       `:ll+++ll++-`          ",
"         `-::::.`             ",};

char beedrill[17][31]=
{
"                              ",
"                              ",
"         ``        ..    ```` ",
"        -.::::`    ..:.....`..",
"     `-::l-.l:``   -..--..-.`-",
"     -` -::-ll++:`.-....:..-..",
"        `l--ll+l::..--:ll-..` ",
"       -llll+l:-:lo+l+ol:--.` ",
"   ..--l`  -::+l++ol:....-..- ",
"  ....--  -l+ol:++ooyyl..-..` ",
" .--.`   ++  :ossyyhy+sl``.   ",
"-.`     ls.   ::::l+ds`:l.    ",
"        o:     .-:l.`   :+:   ",
"     `.:o:      :.       ls.  ",
"    `-`                   s.  ",
"                          -l  ",};

char pidgey[17][31]=
{
"     ``-:-.                   ",
"   .::llos:.                  ",
"  `+o+oll:::-`                ",
":lll+:ooMNho-`                ",
"  ++o.`.sdhso                 ",
"  ll:``.sooss+`               ",
"  .````lloo+ll+l:.            ",
" .`````.ls+llllll+s:   `--.`  ",
"`.`````.:lo++++l+osy-l+++++o+-",
"--`-``--llsssssssyysoyyyysooo-",
" ::lo-:++llyyyyys+l:-o:::-.`  ",
"   -ll:ll::losso+--.-+        ",
"     `.-:::::::ll:::.:        ",
"   --:::+o+:++l.    ``        ",
"  --l:+l+oo++l:ll.            ",
"      .`..:-.                 ",};

char pidgeotto[17][31]=
{
"`-.                     `...` ",
"`.-l-                .:lll:-..",
"`-llll`           `-l:-::l--.`",
"`-ll::+.`---.`   -l:---:l:-.. ",
" -ll::+oll+++l+:.+:---::l-.-` ",
" `-+:l+olyyo+.`lo:---:l:-.`   ",
"  `:+llll-+o+l:l--::ll-..`    ",
"    :lll::l+o+--::l::..       ",
"     `-:``.-l:ll:l:.`         ",
"       .``.-::o+`             ",
"      .---:-:ll+              ",
"`-l-`.--::::l:l-              ",
"..-ll..```.l++:l-             ",
"   `:-    `oos+ooo:           ",
"          .lloollool`         ",
"           ``.-:-``           ",};

char pidgeot[17][31]=
{
"                              ",
"`.``                 .-       ",
".-:-:::-:.`         `ll.      ",
" `---:::::ll:.      .++:      ",
"   ---:::::-:+:     .+s+      ",
"    ``:::-:---+l-...-os:```   ",
"     `--.::::::l++l:l+++o+l:- ",
"         `.::::::::-.sodyl:++.",
"           ``-::::-:+ooso--:.`",
"              ..ll:------..   ",
"               -ol....``..    ",
"              `l+-...```.`    ",
"              -+:+l:...`      ",
"         .-:++o++l:-:l:       ",
"      -:l++++ooo-             ",
"      `.-::llll:              ",};

char rattata[17][31]=
{
"                              ",
"                              ",
"                              ",
"                 .:ll:.       ",
"                 .l+oo+l-     ",
"       `.         `-:- .l:    ",
"      `++o-      ```     l:   ",
"   `  -++ll::-.:+ll+     `o`  ",
"   `-:llllll+++o::lo` ``  +.  ",
"   `++ll+o+o`ooo::+ollll+:o`  ",
"    :--::..--l++++++++++++l   ",
"`-:l+..oo+:-..:+++l+llll+l+.  ",
"`...----l::l.-l+l++l:-.l+++o:`",
"        .---`:+l+o+++-.`.:+ool",
"           `.l++:..`     `:::.",
"           -..-`          .`  ",};

char raticate[17][31]=
{
"                              ",
"                              ",
"       :l                     ",
"``    :oo+-:-`                ",
" .-`.-lll+l+osl+ooo+.  `.-`   ",
" `:l----lol+oosoooo+`     --  ",
" ``:.`l.`-l++oo++++`       .: ",
"   .:-++``-l+oooooo+.       :-",
"  `.-.l:```:llooooooo`      -l",
" `:lll-:.``:ll+ooooool     .::",
"  :---`.``.l+loooooo++.  `.ll`",
"     -..``.-:l+oooooool:lll-` ",
"    `-ll-::::::looooo+ll:.`   ",
"   .-+l:::-::::+oooo:         ",
"     `     `l+l++l+.          ",
"            ``  :.            ",};

char spearow[17][31]=
{
"                              ",
"                ` --`.:-      ",
"                l++ll+l:l:.   ",
"               :ll:l++oo+:.   ",
" `.```..``    `-l+s+loooool:-`",
"  -..`.::l+l-`.-+l+oooooo:.`  ",
"  `-.:::ll+ll+l+++oooooo-     ",
"    l+llllllllloho+++oss-     ",
"---..+oo+++++++oyy+ooods-     ",
" -+ooossssoossssl:l-:+sl      ",
"   -+osso++oo+l-.---:+l       ",
"   .--.  `:--:::::::`         ",
"          ---.```:l-          ",
"          -l`    .l:-.``      ",
"      `..:::`` `-``-:-.:.     ",
"       --```.-.               ",};

char fearow[17][31]=
{
"                              ",
"                              ",
"                              ",
"         `-.-                 ",
"        -:---..          ` `. ",
"        ll++l::`      `:l:.--.",
"        :l+oool-    .loo++l--`",
"        .ooooso:  .l++oo++:.` ",
"         +oosssl `o+++oo+:.`  ",
"      `. .lssool`:o++o+l-.    ",
"     `ll:  -ollllo+ool:.      ",
"     :+++---l+++o+o+:.`       ",
"   `.ll+-`  :l++o+++:--...`   ",
"`....:``    .::+oo+o+l++l-`   ",
"`               .l.-:-        ",
"                -:`.:-        ",};

char ekans[17][31]=
{
"                              ",
"                              ",
"   `..--:::-                  ",
" `-:::l:::oo+`         -:.`   ",
"-::l:ll+loooool.        .::.  ",
"`-::ooooosooooo+:`       -:l. ",
"   `o:-:lsoooooo+:        ll+`",
"   `l++++looo+lol-        llo:",
"     `-l:lllllll:--..`    l:s+",
"   `-:+ooo+++osyyysssol  lloy-",
"   l:::l++ooooo+lllooss:ossyl ",
" `.+o++lllllllll+ooossyyyyyl  ",
".l:l+ossssooooooosooosooss`   ",
":+ol::llllllllllllllosoooo    ",
" :ooooo+++++++oooooossso:`    ",
"   `-:l+++++++++lll:-.`       ",};

char arbok[17][31]=
{
"           `.--:lll:.         ",
"         .---::l+oooo+:.      ",
"       .ll-::llooyoooooo+:`   ",
"      .+slll+ssshysyyssyyo+:  ",
"      -oohssssyhdhyyyysshoo+:`",
"       losyssshsshso++shyoosl-",
"        losyyysooyooosyyyoooo:",
"         .lsyhhdhyyyyhhhsoos+`",
"  ``       .+oshhhhhhys++o+l. ",
"  .+l       ::-++lll+++ll-`   ",
"  -ol      .:::llll:+l-`      ",
"`l++     .-::-::lll+so+o+l-`  ",
"l+++:::loo+::-:::::oossoo++o. ",
"`:ooooosoool::llll+++o+++++o+ ",
"   `--:::--llllll+++++++++s+` ",
"            `-::ll+++ll::-`   ",};

char pikachu[17][31]=
{
"                              ",
"                              ",
"    .y                        ",
"    .ho.                   `. ",
"    -.-`      ``..smmy.  ..`.`",
"    -.-....`.--.-+y+. `.-....-",
"   --...+y:.-:-.`    .------.-",
"  -s-lll.-l+:-:    .:------.` ",
"  -l-:so-:++:::-   `::::.`    ",
"   -::::---:l::--   .ll       ",
"-:-....----::::---`l+l-       ",
"``....-......---..:-+o-       ",
"      -...........-ls-        ",
"      .....-------:l-`        ",
"       .:ll:---:llll          ",
"         .l`      ll          ",};

char raichu[17][31]=
{
"                              ",
"                              ",
"                              ",
"  .-         .--`             ",
" ``++     `+sl-               ",
" ``-y:.--:+s-.`.              ",
"   `:+:::l-:`                 ",
"   `-::::::l.                 ",
":+:--....:lllso:   --.`       ",
" ---``````:llll-----::::.`    ",
"   `  ````--..`   `-:::...-.` ",
"   ``````.lll:-      `-.   ```",
"  :-:-::-+`.-.        `       ",
"  --  -l-:-                   ",
" `:--:l+.                     ",
"     :so`                     ",};

char sandshrew[17][31]=
{
" `l------::-..--:`            ",
"  ol:....-::::+-+             ",
"  :.:-:-:l----++-             ",
" `:---:---:-ss+lo:`           ",
" .so--:-::syms+l+++.          ",
" `:+..---.-l:+l++ll+`         ",
"`l-::-``.:::l:.-lo+l:         ",
"-::::l:::-l:::::lo+ll      `.:",
".l--:l--:l---l:++o+o+...-::l+:",
" `ll:-``.--lllll-.-:looooooo+ ",
" -.-:````````-:..---l+ooo+ol  ",
" -l::l:....--l:::-::l+ooo:`   ",
"  +o++oo+-::::ll+l++oo:.      ",
"`-:lo+l:`      -:+++++        ",
".```             -l::+`       ",
"                  `.-.        ",};

char sandslash[17][31]=
{
"                              ",
"                              ",
"           -  +: +-  .        ",
"        .l:yyo:oyys+.y+ .:    ",
"       ..:syhhs-:syyhsyslo++: ",
"     `lsssyhhhhy+lsoy:ls+:++--",
"  -:l+shdhhhhyhhs:s::lll:   --",
"   -syyhhysooosys-ho-::o.    `",
"  .syyyhdhyosss+::ll:-:.      ",
" `lossyys:--:l:::-::::`       ",
"  `.:+osl-::-:::l:l-````      ",
".:l+++l++lll::+ool.........`  ",
"       :++-`  l+-   ``````    ",
"       -::-   ..              ",
"        -:-                   ",
"        `-.                   ",};

char nidoranf[17][31]=
{
"                              ",
"                              ",
"    ``    .: `    ``.`        ",
"   :.....:ll:l+:---:l:--.`    ",
"  -..````.ll-.-:osyyyyys+:-.` ",
"  -:`+l...---..-osssssyyyyl-..",
" -l:los-..-::::--osssyysss:   ",
".`-l:+l:..-::---:..:+s++l-    ",
"  ` .--.....--......:l:l::`   ",
"     l...............:-l:     ",
"    .............-....-:+-    ",
"    --:-...:.....l----l+:     ",
"    `l-ll--l-..:--:---ll`     ",
"     :lll:-:+-.--l:::lll      ",
"    `.-l-  `-l-::-ll+ll:      ",
"            `---.   ``        ",};

char nidorina[17][31]=
{
"          ` `-:`              ",
"         `l-lll-         ``.  ",
"         `llll++-   -..-:ll.  ",
"        `:lll+l+.  -:+syhhyl:.",
"         `:++:---.:lsyssyss+. ",
"          `l:....-:o+++oysol  ",
"    `.`   `l...--:l::lo+l-`   ",
"    `-....-+:-::l+l::::       ",
"    -l:.--:--::::::::l.       ",
"--.`.:l.-.--:l++++ll+ll-      ",
"-lll:.:..---::+:--:+llll`     ",
" -l+::..::l--:::-----:::-     ",
"  .os:..-:-::::l--l--:::`     ",
"   lll+::l--:l::loo. ```      ",
"   .lllll`````-:l::           ",
"    .-.:.                     ",};

char nidoqueen[17][31]=
{
"                              ",
"            -:.`` ..-llll-    ",
"          `-ll++++osyhyss.    ",
"          +++++o++ooyyyoo`    ",
"           -lo+ssl:+ool:`     ",
"             l+:::-loos+-     ",
"          .-:ol---loo++l-.    ",
"    ``..-l++:-+l++o+o+ll++`   ",
"  `:l++++oo-..-lll:-l+oool`   ",
"  `loooo+--:--:l+-.--:l++oo`  ",
"   .--+:.-llllllllllllll++o`  ",
".-....o+lll-.-:lll++++oooo:   ",
".osssssl++ool:::l:llllso++o:  ",
" `:oyssoosooso+l::l++ossssso  ",
"   `-oooosssoooo+l:.  lssosol`",
"   ``.-:-:.`           ...-..`",};

char nidoranm[17][31]=
{
"         `::                  ",
"        -oo+l       `.-l.     ",
"    .`-+ooooo`  `-ol+oso.     ",
"    looooooooo`-losyhhhs:`    ",
"    +oooooosss++syhyyyhl      ",
"   -ssssssssooyhhyyyyys- `::  ",
"  .syssssss+ohhyyyyyys:.l+l`  ",
"   lssso++olyhyyyysssyooo+.-:.",
"   `s+::::++hhyyssssysssysso-`",
"`-:llll:::+oyshyssooooossys.  ",
"`.l+ssl::looossoooooooooosy-  ",
" `ll+l:::omooosoossoo+ll++o-  ",
"  :::l+ol+oooosssooo+::++++o: ",
" .o++ooo+l+++oooooos+l:lll+o+ ",
"`--:.-.`::::l+o+l::ll+o+ooo+. ",
"       `-.-:-.        ::l:`   ",};

char nidorino[17][31]=
{
" `:                           ",
" -l`-        `.      `-`      ",
" lll:        :-    `-:`       ",
".lll+     . -l..l`-:::-l:.    ",
":lllol`  .l.l++l+ll+++o+.     ",
"-lllo+l. .:ol++losssosol-     ",
".ll+o+o``::+++ossssosoool     ",
"`l+oooo-:::llossoo++o+o+ol:   ",
" `-+ool:-+lllsssoo++++sosos:  ",
"   .+::::llllosso++so++osoool ",
"   -ll:::::l+++oooooooo+:lll:.",
"  `:lll:::+ll++oooo++o+       ",
" ..++::::++lo+oooo++os+       ",
"  -oo:::l++ol````.ll+ssl      ",
" `..--l+:-.`      `loooo.     ",
"                   .---.      ",};

char nidoking[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"    `:`     .`:--`            ",
"    .sy+.-.:osyyo.:           ",
"     -sy+++oyyysoo:``.`    `- ",
"  ``.:+ol++++oos+l+l+ll::` -+:",
"`:llll+++l++++++++ooo:+l+l.+o+",
".l++:.` --:l+l:::+so+l+++++ool",
"  .`    `.l:--:::l++osooooos+`",
"       -:l+....--ll:loyssso:` ",
"       l+oso+-:llo+l++oo+-`   ",
"      `..-:-`  `.:l+l+o+      ",
"                  ....-`      ",};

char clefairy[17][31]=
{
"                              ",
"  .y+::.`    `.``             ",
"  .mso:`.....````..`          ",
"   Nd.`.`.:.``-...`-:....l+++ ",
" ..hd:.....-`....:`...```:shs ",
"--.`l+````..----:.````.`.:mh` ",
"..``.--```-o.```:-.````.ods`  ",
" -``....---.--:----..``.sl.-.`",
" `-...``````-::-`..-..--.```-.",
"  -...```````..``````````.`.-`",
"  ..````````.````.````..::l-  ",
"  .--..```````````.``..-ol::  ",
"   :-:-.............---++:l.  ",
"   .---::---.---------:lll.   ",
"    ------:-..::::---ll-.     ",
"     .---.     .::::.         ",};

char clefable[17][31]=
{
"                              ",
"                              ",
"   -+l-                       ",
"    ll..```  ````         ``` ",
" `..`-.```..-`.....`````.-ss: ",
"  .:l::-.```....-```````.--`` ",
".-::..:+.```.....````.------- ",
" `.l.``...`.-...-.```-ll:::.``",
" `-:l-```.```...````....`-l:-`",
"   ``-..``````````````.-l+:.  ",
"     -```````````````.l:---`  ",
"     -.````````````..-:l-.-   ",
"     .-....```.....---ll--.   ",
"      -------..------ll::-    ",
"      .--.--`-::-.--:::-`     ",
"       `---.   .----``        ",};

char vulpix[17][31]=
{
"                              ",
"                              ",
"                              ",
" `   .::ll:.                  ",
" sol-++++l+ol                 ",
" lhol+++oo+++ll-`-ll++:--.    ",
" `+o++oo+oydddyolll++llll+l.  ",
"ls+++ooo++ssllos+l+ol++o+++l  ",
"`lo++++++++..osoo++o++o+llll:`",
"  .:l+++++l-.:ososoo+o+++++++l",
"     l:+++++++++++ooo+++o+o++l",
"     :..l+++++++++++++ooooo+- ",
"     `+++++++ll++++: `l++ol   ",
"      .ooo++l-ssl+++   `.`    ",
"      `ssyss-oy+ oo+          ",
"      .:ooo- `` +oo.          ",};

char ninetales[17][31]=
{
"                              ",
"                              ",
"         `````      ``..```.` ",
"     ```.``````. `.`:.``...`  ",
"   `` `````..```-.---....-``.`",
"  `.``..````.-..:......`...   ",
" `  ```.-...--.-::-..... .`   ",
".``.````.-..--:--::.`.```     ",
"`.`......:-:-:-:::-``````     ",
" `..--.--:-:-::::.-.```-`     ",
" ``....--::::l:-....:::-      ",
".   `.....:ll:.`.::.l--`      ",
"`.`.` ``.```-.....`.-...:-`   ",
" ``..``.`````....--:::   `-`  ",
"     `....`````.-::-...       ",
"          `````````.-         ",};

char jigglypuff[17][31]=
{
"                              ",
"                              ",
"      `:-..                   ",
"      :md+...```..`           ",
"     .odmy:.--`````..         ",
"     :l:..-..........-```     ",
"    ......-.....----....::-..`",
"   -..-os:o....:l--....-mmNml.",
"  `--`syyys---:::.-:-...+hsl. ",
" `-..--:ll-....-.sh+s:..-:.   ",
"-.-:-..-..--...-:ysyyl..-     ",
" `.::--.....-...-::l:..-.     ",
"    .::------.......--:.      ",
"    `-l::::::::::l..l.        ",
"   -...:l--::::llll:-         ",
"    ```         .----.        ",};

char wigglytuff[17][31]=
{
".```                     `... ",
".`ls+:..         ```   `-:l.` ",
" ..+shhol.     `-.....-:ydl-  ",
"  `.:+hdds:-...:..-...:hh+-`  ",
"     `.:oso-```-.....-lol.    ",
"       `...`.-:o+----lll-     ",
"       -````.+oyy-...-os:-    ",
"     .......-:::`----.--.-... ",
"      ---.....```````````.::-.",
"     `-...--.`````````````-`  ",
"     -:-...``````````````.:   ",
"     -::::.``````````....--   ",
"      .:::..............-.    ",
"        `::--......----.`     ",
"         :---.````.---..-     ",
"         -....                ",};

char zubat[17][31]=
{
"                              ",
"                              ",
"`-l+s+`                       ",
"    `:+ssssy-`.               ",
"  `looooossy.+yo`             ",
" :o+ll+ssssy:lhh+:.`.--.   l- ",
"--..-lssoosys`hNNMhyhss+ `+ss`",
"     ..`.-:oysoyydmll-.-lsoos:",
"            +ssooss+oosooy++++",
"            lssss+::l+++os+++o",
"           -- `l:    `:+solll+",
"          -`   :       -l::ll:",
"         -     -           .+`",
"       `.      -            ` ",
"       `       -              ",
"              .`              ",};

char golbat[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
" ::.                        ``",
"  :l+:`               `-:ll:. ",
"   l++ol.          .l+o+ll`   ",
"   l+ooos.       .+oo++++-    ",
"  .oooso..``..   -soo++++.    ",
"`-++++y:lsooos:  .soooo++l`   ",
"`-:llsssymmmhys-:+soo++l-.`   ",
"   .+ssshdmmmhyso++so+`       ",
"    -.`+hhmmmssl:::+o`        ",
"    -+-ommhhysll.   `         ",
"     o:`l++l:++.              ",
"     `      `o`               ",};

char oddish[17][31]=
{
"                              ",
"  -l`        .                ",
"   l++:    -+yl               ",
"  `o+o+o`:shhyl-::ll++++s`    ",
"  -ssossyhhhyyso++++++++y-    ",
"  `sssysyhyssssooooosyyoo+-.` ",
"   -oyyyyyyyysssssyyhhhhhhsol.",
"   `.lssyyyyyyyyyyyysssooo+:.`",
" .l++lll+++syyyyysssso+++++l-`",
"-ssss++++oossyyoosssssso+-`   ",
"osssssossssssss-``.....`      ",
":oossssssssssss:              ",
" .+ssssssssssso`              ",
"  .shysosyys+-`               ",
"  yhhh:.yhhy                  ",
"  oss: lhhhs                  ",
"   `   `+o+`                  ",};

char gloom[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"           ..:oosol.        . ",
"        `lsosyhyyhysyo:     :l",
"   `:+sshyyyhyssosyhsyhl   :+l",
" `l+ssssyhhhhhysyyyhhhhsl+sss.",
".o+::-:sssyyhhhhhhhhhhyysys+. ",
"+l   -+oosssyyyyhhhhhys++o-   ",
"++-. ool-ooosooosyysss+-+os`  ",
" ..  :o loosssso-+yssso  +s.  ",
"      .:syssssss.ossyso-.`:   ",
"      ll:`lshhhhyhhy+-lo+.    ",
"         .-+y.---+s:-`        ",
"       .++l:`     -l+++`      ",};

char vileplume[17][31]=
{
"                              ",
"                              ",
"                              ",
"                .---llllll-`  ",
"         `--::++ll++llll:+++l`",
"      `-:l+oosyooso+::lll:l+o+",
"    `:+++ooys+ooo++ll::ll:+oo-",
"  `-l:ll+oooo++o+++ll::+ooo+. ",
" :l:l::l+lllll::-:+oo+oool.   ",
":+l:l++l::ll:ll:ll+oyy+-`     ",
"loooos+++l+ll++oosyhhhs`      ",
"`-l+++++++ossyyyhhhhhhy+ll-   ",
"      `.-:oyyyyyyyyyyyhl::`   ",
"       .ll::ossyyyyhhs:       ",
"           .-lyslll:y+-..     ",
"          l++l-     `l+oo:    ",};

char paras[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"       `--:l+:      `..`      ",
"      .-:-lll+    :l--:l:.    ",
"      -llloss++ll:ol:l:::l`   ",
"       `.:+++++oooosoo+::o`   ",
"   `.--:sll:::ll:++sssy+-`    ",
" `-::l:ss+llll+:sdl+soss-l:`  ",
"`l:lll++o+lll+lllll+l::+so++o-",
"l:lll+: ::oy::+++olll:l+-:+l.+",
"llll+-    ` .`` -lll:l+l   s` ",
".+++.           :llll+l    .  ",
" .l-            :+lol-        ",
"                -:-`          ",};

char parasect[17][31]=
{
"                              ",
"                              ",
"               .-:l::-.       ",
"             -::::::ll++`     ",
"           .l:::ll:::llo+     ",
"        `.::llll:lllll+oo.    ",
"     `-:l::::::::lllllooo:    ",
"    :l:::::lllllllll+ooo++`   ",
"   .ll+++l-lo:-+++l++ooo+ll.  ",
" `:::l+oy+::l::odds+losoooo+. ",
"`lll+++ssysoo+osy+l::+ydoso+. ",
":l++ooo:-ol-l+os+ll:l+o+lol+- ",
"ll++.s-:o.     :llll++`  :+:+l",
":l+` ..-:      llll++`   l+`.+",
"`ll            :ll+-   `:l` ` ",
"               -:.            ",};

char venonat[17][31]=
{
"            ``.-.             ",
"             -` .-`           ",
"`.........`` `ll-`.-          ",
"`````.-::lllll:+++:+ll``      ",
"      `.-:l+o+++++o+os++.`    ",
"       `l++++o++ll+o++s+ll:`  ",
"       .+o++o+llllloooos++++  ",
"      .oooooso++l++soo+++sls- ",
"     `+osooooooooosoos:ssysys`",
"     .`lyssosooosssosssssyyys-",
"       :ssssssssssolssssyyyol`",
"       -ysysssssssssysyyyyyy- ",
"        `.yyyyyyyyyyyyyyyyo.  ",
"          `+soyyyyyysyyy+l-.  ",
"        `-::::+...-.`-lo:-:l` ",
"        .:l:-.`         ```   ",};

char venomoth[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"`......                       ",
"...`        `      `..........",
"......`    :`    ...........` ",
" `....-.` -:`. .--.........   ",
"   `...-:-:::.----........    ",
"    `----ll:sl+::-......``    ",
"      `.-:l++++l+:::---       ",
"       .----::lll:----.       ",
"       ``   `.-::` ` ``       ",}; 





	











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
case 10:
memcpy(pokemon,caterpie,sizeof(pokemon));
break;
case 11:
memcpy(pokemon,metapod,sizeof(pokemon));
break;
case 12:
memcpy(pokemon,butterfree,sizeof(pokemon));
break;
case 13:
memcpy(pokemon,weedle,sizeof(pokemon));
break;
case 14:
memcpy(pokemon,kakuna,sizeof(pokemon));
break;
case 15:
memcpy(pokemon,beedrill,sizeof(pokemon));
break;
case 16:
memcpy(pokemon,pidgey,sizeof(pokemon));
break;
case 17:
memcpy(pokemon,pidgeotto,sizeof(pokemon));
break;
case 18:
memcpy(pokemon,pidgeot,sizeof(pokemon));
break;
case 19:
memcpy(pokemon,rattata,sizeof(pokemon));
break;
case 20:
memcpy(pokemon,raticate,sizeof(pokemon));
break;
case 21:
memcpy(pokemon,spearow,sizeof(pokemon));
break;
case 22:
memcpy(pokemon,fearow,sizeof(pokemon));
break;
case 23:
memcpy(pokemon,ekans,sizeof(pokemon));
break;
case 24:
memcpy(pokemon,arbok,sizeof(pokemon));
break;
case 25:
memcpy(pokemon,pikachu,sizeof(pokemon));
break;
case 26:
memcpy(pokemon,raichu,sizeof(pokemon));
break;
case 27:
memcpy(pokemon,sandshrew,sizeof(pokemon));
break;
case 28:
memcpy(pokemon,sandslash,sizeof(pokemon));
break;
case 29:
memcpy(pokemon,nidoranf,sizeof(pokemon));
break;
case 30:
memcpy(pokemon,nidorina,sizeof(pokemon));
break;
case 31:
memcpy(pokemon,nidoqueen,sizeof(pokemon));
break;
case 32:
memcpy(pokemon,nidoranm,sizeof(pokemon));
break;
case 33:
memcpy(pokemon,nidorino,sizeof(pokemon));
break;
case 34:
memcpy(pokemon,nidoking,sizeof(pokemon));
break;
case 35:
memcpy(pokemon,clefairy,sizeof(pokemon));
break;
case 36:
memcpy(pokemon,clefable,sizeof(pokemon));
break;
case 37:
memcpy(pokemon,vulpix,sizeof(pokemon));
break;
case 38:
memcpy(pokemon,ninetales,sizeof(pokemon));
break;
case 39:
memcpy(pokemon,jigglypuff,sizeof(pokemon));
break;
case 40:
memcpy(pokemon,wigglytuff,sizeof(pokemon));
break;
case 41:
memcpy(pokemon,zubat,sizeof(pokemon));
break;
case 42:
memcpy(pokemon,golbat,sizeof(pokemon));
break;
case 43:
memcpy(pokemon,oddish,sizeof(pokemon));
break;
case 44:
memcpy(pokemon,gloom,sizeof(pokemon));
break;
case 45:
memcpy(pokemon,vileplume,sizeof(pokemon));
break;
case 46:
memcpy(pokemon,paras,sizeof(pokemon));
break;
case 47:
memcpy(pokemon,parasect,sizeof(pokemon));
break;
case 48:
memcpy(pokemon,venonat,sizeof(pokemon));
break;
case 49:
memcpy(pokemon,venomoth,sizeof(pokemon));
break;




default:
break;
}
memcpy(holder,pokemon,sizeof(pokemon));
///end program
}
