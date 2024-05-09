#ifndef CIRCLE2D_HPP
#define CIRCLE2D_HPP

#include <cmath>

#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

class Circle2D : public Ellipse2D {
private:
	Vec2 center;
	float radius;

public:
	Circle2D();
	Circle2D(const Vec2& center, float radius);
	Circle2D(const Vec2& center, float radius, int resolution, int iterations, float epsilon);

	Vec2 getCenter() const;
	float getRadius() const;
	float getA() const = delete;
	float getB() const = delete;

	void setCenter(const Vec2& center);
	void setRadius(float radius);
	void setA(float a) = delete;
	void setB(float b) = delete;
};

MATH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !CIRCLE2D_HPP