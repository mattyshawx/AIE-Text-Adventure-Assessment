#include "Player.h"

#include "ConsoleTools.h"


//------------------------------------------------------------------------
//					Constructor and destructor
//------------------------------------------------------------------------

Player::Player(int initialXPosition, int initialYPosition, int mapWidth, int mapHeight)
{
	//Set the map bounds
	m_mapWidth = mapWidth;
	m_mapHeight = mapHeight;

	//Set the X and Y positions
	xPosition = initialXPosition;
	yPosition = initialYPosition;

	//Initialise the current room to a null pointer
	currentRoom = nullptr;

	//Give the player a bunch of spells
	m_spells = {
		"Electroboom",
		"Enlarge",
		"Fizzle",
		"Freeze",
		"Shrink",
		"Tornado",
		"Transform",
		"Whirlwind",
	};
}

Player::~Player()
{

}


//------------------------------------------------------------------------
//					Public functions
//------------------------------------------------------------------------

//Moves the player on the room grid by xDirection, yDirection, and returns true or false if a valid room exists in that direction or not
bool Player::Move(int xDirection, int yDirection)
{
	//Make sure the player can move in this direction
	int newXPosition = xPosition + xDirection;
	int newYPosition = yPosition + yDirection;

	if (newXPosition < 0 || newXPosition >= m_mapWidth || newYPosition < 0 || newYPosition >= m_mapHeight)
	{
		return false; //Tried to move out of bounds, do not allow it
	}

	//Apply the new position
	xPosition = newXPosition;
	yPosition = newYPosition;

	return true;
}

//Prints out all of the spells that the player has access to
void Player::PrintSpells()
{
	//Go through all of the spells
	for (int i = 0; i < m_spells.size(); i++)
	{
		//Print out this spell
		Print(m_spells[i]);

		//Print a comma if there is a following spell
		if (i == m_spells.size() - 2)
		{
			Print(" and ");
		}
		else if (i < m_spells.size() - 1)
		{
			Print(", ");
		}
	}
}
