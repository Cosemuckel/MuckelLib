#ifndef ML_MATH_HPP
#define ML_MATH_HPP

#define MATH_NAMESPACE_BEGIN namespace Math {
#define MATH_NAMESPACE_END }

#include "ml-core.hpp"

ML_NAMESPACE_BEGIN
MATH_NAMESPACE_BEGIN

constexpr double PI = 3.14159265358979323846;
constexpr double TWO_PI = 2.0 * PI;

MATH_NAMESPACE_END
ML_NAMESPACE_END

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

#include "parametric2D.hpp"
#include "bezier2D.hpp"
#include "ellipse2D.hpp"
#include "circle2D.hpp"

#endif // !ML_MATH_HPP
