#include "stdafx.h"
#include "ColorWindow.h"

ColorWindow::ColorWindow() :
	CColorDialog(RGB(drawingColor->r, drawingColor->g, drawingColor->b)) {}

Color *ColorWindow::getColorFromUser() {
	if (this->DoModal() == IDOK) {
		COLORREF mfcColor = this->GetColor();
		return new Color(
			(GLubyte)GetRValue(mfcColor),
			(GLubyte)GetGValue(mfcColor),
			(GLubyte)GetBValue(mfcColor)
			);
	}
	else {
		return nullptr;
	}
}