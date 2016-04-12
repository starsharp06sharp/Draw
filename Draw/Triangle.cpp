#include "Triangle.h"

Triangle::Triangle(unsigned int id, Color *color) :
	AbstractShape(id), drawingColor(color) {}

Triangle::~Triangle() {
	delete this->drawingColor;
	for (auto& vertex : vertexs) {
		delete vertex;
	}
}

void Triangle::addPoint(Point *mousePoint) {
	int i = 0;
	while (vertexs[i] != nullptr) ++i;
	this->vertexs[i] = mousePoint;
	if (i == 2) this->commit(std::bind(&Triangle::drawFunc, this));
}

void Triangle::drawFunc() {
	drawingColor->setDrawingColor();
	glBegin(GL_POLYGON);
	for (auto& vertex : vertexs) {
		vertex->draw();
	}
	glEnd();
}

void Triangle::highlightFunc() {
	this->drawFunc();
	highlightColor.setDrawingColor();
	glBegin(GL_LINE_LOOP);
	for (auto& vertex : vertexs) {
		vertex->draw();
	}
	glEnd();
}

void Triangle::select() {
	std::cout << "Triangle" << this->id << std::endl;
	if (!this->selected) {
		this->selected = true;
		this->commit(std::bind(&Triangle::highlightFunc, this));
	}
}

void Triangle::clearSelectedStatus() {
	this->commit(std::bind(&Triangle::drawFunc, this));
	this->selected = false;
}