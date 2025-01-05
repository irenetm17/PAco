#pragma once
#include "Solid.h"
#include <vector>
using namespace std;
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
	bool CalcularCollision(const vector<Solid*>& balas) { return true; }

	int BalaColisionadora(const vector<Solid*>& balas) { return 0; }
};

