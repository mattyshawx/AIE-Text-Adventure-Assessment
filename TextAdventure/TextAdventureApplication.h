#pragma once

#include <vector>

#include "Player.h"
#include "Room.h"


using std::vector;


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

	void EnterRoom(int xPosition, int yPosition);

	void PrintMinimap();

	//Private variables
private:

	//Game objects
	Player* m_player;
	
	vector<vector<Room>> m_rooms;

	Room* m_currentRoom;

	//Map size
	int m_mapWidth;
	int m_mapHeight;

};

