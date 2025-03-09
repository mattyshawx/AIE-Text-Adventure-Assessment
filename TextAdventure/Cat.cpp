#include "Cat.h"

#include "ConsoleTools.h"


//------------------------------------------------------------------------
//					Constructor
//------------------------------------------------------------------------

//Creates a cat
Cat::Cat()
{
	//Set the name
	name = "cat";

	//Chose a cat type
	int typeNumber = Random(9);
	string catType;
	switch (typeNumber)
	{
		case 0:
		{
			catType = "brown";
			break;
		}

		case 1:
		{
			catType = "white";
			break;
		}

		case 2:
		{
			catType = "black";
			break;
		}

		case 3:
		{
			catType = "light orange";
			break;
		}

		case 4:
		{
			catType = "grey";
			break;
		}

		case 5:
		{
			catType = "spotty";
			break;
		}

		case 6:
		{
			catType = "brown";
			break;
		}

		case 7:
		{
			catType = "fat";
			break;
		}

		case 8:
		{
			catType = "humongous";
			break;
		}

		case 9:
		{
			catType = "mysterious";
			break;
		}

		default:
		{
			m_description = "invalid";

			break;
		}
	}
	m_description = "A " + catType + " cat.";

	//Mark purring as false
	m_purring = false;
}


//------------------------------------------------------------------------
//					Overridden public functions
//------------------------------------------------------------------------

//Describes the cat, including if it is purring or not
void Cat::Describe()
{
	//Print the description
	Print(m_description);

	//If the cat is purring, mention that
	if (m_purring)
	{
		Print("\nIt is purring.");
	}
	else
	{
		Print("\nIt looks unhappy, in need of pat");
	}
}

//Makes the player pat the cat, making it start purring
void Cat::Use()
{
	//Prompt the user
	Print("You pat the cat.\n");

	//Make it purr
	m_purring = true;

	//Print out a response
	int response = Random(4);

	switch (response)
	{
		case 0:
		{
			Print("*meow*");

			break;
		}

		case 1:
		{
			Print("*MOW*");

			break;
		}

		case 2:
		{
			Print("prrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr");

			break;
		}

		case 3:
		{
			Print("*mew*\nIt wants more pats.");

			break;
		}

		case 4: //Pat fail
		{
			Print("You pat it the wrong way.\nIt hisses.");

			m_purring = false;

			break;
		}

		default:
		{
			break;
		}
	}
}
