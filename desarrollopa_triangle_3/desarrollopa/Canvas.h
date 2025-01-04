#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"
#include "Text.h"
#include "Triangle.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Cuboid.h"
#include "Sphere.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)


using namespace std;

class Canvas : public Solid
{
private:
    Cuboid* cuboide = new Cuboid();

    vector<Solid*> gameObjects;  

    Vector3D camPosition;
    Vector3D camOrientation;

public:
    Canvas() {}

    Canvas(Vector3D p, Vector3D o) : camPosition(p), camOrientation(o)
    {

        cuboide->SetPosition(this->GetPosition());
        cuboide->SetColor(Color(0.7f, 0.3f, 0.2f, 1.0f));
        cuboide->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
        cuboide->SetOrientation(this->GetOrientation());
        cuboide->SetSpeed(Vector3D(0.0, 0.0, 0.0));
        //this->gameObjects.push_back(cuboide);

        ModelLoader* loader = new ModelLoader();
        loader->SetScale(0.5);
        loader->LoadModel("..\\3dModels\\heart.obj");
        Model* heart1 = new Model();
        *heart1 = loader->GetModel();
        heart1->SetOrientationSpeed(Vector3D(0, 0.2, 0));
        heart1->SetColor(Color(1.0, 0.0, 0.0, 1.0));
        this->gameObjects.push_back(heart1);

        Model* heart2 = new Model();
        *heart2 = loader->GetModel();
        heart2->SetOrientationSpeed(Vector3D(0, 0.2, 0));
        heart2->SetColor(Color(1.0, 0.0, 0.0, 1.0));
        this->gameObjects.push_back(heart2);

        Model* heart3 = new Model();
        *heart3 = loader->GetModel();
        heart3->SetOrientationSpeed(Vector3D(0, 0.2, 0));
        heart3->SetColor(Color(1.0, 0.0, 0.0, 1.0));
        this->gameObjects.push_back(heart3);

        Text* puntuacion = new Text("Puntos: 0");
        puntuacion->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
        puntuacion->SetSpeed(Vector3D(0.0, 0.0, 0.0));
        this->gameObjects.push_back(puntuacion);

        Sphere* mira = new Sphere();
        mira->SetColor(Color(1.0f, 0.4f, 0.9f, 1.0f));
        mira->SetRadius(0.05f);
        mira->SetSpeed(Vector3D(0.0, 0.0, 0.0));
        this->gameObjects.push_back(mira);

    }

    Vector3D CalcPosInCanvas(float x, float y);

    void Init();

    void Render();
    void Update(const float& time);

    Solid* Clone();
    void CalcSpeedVector(Vector3D camPos) {};


    /*
    void addGameObject(const GameObject& obj) {
        gameObjects.push_back(obj);
    }

    // Posicionar todos los objetos en el plano cercano
    void positionObjectsOnNearPlane() {
        Vector3D nearPlaneCenter = this->camera.GetPosition() + this->camera.GetOrientation() * 1.0f; //1.0f es la distancia al plano near
        Vector3D up = Vector3D(this->camera.GetOrientation().GetX(), this->camera.GetOrientation().GetZ(), -1 * this->camera.GetOrientation().GetY());
        Vector3D right = right.Normalize(this->camera.GetOrientation() ^ up);





        /*
        for (size_t i = 0; i < gameObjects.size(); ++i) {
            // Distribuir los objetos en el plano cercano (puedes ajustar la lógica de distribución)
            float xOffset = (i % 5 - 2) * 0.5f; // Separación horizontal
            float yOffset = (i / 5) * -0.5f;    // Separación vertical

            gameObjects[i].position = nearPlaneCenter + right * xOffset + camera.up * yOffset;
        }
    }*/











};

