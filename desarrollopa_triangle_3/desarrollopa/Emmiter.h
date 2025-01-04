#pragma once
#include <vector>
#include <chrono>
#include "EmmiterConfiguration.h"
#include "Solid.h"
#include "Enemy.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

using namespace std;
using namespace chrono;


class Emmiter : public Solid
{
private:
	EmmiterConfiguration configuracion;  //Configuracion de las partículas
	vector<Solid*> particulas;           //Se irán almacenando las referencias a las partículas generadas

	Solid* enemigo = new Enemy(configuracion.GetParticula());
	//enemigo = new Enemy(configuracion.GetParticula());

	//Variables para medir el tiempo entre partículas:
	milliseconds initialMilliseconds;
	long lastUpdateTime;

public:
	Emmiter() : Solid() {}  //Constructor

	Emmiter(EmmiterConfiguration conf) : Solid(), configuracion(conf)  //Constructor
	{
		this->initialMilliseconds = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		this->lastUpdateTime = 0;
	}

	void Init();
	void Render();
	void Update(const float& time);
	void ProcessKeyPressed(unsigned char key, int px, int py);

	Solid* Clone();
	void CalcSpeedVector(Vector3D camPos) {};

};

