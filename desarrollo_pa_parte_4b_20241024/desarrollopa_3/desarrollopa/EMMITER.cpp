#pragma once
#include "EMMITER.h"
#include <chrono>


void Emmiter::Init()
{
}
void Emmiter::Render()
{
	this->camera.Render();
	for (int i = 0; i < this->particulas.size(); i++)
	{
		this->particulas[i]->Render();
	}
}

void Emmiter::Update()
{
	chrono::milliseconds currentTime = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime > this->configuracion.GetPeriodo())
	{
		
		Solid* newParticle = configuracion.GetParticula()->Clone();
		newParticle->SetPosition(Vector3D(-1.0, 0.0, -3.0));
		newParticle->SetColor(Color(0.1f, 0.9f, 0.3f, 1.0f));
		newParticle->SetOrientationSpeed(Vector3D(0.1, 0.0, 0.3));
		particulas.push_back(newParticle);



	}
	this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();

	for (int i = 0; i < particulas.size(); i++ ) {
		particulas[i]->Update();

	}
}
Solid* Emmiter::Clone()
{
	return new Emmiter(*this);
}