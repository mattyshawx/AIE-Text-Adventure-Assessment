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
			m_rooms[y][x] = new Room(
				GenerateRoomDescription(),
				PickRandomItem()
			);
		}
	}
	
	//Create the player
	m_player = new Player(0, 0, m_mapWidth, m_mapHeight);
}

TextAdventureApplication::~TextAdventureApplication()
{
	for (int y = 0; y < m_mapHeight; y++)
	{
		for (int x = 0; x < m_mapWidth; x++)
		{
			delete m_rooms[y][x];
		}
	}

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
		m_player->currentRoom->Describe();

		//See what action the user would like to take
		PrintDivider();
		Print("Think of what to do (move [direction], use [object], spell, quit game)");

		string inputString;
		Input(&inputString);

		Print("\n");

		//Try to handle the input
		if (inputString.substr(0, 5) == "move ") //Move
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
			else if (direction == "") //Nowhere
			{
				PrintAndWaitForEnter("You just stand there...");
				continue;
			}
			else //Something invalid
			{
				PrintAndWaitForEnter("You try to walk \"" + direction + "\". You confuse yourself.");
				continue;
			}

			//Try and move
			if (m_player->Move(xDirection, yDirection)) //Valid move
			{
				//Set the new room
				EnterRoom(m_player->xPosition, m_player->yPosition);
			}
			else //Move out of bounds
			{
				PrintAndWaitForEnter("You walk " + direction + " into a wall. Your head aches");
			}
			
		}
		else if (inputString.substr(0, 4) == "use ") //Use item
		{
			//Interpret the item to use from the input
			string itemToUse = inputString.substr(4);

			Item* roomItem = (m_player->currentRoom->item);

			//See if an item was inputted at all
			if (itemToUse == "")
			{
				PrintAndWaitForEnter("You do nothing...");
				continue;
			}

			//Make sure there even is an item in the room
			if (roomItem == nullptr)
			{
				PrintAndWaitForEnter("The room is empty, but you think see something... You are hallucinating.");
				continue;
			}

			//Make sure that a present item was entered
			string roomItemName = roomItem->name;

			if (roomItemName != itemToUse)
			{
				PrintAndWaitForEnter("There's a " + roomItemName + " in front of you, but it looks like a " + itemToUse + " to you.\nAre you drunk?");
				continue;
			}

			//Use the item
			roomItem->Use();
			PrintAndWaitForEnter("");
		}
		else if (inputString == "quit game") //Quit game
		{
			PrintAndWaitForEnter("You rage quit and escape the matrix. I will get you for this!");

			break; //Get out of the game loop
		}
		else //Invalid input
		{
			PrintAndWaitForEnter("Your brain switches off, you try to \"" + inputString + "\". Nothing happens.");
		}
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
	m_player->currentRoom = m_rooms[yPosition][xPosition];

	//Mark the room as visited
	m_player->currentRoom->visited = true;

	//Move the player
	m_player->xPosition = xPosition;
	m_player->yPosition = yPosition;

	//Reset the window colour
	ResetConsoleColour();
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
			else if (!m_rooms[y][x]->visited) //An undiscovered room
			{
				Print(" ? ");
			}
			else if (m_rooms[y][x]->item != nullptr) // room has an item in it
			{
				Print("[i]");
			}
			else if (m_rooms[y][x]->visited) //The room has been visited before
			{
				Print("[ ]");
			}
		}


		//Text next to the minimap (this is a pretty bad way of doing it, virtual terminal processing would be better)
		int sideRow = m_mapHeight - y;

		if (sideRow == 1) //Top of compass
		{
			Print("\t  N");
		}
		else if (sideRow == 2) //Middle of compass
		{
			Print("\tW + E");
		}
		else if (sideRow == 3) //Bottom of compass
		{
			Print("\t  S");
		}
		else if (sideRow == 5) //Player key
		{
			Print("\tP = player");
		}
		else if (sideRow == 6) //Item key
		{
			Print("\ti = item");
		}

		//Next row
		if (y > 0)
		{
			Print("\n");
		}
	}

	PrintDivider();
}