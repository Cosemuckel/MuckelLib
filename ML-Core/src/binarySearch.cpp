#include <cmath>
#include <functional>

#include "ml-core.hpp"

ML_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN

BinarySearch::BinarySearch()
	: epsilon(0.0001f), iterations(100) {}
BinarySearch::BinarySearch(float epsilon, int iterations)
	: epsilon(epsilon), iterations(iterations) {}

float BinarySearch::getEpsilon() const {
	return epsilon;
}
int BinarySearch::getIterations() const {
	return iterations;
}

void BinarySearch::setEpsilon(float epsilon) {
	this->epsilon = epsilon;
}
void BinarySearch::setIterations(int iterations) {
	this->iterations = iterations;
}

float BinarySearch::findRoot(const std::function<float(float)>& function, float a, float b, float initialGuess) const {
	float c = initialGuess;
	float fc;
	for (int i = 0; i < iterations; ++i) {
		fc = function(c);

		if (std::abs(fc) < epsilon || std::abs(a - b) < epsilon)
			return c;

		if (function(a) * fc < 0.0f)
			b = c;
		else
			a = c;
		c = (a + b) * 0.5f;
	}

	return (a + b) * 0.5f;
}
float BinarySearch::findRoot(const std::function<float(float)>& function, float a, float b) const {
	return findRoot(function, a, b, (a + b) * 0.5f);
}

CORE_NAMESPACE_END
ML_NAMESPACE_END