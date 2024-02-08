// CS303 Assignment 1 - Part 1 - Manuel Buffa
// This program will create and manipulate integer arrays

#include "functions.h"

int main () {
    int choice;
    size_t arrIter = 0;
    bool doExit = false;
    ifstream inFile;
    // Open the file with the array inputs.
    try{
        inFile.open("A1input.txt");
        if (!inFile.is_open()) {
            throw runtime_error ("ERROR: File did not open.");
        }
    }
    // If file did not open, close program.
    catch (const runtime_error& e) {
        cout << "ERROR: " << e.what() << endl;
        inFile.close();
        cout << "Closing program." << endl;
        doExit = true;
    }

    // File is open, 
    // Main menu loop.
    while (!doExit) {
        // Start by printing the Main Menu.
        openMainMenu();
        // Get user choice (function outputs an integer without checking range)
        choice = getUserInput();
        // Need to check if selection is within range.
        while (choice > 5 || choice < 1) {
            cout << "Please enter a number within the choice range of 1-5." << endl;
            choice = getUserInput();
        }
        // Option 1 is read new array from file.
        if (choice == 1) {}
        else if (choice == 2){}
        else if (choice == 3) {}
        else if (choice == 4) {}
        else if (choice == 5) {doExit = true;}
    }
    cout << "Have a nice day." << endl;
    return 0;
}