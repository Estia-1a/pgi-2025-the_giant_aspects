#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void first_pixel (char*source_path) {
    int R, G, B;
    unsigned char *data;
    int  width;
    int height;
    int channel_count; 
read_image_data(source_path, &data, &width, &height, &channel_count);
R =data[0];
G =data[1];
B =data[2];
printf ("first_pixel: %d, %d, %d", R, G, B);
}

void print_pixel (char*source_path, int x, int y) {
    unsigned char *data;
    int  width;
    int height;
    int channel_count; 
  

read_image_data(source_path, &data, &width, &height, &channel_count);

pixelRGB px = get_pixel(data, width, height, channel_count, x, y);


printf("print_pixel (%d, %d) : %d, %d, %d\n", x, y, px.R, px.G, px.B);
   
}

void color_invert(char *source_path) {
    unsigned char *data;
    int width, height, channel_count; 

    read_image_data(source_path,&data, &width, &height, &channel_count);
    int nbre_pixels = width*height*channel_count;

    for (int i=0; i<nbre_pixels; i++) {
        data[i] = 255 - data[i];
    }

write_image_data("image_out.bmp", data, width, height);
}

void scale_crop (char *source_path, int center_x, int center_y, int box_width, int box_height) {
    unsigned char *data; 
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
}
