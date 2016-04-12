#pragma once

#include <gl\glut.h>
#include "stdafx.h"
#include "Draw.h"

struct Point
{
	GLint x, y;
	Point(GLint x, GLint y) : x(x), y(y) {}
	void draw() { glVertex2i(x, y); }

	static Point* glutPos2Point(int x, int y) {
		return new Point(x - halfWidth, halfHeight - y);
	}
};

struct Color
{
	GLubyte r, g, b;
	Color(GLubyte r, GLubyte g, GLbyte b) : r(r), g(g), b(b) {}
	bool operator== (Color& color2) const {
		return this->r == color2.r && this->g == color2.g && this->b == color2.b;
	}
	void setDrawingColor() const {
		glColor3ub(r, g, b);
	}
	void setBackgroundColor() const {
		glClearColor((GLclampf)(r / 255.0), (GLclampf)(g / 255.0), (GLclampf)(b / 255.0), 0.0);
		glutPostRedisplay();
	}
};