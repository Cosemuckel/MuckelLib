#ifndef VEC4_HPP
#define VEC4_HPP

#include "ml-core.hpp"
#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

class Vec4 {
public:
	float x, y, z, w;

	Vec4();
	Vec4(float x, float y, float z, float w);

	Vec4 operator+(const Vec4& other) const;
	Vec4 operator-(const Vec4& other) const;
	Vec4 operator*(float scalar) const;
	Vec4 operator/(float scalar) const;

	Vec4& operator+=(const Vec4& other);
	Vec4& operator-=(const Vec4& other);
	Vec4& operator*=(float scalar);
	Vec4& operator/=(float scalar);

	bool operator==(const Vec4& other) const;
	bool operator!=(const Vec4& other) const;

	float dot(const Vec4& other) const;

	float length() const;
	float lengthSquared() const;

	Vec4 normalized() const;
	Vec4& normalize();

	Vec4 lerp(const Vec4& other, float t) const;

	friend Vec4 operator*(float scalar, const Vec4& other);
	friend Vec4 operator/(float scalar, const Vec4& other);
};

MATH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !VEC4_HPP