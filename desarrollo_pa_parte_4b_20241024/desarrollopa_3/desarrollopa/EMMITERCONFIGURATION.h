#pragma once
#include "Solid.h"


class EmmiterConfiguration  //Clase que �nicamente usaremos para gestionar la configuraci�n que queremos darle al emisor y a las part�culas
{
private:
	int nParticulas;  //N�mero m�ximo de part�culas que emitir� el emisor
	int periodo;  //Intervalo de tiempo entre la creaci�n de part�culas
	Solid* particula; //Part�cula que se toma como referencia

public:
	EmmiterConfiguration()	{}  //Constructor

	EmmiterConfiguration(int n, int t, Solid* p)  //Constructor
	{
		nParticulas = n;
		periodo = t;
		particula = p;
	}


	//M�todos de acceso
	inline int GetNParticulas() { return this->nParticulas; }
	inline int GetPeriodo() { return this->periodo; }
	inline Solid* GetParticula() { return this->particula; }

};
