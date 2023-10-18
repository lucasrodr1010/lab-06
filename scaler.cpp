
#include <iostream>
#include "ConsoleGfx.h"
#include "Image.h"


using namespace std;

void menu();

int main() {

    ConsoleGfx* consolegfx;
    consolegfx = consolegfx->getInstance();
    cout << "Welcome to the Image Scaler!\n\nDsisplaying Spectrum Image:" << endl;

    consolegfx->displayImage(consolegfx->testRainbow);
    menu();
    int input;
    cin >> input;
    unsigned char* fileData;
    while (input != 0) {

        if(input == 1) {
            cout << "Enter name of file to load: ";
            string filename;
            cin >> filename;
            fileData = consolegfx->loadFile(filename);
            if(fileData == nullptr) cout << "Error: could not load file." << endl;
            else cout << "File loaded." << endl;

        }
        if(input == 2) {
            fileData = consolegfx->testImage;
            cout << "Test image data loaded." << endl;
        }
        if (input == 3) {
            consolegfx->displayImage(fileData);
        }
        if (input == 6) {
            Image* i;
            i = new Image(fileData);
            cout << i->getWidth() << endl;
            cout << *fileData << endl;

        }
        menu();
        cin >> input;
    }

}

void menu() {
    cout << "\nScaler Menu\n-----------\n0. Exit\n1. Load File\n2. Load Test Image\n3. Display Image\n4. Enlarge Image\n5. Shrink Image\n6. Show Image Properties\n\nSelect a Menu Option: ";
}