#ifndef LAB_06_IMAGE_H
#define LAB_06_IMAGE_H


class Image {
    public:
        unsigned char* imageData = nullptr;
        Image(unsigned char *imageData); // function prototypes !!!!!!!
        unsigned char* getImageData();
        unsigned char* getPixelData();
        unsigned char getWidth();
        unsigned char getHeight();


};


#endif //LAB_06_IMAGE_H
