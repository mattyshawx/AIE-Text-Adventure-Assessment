#pragma once


class Minimap
{

	//Constructor and destructor
public:

	Minimap(int mapHeight, int mapWidth, vector<vector<Room>>& rooms, Player& player);

	~Minimap();

	//Public functions
public:

	void Draw();

	//Private variables
private:

	int m_mapWidth;
	int m_mapHeight;

	vector<vector<Room>>& m_rooms;
	Player& player
};

