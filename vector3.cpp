#include "vector3.hpp"
#include <cmath>

Vector3::Vector3(float x, float y, float z) :
	x(x), y(y), z(z) {}

float Vector3::magnitude() {
	return sqrt(x*x + y*y + z*z);
}

Vector3& Vector3::normalise() {
	*this *= (1.0f / magnitude());
	return *this;
}

Vector3& Vector3::operator+=(const Vector3& rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vector3& Vector3::operator*=(float rhs) {
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

Vector3 operator*(float lhs, Vector3 rhs) {
	rhs *= lhs;
	return rhs;
}
