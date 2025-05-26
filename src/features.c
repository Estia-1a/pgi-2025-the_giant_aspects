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
void tenth_pixel (char *source_path) {
    int r,g,b;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    r = data[27];
    g = data[28];
    b = data[29];
    printf("tenth_pixel: %d,%d,%d \n",r,g,b);
}

void dimension(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    if (data == NULL) {
        printf("impossible de lire l'image \"%s\"\n", source_path);
        return;
    }

    printf("dimension: %d, %d\n", width, height);
}

void deuxieme_ligne(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int i = 3 * width;
    int R = data[i];
    int G = data[i + 1];
    int B = data[i + 2];
    printf("deuxieme_ligne: %d, %d, %d\n", R, G, B);
}

void max_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    if (data == NULL) {
        printf("l'Image n'est pas lu\n");
        return;
    }

    int max_sum = -1;
    int max_X = 0, max_Y = 0;
    int R_max = 0, G_max = 0, B_max = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            int R = data[index];
            int G = data[index + 1];
            int B = data[index + 2];

            int sum = R + G + B;
            if (sum > max_sum) {
                max_sum = sum;
                max_X = x;
                max_Y = y;
                R_max = R;
                G_max = G;
                B_max = B;
            }
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", max_X, max_Y, R_max, G_max, B_max);
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