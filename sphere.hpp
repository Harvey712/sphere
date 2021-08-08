#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "vector3.hpp"

class Sphere {
	public:
	Sphere(Vector3 light);
	Sphere();
	Vector3 light;
	void display();

	
	private:
	float yScale;
	float xScale;

	char getChar(float x, float y);
	float getBrightness(float x, float y);
	float getBrightness(const Vector3& point);
	Vector3 getSpherePoint(float x, float y);
	bool inUnitCircle(float x, float y);
	char brightnessToChar(float brightness);

};

#endif
