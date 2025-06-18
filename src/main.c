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
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }

   if ( strncmp( configuration.command, "tenth_pixel", 10 ) == 0 ) {
    tenth_pixel(configuration.filenames[0]);
  }

   if ( strncmp( configuration.command, "first_pixel", 10 ) == 0 ) {
  first_pixel(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
  print_pixel(configuration.filenames[0], atoi(configuration.arguments[0]), atoi(configuration.arguments[1]));
  }

  if (strncmp(configuration.command, "color_invert", 12)== 0) {
    color_invert(configuration.filenames[0]); 
  }

  if ( strncmp(configuration.command, "min_component", 13) == 0 ) {
  char *color = NULL;
  color = argv[argc-1];
    min_component(configuration.filenames[0], color);
  }  
if (strncmp(configuration.command, "dimension", 9) == 0) {
    dimension(configuration.filenames[0]);
}

if (strncmp(configuration.command, "second_line", 11) == 0) {
    second_line(configuration.filenames[0]);
}
if (strncmp(configuration.command, "max_pixel", 9) == 0) {
    max_pixel(configuration.filenames[0]);
}

if (strncmp(configuration.command, "min_pixel", 9) == 0) {
    min_pixel(configuration.filenames[0]);
}
if (strncmp(configuration.command, "stat_report", 11) == 0) {
    stat_report(configuration.filenames[0]);
}
if ( strncmp(configuration.command, "max_component", 13) == 0 ) {
  char *color = NULL;
  color = argv[argc-1];
  max_component(configuration.filenames[0], color);
}  
if (strcmp(configuration.command, "color_red") == 0) {
    color_red(configuration.filenames[0]);
}
if (strcmp(configuration.command, "color_green") == 0) {
    color_green(configuration.filenames[0]);
}
if (strcmp(configuration.command, "color_blue") == 0) {
    color_blue(configuration.filenames[0]);
}if (strncmp(configuration.command, "rotate_cw", 9) == 0) {
    rotate_cw(configuration.filenames[0]);
}
if (strncmp(configuration.command, "rotate_acw", 10) == 0) {
    rotate_acw(configuration.filenames[0]);
}

if (strcmp(configuration.command, "color_gray") == 0) {
    color_gray(configuration.filenames[0]);
}
if (strncmp(configuration.command, "mirror_horizontal", 17) == 0) {
    mirror_horizontal(configuration.filenames[0]);
}
if (strncmp(configuration.command, "mirror_vertical", 15) == 0) {
    mirror_vertical(configuration.filenames[0]);
}
if (strncmp(configuration.command, "mirror_total", 12) == 0) {
    mirror_total(configuration.filenames[0]);
}
if (strncmp(configuration.command, "scale_crop", 10)== 0) {
    int center_x=atoi(argv[argc-4]);
    int center_y=atoi(argv[argc-3]);
    int box_width=atoi(argv[argc-2]);
    int box_height=atoi(argv[argc-1]);
    scale_crop(configuration.filenames[0],center_x, center_y, box_width, box_height);
  }
if (strcmp(configuration.command, "color_gray_luminance") == 0) {
    color_gray_luminance(configuration.filenames[0]);
}

if (strcmp(configuration.command, "color_desaturate") == 0) {
    color_desaturate(configuration.filenames[0]);
}
if (strncmp(configuration.command, "scale_nearest", 13) == 0) {
    char *scale_str = NULL;
    scale_str = argv[argc-1];
    scale_nearest(configuration.filenames[0], scale_str);
}
if (strncmp(configuration.command, "scale_bilinear", 13) == 0) {
    char *bilinear_str = NULL;
    bilinear_str = argv[argc-1];
    scale_bilinear(configuration.filenames[0], bilinear_str);
}
  return 0;




}
