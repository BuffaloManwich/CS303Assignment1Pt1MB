#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#pragma once
using namespace std;

void openMainMenu ();

int getUserInput ();

string cleanInput (string in);

void addNewArray (ifstream& file, int* &array);

void arrayIncrease (int* &array, int addNum);

void openModifyMenu ();

void printCurrArray ();