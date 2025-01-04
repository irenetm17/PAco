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

void Emmiter::Update(const float& time)
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	srand(static_cast<unsigned>(std::time(nullptr)));

	//Si ha pasado el intervalo de tiempo desde la ultima particula generada Y el número de particulas generadas es menor al maximo de particulas, entonces...
	if (((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime > this->configuracion.GetPeriodo()) && (particulas.size() < this->configuracion.GetNParticulas()) && !configuracion.GetType())
	{
		//Solid* newParticle = configuracion.GetParticula()->Clone();
		Solid* newParticle = enemigo->Clone();
		float randy = (static_cast<float>(rand()) / RAND_MAX);
		float a = this->GetOrientation().GetY() + (randy * 90.0f - 45.0f);
		Vector3D direction(sin(degToRad(a * (-1))),	0, cos(degToRad(a * (-1))));
		direction = direction.Normalize(direction);
		newParticle->SetPosition(direction * -10);

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// 
		//        HAY QUE ARREGLAR LO DE LA POSICION ALEATORIA
		// 
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//Establecemos características aleatorias de las partículas:
		//newParticle->SetSpeed(direction);
		newParticle->SetColor(Color(static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, 1.0f));
		newParticle->SetOrientationSpeed(Vector3D(0, 0, 0));
		//((static_cast<float>(rand()) / RAND_MAX) * 2 - 1) * 0.008f   Esto hace que salgan en todas direcciones y el 0.008f es la velocidad

		//Añadimos la partícula al vector
		particulas.push_back(newParticle);

		//Actualiza la variable lastUpdateTime
		this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();

		//cout << "emitiendo..." << this->initialMilliseconds.count();

	}

	for (int i = 0; (i < particulas.size()) && (configuracion.GetType()); i++) {
		particulas[i]->Update(time);
		if (particulas[i]->GetPosition().Dist(this->GetPosition()) > 100)
		{
			particulas.erase(particulas.begin());
		}
	}

	for (int i = 0; i < particulas.size() && (!configuracion.GetType()); i++) {
		particulas[i]->CalcSpeedVector(this->GetPosition());
		particulas[i]->Update(time);
	}
}

void Emmiter::ProcessKeyPressed(unsigned char key, int px, int py)
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	srand(static_cast<unsigned int>(std::time(nullptr)));
	if (((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime > this->configuracion.GetPeriodo()) && (particulas.size() < this->configuracion.GetNParticulas()) && configuracion.GetType() && ((key == 'E') || (key == 'e')))
	{
		Solid* newParticle = configuracion.GetParticula()->Clone();
		newParticle->SetPosition(this->GetPosition());
		Vector3D direction(
			cos(degToRad(this->GetOrientation().GetX())) * sin(degToRad(this->GetOrientation().GetY() * (-1))),
			sin(degToRad(this->GetOrientation().GetX())),                                                  
			cos(degToRad(this->GetOrientation().GetX())) * cos(degToRad(this->GetOrientation().GetY() * (-1)))
		);
		direction = direction.Normalize(direction);

		//Establecemos características aleatorias de las partículas:
		newParticle->SetSpeed(direction * ( - 1.2f));
		newParticle->SetColor(Color(static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, 1.0f));
		newParticle->SetOrientationSpeed(Vector3D(0, 0, 0));
		
		//Añadimos la partícula al vector
		particulas.push_back(newParticle);

		//Actualiza la variable lastUpdateTime
		this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();


	}
}

Solid* Emmiter::Clone()
{
	return new Emmiter(*this);
}