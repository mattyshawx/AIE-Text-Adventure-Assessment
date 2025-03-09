#pragma once

#include "Item.h"


class Lamp : public Item
{

	//Constructor
public:

	Lamp();

	//Public functions
public:

	void Describe() override;

	void Use() override;

	void UpdateColour();

	//Private variables
private:

	bool m_turnedOn;

};

