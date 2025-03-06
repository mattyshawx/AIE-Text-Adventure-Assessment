#include "TextAdventureApplication.h"

#include <cstdlib>
#include <iostream>
#include <string>


#define PRINT(text) cout << text
#define CLEAR system("cls")

#define INPUT(inputString) \
	cout << "\n > "; \
	string inputString; \
	std::getline(cin, inputString)

#define PRESS_ENTER { \
	INPUT(temporaryString); \
}


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
	m_rooms = new Room[mapWidth * mapHeight];

	for (int y = 0; y < m_mapHeight; y++)
	{
		for (int x = 0; x < m_mapWidth; x++)
		{
			m_rooms[GetRoomIndex(x, y)] = *new Room(
				GenerateRoomDescription()
			);
		}
	}
	
	//Create the player
	m_player = new Player(0, 0, m_mapWidth, m_mapHeight);
}

TextAdventureApplication::~TextAdventureApplication()
{
	//Deallocate the rooms
	//THIS DOES NOT WORK, FIX IT LATER
	/*
	for (int i = 0; i < m_mapWidth * m_mapHeight; i++)
	{
		delete m_rooms[i];
	}
	
	delete[] m_rooms;
	*/

	//Deallocate the player
	delete m_player;
}


//------------------------------------------------------------------------
//					Public functions
//------------------------------------------------------------------------

//This introduces the player, and contains the game loop
int TextAdventureApplication::Run()
{
	//Starting message
	PRINT("Welcome to the text adventure...\n\n An open door to a room is in front of you. Press [enter] to start your adventure.");

	PRESS_ENTER;

	//Go to the starting room
	EnterRoom(0, 0);

	//Game loop
	while (true)
	{
		//Clear the output
		CLEAR;

		//Print the minimap
		PrintMinimap();

		PRINT("You are in a room...\n\n");

		//Describe the room
		PRINT(m_currentRoom->Describe());

		//See what action the user would like to take
		PRINT("\nYou can:\n Move North, East, South or West\n");
		INPUT(input);

		
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
	m_currentRoom = &m_rooms[GetRoomIndex(xPosition, yPosition)];

	//Move the player
	m_player->xPosition = xPosition;
	m_player->yPosition = yPosition;
}

//This takes an X and Y, and converts it into a single index for a 1D array
int TextAdventureApplication::GetRoomIndex(int xPosition, int yPosition)
{
	return xPosition + yPosition * m_mapWidth;
}

//Prints out a minimap showing the grid of rooms, and where the player is
void TextAdventureApplication::PrintMinimap()
{
	//Title
	PRINT("MINIMAP:\n");

	//Go through all rooms, these loops are inverted, so room 0, 0 appears in the bottom right corner, to align with the compass directions
	for (int y = m_mapHeight - 1; y >= 0 ; y--) 
	{
		for (int x = m_mapWidth - 1; x >= 0 ; x--)
		{
			//See if this is the player's position
			if (x == m_player->xPosition && y == m_player->yPosition)
			{
				PRINT("[P]");
			}
			else
			{
				PRINT("[ ]");
			}
		}

		//Next row
		PRINT("\n");
	}

	PRINT("\n");
}
