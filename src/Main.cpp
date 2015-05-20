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
        MULTI_GL,
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
            if (strcmp(arg, "multi-gl") == 0)
                mode = MULTI_GL;
            
               
        }
    }
    switch(mode)
    {
        case BASIC:
            std::cout<<"\nCreating basic window";
            BasicWindow();
            break;
        case BASIC_GL:
            SingleGLWindow();
            break;
        case MULTI_GL:
            MultiGLWindows();
        default:
            std::cout<<"\nBad mode. Available modes: basic, gl, multi-gl";
    } 
    std::cout<<"\nExiting";
    return 0;
}

