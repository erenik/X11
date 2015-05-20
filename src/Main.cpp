/// Emil Hedemalm (base from Fredrik Larsson)
/// 2015-05-20

#include <iostream>

#include "Windows.h"

int main (int argc, char *argv[])
{
    int mode = 0;
    enum{ 
        BASIC,
        BASIC_GL,
    };
    for (int i = 0; i < argc; ++i)
    {
        char * arg = argv[i];
        std::cout<<"\nArg "<<i<<": "<<argv[i];
        if (i == 1)
        {
            if (strcmp(arg, "basic") == 0)
                mode = 0;
            if (strcmp(arg, "gl") == 0)
                mode = BASIC_GL;
               
        }
    }
    switch(mode)
    {
        case BASIC:
            std::cout<<"\nCreating basic window";
            BasicWindow();
            break;
        case BASIC_GL:
            GLWindow();
            break;
        default:
            std::cout<<"\nBad mode. Available modes: basic, gl";
    } 
    std::cout<<"\nExiting";
    return 0;
}

