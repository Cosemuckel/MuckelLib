#include <cmath>

#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

Ellipse2D::Ellipse2D()
	: center(Vec2()), a(0.0f), b(0.0f) {}
Ellipse2D::Ellipse2D(const Vec2& center, float a, float b)
	: center(center), a(a), b(b) {}
Ellipse2D::Ellipse2D(const Vec2& center, float a, float b, int resolution, int iterations, float epsilon)
	: Parametric2D(resolution, iterations, epsilon), center(center), a(a), b(b) {}

Vec2 Ellipse2D::atImpl(float t) const {
	return center + Vec2(a * cosf(t), b * sinf(t));
}
Vec2 Ellipse2D::tangentImpl(float t) const {
	return Vec2(-a * sinf(t), b * cosf(t)).normalized();
}

Vec2 Ellipse2D::getCenter() const {
	return center;
}
float Ellipse2D::getA() const {
	return a;
}
float Ellipse2D::getB() const {
	return b;
}

void Ellipse2D::setCenter(const Vec2& center) {
	this->center = center;
}
void Ellipse2D::setA(float a) {
	this->a = a;
}
void Ellipse2D::setB(float b) {
	this->b = b;
}

MATH_NAMESPACE_END
ML_NAMESPACE_END