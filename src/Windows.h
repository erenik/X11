/// Emil Hedemalm
/// 2015-05-20
/// Window creation functions. Each has its own .cpp file.

#ifndef WINDOWS_H
#define WINDOWS_H

// Basics
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <unistd.h>

// Debugging/assertions
#include <cassert>

#include <iostream> // Because debugging.


void BasicWindow();
void SingleGLWindow();
void MultiGLWindows();

#endif
