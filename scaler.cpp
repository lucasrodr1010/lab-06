// Lab Partner: Will Berg
#include <iostream>
#include "ConsoleGfx.h"
#include "Image.h"
#include <cmath>


using namespace std;


void menu() { // menu function to avoid redundant code
    cout << "\nScaler Menu\n-----------\n0. Exit\n1. Load File\n2. Load Test Image\n3. Display Image\n4. Enlarge Image\n5. Shrink Image\n6. Show Image Properties\n\nSelect a Menu Option: ";
}

unsigned char* scaledImage(unsigned char* imageData, int orders) {
    int width = (int)imageData[0];
    int height = (int)imageData[1];
    if (orders > 0) { // scaling upwards
        while (((int)pow(2, orders)*width > 256 || (int)pow(2, orders)*height > 256) && orders>0) orders--;
        if (orders == 0) return imageData;
        auto *enlargedImage = new unsigned char[(int)pow(2, orders)*width*(int)pow(2, orders)*height + 2];
        enlargedImage[0] = (int)pow(2, orders)*width;
        enlargedImage[1] = (int)pow(2, orders)*height;
        unsigned char* k;
        int counter = 2;
        int nextAvailableIndex = 2;
        for(int i = 0; i<height; i++) { // iterates through every row in the original image
            unsigned char enlargedRow[(int)pow(2,orders)*width];
            for (int j = 0; j<(int)pow(2, orders); j++) { // sets enlarged rows into enlargedImage[] for every row
                if (j == 0) { // must create enlarged row if at j=0
                    int l= 0;
                    for (k = imageData+counter; l<(int)pow(2, orders)*width; counter++, k=imageData+counter) { //  // creates enlarged rows for the current row
                        for(int z = 0; z<(int)pow(2, orders); z++, l++) { // duplicates current element
                            enlargedRow[l] = *k;
                        }
                    }
                }
                for(int k = 0; k<(int)pow(2,orders)*width; k++, nextAvailableIndex++) enlargedImage[nextAvailableIndex] = enlargedRow[k];
        }
        }
        return enlargedImage;

    }
    else if(orders < 0) { // reducing image
        while ((pow(2, orders)*width < 1.0 || pow(2, orders)*height < 1.0) && orders < 0) orders ++;
        if (orders == 0) return imageData;
        auto *reducedImage = new unsigned char[(int)pow(2, orders)*width*(int)pow(2, orders)*height + 2];
        reducedImage[0] = (int)pow(2, orders)*width;
        reducedImage[1] = (int)pow(2, orders)*height;
        for(int i = 0; i<height*pow(2,orders); i+=(int)pow(2,-1*orders)) {
            for(int j = 0; j<width*pow(2,orders); j+=(int)pow(2,-1*orders)) {
                int maxes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                return reducedImage;
            }
            }

        }
    else {
        return imageData; // if orders == 0 return the same image back
    }
}

int main() {
    ConsoleGfx* consolegfx = consolegfx->getInstance();
    cout << "Welcome to the Image Scaler!\n\nDisplaying Spectrum Image:" << endl; // welcome message
    consolegfx->displayImage(consolegfx->testRainbow);
    int input = -1;
    Image* i = nullptr;
    while (input != 0) {
        if(input == 1) { // loading file
            cout << "Enter name of file to load: ";
            string filename;
            cin >> filename;
            unsigned char* temp = consolegfx->loadFile(filename);
            if(temp == nullptr) cout << "Error: could not load file." << endl;
            else {
                delete i; // managing memory
                i = new Image(temp);
                cout << "File loaded." << endl;
            }

        }
        if(input == 2) { // loading test image
            delete i;
            i = new Image(consolegfx->testImage);
            cout << "Test image data loaded." << endl;
        }
        if (input == 3) { // displaying image
            if(i == nullptr) cout << "Error: no image loaded." << endl;
            else consolegfx->displayImage(i->getImageData());
        }
        if(input == 4) { // enlarging image
            cout << "Enter orders of magnitude for enlargement: ";
            int orders;
            cin >> orders;
            unsigned char* temp = scaledImage(i->getImageData(), orders);
            delete i;
            i = new Image(temp);
            cout << "Image enlarged!" << endl;
        }
        if(input == 5) { // reducing image
            cout << "Enter orders of magnitude for reduction: ";
            int orders;
            cin >> orders;
            unsigned char* temp = scaledImage(i->getImageData(), orders);
            delete i;
            i = new Image(temp);
            cout << "Image reduced!" << endl;
        }
        if (input == 6) { // image dimensions
            cout << "Image Dimensions: (" << (int)i->getWidth() << ", " << (int)i->getHeight() << ")" << endl;
        }
        menu();
        cin >> input; // check for newest options

    }

}

