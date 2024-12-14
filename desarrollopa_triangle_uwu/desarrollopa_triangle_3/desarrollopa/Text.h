#pragma once
#include "Solid.h"
#include "Color.h"
#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <GL/gl.h>    // Funciones básicas de OpenGL
#include <GL/glu.h>   // Funciones utilitarias de OpenGL
#include <GL/glut.h>  // GLUT para manejar texto y ventanas

class Text : public Solid
{
private:

	string text;

public:


	Text() {}

	void Render();

	inline void SetText(string s) { this->text = s; }
	inline string GetText() { return this->text; }

	Solid* Clone();

};

