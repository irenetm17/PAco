#include "Scene.h"

void Scene::AddGameObject(Solid* gameObjectToAdd)
{
	this->gameObjects.push_back(gameObjectToAdd);
}

void Scene::Init() {}

void Scene::Render() 
{
	this->camera->Render();
	//if (this->GetDrawBoundary()) { this->renderBoundary(); }
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
	}
}

void Scene::Update(const float& time)
{
	//this->camera->Update(time);
	 
	
	//this->canvas->SetOrientation(Vector3D(camera->GetOrientation().GetX() * (-1), camera->GetOrientation().GetY() * (-1), 0.0f));
	Vector3D direction(
		cos(degToRad(camera->GetOrientation().GetX())) * sin(degToRad(camera->GetOrientation().GetY() * (-1))), // X
		sin(degToRad(camera->GetOrientation().GetX())),                                                  // Y
		cos(degToRad(camera->GetOrientation().GetX())) * cos(degToRad(camera->GetOrientation().GetY() * (-1)))  // Z
	);
	direction = direction.Normalize(direction);
/*
	Vector3D up(direction.GetX() * (-1), direction.GetZ(), direction.GetY() * (-1));
	Vector3D right = up^direction;
	right = right.Normalize(right);
	
	Vector3D w = Vector3D(
		right.GetX(), 
		right.GetY() * cos(degToRad(camera->GetOrientation().GetX())) - right.GetZ() * sin(degToRad(camera->GetOrientation().GetX())),
		right.GetZ() * cos(degToRad(camera->GetOrientation().GetX())) + right.GetY() * sin(degToRad(camera->GetOrientation().GetX()))
	);
	w = Vector3D(
		w.GetX() * cos(degToRad(camera->GetOrientation().GetY())) + w.GetZ() * sin(degToRad(camera->GetOrientation().GetY())),
		w.GetY(),
		w.GetZ() * cos(degToRad(camera->GetOrientation().GetY())) - w.GetX() * sin(degToRad(camera->GetOrientation().GetY()))
	);
	float roll = right.GetX() * w.GetX() + right.GetY() * w.GetY() + right.GetZ() * w.GetZ();
	*/
	//float roll = atan2(right.GetY(), right.GetX());
	//roll = radToDeg(roll);

	this->canvas->SetOrientation(Vector3D(camera->GetOrientation().GetX() * (-1),
		camera->GetOrientation().GetY() * (-1),
		0));

	this->canvas->SetPosition(camera->GetPosition() - direction * 5.0f);

	//cout << "X:" << camera->GetOrientation().GetX() * (-1) << " Y:" << camera->GetOrientation().GetY() * (-1) << " Z:" << camera->GetOrientation().GetZ() << endl;
	//cout << "X:" << direction.GetX() << " Y:" << direction.GetY() << " Z:" << direction.GetZ()  << endl;
	

	this->enemigoEmmiter->SetPosition(camera->GetPosition());
	this->balasEmmiter->SetPosition(camera->GetPosition());
	this->enemigoEmmiter->SetOrientation(camera->GetOrientation());
	this->balasEmmiter->SetOrientation(camera->GetOrientation());

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update(time);
	}
	//this->checkBoundary();

}

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {
	if (moveCamera) {
		this->camera->ProcessKeyPressed(key, px, py);
		this->balasEmmiter->ProcessKeyPressed(key, px, py);
		this->enemigoEmmiter->ProcessKeyPressed(key, px, py);
	}
}

void Scene::ProcessMouseMovement(int x, int y) 
{
	if (moveCamera) {
		this->camera->ProcessMouseMovement(x, y);
	}
}

void Scene::ProcessMouseClicked(int button, int state, int x, int y) {}

/*
void Scene::checkBoundary()
{
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->checkBoundary(this->gameObjects[idx]);

	}
} 

void Scene::checkBoundary(Solid* element)
{
	if (element->GetPosition().GetX() > this->boundary.GetX())
	{
		element->SetPosition(Vector3D(this->boundary.GetX(), element->GetPosition().GetY(), element->GetPosition().GetZ()));
		element->SetSpeed(Vector3D(-1 * element->GetSpeed().GetX(), element->GetSpeed().GetY(), element->GetSpeed().GetZ()));
	}

	if (element->GetPosition().GetX() < 0)
	{
		element->SetPosition(Vector3D(0, element->GetPosition().GetY(), element->GetPosition().GetZ()));
		element->SetSpeed(Vector3D(-1 * element->GetSpeed().GetX(), element->GetSpeed().GetY(), element->GetSpeed().GetZ()));
	}

	if (element->GetPosition().GetY() > this->boundary.GetY())
	{
		element->SetPosition(Vector3D(element->GetPosition().GetX(), this->boundary.GetY(), element->GetPosition().GetZ()));
		element->SetSpeed(Vector3D(element->GetSpeed().GetX(), -1 * element->GetSpeed().GetY(), element->GetSpeed().GetZ()));
	}

	if (element->GetPosition().GetY() < 0)
	{
		element->SetPosition(Vector3D(element->GetPosition().GetX(), 0, element->GetPosition().GetZ()));
		element->SetSpeed(Vector3D(element->GetSpeed().GetX(), -1 * element->GetSpeed().GetY(), element->GetSpeed().GetZ()));
	}

	if (element->GetPosition().GetZ() > this->boundary.GetZ())
	{
		element->SetPosition(Vector3D(element->GetPosition().GetX(), element->GetPosition().GetY(), this->boundary.GetZ()));
		element->SetSpeed(Vector3D(element->GetSpeed().GetX(), element->GetSpeed().GetY(), -1 * element->GetSpeed().GetZ()));
	}

	if (element->GetPosition().GetZ() < 0)
	{
		element->SetPosition(Vector3D(element->GetPosition().GetX(), element->GetPosition().GetY(), 0));
		element->SetSpeed(Vector3D(element->GetSpeed().GetX(), element->GetSpeed().GetY(), -1 * element->GetSpeed().GetZ()));
	}
}

void Scene::renderBoundary()
{
	Cuboid* bottom = new Cuboid();
	bottom->SetLength(this->GetBoundary().GetX());
	bottom->SetHeight(0.1);
	bottom->SetWidth(this->GetBoundary().GetZ());
	bottom->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, 0, this->GetBoundary().GetZ()));
	bottom->SetWired(true);
	bottom->Render();

	Cuboid* top = new Cuboid();
	top->SetLength(this->GetBoundary().GetX());
	top->SetHeight(0.1);
	top->SetWidth(this->GetBoundary().GetZ());
	top->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, this->GetBoundary().GetY(), this->GetBoundary().GetZ()));
	top->SetWired(true);
	top->Render();

	Cuboid* left = new Cuboid();
	left->SetLength(0.1);
	left->SetHeight(this->GetBoundary().GetY());
	left->SetWidth(this->GetBoundary().GetZ());
	left->SetPosition(Vector3D(0, this->GetBoundary().GetY() / 2, this->GetBoundary().GetZ()));
	left->SetWired(true);
	left->Render();

	Cuboid* right = new Cuboid();
	right->SetLength(0.1);
	right->SetHeight(this->GetBoundary().GetY());
	right->SetWidth(this->GetBoundary().GetZ());
	right->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY() / 2, this->GetBoundary().GetZ()));
	right->SetWired(true);
	right->Render();
} 
*/