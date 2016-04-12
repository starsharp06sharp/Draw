#include "Shape.h"

AbstractShape* getNewShape(int shapeID, unsigned int id, Color *color) {
	switch (shapeID) {
	case ID(Line):
		return new Line(id, new Color(*color));
		break;
	case ID(Rectangle):
		return new my::Rectangle(id, new Color(*color));
		break;
	case ID(Triangle):
		return new Triangle(id, new Color(*color));
		break;
	}
}
