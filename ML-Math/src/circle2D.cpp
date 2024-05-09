#include <cmath>

#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

Circle2D::Circle2D()
	: center(Vec2()), radius(0.0f) {}
Circle2D::Circle2D(const Vec2& center, float radius)
	: center(center), radius(radius) {}
Circle2D::Circle2D(const Vec2& center, float radius, int resolution, int iterations, float epsilon)
	: Ellipse2D(resolution, iterations, epsilon), center(center), radius(radius) {}

Vec2 Circle2D::getCenter() const {
	return center;
}
float Circle2D::getRadius() const {
	return radius;
}

void Circle2D::setCenter(const Vec2& center) {
	this->center = center;
}
void Circle2D::setRadius(float radius) {
	this->radius = radius;
}

MATH_NAMESPACE_END
ML_NAMESPACE_END