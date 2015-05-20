/// Emil Hedemalm (base from Fredrik Larsson)
/// 2015-05-20

#include "Windows.h"
#include "AEWindow.h"

void * RenderThread(void * args);



void SeparateRenderThreadMultiGLWindows()
{
	for (int i = 0; i < MAX_WINDOWS; ++i)
	{
   		AEWindow & window = windows[i];
   		window.Create();
	}

	// Start the render-thread.

	pthread_t graphicsThread; 
	pthread_create(&graphicsThread, NULL, RenderThread, NULL);

	// Adjust rotations in this thread to demo it.
	while(1)
	{
		for (int i = 0; i < MAX_WINDOWS; ++i)
		{
			AEWindow & window = windows[i];
			float f = 0.f;
			switch(i)
			{
				case 0: f = 0.1f; break;
				case 1: f= -0.2f; break;
				case 2: f = 0.3f; break;
			}
			window.triangleRot += f;
		}
		usleep(1000);
	}
}

void * RenderThread(void * args)
{
	// Create contexts
	for (int i = 0; i < MAX_WINDOWS; ++i)
	{
   		AEWindow & window = windows[i];
   		window.CreateGLContext();
	}

    while ( 1 ) {
    	for (int i = 0; i < MAX_WINDOWS; ++i)
    	{
    		AEWindow & window = windows[i];
    		window.Render();

    	}
		usleep(1000);
    }    
    // Clean-up?

}

