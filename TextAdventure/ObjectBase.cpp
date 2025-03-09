#include "ObjectBase.h"

#include "ConsoleTools.h"


//------------------------------------------------------------------------
//					Constructors
//------------------------------------------------------------------------

//Default constructor, no description given
ObjectBase::ObjectBase()
{
	//Give it a default description
	m_description = "A mysterious, undescribed object";
}

//Constructor that takes in a description
ObjectBase::ObjectBase(string description)
{
	//Set the description
	m_description = description;
}

//------------------------------------------------------------------------
//					Public functions
//------------------------------------------------------------------------

//This just returns the description
void ObjectBase::Describe()
{
	Print(m_description + "\n");
}
