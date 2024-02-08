#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

void openMainMenu ();

int getUserInput();

string cleanInput(string in);

int addNewArray (size_t& iter, ifstream& file);

void openModifyMenu();

void printCurrArray();