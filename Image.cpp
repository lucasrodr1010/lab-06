#include "Image.h"

Image::Image(unsigned char *imageData) { // initialize
    this->imageData = imageData;
}

unsigned char *Image::getImageData() { // returns pointer to the entire image
    return imageData;
}

unsigned char *Image::getPixelData() { // returns pointer to the first pixel
   return imageData+2;
}

unsigned char Image::getWidth() { // returns char of width
    return imageData[0];
}

unsigned char Image::getHeight() { // returns char of height
    return imageData[1];
}
