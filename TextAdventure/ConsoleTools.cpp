#include "ConsoleTools.h"

#include <Windows.h>
#include <iostream>
#include <cstdlib>

#define ESC "\x1b["


using std::cin;
using std::cout;
using std::getline;


//------------------------------------------------------------------------
//					Console manipulation
//------------------------------------------------------------------------

//Enables virtual terminal sequences, escape codes can be used
void EnableVirutalTerminalSequences()
{
	DWORD dwMode = 0;

	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleMode(stdHandle, &dwMode);

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(stdHandle, dwMode);
}

//Clears all text in the console
void Clear()
{
	system("cls");
}


//------------------------------------------------------------------------
//					Input and output
//------------------------------------------------------------------------


//Prints out the given string (using cout)
void Print(string message)
{
	cout << message;
}

//Outputs a string message to the console at a given X and Y position using escape codes
void PrintAtPosition(string message, int xPosition, int yPosition)
{
	//Save the current cursor position, so it can be returned to 
	cout << ESC << "s";

	//Position the cursor at the given position and print the string message
	cout
		<<
		ESC << xPosition << ";" << yPosition << "H" //Position the cursor
		<<
		message; //Print the string

	//Return the cursor to the original position before it was moved
	cout << ESC << "u"; 
}

void Input(string* inputString)
{
	//Print the little icon to show the user that they are to input something
	cout << "\n > ";

	//Grab their input
	getline(cin, *inputString);
}

//Waits for the user to press enter
void WaitForEnter()
{
	//Call the Input() function and give it a temporary string
	string temporaryString;
	Input(&temporaryString);
}

