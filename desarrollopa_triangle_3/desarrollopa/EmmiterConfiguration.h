#pragma once
#include "Solid.h"


class EmmiterConfiguration  //Clase que únicamente usaremos para gestionar la configuración que queremos darle al emisor y a las partículas
{
private:
	int nParticulas;  //Número máximo de partículas que emitirá el emisor
	int periodo;  //Intervalo de tiempo entre la creación de partículas
	Solid* particula; //Partícula que se toma como referencia

	bool type;  //true son balas y false son enemigos

public:
	EmmiterConfiguration() {}  //Constructor

	EmmiterConfiguration(int n, int t, Solid* p, bool b)  //Constructor
	{
		nParticulas = n;
		periodo = t;
		particula = p;
		type = b;
	}


	//Métodos de acceso
	inline int GetNParticulas() { return this->nParticulas; }
	inline int GetPeriodo() { return this->periodo; }
	inline Solid* GetParticula() { return this->particula; }
	inline bool GetType() { return this->type; }

};
