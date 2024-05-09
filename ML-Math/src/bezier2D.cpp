#include <cmath>

#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

Bezier2D::Bezier2D()
	: points{ Vec2(), Vec2(), Vec2() } {}
Bezier2D::Bezier2D(const Vec2 points[3])
	: points{ points[0], points[1], points[2] } {}
Bezier2D::Bezier2D(const Vec2 points[3], int resolution, int iterations, float epsilon)
	: Parametric2D(resolution, iterations, epsilon), points{ points[0], points[1], points[2] } {}
Bezier2D::Bezier2D(const Vec2& p0, const Vec2& p1, const Vec2& p2)
	: points{ p0, p1, p2 } {}
Bezier2D::Bezier2D(const Vec2& p0, const Vec2& p1, const Vec2& p2, int resolution, int iterations, float epsilon)
	: Parametric2D(resolution, iterations, epsilon), points{ p0, p1, p2 } {}

Vec2 Bezier2D::atImpl(float t) const {
	const float u = 1.0f - t;
	return points[0] * (u * u) + points[1] * (2.0f * u * t) + points[2] * (t * t);
}
Vec2 Bezier2D::tangentImpl(float t) const {
	const float u = 1.0f - t;
	return (points[1] - points[0]) * 2.0f * u + (points[2] - points[1]) * 2.0f * t;
}

Vec2 Bezier2D::getPoint(int index) const {
	return points[index];
}
void Bezier2D::setPoint(int index, const Vec2& point) {
	points[index] = point;
}

std::pair<Bezier2D, Bezier2D> Bezier2D::subdivide(float t) const {
	const Vec2 p0 = points[0];
	const Vec2 p1 = points[1];
	const Vec2 p2 = points[2];

	const Vec2 p01 = p0 + (p1 - p0) * t;
	const Vec2 p12 = p1 + (p2 - p1) * t;
	const Vec2 p012 = p01 + (p12 - p01) * t;

	return std::make_pair(Bezier2D(p0, p01, p012, resolution, iterations, epsilon),
		Bezier2D(p012, p12, p2, resolution, iterations, epsilon));
}

Vec2 Bezier2D::operator[](int index) const {
	return points[index];
}

MATH_NAMESPACE_END
ML_NAMESPACE_END