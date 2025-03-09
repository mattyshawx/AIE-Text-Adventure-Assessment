#include "Room.h"

#include <ctime>
#include <cstdlib>

#include "ConsoleTools.h"
#include "Item.h"
#include "Cat.h"

#include <iostream>

const int ROOM_DESCRIPTION_COUNT = 15;
const string ROOM_DESCRIPTIONS[ROOM_DESCRIPTION_COUNT] = {
	"It smells mouldy, the air is moist.",
	"It is dull, the brown carpet floor is stained.",
	"Mice scurry away through a hole in the wall. You can feel the dust in your nose...",
	"The walls are bleached yellow, a mysterious buzz fills the air...",
	"The room is hot, it smells like dead mice.",
	"It smells of old urine and mould.",
	"Exposed asbestos insulation sticks out, your lungs feel spiky.",
	"The walls are beige, the floor has a beige rug, it appeals to you.",
	"The wallpaper is torn, the floorboards are covered in dust.",
	"There are holes in the walls. A roof panel is hanging down.",
	"It is empty, nothing but old 60s wallpaper surrounds you.",
	"The floorboards creek, there are several holes in the roof.",
	"Cream walls surround you, the lights are dim.",
	"The door creeks shut behind you. Dust fills your lungs,",
	"The rooms smells musty. The carpet is permanently stained by old water."
};


//------------------------------------------------------------------------
//					Constructor and destructor
//------------------------------------------------------------------------

//The default constructor, makes a room with no parameters
Room::Room()
{
	//Mark as not visited
	visited = false;

	//Set the item to nullptr
	item = nullptr;
}

//Makes a room from a given description and an item (which may be a null pointer)
Room::Room(string description, Item* givenItem)
{
	//Set the description
	m_description = description;

	//Mark the room as not visited
	visited = false;

	//Set the item
	item = givenItem;
}

//Destructor
Room::~Room()
{
	//Deallocate the item pointer, if there is one
	if (item != nullptr)
	{
		delete item;
	}
}

void Room::Describe()
{
	//If there is an item in the room, describe it
	if (item != nullptr)
	{
		//Room description
		Print(m_description + "\n\nThere is something there...\n\n");

		//item description
		item->Describe();
	}
	else //No item
	{
		Print(m_description + "\n\nThere is nothing else.");
	}
}


//------------------------------------------------------------------------
//					Non class functions
//------------------------------------------------------------------------

//This function generates a room description, as a string
string GenerateRoomDescription()
{
	//Pick a random description
	int index = Random(ROOM_DESCRIPTION_COUNT - 1);

	return ROOM_DESCRIPTIONS[index];
}

//This picks a random item, and returns a pointer to it, or nullptr if no item. There is a 1 in 3 chance of actually getting an item
Item* PickRandomItem()
{
	//Have a chance to not have an item
	if (Random(7) < 4)
	{
		return nullptr;
	}

	//Pick a random item
	int itemNumber = Random(1);

	switch (itemNumber)
	{
		case 0: //Cat
		{
			return new Cat();
		}

		case 1:
		{
			return new Cat();
		}

		default: //Default
		{
			return nullptr;
		}
	}
}