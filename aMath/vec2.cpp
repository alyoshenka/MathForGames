#include "vec2.h"

vec2::vec2()
{
	x = 0.0f;
	y = 0.0f;
}

vec2::vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}

float vec2::magnitude() const
{
	return sqrt(x * x + y * y);
}

float vec2::dot(const vec2 & rhs) const
{
	return x * rhs.x + y * rhs.y;
}

vec2 & vec2::normalize()
{

	x /= magnitude();
	y /= magnitude();
	
	return *this;
}

vec2 vec2::getNormalized() const
{
	return vec2(x, y).normalize();
}

vec2 & vec2::scale(const vec2 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

vec2 vec2::getScaled(const vec2 & rhs) const
{
	return vec2(x, y).scale(rhs);
}

vec2 vec2::operator+(const vec2 & rhs) const
{
	vec2 temp(x, y);
	temp.x += rhs.x;
	temp.y += rhs.y;
	return temp;
}

vec2 vec2::operator-(const vec2 & rhs) const
{
	vec2 temp(x, y);
	temp.x -= rhs.x;
	temp.y -= rhs.y;
	return temp;
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

bool vec2::operator==(const vec2 rhs) const
{
	float val = FLT_EPSILON * 100; // on its own might be too small

	vec2 dif;
	dif.x = x - rhs.x;
	dif.y = y - rhs.y;

	return (dif.x < val && dif.x > val * -1 &&
			dif.y < val && dif.y > val * -1);
}

bool vec2::operator!=(const vec2 rhs) const
{
	return ! (vec2(x, y) == rhs);
}

vec2 vec2::operator-() const
{
	/*vec2 temp(x, y);
	temp.x *= -1;
	temp.y *= -1;
	return temp;*/
	return vec2(x * -1, y * -1);
}

vec2 vec2::operator*(const float rhs) const
{
	return vec2(x * rhs, y * rhs);
}

vec2 & vec2::operator*=(const float rhs)
{
	x * rhs;
	y * rhs;
	return *this;
}

vec2 & vec2::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	return *this;
}

//float & vec2::operator[](size_t idx)
//{
//	return idx == 0 ? x : y;
//}
//
//float vec2::operator[](size_t idx) const
//{
//	return idx == 0 ? x : y;
//}

vec2::operator float*()
{
	/*float temp[2] = { x, y };
	return temp;*/
	return &x;
}

vec2::operator const float*() const
{
	/*float temp[2] = { x, y };
	return temp;*/
	return &x;
}

vec2 vec2::moveTowards(const vec2 & cur, const vec2 & tar, float maxDelta)
{
	// get dif
	vec2 delta(tar - cur);
	// make mag = 1
	delta.normalize();
	// scale to length
	delta *= maxDelta;
	// move
	return cur + delta;
}

//operator Vector2()
//{
//}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	return vec2(rhs.x * lhs, rhs.y * lhs);
}
