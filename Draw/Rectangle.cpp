#include "Rectangle.h"

using namespace my;

Rectangle::Rectangle(unsigned int id, Color *color) :
	AbstractShape(id), drawingColor(color) {}

Rectangle::~Rectangle() {
	delete this->drawingColor;
	delete this->topLeft;
	delete this->buttomRight;
}

void Rectangle::addPoint(Point *mousePoint) {
	if (this->topLeft == nullptr) {//×óÉÏµã
		this->topLeft = mousePoint;
	}
	else {
		this->buttomRight = mousePoint;
		this->commit(std::bind(&Rectangle::drawFunc, this));
	}
}

void Rectangle::drawFunc() {
	drawingColor->setDrawingColor();
	glRecti(this->topLeft->x, this->topLeft->y, this->buttomRight->x, this->buttomRight->y);
}

void Rectangle::highlightFunc() {
	this->drawFunc();
	highlightColor.setDrawingColor();
	glBegin(GL_LINE_LOOP);
		glVertex2i(this->topLeft->x, this->topLeft->y);
		glVertex2i(this->topLeft->x, this->buttomRight->y);
		glVertex2i(this->buttomRight->x, this->buttomRight->y);
		glVertex2i(this->buttomRight->x, this->topLeft->y);
	glEnd();
}

void Rectangle::select() {
	std::cout << "Rectangle" << this->id << std::endl;
	if (!this->selected) {
		this->selected = true;
		this->commit(std::bind(&Rectangle::highlightFunc, this));
	}
}

void Rectangle::clearSelectedStatus() {
	this->commit(std::bind(&Rectangle::drawFunc, this));
	this->selected = false;
}