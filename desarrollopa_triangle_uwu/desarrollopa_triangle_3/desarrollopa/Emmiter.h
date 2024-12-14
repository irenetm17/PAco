#pragma once
#include <vector>
#include <chrono>
#include "EmmiterConfiguration.h"
#include "Solid.h"
#include "Game.h"

using namespace std;
using namespace chrono;


class Emmiter : public Solid
{
private:
	EmmiterConfiguration configuracion;  //Configuracion de las partículas
	vector<Solid*> particulas;           //Se irán almacenando las referencias a las partículas generadas

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
	void Update();

	Solid* Clone();

};

