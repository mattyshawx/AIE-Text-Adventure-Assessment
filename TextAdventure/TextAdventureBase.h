#pragma once

#include <string>


using std::string;


class TextAdventureBase
{

	//Constructors
public:
	
	TextAdventureBase();
	TextAdventureBase(string description);

	//Public functions
public:
	virtual void Describe();

	//Protected variables
protected:

	string m_description;

};

