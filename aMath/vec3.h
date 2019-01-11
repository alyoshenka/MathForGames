#pragma once
#include "math.h"
#include <cfloat>

class vec3
{
public:
	float x, y, z;

	vec3();
	vec3(float x, float y, float z);
	~vec3();

	float magnitude() const;
	float dot(const vec3 &rhs) const;
	vec3 cross(const vec3 &rhs) const;

	vec3 &normalize();
	vec3 getNormalised();

	vec3 &scale(const vec3 &rhs);
	vec3 getScaled(const vec3 &rhs) const;

	float angleBetween(const vec3 &rhs); // test

	vec3 operator+(const vec3 &rhs) const;
	vec3 operator-(const vec3 &rhs) const;
	vec3 operator*(const float rhs) const;
	friend vec3 operator*(const float lhs, const vec3 &rhs);
	vec3 operator/(const float rhs) const;

	vec3 &operator+=(const vec3 &rhs);
	vec3 &operator-=(const vec3 &rhs);
	vec3 &operator*=(const float rhs);
	vec3 &operator/=(const float rhs);

	bool operator==(const vec3 &rhs) const;
	bool operator!=(const vec3 &rhs) const;

	vec3 operator-() const;

	operator float *();
	operator const float *() const;

	// perhaps unintuitive, used for transforms
	vec3 &operator/(const vec3 rhs);
	vec3 &operator*=(const vec3 rhs);
	vec3 &operator/=(const vec3 rhs);
};

vec3 operator*(const float lhs, const vec3 &rhs);

