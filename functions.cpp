#include "functions.h"

void openMainMenu() {
    cout << setw(7) << "Main Menu" << endl;
    cout << "Please choose from the following options:" << endl;
    cout << "(Use option number)" << endl << endl;
    cout << "1) Read new int array from file" << endl;
    cout << "2) Modify current array" << endl;
    cout << "3) Print current array" << endl;
    cout << "4) Exit program" << endl << endl;
    return;
}

int userInput() {
    int out = -1;
    
    while (out == -1) {
        cout << "What is your selection?  ";

    }
}