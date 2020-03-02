/*  CS125_Pokemon
    CS125 Programming Project
    art.c
    All ASCII art for the project
*/

void asciiart(input){
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

    default:
      break;
  }
}
