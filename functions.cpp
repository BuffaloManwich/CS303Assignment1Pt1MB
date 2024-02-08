#include "functions.h"

void openMainMenu() {
    cout << setw(7) << "Main Menu" << endl;
    cout << "Please choose from the following options:" << endl;
    cout << "(Use option number)" << endl << endl;
    cout << "1) Read new int array from file" << endl;
    cout << "2) Modify current array" << endl;
    cout << "3) Print current array" << endl;
    cout << "4) Exit program" << endl << endl;
    cout << "What is your option choice (enter number)?" << endl;
    return;
}

int getUserInput() {
    // This is a function that will have a verification loop for user inputs.
    int out;
    string userIn;
    string userNo;

    getline(cin, userIn);
    userNo = cleanInput(userIn);
    // If userNo is "ERROR", enter while loop until valid choice is entered
    if (userNo == "ERROR") {
        while (userNo == "ERROR") {
            cout << userNo << ": Invalid entry! Please enter a valid selection." << endl;
            getline(cin, userIn);
            userNo = cleanInput(userIn);
        }
    }
    try {
        out = stoi(userNo);
        return out;
    }
    catch (const invalid_argument& e) {
        cout << "ERROR: Invalid entry!" << endl;
        return getUserInput();
    }
}

string cleanInput(string in) {
    string out = "";
    size_t negCount = 0;
    size_t i;
    // Iterate over each char over the length of string
    for (i = 0; i < in.size(); ++i) {
        // This line adds chars to str out if a neg sign or int.
        if ((in.at(i) == '-' && negCount == 0) || isdigit(in.at(i))) {
            out += in.at(i);
            // This ensures only one neg sign is added to the out string
            if (in.at(i) == '-') { negCount = 1; }
        }
    }
    // "Out" string is finished, verify string not empty, and not solely a neg sign.
    if ((out.size() == 1 && out.at(0) == '-') || out.empty()) {
        out = "ERROR";
    }
    // Function will return either a convertable numeric string or the word "ERROR"
    return out;
}
// This function will overwrite the previous array with a bunch of zeros 
// then read the new array from file.
void addNewArray(ifstream& file, int* array) {
    string tempIn = "";
    string entry = "";
    int entryNum;
    int i = 0;
    // Overwrite
    for (i = 0; i < 15; i++) {
        array[i] = 0;
    }

    // Check if file stream is still valid
    if (file.good()) {
        // tempIn holds the entire line read from file.
        getline(file, tempIn);
    }
    else {
        cout << "ERROR: File stream is not good." << endl;
        return;
    }
    stringstream intLine(tempIn);
    // Resetting 'i' = 0
    i = 0;
    // entry will be filled with each entry read from intLine stream of tempIn.
    getline(intLine, entry, ' ');

    while (!entry.empty() && i < 14) {
        entry = cleanInput(entry);
        if (entry != "ERROR") {
            entryNum = stoi(entry);
            // add the converted int to the subsequent index in the array.
            array[i] = entryNum;
            ++i;  
        }
        else { return; }
        entry.clear();
        entryNum = 0;
        // Get next value for entry.
        getline(intLine, entry, ' ');
    }
    return;
}

void arrayIncrease(int* array, int addNum) {
    // Bringing in a int* since passing by reference isn't allowed for int arrays.
    int i = 0;
    while (array[i] != 0) {
        ++i;
    }
    if (array[i] == 0 && array[i + 1] == 0) {
        array[i] = addNum;
    }
    else { ++i; }
    return;
}

void openModifyMenu() {
    cout << setw(7) << " MODIFY MENU" << endl;
    cout << "1) Search for integer in current array (returns index if found)" << endl;
    cout << "2) Modify value at index" << endl;
    cout << "3) Add integer to end of array" << endl;
    cout << "4) Remove value at index" << endl;
    cout << "5) Exit to main menu" << endl << endl;
    cout << "Please choose your operation." << endl;
    return;
}

void printCurrArray(int* currArray) {
    // For interations, a condition of double zeros is present to 
    // indictate the end of the array values
    for (size_t i = 0; i < 14; ++i) {
        if (currArray[i] != 0 && currArray[i + 1] != 0) {
            cout << currArray[i] << " ==> ";
        }
        else if (currArray[i] != 0 && currArray[i + 1] == 0) {
            // Subsequent 0s means end of array vals
            if (i + 2 == 14 || currArray[i + 2] == 0) {
                cout << currArray[i];
            }
            else { cout << currArray[i] << " ==> "; }
        }
        else if (currArray[i] == 0 && currArray[i + 1] != 0) {
            cout << currArray[i] << " ==> ";
        }
        else {
            cout << endl;
            return;
        }
    }
    cout << endl;
    return;
}

int searchArray(int* currArray) {
    // Returns an index if value is found
    int i = 0;
    bool found = false;
    cout << "What value would you like to search for?" << endl;
    int searchVal = getUserInput();
    // Check for concurrent 0s indictating end of array entries.
    while ((currArray[i] != 0 && currArray[i + 1] != 0) && found == false && i < 14) {
        if (currArray[i] == searchVal) {
            cout << "Value " << searchVal << " found at index " << i << endl;
            found = true;
        }
        else { ++i; }
    }
    if (found) { return i; }
    else { return -1; }
}

string replaceValue(int* currArray, int index) {
    // Returns a string containing both the original and changed value.
    int newValue;
    int oldValue;
    string output;
    cout << "What value would you like to input at index " << index << "?" << endl;
    newValue = getUserInput();
    oldValue = currArray[index];
    currArray[index] = newValue;
    output = "Old value at index " + to_string(index) + " is " + to_string(oldValue) + ". The new value is " + to_string(currArray[index]) + ".";
    return output;
}

void removeValue(int* currArray, int index) {
    // Removes a value at index provided
    int i;
    currArray[index] = 0;
    for (i = index; i < 14; ++i) {
        // First case, val at index == 0, next val != 0. Value gets replaced, index gets incremented
        if (currArray[index] == 0 && currArray[index + 1] != 0 && currArray[index] != currArray[index - 1]) {
            currArray[index] = currArray[index + 1];
        }
        // Next case, val at index -1 was replaced by val at index. Val at index + 1 != 0 (not end of array)
        else if (currArray[index] == currArray[index - 1] && currArray[index + 1] != 0 && index + 1 < 14) {
            currArray[index] = currArray[index + 1];
        }
        // Next case, val at index - 1 was replaced by val curr at index, and val at index + 1 == 0 (might be end) 
        else if (currArray[index] == currArray[index - 1] && index + 1 < 14 && currArray[index + 1] == 0) {
            if (currArray[index + 2] == 0) { // End of array values reached (next two values are zero)
                currArray[index] = currArray[index + 1];
                break;
            }
            else if (currArray[index + 2] != 0) { // Not end, val at index + 1 was replaced with 0, by user
                currArray[index] = currArray[index + 1];
            }
        }
        else { break; }
    }
    return;
}
