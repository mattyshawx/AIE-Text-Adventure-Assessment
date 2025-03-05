#include "Room.h"


const int ROOM_DESCRIPTION_COUNT = 5;
const string ROOM_DESCRIPTIONS[ROOM_DESCRIPTION_COUNT] = {
	"It smells mouldy, the air is moist.",
	"It is dull, the brown carpet floor is stained.",
	"Mice scurry away through a hole in the wall. It you can feel the dust as you breathe...",
	"The walls are bleached yellow, a mysterious buzz fills the air...",
	"The room is hot, it smells like dead mice."
};


//------------------------------------------------------------------------
//					Constructor and destructor
//------------------------------------------------------------------------

Room::Room()
{

}

Room::Room(string description)
{
	m_description = description;
}

Room::~Room()
{

}


//------------------------------------------------------------------------
//					Non class functions
//------------------------------------------------------------------------

//This function generates a room description, as a string
string GenerateRoomDescription()
{
	//Pick a random description
	int index = rand() % (ROOM_DESCRIPTION_COUNT - 1);

	return ROOM_DESCRIPTIONS[index];
}
