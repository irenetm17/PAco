#include "Text.h"

using namespace std;

void Text::Render()
{
	glPushMatrix();
	glColor4f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue(), this->GetColor().GetAlpha());
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(),this->GetPosition().GetZ());
	glRasterPos3d(0, 0, 0);
	for (char c : text) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	//GLUT_BITMAP_TIMES_ROMAN_24: fuente Times Roman de tamaño 24 puntos.
	//GLUT_BITMAP_HELVETICA_10 : fuente Helvetica de tamaño 10 puntos.

	glPopMatrix();
}





