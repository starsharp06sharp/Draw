#include "AbstractShape.h"

void AbstractShape::draw(GLenum mode) {
	if (this->commited) {
		if (mode == GL_SELECT) {
			glLoadName(this->id);
		}
		glCallList(this->id);
	}
}

void AbstractShape::commit(std::function<void()> func) {
	glNewList(this->id, GL_COMPILE);
	glPushAttrib(GL_CURRENT_BIT);
		func();
	glPopAttrib();
	glEndList();
	this->commited = true;
	glutPostRedisplay();
}