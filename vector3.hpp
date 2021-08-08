#ifndef VECTOR3_HPP
#define VECTOR3_HPP

class Vector3 {
	public:
	float x;
	float y;
	float z;

	Vector3(float x, float y, float z);

	float magnitude();
	Vector3& normalise();
	Vector3& operator+=(const Vector3& rhs);
	Vector3& operator*=(float rhs);

	friend Vector3 operator+(Vector3 lhs, Vector3& rhs)
	{
		lhs += rhs;
		return lhs;
	}
};

Vector3 operator*(float lhs, Vector3 rhs);

#endif
