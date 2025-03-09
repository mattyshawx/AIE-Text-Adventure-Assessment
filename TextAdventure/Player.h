#pragma once

#include <vector>
#include <string>


using std::string;
using std::vector;


class Room;


class Player
{

	//Constructor and destructor
public:

	Player(int initialXPosition, int initialYPosition, int mapWidth, int mapHeight);
	~Player();

	//Public functions
public:

	bool Move(int xDirection, int yDirection);

	void PrintSpells();

	bool FindSpell(string spellName);

	//Public variables
public:

	//Position
	int xPosition;
	int yPosition;

	Room* currentRoom;

	//Private variables
private:

	//Inventory
	vector<string> m_spells;

	//Bounds
	int m_mapWidth;
	int m_mapHeight;

};

