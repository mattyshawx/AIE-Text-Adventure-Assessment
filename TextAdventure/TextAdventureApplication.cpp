#include "TextAdventureApplication.h"

#include <cstdlib>
#include <iostream>
#include <string>


#define PRINT(text) cout << text
#define CLEAR system("cls")

#define INPUT(inputString) \
	cout << "\n > "; \
	std::getline(cin, inputString)

#define PRESS_ENTER { \
	string temporaryString; \
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
			Room* newRoom = new Room(
				GenerateRoomDescription()
			);

			m_rooms[GetRoomIndex(x, y)] = *newRoom;
		}
	}
	
	
	//Create the player
	m_player = new Player();
}

TextAdventureApplication::~TextAdventureApplication()
{
	//Deallocate the rooms
	for (int i = 0; i < m_mapWidth * m_mapHeight; i++)
	{
		delete m_rooms[i];
	}
	
	delete[] m_rooms;

	//Deallocate the player
	delete m_player;
}


//------------------------------------------------------------------------
//					Public functions
//------------------------------------------------------------------------

//This introduces the player, and begins the game loop
int TextAdventureApplication::Run()
{
	//Starting message
	PRINT("Welcome to the text adventure...\n\n An open door to a room is in front of you. Press [enter] to start your adventure.");

	PRESS_ENTER;

	//Start the game room loop
	while (true)
	{
		//Clear the output
		CLEAR;

		PRINT("You are in a room...\n\n");

		//Describe the room
		break;
	}

	return EXIT_SUCCESS;
}


//------------------------------------------------------------------------
//					Private functions
//------------------------------------------------------------------------

//Given a room pointer, move to that room and describe it
void TextAdventureApplication::EnterRoom(Room* newRoom)
{
	//Set the current room to the new one
	m_currentRoom = newRoom;

	//Title message
	PRINT("You enter a room...\n\n");


}
