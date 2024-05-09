#include <cmath>

#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

Vec2::Vec2()
	: x(0.0f), y(0.0f) {}
Vec2::Vec2(float x, float y)
	: x(x), y(y) {}
Vec2::Vec2(float angle)
	: x(cosf(angle)), y(sinf(angle)) {}

Vec2 Vec2::operator+(const Vec2& other) const {
	return Vec2(x + other.x, y + other.y);
}
Vec2 Vec2::operator-(const Vec2& other) const {
	return Vec2(x - other.x, y - other.y);
}
Vec2 Vec2::operator*(float scalar) const {
	return Vec2(x * scalar, y * scalar);
}
Vec2 Vec2::operator/(float scalar) const {
	return Vec2(x / scalar, y / scalar);
}

Vec2& Vec2::operator+=(const Vec2& other) {
	x += other.x;
	y += other.y;
	return *this;
}
Vec2& Vec2::operator-=(const Vec2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}
Vec2& Vec2::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}
Vec2& Vec2::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;
	return *this;
}

bool Vec2::operator==(const Vec2& other) const {
	return x == other.x && y == other.y;
}
bool Vec2::operator!=(const Vec2& other) const {
	return x != other.x || y != other.y;
}

float Vec2::dot(const Vec2& other) const {
	return x * other.x + y * other.y;
}
float Vec2::cross(const Vec2& other) const {
	return x * other.y - y * other.x;
}

float Vec2::length() const {
	return sqrtf(x * x + y * y);
}
float Vec2::lengthSquared() const {
	return x * x + y * y;
}

Vec2 Vec2::normalized() {
	float l = length();
	return Vec2(x / l, y / l);
}
Vec2& Vec2::normalize() {
	float l = length();
	x /= l;
	y /= l;
	return *this;
}

Vec2 Vec2::rotated90() {
	return Vec2(-y, x);
}
Vec2& Vec2::rotate90() {
	float temp = x;
	x = -y;
	y = temp;
	return *this;
}

float Vec2::angle() const {
	return atan2f(y, x);
}

Vec2 Vec2::reflected(const Vec2& normal) {
	return *this - normal * 2.0f * dot(normal);
}
Vec2& Vec2::reflect(const Vec2& normal) {
	return *this -= normal * 2.0f * dot(normal);
}

Vec2 Vec2::flipped() {
	return Vec2(-x, -y);
}
Vec2& Vec2::flip() {
	x = -x;
	y = -y;
	return *this;
}

Vec2 Vec2::rotated(float angle) const {
	float scalar = sinf(angle);
	float c = cosf(angle);
	return Vec2(x * c - y * scalar, x * scalar + y * c);
}
Vec2& Vec2::rotate(float angle) {
	float scalar = sinf(angle);
	float c = cosf(angle);
	float temp = x;
	x = x * c - y * scalar;
	y = temp * scalar + y * c;
	return *this;
}

Vec2 Vec2::lerp(const Vec2& other, float t) const {
	return *this + (other - *this) * t;
}

Vec2 operator*(float scalar, const Vec2& other) {
	return Vec2(other.x * scalar, other.y * scalar);
}
Vec2 operator/(float scalar, const Vec2& other) {
	return Vec2(scalar / other.x, scalar / other.y);
}


MATH_NAMESPACE_END
ML_NAMESPACE_END