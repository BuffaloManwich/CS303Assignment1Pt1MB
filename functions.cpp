#include "functions.h"

void openMainMenu() {
    cout << setw(7) << "Main Menu" << endl;
    cout << "Please choose from the following options:" << endl;
    cout << "(Use option number)" << endl << endl;
    cout << "1) Read new int array from file" << endl;
    cout << "2) Modify current array" << endl;
    cout << "3) Print current array" << endl;
    cout << "4) Print all arrays" << endl;
    cout << "5) Exit program" << endl << endl;
    return;
}

int getUserInput() {
    // This is a function that will have a verification loop for user inputs.
    int out;
    string userIn;
    string userNo;
    cout << "What is your selection?" << endl;
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
            if (in.at(i) == '-') {negCount = 1;}
        }
    }
    // "Out" string is finished, verify string not empty, and not solely a neg sign.
    if ((out.size() == 1 && out.at(0) == '-') || out.empty()) {
        out = "ERROR";
    }
    // Function will return either a convertable numeric string or the word "ERROR"
    return out;
}

void arrayIncrease(int* &array, int size, int addNum) {
    // Bringing in a int* since passing by reference isn't allowed for int arrays.
    int newSize = size + 1;
    int newArray[newSize];
    int i = 0;
    for (i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    newArray[i + 1] = addNum;
    array = newArray;
}

int addNewArray(string& iter, ifstream& file) {
    string tempIn = "";
    string entry = "";
    int entryNum;
    int intArray[1];
    int* array = intArray;

    while (file.good()) {
        // tempIn holds the entire line read from file.
        getline (file, tempIn);
        stringstream intLine(tempIn);
        // entry will be filled with each entry read from intLine stream of tempIn.
        getline(intLine, entry, ' ');

        while (!entry.empty()) {
            int size = sizeof(intArray) / sizeof(intArray[0]);
            entry = cleanInput(entry);
            if (entry != "ERROR") {
                entryNum = stoi(entry);
                if (size == 1){
                    intArray[0] = entryNum;
                }
                else {
                    arrayIncrease(array, size);
                }
            }
            
        }
    }

}
