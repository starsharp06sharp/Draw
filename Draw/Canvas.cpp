#include "Canvas.h"

int drawingShapeID = ID(Line);
Color *drawingColor = new Color(255, 255, 255);

void Canvas::addPoint(Point *mousePoint) {
	if (this->shapes.size() == 0 || this->shapes.back()->commited) {
		this->shapes.push_back(getNewShape(
			drawingShapeID,
			this->shapes.size() + 1,
			drawingColor
		));
	}
	this->shapes.back()->addPoint(mousePoint);
}

Color* Canvas::getBackgroundColor() const {
	return this->backgroundColor;
}

void Canvas::setBackgroundColor(Color *backgroundColor) {
	if (backgroundColor == nullptr) return;
	if (*(this->backgroundColor) == *backgroundColor) {
		delete backgroundColor;
	}
	else {
		delete this->backgroundColor;
		this->backgroundColor = backgroundColor;
		this->backgroundColor->setBackgroundColor();
	}
}

void Canvas::setDrawingColor(Color *drawingColor) {
	if (drawingColor == nullptr) return;
	if (*drawingColor == *::drawingColor) {
		delete drawingColor;
	}
	else {
		delete ::drawingColor;
		::drawingColor = drawingColor;
	}
}

void Canvas::draw(GLenum mode) {
	for (auto shape : shapes) {
		shape->draw(mode);
	}
}

void Canvas::selectShape(Point &mousePoint) {
	constexpr int SIZE = 1024;
	constexpr GLdouble SELECT_WIDTH = 3;
	constexpr GLdouble SELECT_HEIGHT = 3;
	GLuint nameBuffer[SIZE];
	GLint hits;
	GLint viewport[4];

	glSelectBuffer(SIZE, nameBuffer);
	glGetIntegerv(GL_VIEWPORT, viewport);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glRenderMode(GL_SELECT);
	glInitNames();
	glPushName(0);

	gluPickMatrix(
		(GLdouble)mousePoint.x, (GLdouble)(viewport[3] - mousePoint.y),
		SELECT_WIDTH, SELECT_HEIGHT,
		viewport
		);
	gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
	this->draw(GL_SELECT);
	glMatrixMode(GL_PROJECTION);

	glPopMatrix();
	hits = glRenderMode(GL_RENDER);
	this->handleHits(hits, nameBuffer);
	glutPostRedisplay();
}

void Canvas::handleHits(GLint hits, GLuint buffer[]) {
	GLuint *ptr = buffer;
	for (int i = 0; i < hits; ++i) {
		int names = *ptr;
		ptr += 3;
		for (int j = 0; j < names; ++j) {
			int id = *ptr;
			this->shapes.at(id - 1)->select();
			ptr++;
		}
	}
}

void Canvas::clearSelectedStatus() {
	for (auto shape : shapes) {
		shape->clearSelectedStatus();
	}
	glutPostRedisplay();
}