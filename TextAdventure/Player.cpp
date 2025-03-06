#include "Player.h"


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
}

Player::~Player()
{

}


//------------------------------------------------------------------------
//					Public functions
//------------------------------------------------------------------------


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