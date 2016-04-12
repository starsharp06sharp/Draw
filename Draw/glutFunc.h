#pragma once
#include <gl\glut.h>
#include <iostream>
#include "Draw.h"
#include "Shape.h"
#include "Canvas.h"
#include "ColorWindow.h"

int initGlut(int argc, char **argv);
void initMenu();
void postCallbackFunc();
void menuFunc(int value);
void mouseFunc(int button, int state, int x, int y);
void reshapeFunc(int width, int height);
void displayFunc();
void init();