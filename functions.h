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

void arrayIncrease(int* &array, int size, int addNum);

int addNewArray (ifstream& file);

void openModifyMenu();

void printCurrArray();