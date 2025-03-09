#include "BoxOfDonuts.h"

#include "ConsoleTools.h"


//------------------------------------------------------------------------
//					Constructor
//------------------------------------------------------------------------

//Creates a box of donuts
BoxOfDonuts::BoxOfDonuts()
{
	//Set the description and name
	name = "box of donuts";
	m_description = "A box of donuts.";

	//Set the amount of donuts
	m_count = Random(5) + 1;
	


	//Make it edible
	m_canEat = true;
	m_isRevolting = false;
}


//------------------------------------------------------------------------
//					Overridden public functions
//------------------------------------------------------------------------

//Describes the box and its contents
void BoxOfDonuts::Describe()
{
	//Print the description
	Print(m_description);

	//Mention the state of it
	if (m_count > 0) //Donuts remain
	{
		//If there's multiple donuts, add an s
		string amountModifier = (m_count > 1) ? "s" : "";

		//Print the contents
		Print("\nIt has " + std::to_string(m_count) + " donut" + amountModifier + " in it");
	}
	else if (m_canEat) //Only the box remains
	{
		Print("\nIt is empty");
	}
}

//Makes the player eat a donut, or the box if there is none
void BoxOfDonuts::Use()
{
	//Determine the action
	if (m_count > 0) //Donuts are present, eat one
	{
		//Eat a donut
		m_count--;

		Print("You eat a donut...\n");

		//Hunger notice
		int hungerNumber = Random(3);

		switch (hungerNumber)
		{
			case 0: //Want more
			{
				Print("You are still hungry.");
				break;
			}

			case 1: //Feel fat
			{
				Print("You feel a bit fat...");
				break;
			}

			case 2: //health advice
			{
				Print("[Hint] Donuts are bad for your health!");
				break;
			}

			case 3: //Full
			{
				Print("You don't really feel like eating more...");
				break;
			}

			default:
			{
				break;
			}
		}
	}
	else if (m_canEat) //Take a bite out of the box for some reason
	{
		//Eat the box
		Print("There's no donuts. You take a bite out of the box...\n[Hint] Processed cardboard can cause harm to your system. Please be careful when consuming it!");

		m_description = "A chewed box of donuts";

		//Make sure this does not happen again (even though it will)
		m_canEat = false;
	}
	else if (!m_isRevolting) //Has already eaten a bit of the box, but wants more for some reason
	{
		//Eat the box again
		Print("The box didn't really go down well last time.\nYou take another bite of what's left anyways and vomit...");

		m_isRevolting = true;

		//Turn the box into vomit
		name = "vomit";
		m_description = "A pile of vomit";
	}
	else //Only vomit remains (do not repeat this in real life)
	{
		Print("You eat vomit...\nokay...");
	}
}
