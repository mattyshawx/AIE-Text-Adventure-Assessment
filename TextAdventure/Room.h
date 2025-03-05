#pragma once

#include "TextAdventureBase.h"


//Room class
class Room : TextAdventureBase
{
	//Constructor and destructor
public:

	Room();
	Room(string description);
	~Room();

};

//A function to generate a room description
string GenerateRoomDescription();