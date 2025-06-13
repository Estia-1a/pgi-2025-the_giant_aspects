#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();
void tenth_pixel (char *source_path);
void dimension(char *source_path);
void second_line(char *source_path);
void max_pixel(char *source_path);
void min_pixel(char *source_path);
void first_pixel (char *source_path);
void stat_report(char *source_path);

void print_pixel (char *source_path, int x, int y);

void color_invert(char*filename);

void min_component (char *source_path, char *color);
void max_component (char *source_path, char *color);
void color_red(char *source_path);
void color_green(char *source_path);
void color_blue(char *source_path);

void rotate_cw (char *source_path);
void rotate_acw (char *source_path);
#endif
