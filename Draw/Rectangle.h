#pragma once

#include "AbstractShape.h"
#include "utils.h"
#include <functional>

namespace my {
	class Rectangle : public AbstractShape {
	public:
		Rectangle(unsigned int id, Color *color);
		~Rectangle();
		void addPoint(Point *mousePoint);
		void select();
		void clearSelectedStatus();
	private:
		bool selected = false;
		Color *drawingColor;
		Point *topLeft = nullptr, *buttomRight = nullptr;
		void drawFunc();
		void highlightFunc();
	};
}