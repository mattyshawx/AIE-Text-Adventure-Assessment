#include "Cat.h"

#include "ConsoleTools.h"


//------------------------------------------------------------------------
//					Constructor
//------------------------------------------------------------------------

//Creates a cat
Cat::Cat()
{
	//Set the description and name
	name = "cat";
	m_description = "A brown and white cat.";

	//Mark purring as false
	m_purring = false;
}

//------------------------------------------------------------------------
//					Overridden public functions
//------------------------------------------------------------------------

//Describes the cat, including if it is purring or not
void Cat::Describe()
{
	//If the cat is purring, mention that
	if (m_purring)
	{
		Print(m_description + "\nIt is purring.");
	}
	else
	{
		Print(m_description + "\nIt looks unhappy, in need of pat");
	}
}

//Makes the player pat the cat, making it start purring
void Cat::Use()
{
	//Prompt the user
	Print("You pat the cat\n");

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
			Print("*mew*\nIt wants more pats");

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
