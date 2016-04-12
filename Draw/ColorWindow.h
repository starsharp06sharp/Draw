#pragma once
#include "stdafx.h"
#include <gl\glut.h>
#include "utils.h"
#include "Canvas.h"

class ColorWindow : CColorDialog {
public:
	ColorWindow();
	Color *getColorFromUser();
};