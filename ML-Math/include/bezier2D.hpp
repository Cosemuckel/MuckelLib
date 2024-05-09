#ifndef BEZIER_HPP
#define BEZIER_HPP

#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

class Bezier2D : public Parametric2D {
private:
	Vec2 points[3];

protected:
	Vec2 atImpl(float t) const override;
	Vec2 tangentImpl(float t) const override;

public:
	Bezier2D();
	Bezier2D(const Vec2 points[3]);
	Bezier2D(const Vec2 points[3], int resolution, int iterations, float epsilon);
	Bezier2D(const Vec2& p0, const Vec2& p1, const Vec2& p2);
	Bezier2D(const Vec2& p0, const Vec2& p1, const Vec2& p2, int resolution, int iterations, float epsilon);

	Vec2 getPoint(int index) const;
	void setPoint(int index, const Vec2& point);

	std::pair<Bezier2D, Bezier2D> subdivide(float t) const;

	Vec2 operator[](int index) const;
};

MATH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !BEZIER_HPP
