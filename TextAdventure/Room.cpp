#include "Room.h"

#include <ctime>
#include <cstdlib>


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
	"The rooms smells musty. The carpet is permanently stained by old water.",
};


//------------------------------------------------------------------------
//					Constructor and destructor
//------------------------------------------------------------------------

//The default constructor, makes a room with no parameters
Room::Room()
{
	//Mark as not visited
	visited = false;
}

//Makes a room from a given description
Room::Room(string description)
{
	//Set the description
	m_description = description;

	//Mark the room as not visited
	visited = false;
}

//Destructor
Room::~Room()
{

}


//------------------------------------------------------------------------
//					Non class functions
//------------------------------------------------------------------------

//This function generates a room description, as a string
string GenerateRoomDescription()
{
	//Set the random seed
	srand(rand() + time(nullptr));

	//Pick a random description
	int index = rand() % (ROOM_DESCRIPTION_COUNT - 1);

	return ROOM_DESCRIPTIONS[index];
}
