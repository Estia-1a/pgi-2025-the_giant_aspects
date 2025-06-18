#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "first_pixel", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
  first_pixel(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
  print_pixel(configuration.filenames[0], atoi(configuration.arguments[0]), atoi(configuration.arguments[1]));
  }

  if (strncmp(configuration.command, "color_invert", 12)== 0) {
    color_invert(configuration.filenames[0]); 
  }

   if (strncmp(configuration.command, "scale_crop", 10)== 0) {
    int center_x=atoi(argv[argc-4]);
    int center_y=atoi(argv[argc-3]);
    int box_width=atoi(argv[argc-2]);
    int box_height=atoi(argv[argc-1]);
    scale_crop(configuration.filenames[0],center_x, center_y, box_width, box_height);
  }


  /*
   * TO COMPLETE
   */
  
  return 0;
}
