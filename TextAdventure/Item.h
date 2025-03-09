#pragma once

#include "TextAdventureBase.h"


class Item : public TextAdventureBase
{

	//Constructor
public:

	Item();

	//Public functions
public:

	virtual void Use();

	//Public variables
public:

	string name; //Used to identify the item with the "use" command

};

