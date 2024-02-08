#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

void openMainMenu ();

int getUserInput ();

string cleanInput (string in);

int addNewArray (ifstream& file,const int* &array);

void arrayIncrease (const int* &array, int addNum);

void openModifyMenu ();

void printCurrArray ();