#include <cmath>

#include "ml-core.hpp"
#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

void Parametric2D::updateLengthCache() {
	lengthCache = 0.0f;
	Vec2 p0 = at(0.0f);
	Vec2 p1;

	for (int i = 1; i <= resolution; ++i) {
		p1 = at(static_cast<float>(i) / resolution);
		lengthCache += (p1 - p0).length();
		p0 = p1;
	}
}

Parametric2D::Parametric2D()
	: resolution(100), iterations(20), epsilon(0.0001f), lengthCache(0.0f) {
	binarySearch.setIterations(iterations);
	binarySearch.setEpsilon(epsilon);
}
Parametric2D::Parametric2D(int resolution, int iterations, float epsilon)
	: resolution(resolution), iterations(iterations), epsilon(epsilon) {
	binarySearch.setIterations(iterations);
	binarySearch.setEpsilon(epsilon);
	updateLengthCache();
}

Vec2 Parametric2D::at(float t) const {
	return atImpl(t);
}
Vec2 Parametric2D::tangent(float t) const {
	return tangentImpl(t);
}
Vec2 Parametric2D::normal(float t) const {
	return tangent(t).rotated90();
}
Vec2 Parametric2D::atLength(float length) const {
	const float t0 = 0.0f;
	const float t1 = 1.0f;

	const auto lengthFunction = [&](float t) {
		return at(t).length() - length;
	};

	const float t = binarySearch.findRoot(lengthFunction, t0, t1, length / lengthCache); // initial guess based on the length

	return at(t);
}

float Parametric2D::length() const {
	return lengthCache;
}

void Parametric2D::setResolution(int resolution) {
	this->resolution = resolution;
	updateLengthCache();
}
void Parametric2D::setIterations(int iterations) {
	this->iterations = iterations;
	binarySearch.setIterations(iterations);
}
void Parametric2D::setEpsilon(float epsilon) {
	this->epsilon = epsilon;
	binarySearch.setEpsilon(epsilon);
}

Vec2 Parametric2D::operator()(float t) const {
	return at(t);
}
Vec2 Parametric2D::operator[](float t) const {
	return tangent(t);
}

MATH_NAMESPACE_END
ML_NAMESPACE_END