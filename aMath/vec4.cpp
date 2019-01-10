#include "vec4.h"

vec4::vec4()
{
	x = 0.0f;
	y = x;
	z = x;
	w = x;
}

vec4::vec4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

vec4::~vec4()
{
}

float vec4::magnitude() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

float vec4::dot(const vec4 & rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
}

vec4 vec4::cross(const vec4 & rhs) const
{
	// "The 4D cross-product can be determined by 
	// effectively crossing the first three dimensions 
	// and leaving the fourth dimension, w, alone"

	vec4 temp;
	temp.x = y * rhs.z - z * rhs.y;
	temp.y = z * rhs.x - x * rhs.z;
	temp.z = x * rhs.y - y * rhs.x;
	temp.w = w;

	return temp;
}

vec4 & vec4::normalize()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;

	return *this;
}

vec4 vec4::getNormalised() const
{
	vec4 temp(x, y, z, w);
	temp /= magnitude();
	return temp;
}

vec4 & vec4::scale(const vec4 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;

	return *this;
}

vec4 vec4::getScaled(const vec4 & rhs) const
{
	vec4 temp(*this);
	temp.scale(rhs);
	return temp;
}

vec4 vec4::operator+(const vec4 & rhs) const
{
	vec4 temp(*this);
	temp.x += rhs.x;
	temp.y += rhs.y;
	temp.z += rhs.z;
	temp.w += rhs.w;

	return temp;
}

vec4 vec4::operator-(const vec4 & rhs) const
{
	vec4 temp(*this);
	temp.x -= rhs.x;
	temp.y -= rhs.y;
	temp.z -= rhs.z;
	temp.w -= rhs.w;

	return temp;
}

vec4 vec4::operator*(const float rhs) const
{
	vec4 temp(*this);
	temp.x *= rhs;
	temp.y *= rhs;
	temp.z *= rhs;
	temp.w *= rhs;

	return temp;
}

vec4 vec4::operator/(const float rhs) const
{
	vec4 temp(*this);
	temp.x /= rhs;
	temp.y /= rhs;
	temp.z /= rhs;
	temp.w /= rhs;

	return temp;
}

vec4 & vec4::operator+=(const vec4 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;

	return *this;
}

vec4 & vec4::operator+=(const float & rhs)
{
	x += rhs;
	y += rhs;
	z += rhs;
	w += rhs;

	return *this;
}

vec4 & vec4::operator-=(const vec4 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;

	return *this;
}

vec4 & vec4::operator*=(const float rhs)
{
	*this = *this * rhs;
	return *this;
}

vec4 & vec4::operator/=(const float rhs)
{
	*this = *this * rhs;
	return *this;
}

bool vec4::operator==(const vec4 & rhs) const
{
	float val = FLT_EPSILON * 100; // on its own might be too small

	vec4 dif;
	dif.x = x - rhs.x;
	dif.y = y - rhs.y;
	dif.z = z - rhs.z;
	dif.w = w - rhs.w;

	return (dif.x < val && dif.x > val * -1 &&
			dif.y < val && dif.y > val * -1 &&
			dif.z < val && dif.z > val * -1 &&
			dif.w < val && dif.w > val * -1);
}

bool vec4::operator!=(const vec4 & rhs) const
{
	return !(*this == rhs);
}

vec4 vec4::operator-() const
{
	return vec4(-x, -y, -z, -w);
}

vec4::operator float*()
{
	return &x;
}

vec4::operator const float*() const
{
	return &x;
}

vec4 operator*(const float lhs, const vec4 & rhs)
{
	return vec4(rhs * lhs);
}
