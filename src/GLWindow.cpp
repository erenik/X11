/// Emil Hedemalm (base from Fredrik Larsson)
/// 2015-05-20

#include "Windows.h"
#include "GL.h"

#include <GL/glx.h>

void SetupGL(int width, int height);
void Render(Display * display, Window window, bool swapBuffers);

void GLWindow()
{
    Display                 *display;
    Visual                  *visual;
    int                     depth;
    int                     text_x;
    int                     text_y;
    XWindowAttributes 		window_attributes;
    XSetWindowAttributes    frame_attributes;
    Window                  window;
    XFontStruct             *fontinfo;
    XGCValues               gr_values;
    GC                      graphical_context;
    XEvent               event;
    char                    hello_string[] = "Hello World";
    int                     hello_string_length = strlen(hello_string);
    bool swapBuffers = false;
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
    XVisualInfo * visual_info = glXChooseVisual(display, DefaultScreen(display), doubleBufferAttributes);
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

	GLXContext context = glXCreateContext(display, visual_info, None, true);
	if (context == NULL)
	{
		assert(false && "could not create rendering context");
	}
	// bind the rendering context to the window
	bool bound = glXMakeContextCurrent(display, window, window, context);
	if (bound == false)
	{
		assert(false && "Failed to bind context");
	}

    while ( 1 ) {
    	// Screw events?
		XGetWindowAttributes(display, window, &window_attributes);
		SetupGL(window_attributes.width, window_attributes.height);
		Render(display, window, swapBuffers);
		usleep(1000);
/*        XNextEvent(display, (XEvent *)&event);
        switch ( event.type ) {
            case Expose:
            {
            	std::cout<<"\nExpose";
	            break;
            }
            default:
                break;
        }
        */
    }    
}

void SetupGL(int width, int height)
{
	 // Setup rendering
	glEnable(GL_DEPTH_TEST); // enable depth buffering
	glDepthFunc(GL_LESS); // pedantic, GL_LESS is the default
	glClearDepth(1.0); // pedantic, 1.0 is the default
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 1000.0);
	glViewport(0, 0, width, height);
	glEnable(GL_CULL_FACE);
	glDisable(GL_CULL_FACE);
}

void Render(Display * display, Window window, bool swapBuffers)
{
	static float x_rot = 0.f;
	x_rot += 0.2f;
//	std::cout<<"\nx_rot: "<<x_rot;
	// place whats rendered here
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTranslatef(0.0, 0.0, -2.0);
	glRotatef(x_rot, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES); // front side
	glColor3f ( 1.0, 0.0, 0.0 ); // red
	glVertex3f( 0.0, 0.5, 0.0 );
	glColor3f ( 0.0, 1.0, 0.0 ); // green
	glVertex3f( -0.5, -0.5, 0.0 );
	glColor3f ( 0.0, 0.0, 1.0 ); // blue
	glVertex3f( 0.5, -0.5, 0.0 );
	glEnd();
	if(swapBuffers)
	{
		glXSwapBuffers(display, window );
	}
	else
	{
		glFlush();
	}
}
