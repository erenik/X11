/// Emil Hedemalm
/// 2015-05-20
/// GL-dedicated XWindow.

#ifndef GL_WINDOW_H
#define GL_WINDOW_H

#include "Windows.h"
#include "GL.h"

#include <GL/glx.h>

class AEWindow
{
public:
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
    const char * hello_string;
    int  hello_string_length;
    bool swapBuffers;
    
    XVisualInfo * visual_info;
    GLXContext context;

    /// o.o
    float triangleRot;

    AEWindow();
    /// Creates a dedicated thread to create and maintain this window.
    void Create();  
    void CreateGLContext();
    void Render();
};

#define MAX_WINDOWS 3
extern AEWindow windows[MAX_WINDOWS];

#endif
