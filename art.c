/*  CS125_Pokemon
    CS125 Programming Project
    art.c
    All ASCII art for the project
*/

void asciiart(input){
  switch(input){

    case 1: // Pokeball
      printf("\e[0;31m              (((((((((((((((\n");
      printf("          (((((((((((((((((((((((\n");
      printf("       (((((((((((((((((((((((((((((\n");
      printf("     (((((((((((((((((((((((((((((((((\n");
      printf("    (((((((((((((((((((((((((((((((((((\n");
      printf("   ((((((((((((((((\e[0m$$$$$\e[0;31m((((((((((((((((\n");
      printf("   ((((((((((((((\e[0m$        $\e[0;31m(((((((((((((\n");
      printf("   \e[0m$$$$$$$$$$$$$$          $$$$$$$$$$$$$\n");
      printf("   $             $        $            $\n");
      printf("   $               $$$$$$              $\n");
      printf("    $                                 $\n");
      printf("     $                               $\n");
      printf("       $                           $\n");
      printf("          $                      $\n");
      printf("              $              $\n");
      printf("                  $$$$$$$\n");
      break;

    case 2: // Charmander
      printf("     ,.,,,,,*/                \n");
      printf("    ,,,,,,,, @*               \n");
      printf("   @&,,,,,,,$&/               \n");
      printf("   *,,,,,,,,***@           (  \n");
      printf("    **((//*,@*/           *// \n");
      printf("      ******/*,,$        #**.*\n");
      printf(" ,,,,,,/     ,,,,,,,**  ...,..\n");
      printf("              @,*         .,/#\n");
      printf("           .   ,,,&       @,  \n");
      printf("     ,,..  .,,,,.,,,    ///   \n");
      printf("    .,***......,,,,*////,     \n");
      printf("    ,/*/*       *****       \n");
      printf("                *( , \n");
      break;

    case 3: // Squirtle
      printf("    @,.,,,,,***            \n");
      printf("   @*,,,,,@@.*//           \n");
      printf("   $,*,,,,,*////           \n");
      printf("    ///////////,           \n");
      printf("   **@*(*///#//$//         \n");
      printf(",**,,,..*..,*,,,*/@/@      \n");
      printf("/&//(@......,/***&./*      \n");
      printf("   .../,...,,**,(//   @,$  \n");
      printf("  ,,.......*/,,**( #***////\n");
      printf(" $.,*/,**&*,,,,,,@/////////\n");
      printf(" ,////      **,*/#//////(  \n");
      printf("             */*/,\n");

    case 4: // Bulbasaur
      printf("                          .l::`   \n");
      printf("                .--:lllllll+loo`  \n");
      printf("        ..`   `+llllo+llllllls+   \n");
      printf("       l::l::l++llll:++lllll+sol  \n");
      printf("      :l--loss+l:::::lo+++oooosol \n");
      printf("     -lllo:lll:l:l+l:+oooooooosoo:\n");
      printf("    .:+ll:loo:l:.+:o+++osssoooooo+\n");
      printf("    l-ol:::ll::: sloo+++oyysysoool\n");
      printf("    :+ll::l::::l:l+oo++++ossoosol \n");
      printf("     `-+soo++++osoo+++lll+++l++:  \n");
      printf("       .l+oooosooooo:++:lo+oso++` \n");
      printf("        +os+++o+oss+oll:+oloso+o` \n");
      printf("        `+++++. .+so+:l+:l+++++l  \n");
      printf("         -.--`   `::ll:`  -:::- \n");
      break;

    default:
      break;
  }
}
