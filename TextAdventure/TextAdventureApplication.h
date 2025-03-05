#pragma once


#include "Player.h"
#include "Room.h"


class TextAdventureApplication
{

	//Constructor and destructor
public:

	TextAdventureApplication(int mapWidth, int mapHeight);
	~TextAdventureApplication();

	//Public functions
public:

	int Run();

	//Private functions
private:

	void EnterRoom(Room* room);

	int GetRoomIndex(int xPosition, int yPosition)
	{
		return xPosition + yPosition * m_mapWidth;
	}

	//Private variables
private:

	//Game objects
	Player* m_player;
	
	Room* m_rooms;

	Room* m_currentRoom;

	//Map size
	int m_mapWidth;
	int m_mapHeight;

};

