#pragma once

#include <string>


using std::string;


class ObjectBase
{

	//Constructors
public:
	
	ObjectBase();
	ObjectBase(string description);

	//Public functions
public:
	virtual void Describe();

	//Protected variables
protected:

	string m_description;

};

