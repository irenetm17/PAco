#pragma once

#include "Solid.h"


class Enemy : public Solid
{
private:
	Solid* solido;



public:
	Enemy() : Solid() {}
	Enemy(Solid* s) : Solid() { this->solido = s; }


	inline void SetSolido(Solid* s) { this->solido = s; }
	inline Solid* GetSolido() { return this->solido; }

	void Init();
	void Render();
	void Update(const float& time);
	void CalcSpeedVector(Vector3D camPos);

	Solid* Clone();



};

