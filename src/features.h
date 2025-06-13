#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void first_pixel (char *source_path);

void print_pixel (char *source_path, int x, int y);

void color_invert(char*source_path);

void scale_crop(char *source_path, int center_x, int center_y, int box_width, int box_height);

#endif
