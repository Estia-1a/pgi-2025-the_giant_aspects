#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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

void second_line(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int i = 3 * width;
    int R = data[i];
    int G = data[i + 1];
    int B = data[i + 2];
    printf("second_line: %d, %d, %d\n", R, G, B);
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
void max_component(char *source_path, char *color) {
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    int pixel_count = width * height;
    int max = 0;
    int max_index = 0;

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

        if (value > max) {
            max = value;
            max_index = i;
        }
    }

    int x = max_index % width;
    int y = max_index / width;

    printf("max_component %c (%d, %d): %d\n", color[0], x, y, max);
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

void color_invert(char *filename) {
    unsigned char *data;
    int width, height, channel_count; 

    read_image_data(filename,&data, &width, &height, &channel_count);
    int nbre_pixels = width*height*channel_count;

    for (int i=0; i<nbre_pixels; i++) {
        data[i] = 255 - data[i];
    }

write_image_data("image_out.bmp", data, width, height);
}

void color_red(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    if (data == NULL) {
        printf("Erreur : image non lue\n");
        return;
    }

    unsigned char *red_data = malloc(width * height * channel_count);
    if (red_data == NULL) {
        printf("Erreur : mémoire insuffisante\n");
        return;
    }

    for (int i = 0; i < width * height; i++) {
        int index = i * channel_count;
        red_data[index]     = data[index];
        red_data[index + 1] = 0;
        red_data[index + 2] = 0;
    }

    int result = write_image_data("image_out.bmp", red_data, width, height);
    if (result == 0) {
        printf("Image rouge générée : image_out.bmp\n");
    }

    free(red_data);
}

void color_green(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    if (data == NULL) {
        printf("Erreur : image non lue\n");
        return;
    }

    unsigned char *green_data = malloc(width * height * channel_count);
    if (green_data == NULL) {
        printf("Erreur : mémoire insuffisante\n");
        return;
    }

    for (int i = 0; i < width * height; i++) {
        int index = i * channel_count;
        green_data[index]     = 0;
        green_data[index + 1] = data[index + 1];
        green_data[index + 2] = 0;
    }

    int result = write_image_data("image_out.bmp", green_data, width, height);
    if (result == 0) {
        printf("Image verte générée : image_out.bmp\n");
    }

    free(green_data);
}

void color_blue(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    if (data == NULL) {
        printf("Erreur : image non lue\n");
        return;
    }

    unsigned char *blue_data = malloc(width * height * channel_count);
    if (blue_data == NULL) {
        printf("Erreur : mémoire insuffisante\n");
        return;
    }

    for (int i = 0; i < width * height; i++) {
        int index = i * channel_count;
        blue_data[index]     = 0;
        blue_data[index + 1] = 0;
        blue_data[index + 2] = data[index + 2];
    }

    int result = write_image_data("image_out.bmp", blue_data, width, height);
    if (result == 0) {
        printf("Image bleue générée : image_out.bmp\n");
    }
   
    free(blue_data);
}
void rotate_cw(char *source_path) {
    int width, height, channel_count;
    unsigned char *data_in;

    read_image_data(source_path, &data_in, &width, &height, &channel_count);

    int new_width = height;
    int new_height = width;

    unsigned char *data_out = malloc(new_width * new_height * channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channel_count; c++) {
                data_out[(x * new_width + (new_width - 1 - y)) * channel_count + c] =
                    data_in[(y * width + x) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", data_out, new_width, new_height);
    free_image_data(data_in);
    free(data_out);
}
void rotate_acw(char *source_path) {
    int width, height, channel_count;
    unsigned char *data_in;
    read_image_data(source_path, &data_in, &width, &height, &channel_count);
    int new_width = height;
    int new_height = width;
    unsigned char *data_out = malloc(new_width * new_height * channel_count);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channel_count; c++) {
                data_out[((width - 1 - x) * new_width + y) * channel_count + c] =
                    data_in[(y * width + x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", data_out, new_width, new_height);

    free_image_data(data_in);
    free(data_out);
}

void color_gray(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    if (data == NULL) {
        printf("Erreur : image non lue\n");
        return;
    }

    unsigned char *gray_data = malloc(width * height * channel_count);
    if (gray_data == NULL) {
        printf("Erreur : mémoire insuffisante\n");
        return;
    }

    for (int i = 0; i < width * height; i++) {
        int index = i * channel_count;

        unsigned char R = data[index + 2];
        unsigned char G = data[index + 1];
        unsigned char B = data[index + 0];

        unsigned char gray = (R + G + B) / 3;

        gray_data[index]     = gray;
        gray_data[index + 1] = gray;
        gray_data[index + 2] = gray;
    }

    int result = write_image_data("image_out.bmp", gray_data, width, height);
    if (result == 0) {
        printf("Image en niveaux de gris générée : image_out.bmp\n");
    }

    free(gray_data);
}
void mirror_horizontal(char *source_path){
    int width, height, channel_count;
    unsigned char *data_in;
    read_image_data(source_path, &data_in, &width, &height, &channel_count);

    unsigned char *data_out = malloc(width * height * channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channel_count; c++) {
                data_out[(y * width + (width - 1 - x)) * channel_count + c] =
                    data_in[(y * width + x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", data_out, width, height);

    free_image_data(data_in);
    free(data_out);
}
void mirror_vertical(char *source_path){
    int width, height, channel_count;
    unsigned char *data_in;
    read_image_data(source_path, &data_in, &width, &height, &channel_count);
    unsigned char *data_out = malloc(width * height * channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channel_count; c++) {
                data_out[((height - 1 - y) * width + x) * channel_count + c] =
                    data_in[(y * width + x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", data_out, width, height);

    free_image_data(data_in);
    free(data_out);
}
void mirror_total(char *source_path){
    int width, height, channel_count;
    unsigned char *data_in;
    read_image_data(source_path, &data_in, &width, &height, &channel_count);

    unsigned char *data_out = malloc(width * height * channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channel_count; c++) {
                data_out[((height - 1 - y) * width + (width - 1 - x)) * channel_count + c] =
                    data_in[(y * width + x) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", data_out, width, height);
    free_image_data(data_in);
    free(data_out);
}
void scale_nearest(char *source_path, char *scale_str) {

    int width, height, channel_count;
    unsigned char *data_in;
    read_image_data(source_path, &data_in, &width, &height, &channel_count);
    float scale = atof(scale_str);
    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);
    unsigned char *data_out = malloc(new_width * new_height * channel_count);

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int src_x = (int)(x / scale);
            int src_y = (int)(y / scale);

            for (int c = 0; c < channel_count; c++) {
                data_out[(y * new_width + x) * channel_count + c] =
                    data_in[(src_y * width + src_x) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", data_out, new_width, new_height);
    free_image_data(data_in);
    free(data_out);
}
void scale_bilinear(char *source_path, char *bilinear_str) {
    int width, height, channel_count;
    unsigned char *data_in;
    read_image_data(source_path, &data_in, &width, &height, &channel_count);
    float scale = atof(bilinear_str);
    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);
    unsigned char *data_out = malloc(new_width * new_height * channel_count);

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            float gx = (float)x / scale;
            float gy = (float)y / scale;

            int x0 = (int)gx;
            int y0 = (int)gy;
            int x1 = x0 + 1 < width ? x0 + 1 : x0;
            int y1 = y0 + 1 < height ? y0 + 1 : y0;

            float dx = gx - x0;
            float dy = gy - y0;

            for (int c = 0; c < channel_count; c++) {
                float v00 = data_in[(y0 * width + x0) * channel_count + c];
                float v10 = data_in[(y0 * width + x1) * channel_count + c];
                float v01 = data_in[(y1 * width + x0) * channel_count + c];
                float v11 = data_in[(y1 * width + x1) * channel_count + c];

                float top = v00 + dx * (v10 - v00);
                float bottom = v01 + dx * (v11 - v01);
                float value = top + dy * (bottom - top);

                data_out[(y * new_width + x) * channel_count + c] = (unsigned char)(value);
            }
        }
    }

    write_image_data("image_out.bmp", data_out, new_width, new_height);
    free_image_data(data_in);
    free(data_out);
}

void scale_crop(char *source_path, int center_x, int center_y, int box_width, int box_height) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int start_x = center_x - box_width / 2;
    int start_y = center_y - box_height / 2;

    unsigned char *cropped = malloc(box_width * box_height * channel_count);

    for (int y = 0; y < box_height; y++) {
        for (int x = 0; x < box_width; x++) {
 
            int src_x = start_x + x;
            int src_y = start_y + y;
 
            for (int c = 0; c < channel_count; c++) {
                int dst_index = (y * box_width + x) * channel_count + c;
 
                if (src_x >= 0 && src_x < width && src_y >= 0 && src_y < height) {
                    int src_index = (src_y * width + src_x) * channel_count + c;
                    cropped[dst_index] = data[src_index];
                } else {
                    cropped[dst_index] = 0; 
                }
            }
        }
    }
    write_image_data ("image_out.bmp", cropped, box_width, box_height);
    free(cropped);
}



void color_gray_luminance(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    if (data == NULL) {
        printf("Erreur : image non lue\n");
        return;
    }

    unsigned char *gray_data = malloc(width * height * channel_count);
    if (gray_data == NULL) {
        printf("Erreur : mémoire insuffisante\n");
        return;
    }

    for (int i = 0; i < width * height; i++) {
        int index = i * channel_count;

        unsigned char R = data[index + 2];
        unsigned char G = data[index + 1];
        unsigned char B = data[index + 0];

        unsigned char luminance = (unsigned char)(0.21 * R + 0.72 * G + 0.07 * B);

        gray_data[index]     = luminance;
        gray_data[index + 1] = luminance;
        gray_data[index + 2] = luminance;
    }

    int result = write_image_data("image_out.bmp", gray_data, width, height);
    if (result == 0) {
        printf("Image en niveaux de gris générée : image_out.bmp\n");
    }

    free(gray_data);
}
void color_desaturate(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    if (data == NULL) {
        printf("Erreur : image non lue\n");
        return;
    }

    unsigned char *desat_data = malloc(width * height * channel_count);
    if (desat_data == NULL) {
        printf("Erreur : mémoire insuffisante\n");
        return;
    }

    for (int i = 0; i < width * height; i++) {
        int index = i * channel_count;

        unsigned char R = data[index + 2];
        unsigned char G = data[index + 1];
        unsigned char B = data[index + 0];

        unsigned char min_val = R < G ? (R < B ? R : B) : (G < B ? G : B);
        unsigned char max_val = R > G ? (R > B ? R : B) : (G > B ? G : B);

        unsigned char new_val = (min_val + max_val) / 2;

        desat_data[index + 0] = new_val;
        desat_data[index + 1] = new_val;
        desat_data[index + 2] = new_val;
    }

    int result = write_image_data("image_out.bmp", desat_data, width, height);
    if (result == 0) {
        printf("Image désaturée générée : image_out.bmp\n");
    }

    free(desat_data);
}