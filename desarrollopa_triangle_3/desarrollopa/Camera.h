#pragma once
#include "Solid.h"
class Camera : public Solid
{
private:


public:
	Camera() {}

	Camera(Vector3D pos) : Solid() { this->SetPosition(pos); }


	void Render();
	//void MoverCamara(char key);

	virtual void ProcessMouseMovement(int x, int y) {};
	virtual void ProcessKeyPressed(unsigned char key, int px, int py) {};
	Solid* Clone();
	void CalcSpeedVector(Vector3D camPos) {};
};

