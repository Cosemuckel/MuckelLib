#ifndef VEC3_HPP
#define VEC3_HPP

#include "ml-core.hpp"
#include "ml-math.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

class Vec3 {
public:
	float x, y, z;

	Vec3();
	Vec3(float x, float y, float z);

	Vec3 operator+(const Vec3& other) const;
	Vec3 operator-(const Vec3& other) const;
	Vec3 operator*(float scalar) const;
	Vec3 operator/(float scalar) const;

	Vec3& operator+=(const Vec3& other);
	Vec3& operator-=(const Vec3& other);
	Vec3& operator*=(float scalar);
	Vec3& operator/=(float scalar);

	bool operator==(const Vec3& other) const;
	bool operator!=(const Vec3& other) const;

	float dot(const Vec3& other) const;
	Vec3 cross(const Vec3& other) const;

	float length() const;
	float lengthSquared() const;

	Vec3 normalized() const;
	Vec3& normalize();

	Vec3 reflected(const Vec3& normal) const;
	Vec3& reflect(const Vec3& normal);

	Vec3 flipped() const;
	Vec3& flip();

	Vec3 lerp(const Vec3& other, float t) const;

	friend Vec3 operator*(float scalar, const Vec3& other);
	friend Vec3 operator/(float scalar, const Vec3& other);
};

MATH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !VEC3_HPP
