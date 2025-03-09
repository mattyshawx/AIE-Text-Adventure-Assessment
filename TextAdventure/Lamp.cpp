#include "Lamp.h"

#include "ConsoleTools.h"


//------------------------------------------------------------------------
//					Constructor
//------------------------------------------------------------------------

//Creates a lamp
Lamp::Lamp()
{
	//Set the description and name
	name = "lamp";
	m_description = "An antique lamp.";

	//Turn it off
	m_turnedOn = false;
}


//------------------------------------------------------------------------
//					Overridden public functions
//------------------------------------------------------------------------

//Describes the lamp, with its state
void Lamp::Describe()
{
	//Print the description
	Print(m_description);

	//If the lamp is on or not
	if (m_turnedOn) //Turned on
	{
		Print("\nIt emits a yellow light");

		//Colour the console
		UpdateColour();
	}
	else //Turned off
	{
		Print("\nIt is off");
	}
}

//Makes the player toggle the lamp
void Lamp::Use()
{
	//Toggle the state
	m_turnedOn = !m_turnedOn;

	//Update the console colour
	UpdateColour();

	//Inform the user of what happened
	if (m_turnedOn)
	{
		Print("You turn on the lamp. ");

		//Random entertaining text about the lamp
		int randomNumber = Random(2);

		switch (randomNumber)
		{
			case 0:
			{
				Print("The room lights up.");
				break;
			}

			case 1:
			{
				Print("You look directly at it.\nYour eyes are burning.");
				break;
			}

			case 2:
			{
				Print("It glows.");
				break;
			}

			default:
			{
				break;
			}
		}
	}
	else
	{
		Print("You switch the lamp off.");
	}
}

//------------------------------------------------------------------------
//					Private functions
//------------------------------------------------------------------------

//Updates the console colour to either be the normal black and white, or a lighter colour if the lamp is on
void Lamp::UpdateColour()
{
	if (m_turnedOn)
	{
		SetConsoleColour("E", "0");
	}
	else
	{
		ResetConsoleColour();
	}
}