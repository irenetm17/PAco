#pragma once
#include <vector>
#include "Solid.h"
#include "Color.h"
#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <GL/gl.h>    // Funciones básicas de OpenGL
#include <GL/glu.h>   // Funciones utilitarias de OpenGL
#include <GL/glut.h>  // GLUT para manejar texto y ventanas

using namespace std;

class Text : public Solid
{
private:

	string t;

public:


	Text(string textito) { this->t = textito; } 

	void Render();

	inline void SetText(string s) { this->t = s; }
	inline string GetText() { return this->t; }

	Solid* Clone();
	void CalcSpeedVector(Vector3D camPos) {};
	bool CalcularCollision(const vector<Solid*>& balas) { return true; }
	int BalaColisionadora(const vector<Solid*>& balas) { return 0; }

};

