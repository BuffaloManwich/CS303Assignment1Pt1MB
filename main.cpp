// CS303 Assignment 1 - Part 1 - Manuel Buffa
// This program will create and manipulate integer arrays

#include "functions.h"

int main () {
    int choice;
    size_t arrIter = 0;
    // Start by printing the Main Menu.
    openMainMenu();
    // Get user choice (function outputs an integer without checking range)
    choice = getUserInput();
    // Need to check if selection is within range.
    while (choice > 4 || choice < 1) {
        cout << "Please enter a number within the choice range." << endl;
        choice = getUserInput();
    }
    // Option 1 is read new array from file.
    if (choice == 1) {

    }
    
}