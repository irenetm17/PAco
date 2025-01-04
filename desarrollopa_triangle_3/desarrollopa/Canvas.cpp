#include "Canvas.h"

void Canvas::Render()
{
	for (int idx = 0; idx < gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
	}
}
Vector3D Canvas::CalcPosInCanvas(float x, float y)
{
	Vector3D direction(
		cos(degToRad(camOrientation.GetX())) * sin(degToRad(camOrientation.GetY() * (-1))), 
		sin(degToRad(camOrientation.GetX())),                                               
		cos(degToRad(camOrientation.GetX())) * cos(degToRad(camOrientation.GetY() * (-1)))  
	);
	direction = direction.Normalize(direction);

	//Vector3D nearPlaneCenter = this->camera.GetPosition() + this->camera.GetOrientation() * 1.0f; //1.0f es la distancia al plano near
	Vector3D up = Vector3D(direction.GetX(), direction.GetZ(), -1 * direction.GetY());
	Vector3D right = right.Normalize(direction ^ up);
	Vector3D truePosition = this->GetPosition() + (right * x) + (up * y);
	return truePosition;
}

void Canvas::Update(const float& time)
{
	cuboide->SetPosition(this->GetPosition());
	cuboide->SetOrientation(this->GetOrientation());

	int i = 0;  //esto es una chapuza, ya lo se, luego lo cambio

	gameObjects[i]->SetPosition(CalcPosInCanvas(3.0, 1.5));
	gameObjects[i]->SetOrientation(this->GetOrientation() + Vector3D(0.0, 90.0, 0.0));
	gameObjects[i+1]->SetPosition(CalcPosInCanvas(2.0, 1.5));
	gameObjects[i+1]->SetOrientation(this->GetOrientation() + Vector3D(0.0, 90.0, 0.0));
	gameObjects[i + 2]->SetPosition(CalcPosInCanvas(1.0, 1.5));
	gameObjects[i + 2]->SetOrientation(this->GetOrientation() + Vector3D(0.0, 90.0, 0.0));
	gameObjects[i + 3]->SetPosition(CalcPosInCanvas(-2.5, 1.5));
	gameObjects[i + 4]->SetPosition(CalcPosInCanvas(0.0, 0.0));
}

void Canvas::Init() {}

Solid* Canvas::Clone()
{
	return new Canvas(*this);
}