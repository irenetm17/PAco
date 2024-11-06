#pragma once
#include <vector>
#include <chrono>
#include "EMMITERCONFIGURATION.cpp"
#include "EMMITERCONFIGURATION.h"
#include "Solid.h"
#include "Camera.h"
#include "Cube.h"

using namespace std;


class Emmiter : public Solid
{
private:
	EmmiterConfiguration configuracion;
	vector<Solid*> particulas; //se irán almacenando las referencias a las partículas generadas

	Camera camera;

	chrono::milliseconds initialMilliseconds;
	long lastUpdateTime;

public:

	Emmiter() : Solid()
	{
		this->initialMilliseconds = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
		this->lastUpdateTime = 0;
	}

	void Init();
	void Render();
	void Update();


};

