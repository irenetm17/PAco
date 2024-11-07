#include "Solid.h"

void Solid::Update()
{
	this->orientation = this->orientation + this->orientationSpeed;
	this->position = this->position + this->speed;

	//this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed());
	//this->SetPosition(this->GetPosition() + this->GetSpeed());
}
