#include "glutFunc.h"


int halfWidth, halfHeight;

bool isSelecting;

Canvas canvas;

ColorWindow colorWindow;

int initGlut(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Draw");
	init();
	initMenu();
	postCallbackFunc();
	glutMainLoop();
	return 0;
}

void init() {
	glEnable(GL_LINE_SMOOTH);
}

void initMenu() {
	glutCreateMenu(menuFunc);
	glutAddMenuEntry("Background color...", 0);
	glutAddMenuEntry("Set color...", 1);
	glutAddMenuEntry("Select mode", 2);
	glutAddMenuEntry("Line", ID(Line));
	glutAddMenuEntry("Rectangle", ID(Rectangle));
	glutAddMenuEntry("Triangle", ID(Triangle));
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menuFunc(int value) {
	switch (value)
	{
	case 0://Backgorund color
		canvas.setBackgroundColor(colorWindow.getColorFromUser());
		break;
	case 1://Set Color
		canvas.setDrawingColor(colorWindow.getColorFromUser());
		break;
	case 2://Select mode
		isSelecting = true;
		break;
	case ID(Line):
		isSelecting = false;
		canvas.clearSelectedStatus();
		drawingShapeID = ID(Line);
		break;
	case ID(Rectangle):
		isSelecting = false;
		canvas.clearSelectedStatus();
		drawingShapeID = ID(Rectangle);
		break;
	case ID(Triangle):
		isSelecting = false;
		canvas.clearSelectedStatus();
		drawingShapeID = ID(Triangle);
		break;
	}
}

void postCallbackFunc() {
	glutDisplayFunc(displayFunc);
	glutReshapeFunc(reshapeFunc);
	glutMouseFunc(mouseFunc);
}

void reshapeFunc(int width, int height) {
	halfWidth = width / 2;
	halfHeight = height / 2;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
	glViewport(0, 0, width, height);
}

void displayFunc() {
	glClear(GL_COLOR_BUFFER_BIT);
	canvas.draw();
	glFlush();
}

void mouseFunc(int button, int state, int x, int y) {
	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN) return;
	if (isSelecting) {
		canvas.selectShape(Point(x,y));
	} else {
		canvas.addPoint(Point::glutPos2Point(x, y));
	}
}