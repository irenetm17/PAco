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

Solid* Camera::Clone()
{
    return new Camera(*this);
}