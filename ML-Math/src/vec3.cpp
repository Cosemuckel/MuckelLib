#include <cmath>

#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

Vec3::Vec3()
	: x(0.0f), y(0.0f), z(0.0f) {}
Vec3::Vec3(float x, float y, float z)
	: x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& other) const {
	return Vec3(x + other.x, y + other.y, z + other.z);
}
Vec3 Vec3::operator-(const Vec3& other) const {
	return Vec3(x - other.x, y - other.y, z - other.z);
}
Vec3 Vec3::operator*(float scalar) const {
	return Vec3(x * scalar, y * scalar, z * scalar);
}
Vec3 Vec3::operator/(float scalar) const {
	return Vec3(x / scalar, y / scalar, z / scalar);
}

Vec3& Vec3::operator+=(const Vec3& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}
Vec3& Vec3::operator-=(const Vec3& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}
Vec3& Vec3::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}
Vec3& Vec3::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

bool Vec3::operator==(const Vec3& other) const {
	return x == other.x && y == other.y && z == other.z;
}
bool Vec3::operator!=(const Vec3& other) const {
	return x != other.x || y != other.y || z != other.z;
}

float Vec3::dot(const Vec3& other) const {
	return x * other.x + y * other.y + z * other.z;
}
Vec3 Vec3::cross(const Vec3& other) const {
	return Vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

float Vec3::length() const {
	return sqrtf(x * x + y * y + z * z);
}
float Vec3::lengthSquared() const {
	return x * x + y * y + z * z;
}

Vec3 Vec3::normalized() const {
	float l = length();
	return Vec3(x / l, y / l, z / l);
}
Vec3& Vec3::normalize() {
	float l = length();
	x /= l;
	y /= l;
	z /= l;
	return *this;
}

Vec3 Vec3::reflected(const Vec3& normal) const {
	return *this - normal * 2.0f * dot(normal);
}
Vec3& Vec3::reflect(const Vec3& normal) {
	*this = reflected(normal);
	return *this;
}

Vec3 Vec3::flipped() const {
	return Vec3(-x, -y, -z);
}
Vec3& Vec3::flip() {
	x = -x;
	y = -y;
	z = -z;
	return *this;
}

Vec3 Vec3::lerp(const Vec3& other, float t) const {
	return *this * (1.0f - t) + other * t;
}

Vec3 operator*(float scalar, const Vec3& other) {
	return other * scalar;
}
Vec3 operator/(float scalar, const Vec3& other) {
	return Vec3(scalar / other.x, scalar / other.y, scalar / other.z);
}

MATH_NAMESPACE_END
ML_NAMESPACE_END