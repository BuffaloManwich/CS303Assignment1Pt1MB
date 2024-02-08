#pragma once
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

void openMainMenu();

int getUserInput();

string cleanInput(string in);

void addNewArray(ifstream& file, int* array);

void arrayIncrease(int* array, int addNum);

void openModifyMenu();

void printCurrArray(int* currArray);

int searchArray(int* currArray);

string replaceValue(int* currArray, int index);

void removeValue(int* currArray, int index);