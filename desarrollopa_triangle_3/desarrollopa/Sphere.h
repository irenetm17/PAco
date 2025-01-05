#pragma once
#include <GL/glut.h>
#include "Solid.h"
#include <vector>
using namespace std;

class Sphere : public Solid
{
private:

	float radius;
	int slices;
	int slacks;

public:

	Sphere(float radiusToSet = 0.5, int slicesToSet = 12, int slacksToset = 24) :
		radius(radiusToSet), slices(slicesToSet), slacks(slacksToset), Solid()
	{ }

	inline float GetRadius() { return this->radius; }
	inline int GetSlices() { return this->slices; }
	inline int GetSlacks() { return this->slacks; }

	void SetRadius(float radiusToSet) { this->radius = radiusToSet; }
	void SetSlices(int slicesToSet) { this->slices = slicesToSet; }
	void SetSlacks(int slacksToSet) { this->slacks = slacksToSet; }

	void Render();

	Solid* Clone();
	void CalcSpeedVector(Vector3D camPos) {};
	bool CalcularCollision(const vector<Solid*>& balas) { return true; }
	int BalaColisionadora(const vector<Solid*>& balas) { return 0; }

};

