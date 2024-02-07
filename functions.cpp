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
            cout << out << ": Invalid! Please enter a valid selection." << endl;
            getline(cin, userIn);
            userNo = cleanInput(userIn);
        }
    }
    try {        
        out = stoi(userNo);
        return out;        
    }
    catch (invalid_argument& e) {
        cout << "Invalid entry" << endl;
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

