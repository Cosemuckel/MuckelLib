#ifndef PARAMETRIC2D_HPP
#define PARAMETRIC2D_HPP

#include "ml-core.hpp"
#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

class Parametric2D {
private:
	void updateLengthCache();

protected:
	int resolution;
	int iterations;
	float epsilon;

	float lengthCache;

	virtual Vec2 atImpl(float t) const = 0;
	virtual Vec2 tangentImpl(float t) const = 0;

	Core::BinarySearch binarySearch;

public:
	Parametric2D();
	Parametric2D(int resolution, int iterations, float epsilon);

	Vec2 at(float t) const;
	Vec2 tangent(float t) const;
	Vec2 normal(float t) const;
	Vec2 atLength(float length) const;

	float length() const;

	void setResolution(int resolution); // essentially the number of segments
	void setIterations(int iterations); // for example, the number of iterations for the binary search in atLength
	void setEpsilon(float epsilon); // for example, the epsilon for the binary search in atLength

	Vec2 operator()(float t) const; // same as at
	Vec2 operator[](float t) const; // same as tangent

	virtual ~Parametric2D() = default;
};

MATH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !PARAMETRIC2D_HPP
