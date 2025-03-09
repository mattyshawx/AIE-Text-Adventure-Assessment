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
		Print(m_player->currentRoom->Describe());

		//See what action the user would like to take
		//Print("\nYou can:\n Move North, East, South or West\n");
		Print("\nThink of what to do (move [direction], use [object], spell, quit game)");

		string inputString;
		Input(&inputString);

		//Try to handle the input
		if (inputString.substr(0, 4) == "move") //Move input
		{
			//Extract the direction to move in
			string direction = inputString.substr(5);

			//Interpret the direction to move in
			int xDirection = 0;
			int yDirection = 0;

			if (direction == "north") //North
			{
				yDirection = 1;
			}
			else if (direction == "east") //East
			{
				xDirection = 1;
			}
			else if (direction == "south") //South
			{
				yDirection = -1;
			}
			else if (direction == "west") //West
			{
				xDirection = -1;
			}
			else //Something invalid
			{
				PrintAndWaitForEnter("\nYou try to walk \"" + direction + "\". You confuse yourself.");
			}

			//Try and move
			if (not m_player->Move(xDirection, yDirection))
			{
				PrintAndWaitForEnter("\nYou walk " + direction + " into a wall. Your head aches");
			}
		}
		else if (inputString == "quit game") //Exit the game
		{
			PrintAndWaitForEnter("\nYou rage quit and escape the matrix. I will get you for this!");

			break; //Get out of the game loop
		}
		else //Invalid input
		{
			PrintAndWaitForEnter("\nYour brain switches off, you try to \"" + inputString + "\". Nothing happens.");
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
	m_player->currentRoom = &m_rooms[yPosition][xPosition];

	//Mark the room as visited
	m_player->currentRoom->visited = true;

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
			//Determine what to print in this grid space
			if (x == m_player->xPosition && y == m_player->yPosition) //The room the player is in
			{
				Print("[P]");
			}
			else if (m_rooms[y][x].visited)
			{
				Print("[ ]");
			}
			else //An undiscovered room
			{
				Print(" ? ");
			}
		}


		//Compass row (this is a pretty bad way of doing it, virtual terminal processing would be better)
		int compassRow = m_mapHeight - y;

		if (compassRow == 1) //Top row
		{
			Print("\t  N");
		}
		else if (compassRow == 2) //Middle row
		{
			Print("\tW + E");
		}
		else if (compassRow == 3) //Bottom row
		{
			Print("\t  S");
		}

		//Next row
		Print("\n");
	}

	Print("\n");
}