#pragma once

#include "Player.h"
#include "Room.h"


class TextAdventureApplication
{

	//Constructor and destructor
public:

	TextAdventureApplication();
	~TextAdventureApplication();

	//Public functions
public:

	int Run();

	//Private functions
private:


	//Private variables
private:

	Player m_player;

	Room** m_rooms;

};

