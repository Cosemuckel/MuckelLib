#include <cmath>

#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

Vec4::Vec4()
	: x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
Vec4::Vec4(float x, float y, float z, float w)
	: x(x), y(y), z(z), w(w) {}

Vec4 Vec4::operator+(const Vec4& other) const {
	return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}
Vec4 Vec4::operator-(const Vec4& other) const {
	return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}
Vec4 Vec4::operator*(float scalar) const {
	return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
}
Vec4 Vec4::operator/(float scalar) const {
	return Vec4(x / scalar, y / scalar, z / scalar, w / scalar);
}

Vec4& Vec4::operator+=(const Vec4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}
Vec4& Vec4::operator-=(const Vec4& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}
Vec4& Vec4::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}
Vec4& Vec4::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
	return *this;
}

bool Vec4::operator==(const Vec4& other) const {
	return x == other.x && y == other.y && z == other.z && w == other.w;
}
bool Vec4::operator!=(const Vec4& other) const {
	return x != other.x || y != other.y || z != other.z || w != other.w;
}

float Vec4::dot(const Vec4& other) const {
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

float Vec4::length() const {
	return sqrtf(x * x + y * y + z * z + w * w);
}
float Vec4::lengthSquared() const {
	return x * x + y * y + z * z + w * w;
}

Vec4 Vec4::normalized() const {
	float l = length();
	return Vec4(x / l, y / l, z / l, w / l);
}
Vec4& Vec4::normalize() {
	float l = length();
	x /= l;
	y /= l;
	z /= l;
	w /= l;
	return *this;
}

Vec4 Vec4::lerp(const Vec4& other, float t) const {
	return *this + (other - *this) * t;
}

Vec4 operator*(float scalar, const Vec4& other) {
	return other * scalar;
}
Vec4 operator/(float scalar, const Vec4& other) {
	return Vec4(scalar / other.x, scalar / other.y, scalar / other.z, scalar / other.w);
}

MATH_NAMESPACE_END
ML_NAMESPACE_END