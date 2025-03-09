#include "TextAdventureBase.h"

#include "ConsoleTools.h"


//------------------------------------------------------------------------
//					Constructors
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

//------------------------------------------------------------------------
//					Public functions
//------------------------------------------------------------------------

//This just returns the description
void TextAdventureBase::Describe()
{
	Print(m_description + "\n");
}
