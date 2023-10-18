//
// Created by lucas on 10/18/23.
//

#ifndef LAB_06_IMAGE_H
#define LAB_06_IMAGE_H


class Image {
    public:
        unsigned char* imageData = nullptr;
        Image(unsigned char *imageData);
        unsigned char* getImageData();
        unsigned char* getPixelData();
        unsigned char getWidth();
        unsigned char getHeight();


};


#endif //LAB_06_IMAGE_H
