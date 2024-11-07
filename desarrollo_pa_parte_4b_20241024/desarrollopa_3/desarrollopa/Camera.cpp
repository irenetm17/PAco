#include <GL/freeglut.h>
#include "Camera.h"

void Camera::Render()
{
	glTranslatef(
		-1 * this->GetPosition().GetX(),
		-1 * this->GetPosition().GetY(),
		-1 * this->GetPosition().GetZ());
	glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);
}

Solid* Camera::Clone()
{
	return new Camera(*this);
}