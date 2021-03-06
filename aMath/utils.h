#pragma once
#include <cstdarg>
// #include "stdarg.h"
#include "vec2.h"

int sum(int a, int b);

// returns smaller of two values
int min(int a, int b);
// int min(int a, ...); // does not work correctly

// returns larger of two values
int max(int a, int b);

// returns a value no smaller than min and no larger than max
int clamp(int value, int min, int max);

// defined as PI
// const double PI = 3.141592653589793238;
#ifndef PI
	#define PI 3.14159265358979323846f
#endif

// padding for checking if values are equal
const float EQUAL = FLT_EPSILON * 100;

// multiply this with a angle measure expressed in degrees to get its equivalent in radians
const float DEG_TO_RAD = PI / 180.0f;

// multiply this with a angle measure expressed in radians to get its equivalent in degrees
const float RAD_TO_DEG = 180.0f / PI;

// returns the absolute value of val
int absoluteVal(int val);

int pow(int base, int power);

bool isPowerOfTwo(int val);

int nextPowerOfTwo(int val);

float moveTowards(float current, float target, float maxDelta);

// templated
template <typename T>
T min(T a, T b) {
	return a < b ? a : b;
}

template <typename T>
T max(T a, T b) {
	return a > b ? a : b;
}

template <typename T>
T clamp(T value, T min, T max) {
	if (value > max) {
		return max;
	}
	if (value < min) {
		return min;
	}
	return value;
}

template <typename T>
T pow(T base, int power) {
	if (power == 0) {
		return 1;
	}

	int temp = base;
	for (int i = 0; i < power - 1; i++) {
		temp *= base;
	}
	return temp;
}

template <typename T>
T abs(T val) {
	if (val < 0) {
		val *= -1;
	}
	return val;
}
