#include "TextAdventureApplication.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "ConsoleTools.h"


using std::cin;
using std::cout;
using std::getline;

using std::string;


//------------------------------------------------------------------------
//					Constructor and destructor
//------------------------------------------------------------------------

TextAdventureApplication::TextAdventureApplication(const int mapWidth, const int mapHeight)
{
	//Set the map size
	m_mapWidth = mapWidth;
	m_mapHeight = mapHeight;

	//Fill out the grid of rooms
	m_rooms.reserve(m_mapHeight); //Reserve space for the amount of rows

	for (int y = 0; y < m_mapHeight; y++)
	{
		m_rooms.emplace_back();

		//Reserve space on this row
		m_rooms[y].reserve(mapWidth);
		
		//Fill out all of the rooms on this row
		for (int x = 0; x < m_mapWidth; x++)
		{
			m_rooms[y].emplace_back();

			//Create a new room to put in the array
			m_rooms[y][x] = Room(
				GenerateRoomDescription()
			);
		}
	}
	
	//Create the player
	m_player = new Player(0, 0, m_mapWidth, m_mapHeight);

	//Null pointerise the curent room
	m_player->m_currentRoom = nullptr;
}

TextAdventureApplication::~TextAdventureApplication()
{
	//Deallocate the player
	delete m_player;
}


//------------------------------------------------------------------------
//					Public functions (game loop)
//------------------------------------------------------------------------

//This introduces the player, and contains the game loop
int TextAdventureApplication::Run()
{
	//Enable VT100
	EnableVirutalTerminalSequences();

	//Starting message
	Print("Welcome to the text adventure...\n\n An open door to a room is in front of you. Press [enter] to start your adventure.");

	WaitForEnter();

	//Go to the starting room
	EnterRoom(0, 0);

	//Game loop
	while (true)
	{
		//Clear the output
		Clear();

		//Print the map
		PrintMap();

		Print("You are in a room...\n\n");

		//Describe the room
		Print(m_player->m_currentRoom->Describe());

		//See what action the user would like to take
		Print("\nYou can:\n Move North, East, South or West\n");

		string inputString;
		Input(&inputString);

		//Temporary input movement interpretation
		int xDirection = 0;
		int yDirection = 0;

		if (inputString == "move north")
		{
			yDirection = 1;
		}
		else if (inputString == "move east")
		{
			xDirection = 1;
		}
		else if (inputString == "move south")
		{
			yDirection = -1;
		}
		else if (inputString == "move west")
		{
			xDirection = -1;
		}
		else //No valid input
		{
			break;
		}

		//Try and move
		if (not m_player->Move(xDirection, yDirection))
		{
			continue;
		}

		EnterRoom(m_player->xPosition, m_player->yPosition);
	}

	return EXIT_SUCCESS;
}


//------------------------------------------------------------------------
//					Private functions
//------------------------------------------------------------------------

//This sets the current room to the room present at given x and y coordinates, and moved the player to it
void TextAdventureApplication::EnterRoom(int xPosition, int yPosition)
{
	//Set the current room
	m_player->m_currentRoom = &m_rooms[yPosition][xPosition];

	//Move the player
	m_player->xPosition = xPosition;
	m_player->yPosition = yPosition;
}


//Prints out a map, showing where the player is, and where the rooms are
void TextAdventureApplication::PrintMap()
{
	//Title
	Print("Map:\n");
	
	//Go through all rooms, and print them
	for (int y = m_mapHeight - 1; y >= 0; y--) //The Y axis loop is inverted so row 0 appears at the bottom
	{
		for (int x = 0; x < m_mapWidth; x++)
		{
			//See if this is the player's position or a room
			if (x == m_player->xPosition && y == m_player->yPosition)
			{
				Print(COLOUR_TEXT([P], 32));
			}
			else
			{
				Print("[ ]");
			}
		}

		//Next row
		Print("\n");
	}

	//Print the compass
	PrintAtPosition(COLOUR_TEXT(\t   N\n\tW + E\n\t   S, 31), m_mapWidth, 0);

	Print("\n");
}