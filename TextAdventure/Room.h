#pragma once

#include "TextAdventureBase.h"


class Item;


//Room class
class Room : public TextAdventureBase
{
	//Constructor and destructor
public:

	Room();
	Room(string description, Item* givenItem);
	~Room();

	//Public variables
public:

	bool visited;

	Item* item;

	//Overriden public functions
public:

	void Describe() override;

};

//Class related functions

string GenerateRoomDescription();

Item* PickRandomItem();