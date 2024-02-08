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

void addNewArray (ifstream& file,const int* &array);

void arrayIncrease (const int* &array, int addNum);

void openModifyMenu ();

void printCurrArray ();