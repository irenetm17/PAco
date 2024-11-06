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
		Solid* cube1 = new Cube();
		//Solid* cube2 = cube1->Clone();


		//particulas.push_back();


	}
	this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
}