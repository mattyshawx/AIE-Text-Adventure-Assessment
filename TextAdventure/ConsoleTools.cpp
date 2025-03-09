#include "ConsoleTools.h"

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>


using std::cin;
using std::cout;
using std::getline;


//------------------------------------------------------------------------
//					Console manipulation
//------------------------------------------------------------------------

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

//Combines Print and WaitForEnter, printing the message, and then waiting for the user to press enter
void PrintAndWaitForEnter(string message)
{
	Print(message + " Press [enter]");
	WaitForEnter();
}

void Input(string* inputString)
{
	//Print the little icon to show the user that they are to input something
	cout << "\n > ";
	
	//Grab their input
	getline(cin, *inputString);

	//Convert the input to lowercase
	std::transform(inputString->begin(), inputString->end(), inputString->begin(), std::tolower);
}

//Waits for the user to press enter
void WaitForEnter()
{
	//Call the Input() function and give it a temporary string
	string temporaryString;
	Input(&temporaryString);
}

