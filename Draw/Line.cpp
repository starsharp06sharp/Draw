#include "Line.h"

Line::Line(unsigned int id, Color *color) :
	AbstractShape(id), drawingColor(color) {}

void Line::addPoint(Point *mousePoint) {
	if (this->start == nullptr) {//第一个点
		this->start = mousePoint;
	}
	else {
		this->end = mousePoint;
		this->commit(std::bind(&Line::drawFunc, this));
	}
}

void Line::drawFunc() {
	drawingColor->setDrawingColor();
	glBegin(GL_LINES);
		this->start->draw();
		this->end->draw();
	glEnd();
}

void Line::highlightFunc() {
	highlightColor.setDrawingColor();
	glBegin(GL_LINES);
		this->start->draw();
		this->end->draw();
	glEnd();
}

void Line::select() {
	std::cout << "Line" << this->id << std::endl;
	if (!this->selected) {
		this->selected = true;
		this->commit(std::bind(&Line::highlightFunc, this));
	}
}

void Line::clearSelectedStatus() {
	this->commit(std::bind(&Line::drawFunc, this));
	this->selected = false;
}

Line::~Line() {
	delete this->drawingColor;
	delete this->start;
	delete this->end;
}
