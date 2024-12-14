#pragma once
#include "Emmiter.h"

using namespace std;
using namespace chrono;

void Emmiter::Init() {}

void Emmiter::Render()
{
	for (int i = 0; i < this->particulas.size(); i++)
	{
		this->particulas[i]->Render();
	}
}

void Emmiter::Update()
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	srand(static_cast<unsigned int>(std::time(nullptr)));

	//Si ha pasado el intervalo de tiempo desde la ultima particula generada Y el n�mero de particulas generadas es menor al maximo de particulas, entonces...
	if (((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime > this->configuracion.GetPeriodo()) && (particulas.size() < this->configuracion.GetNParticulas()))
	{

		Solid* newParticle = configuracion.GetParticula()->Clone();
		newParticle->SetPosition(Vector3D(0.0, 0.0, -10.0));

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//
		//PONER VELOCIDAD EN LA DIRECCION EN LA QUE MIRA LA CAMARA PARA LAS BALAS
		// 
		// PONER POSICION ALEATORIA PARA LOS ENEMIGOS
		// 
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//Establecemos caracter�sticas aleatorias de las part�culas:
		newParticle->SetSpeed(Vector3D(((static_cast<float>(rand()) / RAND_MAX) * 2 - 1) * 0.008f, ((static_cast<float>(rand()) / RAND_MAX) * 2 - 1) * 0.008f, ((static_cast<float>(rand()) / RAND_MAX) * 2 - 1) * 0.008f));
		newParticle->SetColor(Color(static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, 1.0f));
		newParticle->SetOrientationSpeed(Vector3D(0, 0, 0));
		//((static_cast<float>(rand()) / RAND_MAX) * 2 - 1) * 0.008f   Esto hace que salgan en todas direcciones y el 0.008f es la velocidad

		//A�adimos la part�cula al vector
		particulas.push_back(newParticle);

		//Actualiza la variable lastUpdateTime
		this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();

		cout << "emitiendo..." << this->initialMilliseconds.count();

	}

	for (int i = 0; i < particulas.size(); i++) {
		particulas[i]->Update();
	}
}
Solid* Emmiter::Clone()
{
	return new Emmiter(*this);
}