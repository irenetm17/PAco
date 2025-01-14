#pragma once
#include "Vector3D.h"
#include "Color.h"
#include <vector>
using namespace std;

class Solid
{
private:
	Vector3D position;
	Vector3D speed;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Color color;
	bool wired;

public:
	Solid(
		Color colorArgument = Color(),
		Vector3D positionArgument = Vector3D(),
		Vector3D speedArgument = Vector3D(),
		Vector3D orientationArgument = Vector3D(),
		Vector3D orientationSpeedArgument = Vector3D())
		: color(colorArgument),
		position(positionArgument),
		speed(speedArgument),
		orientation(orientationArgument),
		orientationSpeed(orientationSpeedArgument),
		wired(false) {}

	
	inline Vector3D GetPosition() const{ return this->position; }
	inline Vector3D GetSpeed()  const { return this->speed; }
	inline Vector3D GetOrientation()  const  { return this->orientation; }
	inline Vector3D GetOrientationSpeed()  const { return this->orientationSpeed; }
	inline Color GetColor()  const { return this->color; }
	inline bool GetWired() const { return this->wired; }

	inline void SetPosition(const Vector3D& coordsToSet) { this->position = coordsToSet; }
	inline void SetSpeed(const Vector3D& speedToSet) { this->speed = speedToSet; }
	inline void SetOrientation(const Vector3D& orientationToSet) { this->orientation = orientationToSet; }
	inline void SetOrientationSpeed(const Vector3D& orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	virtual void SetColor(const Color& colorToSet) { this->color = colorToSet; }
	inline void SetWired(const bool& wiredToSet) { this->wired = wiredToSet; }

	virtual Solid* Clone() = 0;
	virtual void CalcSpeedVector(Vector3D camPos) = 0;

	virtual void Render() = 0;
	virtual void Update(const float& time);

	virtual bool CalcularCollision(const vector<Solid*>& balas) =0;
	virtual int BalaColisionadora(const vector<Solid*>& balas) = 0;
	//virtual void Update();
};

