#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <functional>

#include "ml-core.hpp"

ML_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN

class BinarySearch {
private:
	float epsilon;
	int iterations;

public:
	BinarySearch();
	BinarySearch(float epsilon, int iterations);

	float getEpsilon() const;
	int getIterations() const;

	void setEpsilon(float epsilon);
	void setIterations(int iterations);

	float findRoot(const std::function<float(float)>& function, float a, float b, float initialGuess) const;
	float findRoot(const std::function<float(float)>& function, float a, float b) const;
};

CORE_NAMESPACE_END
ML_NAMESPACE_END

#endif // !BINARY_SEARCH_HPP