#pragma once
#include "EMMITERCONFIGURATION.h"
#include "Solid.h"




//clase que únicamente usaremos para gestionar la configuración que queremos darle al emisor y a las partículas
class EmmiterConfiguration
{
private:
	int nParticulas;
	int periodo;
	Solid* particula;

public:

	EmmiterConfiguration()
	{
	}

	EmmiterConfiguration(int n, int t, Solid* p)
	{
		nParticulas = n;
		periodo = t;
		particula = p;
	}

	inline int GetNParticulas() { return this->nParticulas; }
	inline int GetPeriodo() { return this->periodo; }
	inline Solid* GetParticula() { return this->particula; }

};

//void EMMITERCONFIGURATION::Init(int n, int t, Solid* p)







