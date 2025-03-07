#pragma once

#include <string>


//Macros

//Converts a literal argument to a string
#define TO_TEXT(text) #text

//Takes in a literal argument, and a colour code (has to be a number unfortunately, so I can't pre define colour codes as it takes whatever is passed in literally)
#define COLOUR_TEXT(text, colourCode) TO_TEXT(\x1B[ ## colourCode ## m ## text ## \x1B[39m)


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