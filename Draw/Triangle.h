#pragma once

#include "AbstractShape.h"
#include "utils.h"
#include <functional>

class Triangle : public AbstractShape {
public:
	Triangle(unsigned int id, Color *color);
	~Triangle();
	void addPoint(Point *mousePoint);
	void select();
	void clearSelectedStatus();
private:
	bool selected = false;
	Color *drawingColor;
	Point *vertexs[3]{ nullptr, nullptr, nullptr };
	void drawFunc();
	void highlightFunc();
};