/// Emil Hedemalm (base from Fredrik Larsson)
/// 2015-05-20

#include "AEWindow.h"

// Test windows.
AEWindow windows[MAX_WINDOWS];

AEWindow::AEWindow()
{
	swapBuffers = false;
 	hello_string = "Hello World";
    hello_string_length = strlen(hello_string);
   	triangleRot = 0.f;
}

/// Creates a dedicated thread to create and maintain this window.
void AEWindow::Create()
{
	display = XOpenDisplay(NULL);
    visual = DefaultVisual(display, 0);
    depth  = DefaultDepth(display, 0);
    
    frame_attributes.background_pixel = XWhitePixel(display, 0);
    // create the application window 
    window = XCreateWindow(display, XRootWindow(display, 0), 0, 0, 400, 400, 5, depth, InputOutput, visual, CWBackPixel, &frame_attributes);
    XStoreName(display, window, "Hello World Example");
    XSelectInput(display, window, ExposureMask | StructureNotifyMask);

    fontinfo = XLoadQueryFont(display, "10x20");
    gr_values.font = fontinfo->fid;
    gr_values.foreground = XBlackPixel(display, 0);

    graphical_context = XCreateGC(display, window, GCFont+GCForeground, &gr_values);
    XMapWindow(display, window);

    /// Create context?
    int singleBufferAttributes[10] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, None};
	int doubleBufferAttributes[10] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};
    visual_info = glXChooseVisual(display, DefaultScreen(display), doubleBufferAttributes);
	if (visual_info == NULL)
	{
		std::cout << "No double buffer" << std::endl;
		visual_info = glXChooseVisual(display, DefaultScreen(display), singleBufferAttributes);
		if (visual_info == NULL)
		{
			assert(false && "no depth buffer");
		}
	}
	else
	{
		swapBuffers = true;
	}
}

void AEWindow::CreateGLContext()
{
	context = glXCreateContext(display, visual_info, None, true);
	if (context == NULL)
	{
		assert(false && "could not create rendering context");
	}
}


void AEWindow::Render()
{
	// Spawn a thread for each?
	// bind the rendering context to the window
	bool bound = glXMakeContextCurrent(display, window, window, context);
	if (bound == false)
	{
		assert(false && "Failed to bind context");
	}
	// Screw events?
	XGetWindowAttributes(display, window, &window_attributes);
	SetupViewProjectionGL(window_attributes.width, window_attributes.height);
	RenderTriangle(triangleRot);
	if(swapBuffers)
	{
		glXSwapBuffers(display, window );
	}
	else
	{
		glFlush();
	}
}
