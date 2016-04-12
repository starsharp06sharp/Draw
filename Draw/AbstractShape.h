#pragma once

#include "utils.h"
#include <gl\glut.h>
#include <functional>

const Color highlightColor(255, 255, 0);

class AbstractShape {
public:
	unsigned int id;
	bool commited = false;
	AbstractShape(unsigned int id) : id(id) {}
	void draw(GLenum mode = GL_RENDER);
	virtual void addPoint(Point *mousePoint) = 0;
	virtual void select() = 0;
	virtual void clearSelectedStatus() = 0;
protected:
	void commit(std::function<void()> func);
};