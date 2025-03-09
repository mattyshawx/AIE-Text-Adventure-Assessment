#include "ItemTemplate.h"

#include "ConsoleTools.h"


//------------------------------------------------------------------------
//					Constructor
//------------------------------------------------------------------------

//Creates a ____
ItemName::ItemName()
{
	//Set the description and name
	name = "object";
	m_description = "A strange object.";
}


//------------------------------------------------------------------------
//					Overridden public functions
//------------------------------------------------------------------------

//Describes the ____
void ItemName::Describe()
{
	//Print the description
	Print(m_description);
}

//Makes the player ____
void ItemName::Use()
{

}
