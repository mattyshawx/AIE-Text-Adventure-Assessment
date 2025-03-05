#include "TextAdventureBase.h"


//------------------------------------------------------------------------
//					Constructor and destructor
//------------------------------------------------------------------------

//Default constructor, no description given
TextAdventureBase::TextAdventureBase()
{
	//Give it a default description
	m_description = "A mysterious, undescribed object";
}

//Constructor that takes in a description
TextAdventureBase::TextAdventureBase(string description)
{
	//Set the description
	m_description = description;
}

TextAdventureBase::~TextAdventureBase()
{

}

//------------------------------------------------------------------------
//					Public functions
//------------------------------------------------------------------------

//This just returns the description
string TextAdventureBase::Describe()
{
	return m_description + "\n";
}
