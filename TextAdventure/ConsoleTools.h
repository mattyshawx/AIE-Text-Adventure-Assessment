#pragma once

#include <string>


using std::count;
using std::string;


//Console manipulation
void Clear();
void SetConsoleColour(string backgroundCode, string textCode);
void ResetConsoleColour();

//Input and output
void Print(string message);
void PrintAndWaitForEnter(string message);
void PrintDivider();
void Input(string* inputString);
void WaitForEnter();

//Other functions
int Random(int maxNumber);

void ToLowercase(string* givenString);