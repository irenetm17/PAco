#include "Enemy.h"
#


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



bool Enemy::CalcularCollision(const std::vector<Solid*>& balas)
{
    for (int i = 0; i < balas.size(); i++)
    {
        if (balas[i] != nullptr)
        {
            float D = this->GetPosition().Dist(balas[i]->GetPosition());
            //cout << D << endl;
            if (D <= radio)
            {
                //balaColisionadora = balas[i];
                cout << "posicion de la bala X" << balas[i]->GetPosition().x << endl;
                cout << "posicion de la bala Y" << balas[i]->GetPosition().y << endl;
                cout << "posicion de la bala z" << balas[i]->GetPosition().z << endl;

                cout << "posicion del enemigo X" << this->GetPosition().x << endl;
                cout << "posicion del enemigo Y" << this->GetPosition().y << endl;
                cout << "posicion del enemigo Z" << this->GetPosition().z << endl;
                return true; 
            }
        }
    }
    return false;
}

int Enemy::BalaColisionadora(const std::vector<Solid*>& balas)
{
	for (int i = 0; i < balas.size(); i++)
	{
		if (balas[i] != nullptr)
		{
			float D = this->GetPosition().Dist(balas[i]->GetPosition());
			if (D <= radio)
			{
				return i;
			}
		}
	}
	return -1;
}