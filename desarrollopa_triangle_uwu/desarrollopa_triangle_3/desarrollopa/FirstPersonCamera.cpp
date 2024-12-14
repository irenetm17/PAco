#include "FirstPersonCamera.h"
#include <GL/freeglut.h>
#include <chrono>

using namespace std;
using namespace chrono;

void FirstPersonCamera::Render()
{
	glRotatef(this->GetOrientation().GetX(), 1, 0, 0);
	glRotatef(this->GetOrientation().GetY(), 0, 1, 0);glRotatef(this->GetOrientation().GetX(), 1, 0, 0);
	glRotatef(this->GetOrientation().GetZ(), 0, 0, 1);
	glTranslatef(-1 * this->GetPosition().GetX(), -1 * this->GetPosition().GetY(), -1 * this->GetPosition().GetZ());
}

void FirstPersonCamera::Update(const float& time){
	this->SetSpeed(this->calcSpeedVector());
	Camera::Update(time);
}

Vector3D FirstPersonCamera::calcSpeedVector() 
{
	float yOrientation = degToRad(this->GetOrientation().GetY());
	float xOrientation = degToRad(this->GetOrientation().GetX());

	//Flying camera
	//float xComponent = sin(yOrientation) * cos(xOrientation);
	//float yComponent = -sin(xOrientation);
	//float zComponent = -cos(yOrientation) * cos(xOrientation);

	//Walking camera
	float xComponent = sin(yOrientation);
	float yComponent = 0;
	float zComponent = -cos(yOrientation);

	Vector3D speedVector = { xComponent, yComponent, zComponent };
	return speedVector;
}

void FirstPersonCamera::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key)
	{
	case 'a':
	case 'A':

		break;

	case 'w':
	case 'W':
		this->Update(this->cameraStep);
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

void FirstPersonCamera::ProcessMouseMovement(int x, int y)
{
	if (this->GetMouseX() >= 0 && this->GetMouseY() >= 0)
	{
		Vector3D orientation = this->GetOrientation() + Vector3D(y - this->GetMouseY(), x - this->GetMouseX(), 0);
		this->SetOrientation(orientation);
	}
	this->SetMouseX(x);
	this->SetMouseY(y);
}





















