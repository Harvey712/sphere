#include "sphere.hpp"
#include <curses.h>
#include <cmath>

Sphere::Sphere(Vector3 light) : light(light.normalise()) {
	yScale = 2.4f / LINES;
	xScale = yScale * 0.5f;
}

Sphere::Sphere() : Sphere(Vector3(1, 1, 1)) {}

void Sphere::display() {
	for (int yy = 0; yy < LINES; ++yy) {
		float y = (yy - 0.5f * LINES) * yScale;
		move(yy, 0);
		for (int xx = 0; xx < COLS; ++xx) {
			float x = (xx - 0.5f * COLS) * xScale;
			addch(getChar(x, y));
		}
	}
}

char Sphere::getChar(float x, float y) {
	if (inUnitCircle(x, y)) {
		return brightnessToChar(
			getBrightness(x, y));
	} else {
		return ' ';
	}
}

// gets brightness of point on screen
float Sphere::getBrightness(float x, float y) {
	return getBrightness(getSpherePoint(x, y));
}

// gets brightness of point on sphere
float Sphere::getBrightness(const Vector3& point) {
	return (point.x * light.x) + (point.y * light.y) + (point.z * light.z);
}

// converts (x,y) point to (x,y,z) point on sphere
// assumes x^2 + y^2 <= 1
Vector3 Sphere::getSpherePoint(float x, float y) {
	float z = sqrt(1.0f - (x*x + y*y));
	return Vector3(x, y, z);
}

// checks (x,y) is in unit circle
bool Sphere::inUnitCircle(float x, float y) {
	return (x*x + y*y <= 1.0f);
}

// converts brightness value to char
char Sphere::brightnessToChar(float brightness) {
	if (brightness < -1) {
		return ' ';
	}
	if (brightness >= 1) {
		return '@';
	}
	const char chars[] = " .~*oS#@@";
	return chars[static_cast<int>(floor((brightness + 1) * 4))];
}
