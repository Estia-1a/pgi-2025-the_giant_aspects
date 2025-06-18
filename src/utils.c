#include <estia-image.h>
#include <stdlib.h>

#include "utils.h"

pixelRGB get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
    pixelRGB pixel ={0, 0, 0}; 

    if (!data || x >=width || y>=height) {
        return pixel;
    }

    unsigned int pix=n*(y*width + x);
    pixel.R= data [pix];
    pixel.G= data[pix+1];
    pixel.B= data[pix+2];

    return pixel;

    }

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

