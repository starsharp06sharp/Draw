#pragma once
#include <vector>
#include "utils.h"
#include "AbstractShape.h"
#include "Shape.h"

extern int drawingShapeID;
extern Color *drawingColor;

class Canvas {
public:
	void addPoint(Point *mousePoint);
	Color* getBackgroundColor() const;
	void setBackgroundColor(Color *backgroundColor);
	static void setDrawingColor(Color *drawingColor);
	void draw(GLenum mode = GL_RENDER);
	void selectShape(Point &mousePoint);
	void clearSelectedStatus();
private:
	std::vector<AbstractShape*> shapes;
	Color *backgroundColor = new Color(0, 0, 0);
	void handleHits(GLint hits, GLuint buffer[]);
};