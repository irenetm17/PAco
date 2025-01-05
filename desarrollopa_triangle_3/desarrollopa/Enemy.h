#pragma once
using namespace std;
#include <string>
#include "Solid.h"
#include <vector>
#include <iostream>

class Enemy : public Solid
{
private:
	Solid* solido;
	float radio;

public:
	Enemy() : Solid() {}
	Enemy(Solid* s) : Solid() { this->solido = s; this->radio=5.0f; }


	inline void SetSolido(Solid* s) { this->solido = s; }
	inline Solid* GetSolido() { return this->solido; }

	inline void SetRadio(float r) { this->radio = r; }
	inline float GetRadio() { return this->radio; }

	void Init();
	void Render();
	void Update(const float& time);
	void CalcSpeedVector(Vector3D camPos);

	Solid* Clone();

	bool CalcularCollision(const vector<Solid*>& balas);
	int BalaColisionadora(const vector<Solid*>& balas);
};

