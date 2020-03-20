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
//http://www.unit-conversion.info/texttools/replace-text/
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

char diglett[17][31]=
{
"                              ",
"                              ",
"                              ",
"         `--:::::::-.         ",
"       `::---:::llllll-       ",
"      -l:ly::llssllll+++      ",
"     `++loslll+yoll+++++:     ",
"     :++ol----lo+++++++++     ",
"     :+++++ll+os+++++++++     ",
"     :+++++++o+++++++++++     ",
"     :+++++++++++++++++++     ",
"  `..l++++++++++++++llllo.    ",
" :loos+o+++++++++llllll+soo+- ",
"-ooo+::osoo+ll++o+llllooo+soo.",
"lllsoo+osoool+ooooo+oososo++l.",
"   `-:...-:+oo++llo+l+ooo-.-` ",};

char dugtrio[17][31]=
{
"                              ",
"                              ",
"              .-:llll-`       ",
"             :llyllso++-      ",
"            :++++:looooo      ",
"      `--:::+oooooooooos      ",
"    `:lll+llo+osooooooso      ",
"    llll+y++s+oyssso++++-.    ",
"    o++++oll+oosssl+oll+l+:   ",
"    o++oooooooossoo+l+so++o`  ",
"    +ooooooooo+soooo++ooooo`  ",
"    loo++ooooo+ooooooo+ooo:   ",
"   .+o+ooooooo+osssooo+++s-   ",
"`:++l:losoolloooooosssss++o:  ",
":l+llooooooooss++++++oosssooo:",
"   ```.---::--::o+:-:l:l-`````",};

char meowth[17][31]=
{
"          ..     .`           ",
"      `+l+:-``` `-   ``       ",
"      .dyhd-l-.:-+ssyyh:      ",
"  `.```d+-.`:--:.oooohNl-...  ",
"    ``.-.-.`........:ds`-::-. ",
"  ```....:..```..l`.-:--..-`  ",
"       `.:ll:----:--:l----.`  ",
"       ``.-l+::l+::::-``      ",
"  ```....`...--::.``          ",
"..``..`  ..`````-             ",
"-....`  `-------`      `-:ll- ",
"    `.-...   -:-:-.`   -+oyy+-",
" `:l+++:`   ...` `.---.:+++l- ",
"  -ll:`    `+ll               ",
"          `+++l               ",
"          .++o-               ",};

char persian[17][31]=
{
"                              ",
"                              ",
"                              ",
"                 ++l```.:l:   ",
"                 ll:.`::l++   ",
"                 `-:-.--:-    ",
"                .-:::-:ll:`   ",
"                 ..-:ll::`    ",
" ````     `````.....--::`     ",
"..-...  `............---      ",
"..`.`  .`......-`..:::::`     ",
"`..```.:...:++::..-`.-::-     ",
"  ``..:::.`l+l`--.    .---..` ",
"     `.-.   :l:--`        `-:-",
"      .--``  .::..`           ",
"       .--`    `.--.          ",};

char psyduck[17][31]=
{
"              -: :y.          ",
"              -h+dolo+        ",
"       ........-l+l-.         ",
"    `-::-.........-----..     ",
"   -::l`  -...-.``.-:l----    ",
"  .l:l:------------::l----:.  ",
"  `l:-.  ``.````-::::l------. ",
" `.`    ```````.+::::+------: ",
"  ..``````````.::::::l::::--: ",
"    `.-------------:::l:::::  ",
"     -.............---:::::l` ",
"-::--:............---:::::::- ",
" .:ll+:-----------:::::-::-l..",
"   `-l+l::::::::::::::.:::::. ",
"       `:lllllll:--..--::--`  ",
"       .....---l`             ",};

char golduck[17][31]=
{
"                              ",
"                              ",  
"           .- `-:             ",
"         +-ll-l+- ``          ",
"         +l:ll++++-           ",
"      ```+ll+++o-             ",
"  ``-ll+:.-:+oool:.....     .:",
"`:l++.`.``:loooo+o++lll   `:+-",
".:.:`     `-l+++++++l+``-loo- ",
"           -llllll++:oloos+.  ",
"         `:l+++++olllooo+-    ",
"        .l+++:lll+lll+o.      ",
"       `.oooo:- ```:ooo:      ",
"     `:ll++l.      loooo-     ",
"     ```.`        `:::+-l-    ",
"                   ` .-  `    ",};

char mankey[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"-::         ```               ",
".::+-  -:..`..`.`-`    -::    ",
"   -.``.l.`````.l+.   -lll:   ",
"   ``.-.`````````--```..``.-:-",
"      -``--..:.`.--.```` :l:+-",
"      `-..--:-.----  ```.-::. ",
"     `.:l:.-----.`.---...`    ",
"    --l+-`      `.l.          ",
"    ` -`         :o+.`        ",
"                `:. --        ",};

char primeape[17][31]=
{
"                              ",
".--::lossl                    ",
"       -llll+syhmml`          ",
"       -l+++o+ssoo+ol.        ",
"  `---.   .-l:--`.l+o:        ",
" :++l+l  ...:l:.:l+oo` `      ",
"-oysll-.-...--.`.ooo+::`      ",
"lodo  -l.``.--``.l+ol:l.      ",
"`++-  `-`..--..`.-::llll-     ",
" -ll++l.-:-::...-:l+osloo..`  ",
"  .-:::-.-::-.--::+sss+hoool. ",
"        .:--::::llll++oossss+-",
"     `-:+soo++llllll.:osool::.",
"     -l+s+oss+``.-:  `-::.    ",
"       -osssl-                ",
"        -lo.                  ",};

char growlithe[17][31]=
{
"                 `..---.      ",
"               .-....--::l.`  ",
"              -.-----:::::-`  ",
"           :+::::lll+++oo+:`  ",
"          ls++:lsy.:ll+o++++- ",
"          -:l:...-.-::++++:-` ",
"          `-------::--l+l+-   ",
"   ``````.```:-:---------::-.`",
" .:---...---::.....------:+l  ",
".-:::-----:oysl.....-----::l-`",
" .:l:::lllsoh+lll-:---:::::l: ",
"`...::oyo:::++:::ll+:::::l++- ",
"     lsssl:lloss+lllo:::oo+o  ",
"     :y+llll+llloyddyo+oshh+  ",
"      :++l++ll+l::l+lo+++++l  ",
"       -----`` ::-l-::l-:-:-. ",};

char arcanine[17][31]=
{
"                              ",
"                              ",
"      . -.`                   ",
"   `-::..---.`     `..        ",
".::l-:...-ll+:  `....:`       ",
" -l++l--l+llo:`.....-...`     ",
" .---:l+::-::l-------l:::.    ",
"  `----:-:ls+ll::::::lll:l-`` ",
"  `.--.---l+ys++++s+::l::::l-`",
"  `-:....-:+oyhy+oyys:`.:...  ",
"   -y:--:+oyyhss+oyhy`.`--:   ",
"    ++o+l+:ly+loossyh+----`   ",
"    :+hy+olys..+ss+++:::::    ",
"    -s++.-sy+++ss::lllll.     ",
"   .llll .lllll:--++ol``      ",
"   `...``::l:`    ```         ",};

char poliwag[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"   `--:lloo:.                 ",
" `:yhs+ll+ys-o:`              ",
"`l:+ssl::l+l+oo+.             ",
":lll+:--:ll+l:loo             ",
"++++:-l++ooo+o-+s.            ",
"looo:lls+:oooo:o+             ",
"`looolo+ooooooos+:.           ",
"  .l+osss+oosl-osoo-------.`  ",
"    ``sso-`.-+++++l:::::::---.",
"      -o++:   .-::ll++lll:-..-",
"       .-:.      `..-------.. ",};

char poliwhirl[17][31]=
{
"                              ",
"                              ",
"                              ",
"`...-..`   `                  ",
":-::l::l.+l+ol..--::.         ",
"`-l::::-+o++oooolysyo-        ",
"   .-+olll++l+oooysso+`       ",
"     .:-:llll+:looooooo`      ",
"     ++olollll+::oooool--...` ",
"     +ossosl:y`y`oooos+-.....:",
"     -oo+loo.o-y`sosss+-.-.--:",
"      -+oo+loly-+ssss: -:::-. ",
"        .-llo++ssso:`         ",
"        `.lso:-.:ss-`         ",
"      .+++oo+-  oo+++:        ",
"       ...`     -ll++l        ",};

char poliwrath[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"          `-:---:ll:          ",
"         -l:+++++::o+:`       ",
"       .+ol-:+ss+l-:ooo+---.. ",
" .....:osl.o+oo+olo.loool.....",
"-..:::ssso-o+sos++s-os+o::...-",
".::l:ll-`+sos++++oossl  .-..` ",
"          lss++++oss+         ",
"        `:so.     -ss:        ",
"     `l++ool       ooo:-`     ",
"      ...`         .:l++l     ",};

char abra[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"          .....----::.        ",
"          -:----::ll:`      ` ",
"           :----:::ll`     `:.",
"           -::::l++ll.     -::",
"           `+ollyNy+os+   -l+:",
"   ```     `lys+ohhso+-`.-::+.",
"``.`l+` .-``:o:lo+ll::l++++l. ",
"..:++ol::l+llyl+lll:ll+so+-`  ",
"   .+++:::l:.++l++o+oll-`     ",
"   `:l.      --.-:----:.      ",};

char kadabra[17][31]=
{
"      `-+loooo:-:-:-`         ",
"        `++:.--`````          ",
"        `:ll:-`.-             ",
"         -l.l+l:l-.      .-`  ",
"         l+++l:--:l:`  ::+o:-.",
"        `ssysso+ll+ol. `loo+:`",
"    ``.-:yyyyolloyhdhl``:+:`  ",
"   .---::+sys:+o+oshyl:l:.    ",
"  -:::::++sslssyyyhyl-        ",
" `::l+lo+looosys+++-`         ",
" `::loysooool:l+l+ool:-.      ",
"-.:l++oso++l+osooss:l++l      ",
"-++++++-:l+osssss+. .l+:`     ",
" `-::-``:+ol:::-`   -::::ll:-`",
"      -l:::l:            `l-..",
"      --   --                 ",};

char alakazam[17][31]=
{
"                              ",
"                              ",
"                              ",
"          `-`          `      ",
"           -::`    .-:-`      ",
"   `:-.`    :::-:::l:`   `..``",
"  .:---::lsol:-::lll.`.---.-. ",
"  `-:---:++yho:llssoo++l..-.  ",
".::oo:+ss-.-ly+shhyssyhl`.`   ",
"`-+-ll+l-:: `sdddo:--+so:oo:-`",
"     ` :ll-:osossos+lo+++o+l:.",
"      `ssh+.`:+o--ol++.       ",
"  .-.-::l:        .:lo+ll.    ",
" ``:++o++.        .:ssss-     ",
"     lss+`        `:+so-      ",
"      .:`           :l        ",};

char machop[17][31]=
{
"                              ",
"                `.--:--``     ",
"               .----ll+ll     ",
"       `.`    -----::++o+     ",
"  `.--:---:-`:--lyl-:+oo+     ",
"`--:--:---l+l+ll+o::-::s+-`   ",
"-::l--l:::+ll+++ll::::l++++:-`",
" `.--::+ll+lll+++l++`````l++l:",
"       .-..::ll::lll`    .:::.",
"       `--::------:l-         ",
"      `-:ll:::----::l         ",
"      ::lll+++lll::ll         ",
"      :llll.```:::::.         ",
"       ``.`  .ll:l:`          ",
"            -l::::            ",
"            ::::::`           ",};

char machoke[17][31]=
{
"          `--:ll:`            ",
"        .+++++++oo-           ",
"        `-+oooooooo:...`      ",
"   `.-::::::+o+ll:l::::::.`   ",
" .:l+loo+---:::::::::l+oo++:-`",
".llllloo+:::lll::l+o++++ll+++l",
"l++ll+l``.s+ooo+yy+lll++++lll.",
"-+l:::l.`lyo+++ohl:::::l+:-.` ",
"`:ll+++++shddhdmhso+ll:.      ",
" ``.-l::l+shddmyol::l+l`      ",
"   .l::lll+l...-::l:::l:      ",
"   :::+o+-`      `-l:::+l`    ",
"   +oooo+          ::+oool    ",
"   :ooo+`          `.loooo.   ",
"`.-:::l+`             ll:ll.  ",
".------`             :lll:::` ",};

char machamp[17][31]=
{
"   .-:-`                      ",
" `:::lo+`           ````      ",
"  :loo:.           -:-:::     ",
"  .:++l`           .lsoss`    ",
"   :+++o-..` ``-.     ::+l    ",
"   `-loo+++ooll+++l.--l:+l.   ",
"   `..-::::::-:l+ssoooool:`   ",
" --::++oo+l:l-l:loll+:.       ",
" ::::oooso--:ll+oo::::-`      ",
" `-:+oo+-+ll:l+++o+--::---.   ",
"   `.`..``ss+oosl-`  .-:l-::. ",
"      `-:::shydy+-.`    :::ll:",
"     `::::lshyol::::-    ``.-.",
"    -+lll:.    .osoo-         ",
"   .+++:`      `oss.          ",
"  .ll+`         :+++--        ",};

char bellsprout[17][31]=
{
"          `......`            ",
"        `.```.....-           ",
"        :........--.          ",
"       -:...:l..---`          ",
"     .--.......--l.           ",
"    .-o+::..--.` +            ",
"    .llshlll`   :-   ``.`     ",
"  -::::ll++++.`l+.::l:::ll:-  ",
"`l::::lll+++++l+l:::::::::lll.",
"`..-l+l+++++lll::::::::::l:-` ",
"     `.---` :l``:l::::ll:`    ",
"           -ll    `...`       ",
"        ```-s+           `    ",
"    `---...-+s.        .:-.`  ",
"  .+.        .+:`    `:ol.`   ",
".-ll`           .---..    .`  ",};

char weepinbell[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"``-:l++:                      ",
"-::::--.`   `......-+.  -`    ",
" .lllll++:`-.``-....:`.--:::-.",
"  -+++++++:.....-..-ll:::::-  ",
"   l++++ls-..lsl--:lllllll-   ",
"   `:lll::--.-l--:llllllll    ",
"    `--ool--:----:llllll-`    ",
"     ::sMdo+:l::--:--..`      ",
"      ::dMdso:l:--`           ",
"      `:omdh+l:-`             ",
"       .-l::-`                ",};

char victreebel[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"         .l+l:---.`           ",
"    `.-::+::::l++:-.          ",
"   -ll:::l:ll+sl-:l`          ",
"  -.`.-:l+odNMMhl `l-         ",
"     ` -omMMNhhsl`  :l   `````",
"  :l:::l+smdyoll:-. `+:-::ll-`",
" `-.l+l++++:::--..:::::::::`  ",
"    :++++o+.....-.lll:::::-   ",
":.` :+++++:.``--..ll:::::l`   ",
":ll:`:+++.``-....-+lllll:`    ",
" .------:-.....---l:---`      ",
"      ``...---:--.`           ",};

char tentacool[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"            `.:-ss+.          ",
"         .---+shhhhyl         ",
"        -l:--+sssssso:        ",
"        ++s:-:+oo+++l:        ",
"        -ll--:llll+ll:   .+l. ",
"         :-:l:l+++++l     :oo:",
"         -ll::++++++l:::-. -oo",
"         .:+sssosss++shNNy -+-",
"         :hmNNmdmNNmdmmmo.-l. ",
" `.--::---``loyddmdys+::-.`   ",
".:l:.                         ",
"ll.                           ",};

char tentacruel[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"           `.:-:o+lol`        ",
"         `+syl-+yhhhhy-       ",
"         lsool+lssoooso-`     ",
"       .-++llool:+++ooolll-`  ",
"       .:::l:l:ll+ys+ll-..-`  ",
"     `` `-loy+shydhyyl-.`     ",
" .::---llll+ll+s+s+ss+::::..` ",
"-l:` .:++l+:+oo++:.:s+ll:::l:-",
".:`.::+.ll+l++-o+` :o.:l.l.l``",
"   `` -` -`:+++-l-.:.:.l-.-   ",
"           ```.-    .``l.     ",};

char geodude[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
" `--:`     ` `.``       -::-` ",
":lossl   .:+llllo-`    -solll.",
"`:lo+`  -llll:+osol-:-::+o+:-.",
"  -:l:`-l:llll+sss:``....`    ",
"   .:::-`.-:l+o+:`            ",};

char graveler[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"         `.::---::.`          ",
"        -:::---::::l-.--`     ",
"     `-:ll:-----ll::l:::-:: ` ",
"   -:::l::::::ll:::ls..:+sysl-",
"  :l+l.:l:l+++++llloo `lo+:-  ",
"`+syol-`+ssossyssyyy:         ",
"-l:-..`  `-osoll:::-`         ",};

char golem[17][31]=
{
"                              ",
"                              ",
"           `.:.-:ll::-`       ",
"         .:+yyllll++++ysl-    ",
"       `+oosyhsoos+yyymdyyy:  ",
" ``   `lylll+oddys++o+sddhhh: ",
" `l+:l+o+++++yds+o+++l+syhddhl",
"`:+osssl:::+shdooo+syl+oohhdhs",
"`` ``o::+o:+++ydyyhhd+:oohmddo",
"     :l+o++osydmmdddmhhhhhdhy ",
"      `.+llshhhdmhhhdh+++ohh. ",
"       `losyhhhhddddd+::::o:  ",
"      `:ssyyhso+hhhhhs:::los` ",
"     .++oo+l:`    ``  .ossssl ",
"      ``             `:l+++sl`",
"                     ``-.`- ``",};

char ponyta[17][31]=
{
"             `-`              ",
"   `.--::::-:ll.              ",
"  .:::l+++l+++-               ",
"  -:::l:-:ll:`                ",
" ``.-oo`.:+:`              `` ",
".````-....:+..    ..-::::-`.l.",
" ``  `.....l+-.`. `::l++++++l ",
"     ```...`--::---++++++l-.` ",
"     .``````````````ll++l.    ",
"     .``````````````:l::.     ",
"     ````-```::l-...:++:`     ",
"      .``+: .+++-`-.-l+-      ",
"       .`:`..:ll.  `---       ",
"      `..  ..::.   ``-        ",
"      :-. ``.+:   .-..        ",
"     .::  lo+`    -:.         ",};

char rapidash[17][31]=
{
"                  `.-...`     ",
"                `-.-:--..`    ",
"            ``  `:ll+l:++l`   ",
"  ` .-.``-..--.```.`-l+++l:   ",
" `::.:ll:-l--:-.`..`..++:-.   ",
"  `   ``  `:l+l:ll-..`-.      ",
"     .-. ``..-..::..````      ",
"  ...:+l-lll:l:::.  ```.      ",
"`-:lll:l++l-````` `````.`..   ",
".:```` -ll:``````````..--:.`  ",
"        `..``.-::-```-.-:::.`.",
"    `````.-`.-:+l-```` `.l+:. ",
"   .--:l--`--l+l-` ``.  l-..  ",
"   `  `:ll-. .llll-.-.  :.    ",
"         .--   `++ll:`.       ",
"          ::`       `lo`      ",};

char slowpoke[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"           ```..-----.`       ",
"           .`````.-:::-:-`    ",
"                    .:::::-   ",
"                      :::ll-  ",
"  `.--.`..`....```.``  +l++l  ",
"  -:-...-:::l::l-----:-+++++  ",
"  ..:-::- `-:ll::::::::::++l  ",
" `........-:::::::::::::::+`  ",
" .:++l::::l:l::::::::::::ll`  ",
"-::lol:ll++:l:::::::::::lll-  ",
"-:::lll:l-----::::::::lllllll-",
" `.-..`--::::::-----:::--..-. ",};

char slowbro[17][31]=
{
"   ..-:.````.::l:`            ",
"   l+l..`..-::+++`            ",
"   `:. ------ -+.       `     ",
"    :.``` ` ``.+-  `.  `:--.  ",
"   `l-:ll++lll:+:  :+-`-ll+o` ",
"   `::l+l:ll+++ll` ::-..-:+o` ",
"   --::llll+++ll:l---:l--:+ol ",
"  .--:l::::ll+---:l.--:::oss- ",
"  --::l+::::l----l+:----+sso` ",
" `:l::l+::::l--:l++:::::lossl-",
"`--:-::-....:lll::::+ssyyyy-  ",
"---:-.`.....--l--:::lssdhys   ",
"-lll+l:----::+l-::lloyhddy:   ",
" -+oooool:ll++oooooosysl-`    ",
"..l-l::-`     `++++++.        ",
"               -..:.-`        ",};

char magnemite[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
".l++l.      `.-:+:            ",
"          `+sss:    `-::+oool ",
"           `.:--.-.-:-oo-` `.`",
"          ..`  .---:::ll:l++oo",
"ls+l:--.`-.. `  ----:ll+++l:-`",
" :++++ool+--...-:ls+:.        ",
"   :l-:o+ooll-----::-         ",
"   .+ooool-----.-..`          ",};

char magneton[17][31]=
{
"                              ",
"                              ",
"                              ",
"      -++.            .:`     ",
"   .l:`lso:` `:++l``-l+ol `   ",
"   :ooo:-sl+`.-ss--l+o:.:lo-  ",
"    `-++o+ll.`...-l+os++l:.`  ",
" .-..`...`:-`.```-::-:::--::. ",
" .-:l++o``:+:-``.:::``+++l:-. ",
"-:-.:+l:..:++:--:ll+--l+s::+o:",
"`-:ll+.`.`:l::  ---`.`-:oo+:.`",
"    `.:``-lol:  lso-``.l.`    ",
"     `:o-:-l++ `+so:-.-o+     ",
"     -+.  `+y+  +yh`   ``     ",
"          .oy:  .sh:          ",
"           oy`   :o.          ",};

char farfetchd[17][31]=
{
"        ``      ll:           ",
".+ol+:`.-l-  `--++o..         ",
":ssyssl.--ll``l+o+o+l`        ",
" .ooss+-::-lo::l+os+l:`       ",
"  `:+oo:-l+:l:syhs:++++`      ",
"    .lll::ll+-oo+l`sl++-      ",
"     -:ll+lll:::::l+ooo`      ",
"     `::lll+++++++++oo+:`     ",
"     :::::ll+++++++++oo++- `--",
"     -:::::l++++++++++++++++o.",
"      -:lllll+++++++++++++++. ",
"       `.::::++++++++ll:::-`  ",
"         .`-``.-ll::::l:.`    ",
"          ...``.ll:` :+:      ",
"          --l:-:::--`:ll:.`   ",
"             ``    ...-:---   ",};

char doduo[17][31]=
{
"                          .:. ",
"                         `ll. ",
"                    .---:ll-  ",
"         ``-.-.`   lloo+++s:  ",
"`...-:---llso+++:  -ossssso.  ",
"      ``-ooooss+-    `sh.`    ",
"          `..y+      lh:      ",
"             .yoll++sho:.     ",
"            .ll+oo++oosoo+-   ",
"            :lllll+++ossso-   ",
"            .l++++ooossss:`   ",
"               .-ll+sl-ll.    ",
"                 ...ll:::.    ",
"                -:..ll  `     ",
"             `..-:lll-:-`     ",
"            `-..-:-`   ```    ",};

char dodrio[17][31]=
{
"       `l:      -.-l-.`       ",
"         -+...-lhhsso`        ",
"          :s+ll++-:yho-       ",
"````  `.-+hso++ol::loo-       ",
"  `-::++osy- :- .+++o+:-...`  ",
"     l+osss` ..  `oll-  ``  ` ",
"    `-    --``:..-:           ",
"           `-l++l+++:         ",
"            :l:::l+oo-`       ",
"            `os+ssssy++l::-.` ",
"              :sdshds+ll:::--.",
"               `+``ll--....`` ",
"              .-   .-         ",
"          ....-   `:`         ",
"         .-.:.`..--:`         ",
"               ``-`-.         ",};

char seel[17][31]=
{
"                              ",
"                              ",
"                              ",
"             ..````  ```....` ",
"            .`````--.``````.-.",
"           `-``.......`...--.-",
"            ```  ...-   `..-` ",
"                `.```.    `   ",
"             `````````.`      ",
"           ..``````````.`     ",
"          .-..````````..-     ",
"        ..```...........-     ",
"  `````-l-```-+...-.....`     ",
"`-....--..::..:--.-.....```..`",
".....`---:l:--.-:---..````...-",
"        ....--.-.     ``.....`",};

char dewgong[17][31]=
{
"                              ",
"                              ",
"                 `.`          ",
"               `.```.`        ",
"     ```.`.    .````...`      ",
"  `:.`````..`  .`..--:---.`   ",
" ..l.``:l:``.  .---:-.```...` ",
" .-.-``:o-....  `.-.      .`.`",
" ``.----.......`        `````.",
" --.-............````````````.",
".----``.........````````````.`",
" .--:```...-...-.....``````.. ",
"   `..`````...`.````..``..`   ",
"      `....``....`````:..`    ",
"         ``...--.``.``.       ",
"                ````.         ",};

char grimer[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"         `..-::::.            ",
"        `.llll`-ssl`          ",
"        -:l+ossssso+`         ",
"         `+mdhhoooooo:`       ",
"   `  `:llh+l++oosssool       ",
"`:l+l++++++lllosoo+ooso+-.    ",
"-looll+ll+ooosll+++l+oooso.   ",
"..`..--`l:l++++olll++oosoooll`",
"      `-+oosssssosysssoooooool",
"       ---:++ll::l+++l--::.   ",};

char muk[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"          ..-:ll:-.           ",
"       `.++yohddhys+          ",
"     .-l++hNdNNNmo-```````    ",
"  `.-+++++ssossydyosoo+++l:.` ",
" -:lo+oo++++++++osyl.:l+l+++l:",
"-osossssssssyssyyyyo`  `````.`",
" -llll+++l:::l+ool-`          ",};

char shellder[17][31]=
{
"                              ",
"                              ",
"                `l+oool.``.`  ",
"`--`     `..-::l+++oossso+l-  ",
" :l++:--:::lllllllllooso+o+:  ",
"  -+oo+lllllllllll++++oooso:  ",
"  .+llll+llllllll+++++oooo    ",
" -+llllo+oo+++l+ll+++++oss.   ",
"-l++s++hmddddhyll++++ohhos:`  ",
":+l.d..-mmmdddo..--:hNNhoss+-`",
"`.  so-.dMNmmmd+:-:sNmdhs::::-",
"  `+ddhhms+++odMNmmmdddh+`    ",
"  `ls+oyl:l:::ymdhhyhhdho-    ",
"      `l--::::ol:-```.--.     ",
"      `l--::::l               ",
"       .-:lll:.               ",};

char cloyster[17][31]=
{
"                              ",
"                              ",
"                        `-:l- ",
"                    `-:ll+l.  ",
"--..`   .+ollo+:`  .+l+++-    ",
"`-lll+++:ohhh+o++l:+oll-      ",
"   -lsys+sll+soool+oo:        ",
"     `:shhyyoooosl++ls+oo.    ",
"     .ohhsys++shs++l+oosy-    ",
"     `+yssllssy:-oy+ll+++++++:",
"    .:lyysysysyshhyo++oosol`  ",
"   .lllyyhodddhdmmo++oooyl`   ",
"       :sssyyyhhsso+++sys     ",
"       `++shhyhhoo++os+-      ",
"         :sooyhhloo++l++:`    ",
"        `l- `:s+:+l-   `.     ",};

char gastly[17][31]=
{
"                              ",
"                              ",
"           -l                 ",
"       `.``-:`   ``   ..      ",
"     `-+++oo-``:l+++-:++.     ",
"    `.oossyyssssssoo+-:l`     ",
"-...osyhhhhhdmmdhyyso..::`  ` ",
"`++lhhmNNmmmNNNNmddhsoo+++  l.",
"`l-`sNNNNNNNNNNdsldmhsool. `:.",
" .```sNNNNNNho-...+mdyoo-`ll- ",
" `:``-smNms:````..omdyooo+o++.",
" -+:-:hNNm:.``...lmmhsoooooll`",
" `.lohmNNmdhsl+oyddhsoo+++-   ",
"   .l:oyyysshyddhysoooo.      ",
"       losssossoo:los+:`:`    ",
"       `.lll`.:-`  -- `       ",};

char haunter[17][31]=
{
"                              ",
"                              ",
"                              ",
"            l`                ",
"           -l+`               ",
"          `++so:::-..`..----:-",
"        .-l+osoooooo++++ossl. ",
"        .yo+ssooooosssyyo:    ",
"  `--.` :olll+++l:hyyyyyss++:`",
" lssyyyy lysss+::ohhyhhhy+-   ",
"lhoso+-.  -yyssssshhhhhho:`   ",
" .  :      -oysoshhhhhh.      ",
"             `+syssshhhl      ",
"            `y+ooosososs.     ",
"            `l ys.:o+   .     ",
"               :. :+          ",};

char gengar[17][31]=
{
"                              ",
"     .l-                      ",
"     `s+l-`                   ",
"      soo+o:sll-los+          ",
".++:. osso+++++ossso+.........",
"`+so+oss+llllll++ossso++++oo:`",
"  :sssss++lll+++oosssssss+-   ",
"   lssss:lsoooossssssssl.     ",
"   oss+so+ossssollossss+++ll. ",
"  .ooy+.:osysso++ossssssssoo. ",
"  .yshhs:-`.-l:::oyyyy+l-`    ",
"  yhhddddhs++llshhddy`        ",
"  oyhdddddddddhhyyhy`         ",
"   -ydyohddddhysssys          ",
"     `   -sdllyyyys:          ",
"              -yyo.           ",};

char onix[17][31]=
{
"                              ",
"   `l      `.-l::l..`         ",
"   .s` ``.-l:-oooo++oslloo:.  ",
"   -o::...--:+hdy+yysdyssssy: ",
"   :o+++++++oosdhydddmhssysys ",
" `.lso+osso++syo:--:yhdddhhdo`",
".:-+o++o++ohys.     `-oddmmmdo",
"::-:++loo+o:-`        .yddmmd-",
":--:+::oso+           `lshdmh-",
"--.+::sds.          `:oyyhhdm+",
" .:yyhy+`         -osdhddmys: ",
"   `..`         lohhddmhs+`   ",
"              `:hhdmdo+`      ",
"              +hdmm+.         ",
"              .oymh...`.      ",
"                 .loyhys.     ",};

char drowzee[17][31]=
{
" -::``      ```````           ",
"--l:l:.``.--.....-::`         ",
":::::ss+:::l:-:---::+         ",
"--::::l::::lossso:::l      `.`",
"-.-::::::::::ll:lo`  `.--:ll:`",
" -.-----:l:::::lll:::-::::l..`",
"  -.--:::::::::::::::::::.    ",
"  .:-:::-----::::-:::::`      ",
"  -..:ll----lll:::lll::l      ",
"  l:l+oso++ssssoossssssy+`    ",
" :+++oosssssssssssssyyyyys`   ",
"`sooosssssysssssyyyyyyhyyyo   ",
"lsssssssssyyyyyyyyhhhhyyyys   ",
"-yyyyyyyyo:-::::--:oyyyyyy.   ",
" oyyyhyl`           -:los+:.  ",
" ::l:::`                 `.`  ",};

char hypno[17][31]=
{
"         `-`       `          ",
"`---..   --:.   `-l-   `..`   ",
"::---:   l-----:+so`  `:.:-:.`",
"  .---` .......-l+:  --+ll:l-:",
"  `:--. :-.--:---::   .o+++l-.",
"   :-:l-:..-:-:::l::. -:l::   ",
"   .--l---:l::lll:-:o+::++`   ",
"      `-.`..--:.---ll:-o++l   ",
"        --..``..-l+    `-.    ",
"        `:----::-::.          ",
"      `.::::::::::::-`        ",
"    `.-----::::l:::::l:       ",
"    :-----.`    `:ll::l`      ",
"    .lll:l      .l++++.       ",
"    `:lll:-      -l::::`      ",
"   .-:-:--.                   ",};

char krabby[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"     .....        `-::::.     ",
"   `:::lll:`      ::oslll-    ",
"  `l:llso           `hhll+-   ",
"  -lll+ho-  .. `-  -lss++++   ",
"  `+++oo+-``-l:::```++o+++-   ",
"  `:++ll:ll--:::-::+--l+l:    ",
"   -:+l-l.-.-:l:.`.-+l:l:-    ",
"  `::.:+o:--....--::oo+:l+:`` ",
":l+:    ``..-...-..``    `:l::",};

char kingler[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                  `-:-`       ",
"                 .--l++:`     ",
"   ````         `::l++++l     ",
"  -lss`   ..-- :.-l+oyy++l.   ",
" .+ooo.  .-llll+l+:ohmmsll:   ",
"  ++o+- `-:lll:-l+.-sdhooo:   ",
"  .::-`::.--::-----++oooo-`   ",
"   .-ll-ll------:::lollll:-`  ",
".:-``-    `````````     .lll-.",};

char voltorb[17][31]=
{
"                              ",
"                              ",
"     `.-::ll++ll::.           ",
"    `-:-.------lllll++l-`     ",
"   :l-.`..------lllllll++:    ",
" `+l-----------:llllllll+++`  ",
"`+ll----------:---llllll++++` ",
"l+ll:-------:l+l:-:lllll++++l`",
"+lllllllllllllll-llllll+o++++l",
"l---:llllllllll. `.++l++o++++:",
":---...:lllllll-....-++o+o+ol ",
" :---..``..-:::l+lll+++++:lo` ",
" `:----........--:llll+ll++`  ",
"   -:-------------------:-    ",
"     -::-------------::-      ",
"        .--:::::::--.         ",};

char electrode[17][31]=
{
"                              ",
"        `..------:::-.        ",
"     .--`    ````.-:::l:.     ",
"   .-`        `````.-::::l.   ",
"  :. `         ```-..--:::::  ",
" :.....       `--.`-::::::::l ",
"....  `.   ` --``````.:::::::-",
":```   `  .::`````````-::::::l",
"l.````-````.``.``````.:::::::+",
"l--```````````-`````.-::::-l++",
"-o+l:-.````````````.-:ll+++++-",
" lo+oo+o+l::::llll+oooo+++++l ",
"  lo+o+l:::lllllllllo++++++:  ",
"   .+o++o+lllll+ll+o+++++l.   ",
"     .loo++++++++++++++:.     ",
"        .:ll++oo++ll:.        ",};

char exeggcute[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"        ``        `..--..     ",
"     .+l+s+.```.`.---:..l-    ",
"    .::--::--.`..-----llll    ",
"    -::::l-..-..-..ll:-..-.-. ",
" ```...-:l-.......-:+.```..-l.",
"..``.```.-:::-----..--.:--:-l:",
":.``-....-l-:::-`````-.:l::::.",
"--......--- `.---.```---l::-` ",
" .----.--.   .....`.-----     ",
"    `.``      ---::-----`     ",
"               `.----.`       ",};

char exeggutor[17][31]=
{
"                              ",
"                              ",
"                .:`   `..`    ",
"      `--`    `:l` .-::.```   ",
"        -l- .`ll`-++l:::-.`   ",
" `.-----`-+lll+:loo+l-``````  ",
"`....-l+++losysoss+lll+l:---.`",
"  `.--::l+ossyysysso+l::-.`   ",
" ----:l++oooosysl::-````.-:.  ",
"  `:-.``ll-.-:o-..-:.      `  ",
"  .`    -ll-l-ll:--:.         ",
"         `-:::l+++++.         ",
"           -::::l++++.`       ",
"      `-:..l::::llo+l+::      ",
"       ::l+oo++++ooo+::l`     ",
"        ..l-` `.--..--..      ",};

char cubone[17][31]=
{
"      `--..` ``.....` `.-:`   ",
"       .:....```..--:-.-:.    ",
"        .:````..-lo+l::l`     ",
"        -.......oso++l:::.``  ",
"        -......lsso:++:::::-  ",
"      `.......-:ydsl++l::l.   ",
"     -.....:l::::lll++:::`    ",
"     `:...lmh+:--l+++o-``     ",
"      -:::l+++o+:++++ool-`    ",
"       .llll::---------++l:.` ",
"     `:l::lll.`.``.....-+l::l:",
"   -:o:+l+l:l:.`........olll:`",
"   :o:-sl:-:::l........ll:l   ",
"   ---osl:::::+:----:lo+ll-   ",
"-....:`+++++ll:::---:ll+o+:`  ",
"-----:``lll-                  ",};

char marowak[17][31]=
{
"    ``----                    ",
"    :----:`                   ",
"     ``.-::-`                 ",
"          .looo-              ",
"  -.-..````:ssssl.`           ",
"  ----.```.---..-++:...       ",
"  -.`````....-:: `:l::l:      ",
" -.```...---::ll`  -ll.:--`   ",
" -....--ol----.l .-::l+ssol.  ",
" l``-::--..-+++olll++::.      ",
"-.`:::::::l+ooooosso:`        ",
":-l::.` -.-:ll+o+++llll:-..l:.",
"  ``   :l-`...--l+lllllossos+`",
"      -::ll:--::lo::lllls+:`  ",
"      .++ll-..-::::lll++o.    ",
"                    `:ll+.    ",};

char hitmonlee[17][31]=
{
"                              ",
"                              ",
"                              ",
"     `--::::.                 ",
"    `::::::ll:            .`` ",
"    -ll::loy++l.        `:l::.",
"`--:l+llll++++oso- ```..::+++`",
".-:-.lll++++++l::l:lll:-:l+-  ",
"     `l++++++ol:..`:+..       ",
"      `ll+++:`                ",
"       -lll`                  ",
"       .--.                   ",
"       .--:                   ",
"        l+l`                  ",
"        .+++.                 ",
"        -:-::`                ",};

char hitmonchan[17][31]=
{
"    ``            .- :::      ",
"`.-::l++.       .:ll::l--:`   ",
"llll+o+so   ``` :l::::::ll.   ",
"`-l+oo+o+:-+ssol+:o::l:+o+-   ",
"        ``.:looo++ollsllllll-`",
"             :soll+++yo+l:l+l-",
"              `ll::::loosoo`  ",
"            .:::+oss++:`+++   ",
"            --:l+l--:l+:`.`   ",
"             `oo+--l++:-      ",
"             `oolll-.`        ",
"              .:+++.          ",
"                -l+o`         ",
"                -l+s+         ",
"             `..--:+-         ",
"             .lll::.          ",};

char lickitung[17][31]=
{
"                              ",
"                              ",
"                              ",
"        `..-:--.`             ",
"      `l-.---:+--.    ``      ",
"      :l::-::l+::l--:::ll::.  ",
"   ```-loooooosslll:::::lll+: ",
" ..---:l-:---l++ll:------:l+l-",
" .---:::---:ll::l+l:::----l++l",
"  `.--:---:----:l:l:ll+lll+++l",
" `--:----l-.----.-----+llll+l-",
"`..-...-l.`.....:-----:+ll++l ",
".````..-l:----::l------ll+++` ",
"-.....-++++llll+l--:-::+-lll  ",
"`---:lo+++o-::lllllllll-  .-  ",
"    `.---.`      .-:l:-       ",};

char koffing[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
" .---.`            ``         ",
".:lllll.     ..   ::l` `--..` ",
":ll++l+` `.-+++l:---. .:-:--:-",
"`-:--.:llllll++++++ol-:llllll-",
"  -l: :lll+l++ooo++syso`-::.. ",
"  `.`.+++++osssssyyyyyo  ``   ",
"    `+++o+++++++osyyyyy       ",
"     -sooooooo+osossyyy.      ",
"      -syyyyysoooossy+:`      ",
"  `---..syyysssyssss+.--.`    ",
"  .-:l+-`..-:+o+:.`` ll::.    ",
"  `.-:: `:            ``      ",};

char weezing[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"            `----`            ",
"   ...-`    .:ll:             ",
"  `--::-` ```--.` ..--::.``   ",
"   ``-----:::l::l:::l:lll++   ",
".-: `::l::++l::+o+llllll+os-  ",
"`...ll:l:lllll:+ooo++ooooo+-` ",
"    lllo+ooo++:osoososso+-...-",
"    -+loo+oooo+oooooosys` `..`",
"    `lo+o+oo+oosooo:.++-      ",
"      :++++++oo++:-.:-:`      ",
"    ..-.` `.-::`   `-:-`      ",
"    :::`                      ",};

char rhyhorn[17][31]=
{
"           -+: .ls+           ",
"          :lssll+ss:          ",
"          -+sssssyysl.        ",
"       :-:o+sssyo+ossy+.``    ",
"    .-yyl++lyso:++oosssohhl   ",
"   o-+ss+ollool:lsho++++l+l   ",
"  .+:+o+llllllllllos++++++ds. ",
"  -::++lllllllll+ssyyyo++ddhy ",
"  -l:++lllll+:llssssho++shyso:",
" -l+l:olllll:llssssssyssssssyl",
"`+ll+:l:l+lllossssssyssyyysss:",
"+y++lsl:lll+osssoossshyyyyhhs`",
"`+ossoo:l+ossydy++ll+yhhhhhh+ ",
" `sysyhysyys:loslll+oo:soyss. ",
"  :ls+s:```   +l:lllo-        ",
"     `        .-.ll`-         ",};

char rhydon[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"    :+`  -l`                  ",
"   `-+l:l++`.-    ``          ",
".l:-:lllllllo+:`-:l+:         ",
"`lo++ll+l+lo+:l:l+ll`         ",
"  .:ls++ooool:+ol`            ",
"     :l+ooll++oo.      `.:::-`",
"     .l::l+l:+++o`   :+osol--.",
"    -l:------l:::+oosssso`    ",
"   loool::::ll-::l+ssso+`     ",
"   :ssssllooosl::l+ool.       ",
"  -:::-.   ..-.:+l+l          ",
"                ----          ",};

char chansey[17][31]=
{
"                              ",
"                              ",
"                              ",
"          ``.......`          ",
"  `l:---.-..``.....-:.        ",
":--l::--...-..--...-:l:.`     ",
"`:::--..`...-.......-::lll:::-",
"    ..```...........-.--::l:.`",
"   `.``.-............:l:-:l--.",
"   ...-.:....--......:::l+.   ",
"   ....-.````----...::::::    ",
"   `-.:`````..:...-:::::::`.` ",
"    `-l:---::l+-::::::::++l-` ",
"     `-++llll+l:::::::::-`    ",
"    .-ll++lll::::::ll+l`      ",
"     ````    ```    ----      ",};

char tangela[17][31]=
{
"                              ",
"                              ",
"                              ",
"     `-  `:+os+l``-::-`       ",
"     +o.:+ooooooysoosss-      ",
"  `:+ss++sysssyoos++oosol-`   ",
" `+ossoosysyy++yho+yyoyssso+` ",
"`+syssooossso+yNMmsosyysysooo`",
":oys+ossoddl:loNNo:lyNosyyysol",
"ooh+ssyy+hh.``-hhl``:d+sy+s:`.",
"-sssshssoyhssysoosyshysooool. ",
" -shooo+sysss+osoooy++hsyo+o- ",
"  .yol+++ssyooyyooosslys+l+oo ",
"   :o+ooo+oyysssyyso+oolloooo ",
"    -+oooo+ollys+::-+:-l+os+. ",
"     `:l++:`  `        `--`   ",};

char kangaskhan[17][31]=
{
"                              ",
"             ::l+oo:-:::      ",
"            :l+oolo+l+:`      ",
"       `--l..`+ooooo++o` `-.` ",
"      `ll:++-:l::l++o+o:-l+:l-",
"      l::ll+o++++ooo+l+l+l+++:",
"      :lll+++--.-:l+++l++ll++l",
"          `-`:lsl---++oo:l+++.",
" `   ``  ..--::::----o+:  `.` ",
" :::llll+.`````.--:::++o`     ",
".oooooo++...``...----l+o`     ",
" :ooooo++l----------:l:l.     ",
"  `---osoo+:::----:lllll:.    ",
"   -:+oososo+lll:oo+ll+ll-    ",
" `:+oooosoo+l:.  -+o+++ol     ",
"     ```          .--.::.     ",};

char horsea[17][31]=
{
"         `...----..`...       ",
"        -...-----::::.        ",
" ``    :.:o-`:-----ll-        ",
"ls-----:-+h+`:----:ll::::-    ",
":do------:+-----:::ll-`       ",
" :+---::::---::llll::-.       ",
"         .-:ll++lll``.---.....",
"             .l+ll+ -:ll-....-",
"           `.-.llllolll-..... ",
"         .-....llll+.--....`  ",
"     `` :-...-l:llll          ",
"  .--..::-.-:::llll:          ",
" --.-:::--+::llllll           ",
" ---:----:::lllll:            ",
" `::-::::::llll:`             ",
"   .-:::lll:-.                ",};

char seadra[17][31]=
{
"                              ",
"                              ",
"                              ",
"         `.---``-:            ",
".l.`  .-l:::l::++`      `.    ",
"od-::::l::l+ll+s+oo:-`.:-     ",
"``..-:::l::lll+osl`-:::.      ",
"     `:lllll::::+++l::--::::-.",
"        .::l+:+llll+l::-..`   ",
"         ---ll++ooool:-`      ",
"         ---:ll+ol-.--.-.     ",
"         `:-:l+++oo+.         ",
"           ---::llo++`        ",
"           -:l::l++ol-        ",
"           .::ll+oo+l         ",
"            `-l+++l-          ",};

char goldeen[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"          ````                ",
"        ..`````.     `.       ",
"   ````.::..lol::::.-..       ",
"  ```  `---:oss::..-:-:..     ",
"`.````.:+ossssl..`:+l`  ..    ",
"``````.-:--..-:-``````:l+l-`  ",
"      `.``````.........l:l:-.`",
"        ...``.  `````  `.`.```",};

char seaking[17][31]=
{
"                              ",
"                              ",
"                              ",
"        `..```  `..           ",
"  `      ..```.:-::     ``````",
"  `..``..::l:..-l+:  ``-`+l``.",
"   -:::::l::odho-::`````-````.",
"  -++lllssdllddNd+:..```````` ",
" .lll-lloyso+dyyyy:-``````.   ",
"  .```-ll+yhomooy+:-.`--:`.   ",
" `.::-.+++ooho--:o....`.-``.  ",
"..+:lo+ooooo+::---:.-.``l```  ",
"``..-:``...-l+:-`...--  ```   ",
"          .:l::``.-.oo.`      ",
"          `.-.`   ..`-.``     ",
"                  `..`.`      ",};

char staryu[17][31]=
{
"                              ",
"             .++              ",
"            -lss:             ",
"           ::osos.            ",
" `       `l+lssooo`   ``.-:l+:",
"l+l:::-:.l+llooool:l:l++ooss+`",
"`ooooo++:`:...--.-osoososoo:  ",
" `+ooss-.---+l:::-:sssooo+.   ",
"  `+so:..:+++ll--::losssl`    ",
"   `ls+---:+l:-l+++ooos:      ",
"    -ll+::++l+l:losyss+       ",
"   `l:losss+looo+syysss       ",
"   :llsysss+:l+++syysss:      ",
"  `++ssso:`   `-lsyyysss      ",
"  -+sy+.         .lssysy.     ",
"  .::`              .loo.     ",};

char starmie[17][31]=
{
"                              ",
"                              ",
"              .+:        ``   ",
"    l:-.    `--++-   `-:loo`  ",
"    :o+ll:.`:-l+l+:lll+syy:   ",
"     +ooll++--l++lso+ssss-    ",
"     .oys:o:l.:l++llyyso.     ",
"      :sol---:lll-:ollo-      ",
"    `-::l-`:+-.oo+-::::::.`   ",
"  .-::+l:l:+l++ooo:l++o+lll:. ",
" .:l+++oo+loll+olllo+oooooo:- ",
"  `:+osyl-+++-lllllo++yysool` ",
"`-+oosyo:+++o-lo++o+l+syssso+.",
":++l::-l:+++ossso+l+++o:-:ll+:",
"      .-++:..+ss+`-l+oo:      ",
"      .+l.   .+:    .:+l      ",};

char mrmime[17][31]=
{
"                              ",
"                              ",
"  ..-..l-           :so+:`    ",
"-l:-lloyy+::.```.-lyhhh+::    ",
" `----+oyhy:````ohhhh--       ",
"  `:-.  -o-.`....+sl:         ",
"  `.`  `.l-::-:-ll--.         ",
"  ``.--l:ll:::::ll:ll+-...    ",
"     `+++l+.-:::.lll+l  ...   ",
"       .l-`::::ll`-l` ...``.-.",
"       `:ll:lllllll:  ``..--.`",
"      `-+++l----o++:``` `     ",
"    ..-:`..  `` `.` `---      ",
"    ::-::l           `::-  `  ",
"   :hyshys.           ssys+ss-",
"   `l++l.              .l++oo-",};

char scyther[17][31]=
{
"      .:::-`                  ",
"        `--ll   .             ",
"         -::+   +`            ",
"         .-:+.`.+.            ",
"           `++l:ll-.  ``....-`",
"            -+l:l+:..---...`  ",
"            :+ll++l:-.....`   ",
"        `   .+lll+:..`.``     ",
"        ::-.-+++ll:-.``       ",
"        l::+:ll+++------...`  ",
"       `::l+lllooo:``.`````:` ",
"     .::l `:l:-.--++. `````l` ",
"   `-::l.         :ool..`--:  ",
"  .:::ll          .+ooo-.--   ",
"`:lll++-           -l++-.`    ",
" ..-:.`                       ",};

char jynx[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"           ``....```          ",
"          ``:ol++:``.         ",
"        `..::ll::l:.`.`       ",
"        ..`o+l:++os`--:       ",
"   .    -.-o+++l++o`.-:.` :-. ",
" ::o-:: ::-ool:+ool--:l-+oso:`",
".lossl--:l:loo+ool-::::-:++o-`",
" .`` ....lo+oooo++o+l+--.  `` ",
"      .:++++++ooooooo+`       ",
"    `-lol+++lossoo+oos+.      ",
"  :++o+++llllossso+++oo+:.    ",
"      .:lllll:..:+++:--:.     ",};

char electabuzz[17][31]=
{
"                              ",
"                              ",
"        `.-l++.               ",
"      `.s++++l.               ",
"     `y+ysl.:.                ",
"     -:+l:-l:..:-             ",
"     ``os++ol.-::``.-.````    ",
"        :lo:ll+osoo-lh++l:.-. ",
"        `ls+osloo:.``:.-:::-::",
"       :shmmhl:l:      `...-:-",
"      `:-oddyosyo             ",
"      `lyy++ohhs:    `+s`     ",
"     .+hll++oolo+``-lyl-      ",
"  ``:ss-  ``-++o++ll.`        ",
"..--::.        -:+l:.         ",
"                `.`-.``       ",};

char magmar[17][31]=
{
"                              ",
"                              ",
"              ..`  `-`        ",
"             .-.- .--`        ",
"            `.:-:----`        ",
"           `:l+o++++l.        ",
"          `:+oll++o+:`        ",
"`    ```.:l:+l:+shysl:l+l:---`",
".--`.loooosssolloooo++osysso+`",
".-:l.---:loyso++::+++:-....`  ",
" -l+-    -+:::l+::oo+:l-      ",
" `-:-    `:---:+lllllll:`     ",
"    -:-..-+llll+ll:-:+sy`     ",
"     `-:lshds++l:.  `syyo:-`  ",
"       .l+ool`       `-ll:l-` ",
"       .-:::`                 ",};

char pinsir[17][31]=
{
"                              ",
"                ....          ",
"                `-.--`    ``  ",
"      ..         .--::`   -o:.",
"  -` `-.-        ..-:l-  `-sy.",
".loo-.----`   ``.:-:ll-    -+.",
" -os. .::::-.-:ll:lll+`    `ll",
"  .++` .-::ll:l+l-l+ssl..``.+:",
"   `l+.  `.+::+yo++sysl+++::- ",
"     -l:---+:looyooyyyys+.    ",
"       `.lsyo+oosysyys++ll`   ",
"          -losyyyyyyyossso-   ",
"          -:loyyyyyyyy+sys`   ",
"         .l++syo:llll. `.:    ",
"       `l+ossys.              ",
"           .-+-               ",};

char tauros[17][31]=
{
"                              ",
"                              ",
"                              ",
"                            -:",
"              -::-..`      -ol",
"              `--`  `.- `..`` ",
"       ``.--..`       l..``   ",
"`.   .:l++oo+l::.`   `+-.```-`",
":l.-:l+++oooo+llll:::+-     -.",
"`-+lll++ooooss+lll::l+l  .`.. ",
"  :llloyysyyyyllllll+++ -+-   ",
"  :+l-ohyyyyy+++++ollll.``    ",
"      -hhyyyll+`.sh: .ll`     ",
"     -ys:-:lll.  +o.  `+-     ",
"     `y:    :o` +s     +o     ",
"      :+   `oo         --     ",};

char magikarp[17][31]=
{
"              `-.             ",
"         ..  --.-             ",
"         --::----             ",
"        `:l::---:::`          ",
"   `-::ll++o++lll.            ",
" .::ll--l++o+olll-`           ",
".l+++`  `+++ooo++++-    `.--:.",
" +l++l:-l++llll:l+ss:.l+l:-.- ",
"`+lo++++oo:.``.:+osssol-...-` ",
":losoo+oool-.`+oossss-````.`  ",
"-:`:+ssossysolosss+s+.```.    ",
" :-  `:+syyyysl:-` -s...`.    ",
"  :-  -++++++l:`    :+...     ",
"   l` `.l:-l:--:.    .l`      ",
"   :`   `:.`.                 ",
"   `      `-..`               ",};

char gyarados[17][31]=
{
"                              ",
"            .-                ",
"     ``   ``:-.               ",
" `  `+`   -l++-`   `          ",
"`:--ooo+++ooooool:-.          ",
"-+oosooooooo+sooo:.`      `   ",
".lsssooss+:-:++o+-    `..::`  ",
" .ohsoso:-::lll+o:    -+++-   ",
"  +l:+l `-`-:ll+o: .:+syso.   ",
" `:l:.   -`-:llo+.:ososssys::.",
" ...    -`--lllooosoosl.-+yo- ",
"        `.-:ll+ososso-   :ol  ",
"          .:ll+sso+:`  `-+s.  ",
"            `.---.`  `:l+oy   ",
"                    `--l+l+   ",
"                        `:.   ",};

char lapras[17][31]=
{
"                              ",
"                              ",
"          `-++-.--`           ",
"          +oll++oo+           ",
"         :l++ooool`           ",
"         :llll++o             ",
"            `+oo.             ",
"            .l+:              ",
"          `-llll::-           ",
"         `:+l:l:::l:l.        ",
"        .:l:::::::llll:.      ",
"       `++ll:-:lllllll+l      ",
"   `.--:+ll++lllllllll+o:-.   ",
" .::::l+l++oooo+++l++++soo++l.",
"-l:::::--`-lll++ooooooo+oool. ",
"`        `l-----.``.-:l. ```  ",};

char ditto[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"           .--:---...`        ",
"    .-:::::----------:.       ",
"    l-------:ll::l:::-:.      ",
"    .:--:------::::----:--.`  ",
"     l:::----:::::---------l` ",
"    :l:-:::--::::---------:-  ",
"  `:+l------:::----------:-   ",
" -l++l::::::---------::::ll`  ",
":llll++lllll:-::---:ll++l++l- ",
"lllll++++++lll::::l+++++llllll",
" .::::ll++lllllllll+ll++llll+:",
"         .-:l+++ll:--.......` ",};

char eevee[17][31]=
{
".l`                           ",
"+ms:                          ",
"ldhyl                         ",
".hdhh-  ` `          `...--`  ",
" -ymM+llll:::-  .lsyyhhdhl`   ",
"  `:s+llllll+++smMNmdhs:`  .:-",
"   .+sy++++++++os+l::-----:--:",
"   -omh++++sdd++ `loooooooo:-:",
"`..l++++o++shso:.+sooooooooll-",
".`..-:l++oo+o+l:-oysssooossyo ",
"-:.-`....--::l:::ooyyyyyyysl  ",
"  .--:...`.:ll:loooo+lll:.    ",
"    -+l:::l+osso++oo`         ",
"     loos+ooshy-l+++          ",
"     -llo+++s+`-+++`          ",
"     .:-lll-   `.-`           ",};

char vaporeon[17][31]=
{
"           -.            `    ",
"           `s        `-::-    ",
"           `++``.` .++--.`    ",
"         ..:ohyoo+s+l:-.      ",
" .:--:ll+l+l:ll:lsol:.-       ",
"  `.---:ll+hsl::oo+:--.`      ",
"     `-.-::+l+ss++l---        ",
"       .-.`-:l+ll:---`        ",
"         +l...-::l.`          ",
"     .-:so::::lloo.           ",
" `-o+o+l:::::::+oo:    `....` ",
".os:::::::::l:+yssol+ll:---::.",
"ls::llllllosyssoo+l-.l::l:-.  ",
":so+++ossso+++oss.   :l:ll-   ",
".:ll++ll:ll+lsoso     -l+++   ",
" `-:lllll:-` -+ll        .l   ",};

char jolteon[17][31]=
{
"           `..-.              ",
"       `.:l::l.   ```         ",
"      -lllll+ooyhyl-`         ",
"   ``:::++ydmmmh+:`           ",
" `---:--:osoll-.``            ",
":--loy:::lll-.`...```-   `.`  ",
"`-::::::llll-..-:`-ll-..--.`  ",
"  .-lllll:--..:-------.-:....`",
"  `---------..:-----....--.`  ",
"   ..l`..-`---.:-----..-:..`  ",
"  .` l.--:--:---::::::---l`   ",
"     -ll----..` `+l----: `    ",
"      ll-.-      l++---:-     ",
"      ::--`   `.l+l`  -::.    ",
"     .-:--    .:-.  `.::-     ",
"     -::-`          -:-`      ",};

char flareon[17][31]=
{
"                              ",
"                              ",
"                              ",
"        -.                `-` ",
"      -oo`         `       -.`",
"    `sssl      `-.-l-:..``.-.-",
"    +sol` `-:oyy+:----------l.",
"  `---..++hmNNd+l::-------:l- ",
"  -...-lsNNdhso++++llll:::l:  ",
" .lll+o++ol--.:+++++olllllll- ",
" .++smyooo:----+lll+oolllll-  ",
"  .ll+++l:::::loo+++ooo:-.    ",
"   .-`...-:::+sy`.::looo.     ",
"  .loo:-----+ooo-  `:oo:      ",
":lll-`     `l++:   -ll-       ",
"          .ll:`               ",};

char porygon[17][31]=
{
"                              ",
"                        :+    ",
"        ..--..:`       -:o    ",
"     `-------l++-     .-o+    ",
"    .-...:--:+oos+    ::yl    ",
"   --...-:.o-:yss-   --oy:    ",
" `--...-++ll+sss+```-++yy-    ",
" :---:+oosssssyso+++o+osh`    ",
".:-::+osyysssosso+++++oys`    ",
":::l+oyss:l+++os+o++ooooo+ll:.",
" ``..`sol..-:++o+ooss.--:loss+",
"     -oo+l:::l++ssyy+....-sss.",
"     `-:+sllosssyyyy-.---+ys. ",
"         `   .-llos+::ll+ys-  ",
"                   +oo++sy-   ",
"                    `-l+y-    ",};

char omanyte[17][31]=
{
"                              ",
"     `..----:::-.`            ",
"   ..--....------ll.          ",
" `l..:..---....----ll`        ",
"`--:----..---------:l+.       ",
"-.l.....:.``.------.:l+.      ",
":.l`:.-.---.---------+++      ",
":-l.:.-..:..........-l+o      ",
"-.l.--:..:.---------l++o`     ",
"`:.:--:::-.......--:l+++-`-.  ",
" .-:-l-l-.-l-::llll+l+ll+-lll.",
"  `-l:-::ld++hhhssy+ydd+doooo+",
"    :o::::ll+yyo+loosysoysoool",
"   -+so+llllllllllooosososss- ",
"    .lo+l:ll::ll:+sooyssss+:  ",
"      `..::::llll-`-++o:--`   ",};

char omastar[17][31]=
{
"                              ",
"                              ",
"                              ",
"             .`   :-          ",
"            `-::--::.`        ",
"         `....--...-::-.      ",
"         :--::----:::l:lo.    ",
"        :-.-::..-::l::l+sl    ",
"-.  .. `l----.--:lll:+ssss::  ",
"`+  .:--::---..-::l::ysyssl   ",
".+  `l::-::::--l-l+-:osysyl   ",
".+. -::::s.+l+-h-l::::ysyy.   ",
" :sl:l:::l:hh::+:::::oys+.    ",
"   .:ooll++Ns+oyll+oyhs+-`   -",
":-.:ooysoooyyoosooooss+:l++::.",
" `.. -:+l-.`   `.-l++l.-.     ",};

char kabuto[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"       `.-:lllllloo:.         ",
"    -ll:l++llll+++o+++l:      ",
"  .ll:::+++++++++++++++++l    ",
" :ll++ll++++ooyhdhs++++++os.  ",
"l+yNMMmdhhhdmNdyhNMNy+++++ss- ",
"osmNMylloNMMMslll+MMMmhsoosss.",
":oyddoll+NMMMmsosdMMMNNMMmyss+",
"  lsyddmNMMMMMMMMMMNs++yhddyso",
"  l--lhhdmmmNNNMMMMNl::lssyyy:",
"  l..-ooyyyysyyooooo---ooo- ` ",
"   -:::l+ll`    `--::::::`    ",};

char kabutops[17][31]=
{
"         -:                   ",
"       .lo+:-....`  `..-      ",
"      `+o++++++ooo++++l.      ",
"      :o++++++osooooo:        ",
"      -o+++++sysssyy+`    :-  ",
" `::-.`:soososyysydh+-``.:l-- ",
" :---`.-+:..l+o+++ymhyy+.`:.:.",
"--..       `.l++::oyyhhsl ...l",
":.-      `:+++omo:o++yhs`  --:",
":.-      +oo+l:...:++shh+``.:`",
"`--.     :y+`     `loyl+yy::. ",
"  .:.     `so`      .lsl-llo` ",
"      `.::lyy.        .sol`.: ",
"     ``l::.``          :sl    ",
"                      .+o+`   ",
"                     .....-   ",};

char aerodactyl[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"   .` `.`          `:-..```   ",
"  :++`-++ll:-      -oo+lll:-.`",
".l::l+- sy++`     .olll:.     ",
"     .++l+l:.-  `-+++l:       ",
"      +ll++.---+ol-...`  ```  ",
"       `` ---.-l-    `.--:.`  ",
"          -l:::llllll-.       ",
"          .+l.-:l+.`          ",
"           ..   -l`           ",};

char snorlax[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"          -++:---.-:l         ",
"         `+++++o++ooy`        ",
"      `-:+:.`:+:..:shy+:`     ",
"   `-l++os:.....---+hhyo+l-   ",
"  .osssss+l--::::::lossoooo+- ",
"  :++yy+-```..........+yyysss:",
"    -yl````````````````+yho..`",
" `.`:y-...```````````..:sy+`  ",
".-----:::------------::--..-- ",
"`-+oo+-+s+l::::::::l+o-l+++-- ",
"  .:l:.``` ``......-::-l++l.  ",};

char articuno[17][31]=
{
" --`                 `...`    ",
" :l::`           `.-:l:--`    ",
".-:l:l          `l:::::--     ",
"-::l::  `.:-    l::::::-.     ",
"`:::l- -oool-` -l::::::.      ",
"`-llll`:o+l.  `l::::-.        ",
" `:+o++:--l--:l::l::.         ",
"   .l+l..`:ll:::ll.``  ``     ",
"     ..`..lll:-..` .:lll++l:. ",
"      ..-:l::-   .+oo+o+lyyyyl",
"      `:++lll+:losss+:.`lhhhho",
"        :l`.o-::::.`  -oyyyys.",
"      `.l` `l```..-:+ssyyys:` ",
"     :l::l+++:::ll+++++ll-`   ",
"     `.:+++:.                 ",
"       .+```                  ",};

char zapdos[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"``     `   `   `    `    ``.` ",
" `....l+l.`.``.` `.+o-...---` ",
"  `:ol-:l::-.----:-...-oyo:`  ",
"  ``.:l:llllll-:::--.-l.``    ",
"     ``.-lll::l:l:-.```       ",
"       .-l::l.l+.:-.`         ",
"      `:lo:--ll::+::.         ",
"          :-+lllsl.``         ",
"          `::y:sl:`           ",
"           ` `.```            ",};

char moltres[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"       ````                `.-",
"  ..````---`.``  ``      `-:-.",
"`.-:l::-::-:---` .--.` .:l-`  ",
"   ``-:l-:::l:-:  .--:ll-`    ",
"      ``.-::::::---::::-`     ",
"            ::::l:-..-ll`     ",
"           .l   -.    `.-.    ",};

char dratini[17][31]=
{
"                              ",
"                              ",
"                       ..     ",
"             `.`      `-:-    ",
"              `...`.-:-:lll   ",
"               --.-:s+s::-l`  ",
"               `.:::lsy.```.` ",
"                 -.:lll:::.`  ",
"                    -ll:--.   ",
"                     .:.```.  ",
"                      .:.```. ",
" `..---..`             --````.",
"`...--:l+lll:.`        --```.-",
"        `-:l++++:--..---.`.---",
"            .:ll::---....---- ",
"               `.---::::--.`  ",};

char dragonair[17][31]=
{
"          `       ..          ",
"           :.    `.-`         ",
"           .:-:l:.-:`         ",
"           `l:l+o::.          ",
"            .+loso-           ",
"            `:l+ol            ",
"              lsl             ",
"             `.l`             ",
" -:         ``:.              ",
":s-       `` -:               ",
"-:       ````l.     `.--::-.` ",
".l       .  .l. `-:llllllll:l.",
" -+:.`  `````l+osooo+++ll:::.-",
"   -l+ooo.````-l++++ll::-.``..",
"       ```...`````...`....-.` ",
"           `.------...``      ",};

char dragonite[17][31]=
{
"  `              :            ",
" -` ````-:--.```.`            ",
" `.`` -:-:ll:.     ``         ",
"      .:-::oll     :sol`      ",
"      ll:::l+l-  `loosool`    ",
".:::-lsys---l::-lssoosooo+    ",
" .:lll++....::--l:.-l:. `+`   ",
"   ``.-.`..-::::::-`     `    ",
"     .```..-:::l::::.      `-:",
"   .:.```...:::::ll:-   `.:++.",
"  `-:-......-:---::llll++++l` ",
"  `::::....--:--::::o+++ol.   ",
"    -l++ll::l+ll:::+o+:.`     ",
" `---ll+:` ...--lll:          ",
"  ``..`        -::::-         ",
"                .--:-         ",};

char mewtwo[17][31]=
{
"               `.-``..        ",
"               ...-..:        ",
"              ...-l..-`       ",
"        .---` `:-::---        ",
"      ``.-:l:-:::-:--         ",
" .::-...----...:--.-::.       ",
":+``-+l.        `-:::.-:-.    ",
"l+   `+ol`      `--:l:. `--`  ",
".o:   `+++:.  .....l+l+:`----`",
" .ol.  `+ooool.....++++l:..::-",
"  .lll:.`:+oo:--::+o+o+l-     ",
"    -llll `-ll:l++l:+l-`      ",
"      `.`  `.-`    `::        ",
"          .-:`    `:ll:.```   ",
"         ...:-     ``.-::--`  ",
"        -.....`               ",};

char mew[17][31]=
{
"                              ",
"         `...                 ",
"      `----.  ```             ",
"    `:l:::-.....:`            ",
"  `:l:--.....--:.-            ",
" .:.   .--:..--o--  `...---.` ",
".:     `.-l...-l+ll:-``     `l",
"l`    `.--l:::l:--...      .l.",
" .----.`  -..`-.....`   `-:.  ",
"             .......--::-`    ",
"             -....-...-       ",
"             :::-:ll-:l`      ",
"             -::`    `:-`     ",
"              :-:     -.-`    ",
"              `--     .``-    ",
"                      `---    ",};

char rayquaza[17][31]=
{
"                              ",
"                              ",
"                              ",
"  .:                          ",
"   :l`      `-l-              ",
"   `+-`  .:+ol`               ",
"  :l++o+osl.`                 ",
"`loshssssoool-:               ",
"`.`++sl:o:.:ssh+l:-           ",
"   -+yys+s+looysys+`          ",
"  .+yhyssyoolyoyssso+-`       ",
".:+olsol..``lssy+:``-+ol`     ",
"ll+:+o++``.:+s+.      `-oo:`  ",
".+o++++s+l+++:`         `ohy+.",
" `-ssssyol:.             `+l. ",
"   :los:                      ",};

char greninja[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"         `        l        ``.",
"  .-::-.` ``` l.`ly `````-lll.",
"   ````-:---:+syosoll:-.````` ",
"          `:+++yy+-`          ",
"         `-s+o+syyl-`         ",
"       -llyylsshdso-          ",
" ``.-ll:``-+s:.+o:-:`         ",
"`.``--``-:-+l`:-`             ",};

char sobble[17][31]=
{
"                              ",
"                `.....`       ",
"              -::-----`       ",
"            :l------:.        ",
"           +o-----:-`         ",
"           ys+:--::--:        ",
"       ``..+o++:-...`         ",
"   `-:::::::::::l:-`          ",
" `:l:-ll:::::l:--lll:         ",
" lly+l:-...-:sly``lll+lll:-`  ",
"`ys+:---.-...:+:`lollo++llll: ",
" .++l:+osoo+l:-:osssyyyyylllo`",
"    `.-lll+o+osoo++lossssoos+ ",
"        .++::::+++sosssssol.  ",
"        .+soo++o+oys+---`     ",
"       .::l-....:----:.       ",};

char snom[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"              ...`            ",
"      `....`..``..`           ",
"     `..`..-.```....` `       ",
" ..``.--.``..`...````...      ",
" --.``-:.```````        ```   ",
"`.:::-.--.````            `.  ",
"`..--.....````             .` ",
" `-...-`````.`           `.  .",
" `-:::-```.--.``-.       `.```",
"   ```.-----:::-++-----...``  ",};





char eternatus[17][31]=
{
"                              ",
"                              ",
"                              ",
"                              ",
"                              ",
"                          .lyo",
"     `::``:+so+l`      `-yylol",
"   .+y:.llohl`-:+.    -hh:  - ",
"  lhysss-ods:-`      oh+`     ",
" +hyoyhhhyd`        +s:       ",
":o+ooysoshyol-`   .l:         ",
"``.---...+oosys+l+s-          ",
" `..-ol. -++++yhso+++..`      ",
" ``...`  `:l+syhy+++.         ",
"           .-:l+-             ",
"            .-`               ",};



















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
case 50:
memcpy(pokemon,diglett,sizeof(pokemon));
break;
case 51:
memcpy(pokemon,dugtrio,sizeof(pokemon));
break;
case 52:
memcpy(pokemon,meowth,sizeof(pokemon));
break;
case 53:
memcpy(pokemon,persian,sizeof(pokemon));
break;
case 54:
memcpy(pokemon,psyduck,sizeof(pokemon));
break;
case 55:
memcpy(pokemon,golduck,sizeof(pokemon));
break;
case 56:
memcpy(pokemon,mankey,sizeof(pokemon));
break;
case 57:
memcpy(pokemon,primeape,sizeof(pokemon));
break;
case 58:
memcpy(pokemon,growlithe,sizeof(pokemon));
break;
case 59:
memcpy(pokemon,arcanine,sizeof(pokemon));
break;
case 60:
memcpy(pokemon,poliwag,sizeof(pokemon));
break;
case 61:
memcpy(pokemon,poliwhirl,sizeof(pokemon));
break;
case 62:
memcpy(pokemon,poliwrath,sizeof(pokemon));
break;
case 63:
memcpy(pokemon,abra,sizeof(pokemon));
break;
case 64:
memcpy(pokemon,kadabra,sizeof(pokemon));
break;
case 65:
memcpy(pokemon,alakazam,sizeof(pokemon));
break;
case 66:
memcpy(pokemon,machop,sizeof(pokemon));
break;
case 67:
memcpy(pokemon,machoke,sizeof(pokemon));
break;
case 68:
memcpy(pokemon,machamp,sizeof(pokemon));
break;
case 69:
memcpy(pokemon,bellsprout,sizeof(pokemon));
break;
case 70:
memcpy(pokemon,weepinbell,sizeof(pokemon));
break;
case 71:
memcpy(pokemon,victreebel,sizeof(pokemon));
break;
case 72:
memcpy(pokemon,tentacool,sizeof(pokemon));
break;
case 73:
memcpy(pokemon,tentacruel,sizeof(pokemon));
break;
case 74:
memcpy(pokemon,geodude,sizeof(pokemon));
break;
case 75:
memcpy(pokemon,graveler,sizeof(pokemon));
break;
case 76:
memcpy(pokemon,golem,sizeof(pokemon));
break;
case 77:
memcpy(pokemon,ponyta,sizeof(pokemon));
break;
case 78:
memcpy(pokemon,rapidash,sizeof(pokemon));
break;
case 79:
memcpy(pokemon,slowpoke,sizeof(pokemon));
break;
case 80:
memcpy(pokemon,slowbro,sizeof(pokemon));
break;
case 81:
memcpy(pokemon,magnemite,sizeof(pokemon));
break;
case 82:
memcpy(pokemon,magneton,sizeof(pokemon));
break;
case 83:
memcpy(pokemon,farfetchd,sizeof(pokemon));
break;
case 84:
memcpy(pokemon,doduo,sizeof(pokemon));
break;
case 85:
memcpy(pokemon,dodrio,sizeof(pokemon));
break;
case 86:
memcpy(pokemon,seel,sizeof(pokemon));
break;
case 87:
memcpy(pokemon,dewgong,sizeof(pokemon));
break;
case 88:
memcpy(pokemon,grimer,sizeof(pokemon));
break;
case 89:
memcpy(pokemon,muk,sizeof(pokemon));
break;
case 90:
memcpy(pokemon,shellder,sizeof(pokemon));
break;
case 91:
memcpy(pokemon,cloyster,sizeof(pokemon));
break;
case 92:
memcpy(pokemon,gastly,sizeof(pokemon));
break;
case 93:
memcpy(pokemon,haunter,sizeof(pokemon));
break;
case 94:
memcpy(pokemon,gengar,sizeof(pokemon));
break;
case 95:
memcpy(pokemon,onix,sizeof(pokemon));
break;
case 96:
memcpy(pokemon,drowzee,sizeof(pokemon));
break;
case 97:
memcpy(pokemon,hypno,sizeof(pokemon));
break;
case 98:
memcpy(pokemon,krabby,sizeof(pokemon));
break;
case 99:
memcpy(pokemon,kingler,sizeof(pokemon));
break;
case 100:
memcpy(pokemon,voltorb,sizeof(pokemon));
break;
case 101:
memcpy(pokemon,electrode,sizeof(pokemon));
break;
case 102:
memcpy(pokemon,exeggcute,sizeof(pokemon));
break;
case 103:
memcpy(pokemon,exeggutor,sizeof(pokemon));
break;
case 104:
memcpy(pokemon,cubone,sizeof(pokemon));
break;
case 105:
memcpy(pokemon,marowak,sizeof(pokemon));
break;
case 106:
memcpy(pokemon,hitmonlee,sizeof(pokemon));
break;
case 107:
memcpy(pokemon,hitmonchan,sizeof(pokemon));
break;
case 108:
memcpy(pokemon,lickitung,sizeof(pokemon));
break;
case 109:
memcpy(pokemon,koffing,sizeof(pokemon));
break;
case 110:
memcpy(pokemon,weezing,sizeof(pokemon));
break;
case 111:
memcpy(pokemon,rhyhorn,sizeof(pokemon));
break;
case 112:
memcpy(pokemon,rhydon,sizeof(pokemon));
break;
case 113:
memcpy(pokemon,chansey,sizeof(pokemon));
break;
case 114:
memcpy(pokemon,tangela,sizeof(pokemon));
break;
case 115:
memcpy(pokemon,kangaskhan,sizeof(pokemon));
break;
case 116:
memcpy(pokemon,horsea,sizeof(pokemon));
break;
case 117:
memcpy(pokemon,seadra,sizeof(pokemon));
break;
case 118:
memcpy(pokemon,goldeen,sizeof(pokemon));
break;
case 119:
memcpy(pokemon,seaking,sizeof(pokemon));
break;
case 120:
memcpy(pokemon,staryu,sizeof(pokemon));
break;
case 121:
memcpy(pokemon,starmie,sizeof(pokemon));
break;
case 122:
memcpy(pokemon,mrmime,sizeof(pokemon));
break;
case 123:
memcpy(pokemon,scyther,sizeof(pokemon));
break;
case 124:
memcpy(pokemon,jynx,sizeof(pokemon));
break;
case 125:
memcpy(pokemon,electabuzz,sizeof(pokemon));
break;
case 126:
memcpy(pokemon,magmar,sizeof(pokemon));
break;
case 127:
memcpy(pokemon,pinsir,sizeof(pokemon));
break;
case 128:
memcpy(pokemon,tauros,sizeof(pokemon));
break;
case 129:
memcpy(pokemon,magikarp,sizeof(pokemon));
break;
case 130:
memcpy(pokemon,gyarados,sizeof(pokemon));
break;
case 131:
memcpy(pokemon,lapras,sizeof(pokemon));
break;
case 132:
memcpy(pokemon,ditto,sizeof(pokemon));
break;
case 133:
memcpy(pokemon,eevee,sizeof(pokemon));
break;
case 134:
memcpy(pokemon,vaporeon,sizeof(pokemon));
break;
case 135:
memcpy(pokemon,jolteon,sizeof(pokemon));
break;
case 136:
memcpy(pokemon,flareon,sizeof(pokemon));
break;
case 137:
memcpy(pokemon,porygon,sizeof(pokemon));
break;
case 138:
memcpy(pokemon,omanyte,sizeof(pokemon));
break;
case 139:
memcpy(pokemon,omastar,sizeof(pokemon));
break;
case 140:
memcpy(pokemon,kabuto,sizeof(pokemon));
break;
case 141:
memcpy(pokemon,kabutops,sizeof(pokemon));
break;
case 142:
memcpy(pokemon,aerodactyl,sizeof(pokemon));
break;
case 143:
memcpy(pokemon,snorlax,sizeof(pokemon));
break;
case 144:
memcpy(pokemon,articuno,sizeof(pokemon));
break;
case 145:
memcpy(pokemon,zapdos,sizeof(pokemon));
break;
case 146:
memcpy(pokemon,moltres,sizeof(pokemon));
break;
case 147:
memcpy(pokemon,dratini,sizeof(pokemon));
break;
case 148:
memcpy(pokemon,dragonair,sizeof(pokemon));
break;
case 149:
memcpy(pokemon,dragonite,sizeof(pokemon));
break;
case 150:
memcpy(pokemon,mewtwo,sizeof(pokemon));
break;
case 151:
memcpy(pokemon,mew,sizeof(pokemon));
break;
case 384:
memcpy(pokemon,rayquaza,sizeof(pokemon));
break;
case 658:
memcpy(pokemon,greninja,sizeof(pokemon));
break;
case 816:
memcpy(pokemon,sobble,sizeof(pokemon));
break;
case 872:
memcpy(pokemon,snom,sizeof(pokemon));
break;
case 890:
memcpy(pokemon,eternatus,sizeof(pokemon));
break;














default:
break;
}
memcpy(holder,pokemon,sizeof(pokemon));
///end program
}
