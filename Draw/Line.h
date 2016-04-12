#pragma once

#include "AbstractShape.h"
#include "utils.h"
#include <functional>

class Line : public AbstractShape {
public:
	Line(unsigned int id, Color *color);
	~Line();
	void addPoint(Point *mousePoint);
	void select();
	void clearSelectedStatus();
private:
	bool selected = false;
	Color *drawingColor;
	Point *start = nullptr, *end = nullptr;
	void drawFunc();
	void highlightFunc();
};