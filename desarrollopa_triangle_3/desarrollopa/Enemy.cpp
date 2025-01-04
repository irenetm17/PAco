#include "Enemy.h"

void Enemy::Init() {}

void Enemy::Render()
{
	solido->Render();
}

void Enemy::Update(const float& time)
{
	//solido->SetPosition(this->GetPosition());
	solido->SetColor(this->GetColor());
	solido->SetOrientationSpeed(this->GetOrientationSpeed());
	solido->SetSpeed(this->GetSpeed());
	solido->Update(time);
}

void Enemy::CalcSpeedVector(Vector3D camPos)
{
	Vector3D vel = camPos - this->GetPosition();
	vel = vel.Normalize(vel);
	this->SetSpeed(vel);
}

Solid* Enemy::Clone()
{
	return new Enemy(*this);
}