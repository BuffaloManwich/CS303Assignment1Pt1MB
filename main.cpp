// CS303 Assignment 1 - Part 1 - Manuel Buffa
// This program will create and manipulate integer arrays

#include "functions.h"

int main () {
    int choice, i;
    bool doExit = false;
    ifstream inFile;
    int* currArray = new int[15];
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
        while (choice > 4 || choice < 1) {
            cout << "Please enter a number within the choice range of 1-4 inclusive." << endl;
            choice = getUserInput();
        }
        // Option 1 is read new array from file.
        if (choice == 1) {
            addNewArray(inFile, currArray);
        }
        else if (choice == 2) {
            // Choice 2 is open the modify menu.
            openModifyMenu();
            choice = getUserInput();
            while (choice < 1 || choice > 5){
                cout << "Please enter a number within the choice range of 1-5 inclusive." << endl;
                choice = getUserInput();
            }
            if (choice == 1) {
                    int result;
                    // Choice 1 is search for a value and return an index if present
                    result = searchArray(currArray);
                    if (result == -1) {
                        cout << "Entered value not found." << endl;
                    }
                    else {
                        cout << "Search successful. Value at index " << result << endl;
                    }
            }
            else if (choice == 2) {
                // Choice 2 is modify a value at chosen input 
                // returns original and modified values
                cout << "What index would you like to modify?" << endl;
                choice = getUserInput();
                while (choice > 13 || choice < 0) {
                    cout << "Index out of range. Please enter a new index between 0-13 inclusive." << endl;
                    choice = getUserInput();
                }
                string values = replaceValue(currArray, choice);
                cout << values << endl;
                printCurrArray(currArray);                                
            }
            else if (choice == 3) {
                cout << "Please type the number you would like to add to the end of the array." << endl;
                choice = getUserInput();
                arrayIncrease(currArray, choice);
                printCurrArray(currArray);
            }
            else if (choice == 4) {
                // Choice 4 is remove value at index
                cout << "What index would you like to delete?" << endl;
                choice = getUserInput();
                // The range of 0-13 will allow the final slot to remain empty (== 0)
                while (choice < 0 || choice > 13) {
                    cout << "Index out of range. Please enter a new index between 0-13 inclusive." << endl;
                    choice = getUserInput();
                }
                removeValue(currArray, choice);
                printCurrArray(currArray);
            }
            else if (choice == 5) {
                continue;
            }
        }
        else if (choice == 3) {
            // Choice 3 is print array.
            printCurrArray(currArray);
        }
        else if (choice == 4) {doExit = true;}
    }
    
    inFile.close();
    cout << "Have a nice day." << endl;
    return 0;
}