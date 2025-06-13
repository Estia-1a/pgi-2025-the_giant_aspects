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
void min_component(char *source_path, char *color) {
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    int pixel_count = width * height;
    int min = 255;
    int min_index = 0;

    int channel_offset;

    if (color[0] == 'R') {
        channel_offset = 0;
    } else if (color[0] == 'G') {
        channel_offset = 1;
    } else if (color[0] == 'B') {
        channel_offset = 2;
    } else {
        printf("Couleur non valide : %s. Utilisez R, G ou B.\n", color);
        return;
    }

    for (int i = 0; i < pixel_count; i++) {
        int index = i * channel_count + channel_offset;
        unsigned char value = data[index];

        if (value < min) {
            min = value;
            min_index = i;
        }
    }

    int x = min_index % width;
    int y = min_index / width;

    printf("min_component %c (%d, %d): %d\n", color[0], x, y, min);
}