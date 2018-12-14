#pragma once
#include "lerp.h"

// p1 (orig), p2 (offset), p3 (dest), scale
template <typename T>
T quadraticBezier(const T& a, const T& b, const T& c, float t)
{
	T x = lerp1(a, b, t);
	T y = lerp1(b, c, t);
	return lerp1(x, y, t);
}

// 4 pts along curve, scale
template <typename T>
T cubicBezier(const T& a, const T& b, const T& c, const T& d, float t)
{
	T x = lerp1(a, b, t);
	T y = lerp1(b, c, t);
	T z = lerp1(c, d, t);
	return quadraticBezier(x, y, z, t);
}


