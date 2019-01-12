#pragma once
#include <cmath>

// start, end, scale
template <typename T>
T lerp1(const T& a, const T& b, float t) 
{
	return a * (1 - t) + b * t;
}

// start, end, scale
template <typename T>
T lerp2(const T& a, const T& b, float t)
{
	return a + (b - a) * t;
}

// elapsed time, begin, change (delta), duration
 template <typename T>
 T linearEase(float t, const T& b, const T& c, float d)
 {
	 return b + c * (t / d);
 }

 // elapsed time, begin, change (delta), duration
 template <typename T>
 T easeInSine(float t, const T& b, const T& c, float d)
 {
	 // return b + c - c * cosf(t / d * (PI / 2));
	 return b;
 }

 // elapsed time, begin, change (delta), duration
 float easeInOutBack(float t, const float b, const float c, float d);


