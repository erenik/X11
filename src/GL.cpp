/// Emil Hedemalm
/// 2015-05-20
/// GL basics

#include "GL.h"
#include <iostream>
#include <cassert>

// Init glew, check version, init gl and check versions.
void InitGlewAndGL()
{
	 // initializing glew
	GLenum err = glewInit();
	// check if glew is ok
	if (GLEW_OK != err)
	{
	assert(false && "Error: " && glewGetErrorString(err));
	}
	std::cout << "GLEW version" << std::endl;
	std::cout << "\t" << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "GL version" << std::endl;
	std::cout << "\t" << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version" << std::endl;
	std::cout << "\t" << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}



void SetupViewProjectionGL(int width, int height)
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

void RenderTriangle()
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
}

