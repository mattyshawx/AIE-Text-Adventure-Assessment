#include <iostream>

#include "TextAdventureApplication.h"

#ifdef _DEBUG
    #define _CRTDBG_MAP_ALLOC
    #include <crtdbg.h>
#endif


int main()
{
    #if _DEBUG //Catch those pesky bugguses
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
       // _CrtSetBreakAlloc(75325236); //Don't forget to comment this out when not using it mate
    #endif

    //Initialise the text aventure application
    TextAdventureApplication* application = new TextAdventureApplication(5, 3);

    //Run the application
    int runResult = application->Run();

    //Deallocate the application
    delete application;

    //Exit
    return runResult;
}