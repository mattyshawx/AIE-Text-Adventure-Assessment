#pragma once

#include "TextAdventureBase.h"


//Room class
class Room : public TextAdventureBase
{
	//Constructor and destructor
public:

	Room();
	Room(string description);
	~Room();

	//Public variables
public:

	bool visited;

};

//A function to generate a room description
string GenerateRoomDescription();