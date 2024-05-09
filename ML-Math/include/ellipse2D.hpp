#ifndef ELLIPSE2D_HPP
#define ELLIPSE2D_HPP

#include <cmath>

#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

class Ellipse2D : public Parametric2D {
private:
	Vec2 center;
	float a;
	float b;

protected:
	Vec2 atImpl(float t) const override;
	Vec2 tangentImpl(float t) const override;

public:
	Ellipse2D();
	Ellipse2D(const Vec2& center, float a, float b);
	Ellipse2D(const Vec2& center, float a, float b, int resolution, int iterations, float epsilon);

	Vec2 getCenter() const;
	float getA() const;
	float getB() const;

	void setCenter(const Vec2& center);
	void setA(float a);
	void setB(float b);
};

MATH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !ELLIPSE2D_HPP