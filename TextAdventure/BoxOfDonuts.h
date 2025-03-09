#pragma once

#include "Item.h"


class BoxOfDonuts : public Item
{

	//Constructor and destructor
public:

	BoxOfDonuts();

	//Public functions
public:

	void Describe() override;

	void Use() override;

	//Private variables
private:

	int m_count;
	bool m_canEat;
	bool m_isRevolting;

};

