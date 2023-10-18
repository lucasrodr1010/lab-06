#include "Image.h"

Image::Image(unsigned char *imageData) {
    this->imageData = imageData;
}

unsigned char *Image::getImageData() {
    return imageData;
}

//unsigned char Image::getPixelData() {
//
//}

unsigned char Image::getWidth() {
    return imageData[0];
}

unsigned char Image::getHeight() {
    return imageData[1];
}
