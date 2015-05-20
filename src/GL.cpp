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