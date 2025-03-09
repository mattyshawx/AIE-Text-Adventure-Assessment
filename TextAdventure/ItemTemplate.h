#pragma once

#include "Item.h"


class ItemName : public Item
{

	//Constructor
public:

	ItemName();

	//Public functions
public:

	void Describe() override;

	void Use() override;

	//Private variables
private:

	

};

