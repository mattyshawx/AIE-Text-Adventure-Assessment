#pragma once

#include <string>


using std::count;
using std::string;


//Console manipulation
void Clear();

//Input and output
void Print(string message);
void PrintAndWaitForEnter(string message);
void Input(string* inputString);
void WaitForEnter();