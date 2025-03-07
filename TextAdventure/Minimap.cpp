#include "Minimap.h"

#include <vector>

#include "ConsoleTools.h"


using std::vector;


class Player;
class Room;


//------------------------------------------------------------------------
//					Constructor and destructor
//------------------------------------------------------------------------

Minimap::Minimap(int mapHeight, int mapWidth, vector<vector<Room>>& rooms, Player& player)
{
	//Map size
	m_mapHeight = mapHeight;
	m_mapWidth = mapWidth;

	//Room and player
	m_rooms = rooms;
	m_player = player;
}

Minimap::~Minimap()
{

}

//------------------------------------------------------------------------
//					Public functions
//------------------------------------------------------------------------

//Prints out a map, showing where the player is, and where the rooms are
void Minimap::Draw()
{
	//Title
	Print("Minimap:\n");

	//Go through all rooms, the y loop if inverted, so room 0, 0 appears in the bottom left corner, to align with the compass directions
	for (int y = m_mapHeight - 1; y >= 0; y--)
	{
		for (int x = 0; x < m_mapWidth; x++)
		{
			//See if this is the player's position
			if (x == m_player->xPosition && y == m_player->yPosition)
			{
				Print("[P]");
			}
			else
			{
				Print("[ ]");
			}
		}

		//Compass row
		int compassRow = m_mapHeight - y;
		if (compassRow == 1)
		{
			Print("\t  N");
		}
		else if (compassRow == 2)
		{
			Print("\tW + E");
		}
		else if (compassRow == 3)
		{
			Print("\t  S");
		}

		//Next row
		Print("\n");
	}

	Print("\n");
}