#include "Image.h"

Image::Image(unsigned char *imageData) {
    this->imageData = imageData;
}

unsigned char *Image::getImageData() {
    return imageData;
}

unsigned char *Image::getPixelData() {
   return imageData+2;
}

unsigned char Image::getWidth() {
    return imageData[0];
}

unsigned char Image::getHeight() {
    return imageData[1];
}
