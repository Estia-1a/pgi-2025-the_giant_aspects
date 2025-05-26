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

void min_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    if (data == NULL) {
        printf("l'Image n'est pas lu\n");
        return;
    }

    int min_sum = 256 * 3 + 1;
    int min_x = 0, min_y = 0;
    int R_min = 0, G_min = 0, B_min = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            int R = data[index];
            int G = data[index + 1];
            int B = data[index + 2];

            int sum = R + G + B;
            if (sum < min_sum) {
                min_sum = sum;
                min_x = x;
                min_y = y;
                R_min = R;
                G_min = G;
                B_min = B;
            }
        }
    }

    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, R_min, G_min, B_min);
}

void stat_report(char *source_path) {
    FILE *file = fopen("report.txt", "w");
    if (!file) {
        printf("créer report.txt pas possible\n");
        return;
    }

    unsigned char *data = NULL;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    if (data == NULL) {
        fprintf(file, "l'image est non lu\n");
        fclose(file);
        return;
    }


    int max_sum = -1, max_x = 0, max_y = 0, R_max = 0, G_max = 0, B_max = 0;
    int min_sum = 256*3+1, min_x = 0, min_y = 0, R_min = 0, G_min = 0, B_min = 0;
    int R_min_val = 255, R_max_val = 0, G_min_val = 255, G_max_val = 0, B_min_val = 255, B_max_val = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            int R = data[index];
            int G = data[index + 1];
            int B = data[index + 2];

            int sum = R + G + B;

            if (sum > max_sum) {
                max_sum = sum;
                max_x = x;
                max_y = y;
                R_max = R;
                G_max = G;
                B_max = B;
            }
            if (sum < min_sum) {
                min_sum = sum;
                min_x = x;
                min_y = y;
                R_min = R;
                G_min = G;
                B_min = B;
            }

            if (R < R_min_val) R_min_val = R;
            if (R > R_max_val) R_max_val = R;
            if (G < G_min_val) G_min_val = G;
            if (G > G_max_val) G_max_val = G;
            if (B < B_min_val) B_min_val = B;
            if (B > B_max_val) B_max_val = B;
        }
    }

    fprintf(file, "max_pixel (%d, %d): %d, %d, %d\n\n", max_x, max_y, R_max, G_max, B_max);
    fprintf(file, "min_pixel (%d, %d): %d, %d, %d\n\n", min_x, min_y, R_min, G_min, B_min);
    fprintf(file, "max_component R: %d\n", R_max_val);
    fprintf(file, "max_component G: %d\n", G_max_val);
    fprintf(file, "max_component B: %d\n\n", B_max_val);
    fprintf(file, "min_component R: %d\n", R_min_val);
    fprintf(file, "min_component G: %d\n", G_min_val);
    fprintf(file, "min_component B: %d\n", B_min_val);

    fclose(file);
}
