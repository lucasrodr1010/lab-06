// Lab Partner: Will Berg
#include <iostream>
#include "ConsoleGfx.h"
#include "Image.h"


using namespace std;


void menu() {
    cout << "\nScaler Menu\n-----------\n0. Exit\n1. Load File\n2. Load Test Image\n3. Display Image\n4. Enlarge Image\n5. Shrink Image\n6. Show Image Properties\n\nSelect a Menu Option: ";
}

unsigned char* scaledImage(unsigned char* imageData, int orders) {

}

int main() {

    ConsoleGfx* consolegfx;
    consolegfx = consolegfx->getInstance();
    cout << "Welcome to the Image Scaler!\n\nDsisplaying Spectrum Image:" << endl;

    consolegfx->displayImage(consolegfx->testRainbow);
    menu();
    int input;
    cin >> input;
    Image* i = nullptr;
    while (input != 0) {
        if(input == 1) {
            cout << "Enter name of file to load: ";
            string filename;
            cin >> filename;
            unsigned char* temp = consolegfx->loadFile(filename);
            if(temp == nullptr) cout << "Error: could not load file." << endl;
            else {
                delete i;
                i = new Image(temp);
                cout << "File loaded." << endl;
            }

        }
        if(input == 2) {
            delete i;
            i = new Image(consolegfx->testImage);
            cout << "Test image data loaded." << endl;
        }
        if (input == 3) {
            if(i == nullptr) cout << "Error: no image loaded." << endl;
            else consolegfx->displayImage(i->getImageData());
        }
        if(input == 4) {

        }
        if (input == 6) {
            cout << "Image Dimensions: (" << (int)i->getWidth() << ", " << (int)i->getHeight() << ")" << endl;
        }
        menu();
        cin >> input;
    }

}

