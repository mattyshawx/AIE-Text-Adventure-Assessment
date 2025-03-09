#pragma once

#include "ObjectBase.h"


class Item : public ObjectBase
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

