#include "Solid.h"

void Solid::Update(const float& time)
{
	this->position = this->position + this->speed * time;
	this->orientation = this->orientation + this->orientationSpeed * time;
}
