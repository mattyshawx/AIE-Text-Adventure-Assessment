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

void PrintDivider()
{
	Print("\n------------------------------------------\n");
}

void Input(string* inputString)
{
	//Print the little icon to show the user that they are to input something
	cout << "\n > ";
	
	//Grab their input
	getline(cin, *inputString);

	//Convert the input to lowercase
	ToLowercase(inputString);
}

//Waits for the user to press enter
void WaitForEnter()
{
	//Call the Input() function and give it a temporary string
	string temporaryString;
	Input(&temporaryString);
}


//------------------------------------------------------------------------
//					Other
//------------------------------------------------------------------------

//Generates a random number between 0 and maxNumber
int Random(int maxNumber)
{
	//Set the random seed
	srand(rand() + time(nullptr));

	//Pick and return a random number
	return rand() % (maxNumber + 1);
}

//Converts a string to lowercase
void ToLowercase(string* givenString)
{
	//Convert it to lowercase using the standard transform and tolower functions
	std::transform(givenString->begin(), givenString->end(), givenString->begin(), std::tolower);
}

