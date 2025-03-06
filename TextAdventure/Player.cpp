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
