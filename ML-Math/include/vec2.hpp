#ifndef VEC2_HPP
#define VEC2_HPP

#include "ml-core.hpp"
#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

class Vec2 {
public:
	float x, y;

	Vec2();
	Vec2(float x, float y);
	Vec2(float angle);

	Vec2 operator+(const Vec2& other) const;
	Vec2 operator-(const Vec2& other) const;
	Vec2 operator*(float scalar) const;
	Vec2 operator/(float scalar) const;

	Vec2& operator+=(const Vec2& other);
	Vec2& operator-=(const Vec2& other);
	Vec2& operator*=(float scalar);
	Vec2& operator/=(float scalar);

	bool operator==(const Vec2& other) const;
	bool operator!=(const Vec2& other) const;

	float dot(const Vec2& other) const;
	float cross(const Vec2& other) const;

	float length() const;
	float lengthSquared() const;

	Vec2 normalized();
	Vec2& normalize();

	Vec2 rotated90();
	Vec2& rotate90();

	float angle() const;

	Vec2 reflected(const Vec2& normal);
	Vec2& reflect(const Vec2& normal);

	Vec2 flipped();
	Vec2& flip();

	Vec2 rotated(float angle) const;
	Vec2& rotate(float angle);

	Vec2 lerp(const Vec2& other, float angle) const;

	friend Vec2 operator*(float scalar, const Vec2& other);
	friend Vec2 operator/(float scalar, const Vec2& other);
};

#endif // !VEC2_HPP

MATH_NAMESPACE_END
ML_NAMESPACE_END