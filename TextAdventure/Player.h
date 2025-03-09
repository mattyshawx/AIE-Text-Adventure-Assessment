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

	bool Move(int xDirection, int yDirection);

	//Public variables
public:

	//Position
	int xPosition;
	int yPosition;

	Room* currentRoom;

	//Private variables
private:

	//Bounds
	int m_mapWidth;
	int m_mapHeight;

};

