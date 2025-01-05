#pragma once
#include <GL/glut.h>
#include "Solid.h"
#include <vector>
using namespace std;

class Teapot : public Solid
{
private:
	float size;

public:

	Teapot() : size(0.6), Solid() {}

	inline float GetSize() { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }
	
	void Render();

	Solid* Clone();
	void CalcSpeedVector(Vector3D camPos) {};
	bool CalcularCollision(const vector<Solid*>& balas) { return true; }
	int BalaColisionadora(const vector<Solid*>& balas) { return 0; }
};

