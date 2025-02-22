/*  CS125 Group Project
    File: art.c
    Description: All ASCII art utilized in UI elements
    Authors: Vince Tran, Forrest Mobley
    References: N/A
*/

// Utilized libraries
#include <stdio.h>

// Header files
#include "art.h"

void asciiart(int input){
  switch(input){
    case 1: // Pokeball large
      printf("\e[0;31m              (((((((((((((((\n");
      printf("          (((((((((((((((((((((((\n");
      printf("       (((((((((((((((((((((((((((((\n");
      printf("     (((((((((((((((((((((((((((((((((\n");
      printf("    (((((((((((((((((((((((((((((((((((\n");
      printf("   ((((((((((((((((\e[0m$$$$$$\e[0;31m(((((((((((((((\n");
      printf("   ((((((((((((((\e[0m$        $\e[0;31m(((((((((((((\n");
      printf("   \e[0m$$$$$$$$$$$$$$          $$$$$$$$$$$$$\n");
      printf("   $             $        $            $\n");
      printf("   $               $$$$$$              $\n");
      printf("    $                                 $\n");
      printf("     $                               $\n");
      printf("       $                           $\n");
      printf("          $                      $\n");
      printf("              $              $\n");
      printf("                  $$$$$$$$\n");
      break;

    case 2: // Pokeball small
      printf("\e[0;31m          (((((((\n");
      printf("       (((((((((((((\n");
      printf("     (((((((((((((((((\n");
      printf("    (((((((((((((((((((\n");
      printf("   (((((((((\e[0m$$$\e[0;31m(((((((((\n");
      printf("   (((((((\e[0m$     $\e[0;31m(((((((\n");
      printf("   \e[0m$$$$$$$       $$$$$$$\n");
      printf("   $      $     $      $\n");
      printf("   $        $$$        $\n");
      printf("    $                 $\n");
      printf("     $               $\n");
      printf("       $           $\n");
      printf("           $$$$$\n");
      break;

    case 3: // Charmander
      printf("\e[0;31m        ,.,,,,,*/                \n");
      printf("       ,,,,,,,, @*               \n");
      printf("      @&,,,,,,,$&/               \n");
      printf("      *,,,,,,,,***@           (  \n");
      printf("       **((//*,@*/           *// \n");
      printf("         ******/*,,$        #**.*\n");
      printf("    ,,,,,,/     ,,,,,,,**  ...,..     Charmander\n");
      printf("                 @,*         .,/#\n");
      printf("              .   ,,,&       @,  \n");
      printf("        ,,..  .,,,,.,,,    ///   \n");
      printf("       .,***......,,,,*////,     \n");
      printf("       ,/*/*       *****       \n");
      printf("                   *( , \e[0m\n");
      break;

    case 4: // Squirtle
      printf("\e[0;34m       @,.,,,,,***            \n");
      printf("      @*,,,,,@@.*//           \n");
      printf("      $,*,,,,,*////           \n");
      printf("       ///////////,           \n");
      printf("      **@*(*///#//$//         \n");
      printf("   ,**,,,..*..,*,,,*/@/@              Squirtle\n");
      printf("   /&//(@......,/***&./*      \n");
      printf("      .../,...,,**,(//   @,$  \n");
      printf("     ,,.......*/,,**( #***////\n");
      printf("    $.,*/,**&*,,,,,,@/////////\n");
      printf("    ,////      **,*/#//////(  \n");
      printf("                */*/,\e[0m\n");
      break;

    case 5: // Bulbasaur
      printf("\e[0;32m                         .l::`   \n");
      printf("               .--:lllllll+loo`  \n");
      printf("       ..`   `+llllo+llllllls+   \n");
      printf("      l::l::l++llll:++lllll+sol  \n");
      printf("     :l--loss+l:::::lo+++oooosol \n");
      printf("    -lllo:lll:l:l+l:+oooooooosoo:\n");
      printf("   .:+ll:loo:l:.+:o+++osssoooooo+     Bulbasaur\n");
      printf("   l-ol:::ll::: sloo+++oyysysoool\n");
      printf("   :+ll::l::::l:l+oo++++ossoosol \n");
      printf("    `-+soo++++osoo+++lll+++l++:  \n");
      printf("      .l+oooosooooo:++:lo+oso++` \n");
      printf("       +os+++o+oss+oll:+oloso+o` \n");
      printf("       `+++++. .+so+:l+:l+++++l  \n");
      printf("        -.--`   `::ll:`  -:::- \e[0m\n");
      break;

    case 6: // Trophy art
      printf("\e[0;33m\t        .-=========-.\n");
      printf("\t        \\'-=======-'/\n");
      printf("\t\\|/     _|   .=.   |_\n");
      printf("\t-.-    ((|  {{1}}  |))\n");
      printf("\t/|\\     \\|   /|\\   |/   \\|/\n");
      printf("\t         |   ‘`’   |    -.-\n");
      printf("\t         | You are |    /|\\\n");
      printf("\t         | amazing |\n");
      printf("\t         \\__     __/\n");
      printf("\t           _`) (`_\n");
      printf("\t         _/_______\\_\n");
      printf("\t        /___________\\\e[0m\n");
      break;

    case 7: // Frowny Face
    printf("\n");
      printf("         .-\"\"\"\"\"\"-.\n");
      printf("       .'          '.\n");
      printf("      /   O      O   \\\n");
      printf("     :           `    :\n");
      printf("     |                |\n");
      printf("     :    .------.    :\n");
      printf("      \\  '        '  /\n");
      printf("       '.          .'\n");
      printf("         '-......-'\n");
      break;


    case 150: // Mewtwo - for easter-egg Pokemon that was never implemented
    printf("\e[0;35m                                               `/:+`                      ```                        \n");
    printf("                                              :- .+`     `....``        -+-:/:                      \n");
    printf("                                              ./. `/--:::-....--:::::-./:   +.                      \n");
    printf("                                               `/.  .`              `.:`  `/.                       \n");
    printf("                                                `/                       `+`                        \n");
    printf("                                                `o                       /.                         \n");
    printf("                                                :-                       /.                         \n");
    printf("                                               `+                        ./                         \n");
    printf("                                               .:                        `+                         \n");
    printf("                                               `+    `.`           `     .+                         \n");
    printf("                                                :-`-:``.-`      `..` `-.`/.                         \n");
    printf("                                                `+``o/o.` `- `- ```:+-/ ./                          \n");
    printf("                                                 :- //Nh/. .:-/ .:hNh--.+`                          \n");
    printf("                        `-:::::-`                `+```:+ss::.`:/yoo/.``+`                           \n");
    printf("                       `+-`   `.+.              `:+-     ``     `     -:                            \n");
    printf("                       /-       .o              +.`./-.            `-:-`                            \n");
    printf("                       :/       :+:`           ::  --.-::.` ``. `.::.                               \n");
    printf("                        :/-...-/:`./:--..`     o   o    s.::-..::-`                                 \n");
    printf("                         `..-+-`    -+:..-:-.` + `.+:---o````.+-                                    \n");
    printf("                  `...`      :+      `:/-..-//:+:/:-.` `.--:``-:-.-.                                \n");
    printf("                -/:-.-:/-``.:/. -      .s:...-/-````.-:`  `..-:-  `:-                               \n");
    printf("               .o`     `o/--.  `o      o`     `o`     `/.      -``  -:                              \n");
    printf("        ```    -/       /-      +`     s       o`       +`     ` .:` :-                             \n");
    printf("    `-//:::://:-s:`   `:o.``    `.   ``++.`  `:/-`      -/     .- -/  +`                            \n");
    printf("  `//-`       `-:os+:::----:::.````-/:-.-:::::. ./`     `+      /  +` :/                            \n");
    printf(" .o.   ``...:.    `:+.       `-::::-`            `+.    `+      `  :` :s                            \n");
    printf("`o.  `::----:+/`    `+:                           `/:`   /.      `..``/o                            \n");
    printf(":+  `+.       -+`     //                            ./-` `::-..-::-` :./`                           \n");
    printf("o.  :/         -o`     /+                             -/.    `    `  /..:                           \n");
    printf("y   +.          :+      //                             `::        /. :-`/                           \n");
    printf("y   +.           //      o-                              +.       `o``+`/`                          \n");
    printf("s`  /:            +/     .o                              -/        .+ .+./`                         \n");
    printf("+-  .o             /+`    s.                             -:         -- .+.+`                        \n");
    printf("-+   +-             -o:   s`                        ./::-:` .`       `  `/:o`                       \n");
    printf(" o`  `o.              -///-                      `:/-        ``       ````-/o:                      \n");
    printf(" .o   `o`                                      `//`              .:-::::::/++s+                     \n");
    printf("  :/   `+-                                    -+`                 -:        :+:+-                   \n");
    printf("   //    :+`                                 :/`                   +         `o-:+`                 \n");
    printf("    :+`   `//`                              :/                     o          `s`-o`                \n");
    printf("     -+`    .//-                           -+                     .o           o. -+                \n");
    printf("      `+-     `-/:-.                     `-s                      +-           o.  /:               \n");
    printf("       `//`      `.-:::---.....-------::::s.                     .o           `s   `s               \n");
    printf("         .+:`         ````......``````   :/                     `o.           //    s`              \n");
    printf("           -/:`                         `o`                     +-           .o`    s`              \n");
    printf("             ./:`                       -/                    `+-           `o.     s`              \n");
    printf("               .:/-`                    +.                   `+-           `o-      s               \n");
    printf("                 `-/:.`                 o`                  .+-           -+.      `o               \n");
    printf("                    `-/:-.`             o`                `//`          ./:`       :-               \n");
    printf("                       `.-:::-.``       :`              `:/.          .//.        ./                \n");
    printf("                            `.--::::-.-:+`            .:/.         `-/:.        .::`                \n");
    printf("                                  `.://:`          `.//.        `-:/-`       .-/-`                  \n");
    printf("                                  -/-`          `-/+:.````...-:/s:.      `.-/-.                     \n");
    printf("                                 `o         .::::-:---------..` o       `+-`                        \n");
    printf("                                  o`      `-:-`                 ::      .+                          \n");
    printf("                                  o`     ./.                     +`     +.                          \n");
    printf("                                 `o     .o`                      +.     +                           \n");
    printf("                                 ::     o.                      `o`     /`                          \n");
    printf("                                `o`    :+                      `+-      `+-                         \n");
    printf("                                :/     y`                    ./o/-`      `:/.                       \n");
    printf("                               `o`     h/-                  -+. `-s`       `//.`                    \n");
    printf("                              `o.      y`o`                 o`    o.         `:/:`                  \n");
    printf("                              /:       s.o.                 -o.``:s.`           .:/:.`       ````   \n");
    printf("                             :/        :o-                   `///-`-:/:.         ...:///::::/::://` \n");
    printf("                            :/         `o.`..``                       .:+.        .-:/::/++-`    .+:\n");
    printf("                           -+  `://`    `/:..::/-                       `+:`               -+-    `s\n");
    printf("                          -o      -+            //                        -//:.```         `/o-:--:.\n");
    printf("                          /:     `/o-:::::::`   `s                           `-:::::::::--:-`       \n");
    printf("                           :/::://-        `:////-  \e[0m\n");
    break;

    default:
      break;
  }
}
