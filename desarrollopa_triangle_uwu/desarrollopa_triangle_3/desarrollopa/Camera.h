#pragma once
#include "Solid.h"
class Camera : public Solid
{
private:

public:
	Camera() {}

	Camera(Vector3D pos) { this->SetPosition(pos); }

	void Render();
	//void MoverCamara(char key);

	Solid* Clone();
};

