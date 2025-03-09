#pragma once

#include "Item.h"


class Cat : public Item
{

	//Constructor
public:

	Cat();

	//Public functions
public:

	void Describe() override;

	void Use() override;

	//Private variables
private:

	bool m_purring;

};

