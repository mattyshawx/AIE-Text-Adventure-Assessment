#pragma once

#include <string>


using std::string;


class TextAdventureBase
{

	//Constructors and destructor
public:
	
	TextAdventureBase();
	TextAdventureBase(string description);
	~TextAdventureBase();

	//Public functions
public:
	virtual string Describe();

	//Protected variables
protected:

	string m_description;

};

