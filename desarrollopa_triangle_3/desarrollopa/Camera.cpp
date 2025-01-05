#include <GL/freeglut.h>
#include <iostream>
#include "Camera.h"

using namespace std;

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
/*
void Camera::MoverCamara(char key)
{
    float camaraVel = 0.1f;
    Vector3D pos = GetPosition();
    
    cout << "La camara se mueve" << endl;
    switch (key) {
    case 'w':
        pos = pos.Add(Vector3D(0.0f, 0.0f, -camaraVel));
        break;
    case 's':
        pos = pos.Add(Vector3D(0.0f, 0.0f, camaraVel));
        break;
    case 'a':
        pos = pos.Add(Vector3D(-camaraVel, 0.0f, 0.0f));
        break;
    case 'd':
        pos = pos.Add(Vector3D(camaraVel, 0.0f, 0.0f));
        break;
    default: //para cualquier otra letra no hace nada
        break;
    }
    
    // Actualizar la posición de la cámara
    SetPosition(pos);
} */
/**
void Camera::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key)
	{
	case 'a':
	case 'A':

		break;

	case 'w':
	case 'W':
		this->SetPosition(this->GetPosition() + (Vector3D(0.0, 0.0, 1.0) * this->cameraStep));
		//this->Update(this->cameraStep);
		break;

	case 's':
	case 'S':
		this->Update(-1 * this->cameraStep);
		break;

	case 'd':
	case 'D':

		break;
	}
}
*/

Solid* Camera::Clone()
{
    return new Camera(*this);
}