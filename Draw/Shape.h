#pragma once

#include "utils.h"
#include "AbstractShape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"

#define ID(Shape) Shape##ID

enum ShpaeID {
	ID(AbstractShape) = 3,
	ID(Line),
	ID(Rectangle),
	ID(Triangle),
};

AbstractShape* getNewShape(int shapeID, unsigned int id, Color *color);
