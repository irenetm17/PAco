#include "Vector3D.h"

Vector3D Vector3D::Add(const Vector3D& other) const
{
	/*
	return Vector3D(
		this->GetX() + other.GetX(),
		this->GetY() + other.GetY(),
		this->GetZ() + other.GetZ()); */

	return Vector3D(
		x + other.GetX(),
		y + other.GetY(),
		z + other.GetZ());
		
}

Vector3D Vector3D::operator+(const Vector3D& other)
{
	return this->Add(other);
}

Vector3D Vector3D::Product(float a)
{
	return Vector3D(
		this->GetX() * a,
		this->GetY() * a,
		this->GetZ() * a);
}

Vector3D Vector3D::operator*(float a)
{
	return this->Product(a);
}

Vector3D Vector3D::operator-(const Vector3D& other)
{
	return Vector3D(
		this->GetX() - other.GetX(),
		this->GetY() - other.GetY(),
		this->GetZ() - other.GetZ());
}

Vector3D Vector3D::operator^(const Vector3D& other) //esto es el cross product
{ 
	return Vector3D(
		this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x
	);
}

Vector3D Vector3D::Normalize(const Vector3D& vector)
{
	float magnitude = vector.Magnitude();
	if (magnitude > 0.0f) // Evitar división por cero
	{
		return Vector3D(vector.GetX() / magnitude, vector.GetY() / magnitude, vector.GetZ() / magnitude);
	}
	else
	{
		return Vector3D(0, 0, 0);
	}
}

float Vector3D::Magnitude() const
{
	float magnitude = sqrt(x * x + y * y + z * z);
	return magnitude;
}

float Vector3D::Dist(const Vector3D& vector)
{
	Vector3D v = Vector3D(x,y,z) - vector;
	float dist = v.Magnitude();
	return dist;
}