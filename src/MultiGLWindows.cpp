/// Emil Hedemalm (base from Fredrik Larsson)
/// 2015-05-20

#include "Windows.h"
#include "AEWindow.h"

void MultiGLWindows()
{

#define MAX_WINDOWS 3
	AEWindow windows[MAX_WINDOWS];
	for (int i = 0; i < MAX_WINDOWS; ++i)
	{
   		AEWindow & window = windows[i];
   		window.Create();
   		window.CreateGLContext();
	}

    while ( 1 ) {
    	for (int i = 0; i < MAX_WINDOWS; ++i)
    	{
    		AEWindow & window = windows[i];
        window.triangleRot += 0.4f + i * 0.1f;
    		window.Render();

    	}
		usleep(1000);
    }    
}

