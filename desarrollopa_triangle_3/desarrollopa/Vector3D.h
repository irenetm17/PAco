#pragma once
#include <cmath>
#include <iostream>



class Vector3D
{
private:

	

public:
	float x;
	float y;
	float z;
	Vector3D() : x(0.0), y(0.0), z(0.0) {}

	Vector3D(float xArgument, float yArgument, float zArgument)
	{
		this->x = xArgument;
		this->y = yArgument;
		this->z = zArgument;
	}

	inline float GetX() const { return this->x; }
	inline float GetY() const { return this->y; }
	inline float GetZ() const { return this->z; }

	inline void SetX(const float& xToSet) { this->x = xToSet; }
	inline void SetY(const float& yToSet) { this->y = yToSet; }
	inline void SetZ(const float& zToSet) { this->z = zToSet; }

	Vector3D Add(const Vector3D& other) const ; ////////NO SE QUE HACE EL CONST Y ME PONE NERVIOSO UWU
	Vector3D operator+(const Vector3D& other);

	Vector3D Product(float a);
	Vector3D operator*(float a);

	Vector3D operator-(const Vector3D& other);

	Vector3D operator^(const Vector3D& other);

	Vector3D Normalize(const Vector3D& vector);

	float Magnitude() const;

	float Dist(const Vector3D& vector);

};

