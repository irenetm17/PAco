#include "Scene.h"

void Scene::AddGameObject(Solid* gameObjectToAdd)
{
	this->gameObjects.push_back(gameObjectToAdd);
}

void Scene::Init() 
{
}

void Scene::Render() 
{
	this->camera.Render();
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
	}
}

void Scene::Update() 
{
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update();
	}
}

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {}

void Scene::ProcessMouseMovement(int x, int y) {}

void Scene::ProcessMouseClicked(int button, int state, int x, int y) {}
