#pragma once

#include <string>


using std::count;
using std::string;


//Console manipulation
void EnableVirutalTerminalSequences();
void Clear();

//Input and output
void Print(string message);
void PrintAtPosition(string message, int xPosition, int yPosition);
void Input(string* inputString);
void WaitForEnter();