#pragma once

#include "TextAdventureBase.h"


class Room;


class Player : TextAdventureBase
{

	//Constructor and destructor
public:

	Player(int initialXPosition, int initialYPosition, int mapWidth, int mapHeight);
	~Player();

	//Public functions
public:

	bool MovePlayer(int xDirection, int yDirection)
	{
		//Make sure the player can move in this direction
		int newXPosition = xPosition + xDirection;
		int newYPosition = yPosition + yDirection;

		if (newXPosition < 0 || newXPosition >= m_mapWidth || newYPosition < 0 || newYPosition >= m_mapWidth)
		{
			return false; //Tried to move out of bounds, do not allow it
		}

		//Apply the new position
		xPosition = newXPosition;
		yPosition = newYPosition;

		return true;
	}

	//Public variables
public:

	//Position
	int xPosition;
	int yPosition;

	//Private variables
private:

	//Bounds
	int m_mapWidth;
	int m_mapHeight;

};

