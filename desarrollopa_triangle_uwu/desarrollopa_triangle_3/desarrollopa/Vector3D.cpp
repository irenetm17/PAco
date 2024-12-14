#include "Vector3D.h"

Vector3D Vector3D::Add(const Vector3D& other)const
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

Vector3D Vector3D::operator+(Vector3D& other)
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

Vector3D Vector3D::operator-(Vector3D& other)
{
	return Vector3D(
		this->GetX() - other.GetX(),
		this->GetY() - other.GetY(),
		this->GetZ() - other.GetZ());
}