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