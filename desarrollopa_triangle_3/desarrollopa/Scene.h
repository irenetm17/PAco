#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"
#include "FirstPersonCamera.h"
#include "Cuboid.h"
#include "Canvas.h"
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Display.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Scene.h"
#include "Triangle.h"
#include "Model.h"
#include "ModelLoader.h"
#include "EmmiterConfiguration.h"
#include "Emmiter.h"
#include "Enemy.h"

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

using namespace std;

class Scene
{
private:
	vector<Solid*> gameObjects;
	Camera* camera;
	Cuboid* canvas = new Cuboid();
	//Canvas* canvas;
	bool moveCamera; // true si se mueve; false si no se mueve
	//Canvas* canvas;
	
	Emmiter* enemigoEmmiter;
	Emmiter* balasEmmiter;
	
	//Vector3D Direction;

	//Vector3D boundary;
	//bool drawBoundary;
	//void checkBoundary();
	//void renderBoundary();

protected:
	//void checkBoundary(Solid*);

public:
		
	Scene(bool c = false, Vector3D CameraPosition = Vector3D(0, 0, 50)) :moveCamera(c)
	//Scene(Vector3D boundaryArgument = Vector3D(14, 7, 4)) : boundary(boundaryArgument)
    {

		if (c) {
			this->camera = new FirstPersonCamera(CameraPosition);
			//canvas = new Canvas(CameraPosition, camera->GetOrientation());

			canvas->SetPosition(CameraPosition - Vector3D(0.0f, 0.0f, 1.0f));
			canvas->SetColor(Color(0.7f, 0.3f, 0.2f, 1.0f));
			canvas->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
			canvas->SetSpeed(Vector3D(0.0, 0.0, 0.0));
			//this->AddGameObject(canvas);
			
			EmmiterConfiguration config(50, 1000, new Sphere(), false);
			enemigoEmmiter = new Emmiter(config);
			enemigoEmmiter->SetPosition(CameraPosition);
			enemigoEmmiter->SetOrientation(camera->GetOrientation());
			enemigoEmmiter->SetColor(Color(0.0f, 0.5f, 0.3f, 1.0f));
			this->AddGameObject(enemigoEmmiter);

			EmmiterConfiguration configur(50, 1000, new Sphere(), true);
			balasEmmiter = new Emmiter(configur);
			balasEmmiter->SetPosition(CameraPosition);
			balasEmmiter->SetOrientation(camera->GetOrientation());
			balasEmmiter->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
			this->AddGameObject(balasEmmiter); 
		}
		else {
			this->camera = new Camera(CameraPosition);
			//canvas = new Canvas();
			enemigoEmmiter = new Emmiter();
			balasEmmiter = new Emmiter();
		}
		this->camera->SetSpeed(Vector3D(0, 0, 0));

		//this->AddGameObject(canvas);      


		//this->canvas = new Canvas(camera);
		//this->drawBoundary = true;
		//this->camera->SetPosition(Vector3D(boundary.GetX() / 2, boundary.GetY() / 2, boundary.GetZ() * 3.5));
	}

	//inline Vector3D GetBoundary() { return this->boundary; }
	//inline bool GetDrawBoundary() { return this->drawBoundary; }
	//inline void SetDrawBoundary(bool drawBoundaryToSet) { this->drawBoundary = drawBoundaryToSet; }
	
	//inline Camera GetCamera() { return this->camera; }

	void AddGameObject(Solid* gameObject);

	void Init();
	void Render();
	void Update(const float& time);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

