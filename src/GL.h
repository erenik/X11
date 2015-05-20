/// Emil Hedemalm
/// 2015-05-20
/// GL basics

#ifndef GL_H
#define GL_H

#include <GL/glew.h>
#include <GL/gl.h>

// Init glew, check version, init gl and check versions.
void InitGlewAndGL();

/// Sets up View and Projection matrices for test-rendering.
void SetupViewProjectionGL(int width, int height);
void RenderTriangle(float triRot);


#endif
