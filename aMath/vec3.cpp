#include "vec3.h"

vec3::vec3()
{
	x = 0.0f;
	y = x;
	z = x;
}

vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

vec3::~vec3()
{
}

float vec3::magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

float vec3::dot(const vec3 & rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

vec3 vec3::cross(const vec3 & rhs) const
{
	vec3 temp;
	temp.x = y * rhs.z - z * rhs.y;
	temp.y = z * rhs.x - x * rhs.z;
	temp.z = x * rhs.y - y * rhs.x;
	// temp.normalize();
	return temp;
}

vec3 & vec3::normalize()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;

	return *this;
}

vec3 vec3::getNormalised()
{
	vec3 temp(x, y, z);
	temp /= magnitude();
	return temp;
}

vec3 & vec3::scale(const vec3 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

vec3 vec3::getScaled(const vec3 & rhs) const
{
	return vec3(x, y, z).scale(rhs);
}

float vec3::angleBetween(const vec3 & rhs)
{
	// has been tested
	return acos(this->dot(rhs) / (magnitude() * rhs.magnitude()));
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	vec3 temp(x, y, z);
	temp.x += rhs.x;
	temp.y += rhs.y;
	temp.z += rhs.z;
	return temp;
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	vec3 temp(x, y, z);
	temp.x -= rhs.x;
	temp.y -= rhs.y;
	temp.z -= rhs.z;
	return temp;
}

vec3 vec3::operator*(const float rhs) const
{
	return vec3(x * rhs, y * rhs, z * rhs);
}

vec3 vec3::operator/(const float rhs) const
{
	return vec3(x / rhs, y / rhs, z / rhs);
}

vec3 & vec3::operator+=(const vec3 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

vec3 & vec3::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

vec3 & vec3::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

bool vec3::operator==(const vec3 & rhs) const
{
	float val = EQUAL; // on its own might be too small

	vec3 dif;
	dif.x = x - rhs.x;
	dif.y = y - rhs.y;
	dif.z = z - rhs.z;

	return (dif.x < val && dif.x > val * -1 &&
			dif.y < val && dif.y > val * -1 &&
			dif.z < val && dif.z > val * -1);
}

bool vec3::operator!=(const vec3 & rhs) const
{
	return ! (vec3(x, y, z) == rhs);
}

vec3 vec3::operator-() const
{
	return vec3(-x, -y, -z);
}

vec3::operator float*()
{
	return &x;
}

vec3::operator const float*() const
{
	return &x;
}

vec3  vec3::operator/(const vec3 rhs)
{
	return { x / rhs.x, y / rhs.y, z / rhs.z };
}

vec3 & vec3::operator*=(const vec3 rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

vec3 & vec3::operator/=(const vec3 rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	return *this;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	return vec3(rhs * lhs);
}
