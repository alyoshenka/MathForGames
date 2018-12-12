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
	float temp = sqrt(x * x + y * y);
	if (temp == 0) {
		return 0;
	}
	return temp;
}

float vec2::dot(const vec2 & rhs) const
{
	return x * rhs.x + y * rhs.y;
}

vec2 & vec2::normalize()
{
	if (magnitude() == 0) {
		// do nothing
		return *this;
	}

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

vec2 vec2::getPerpCW() const
{
	return vec2(y, -x);
}

vec2 vec2::getPerpCCW() const
{
	return vec2(-y, x);
}

float vec2::angleBetween(const vec2 & rhs) const
{
	return acos(this->dot(rhs) / (this->magnitude() * rhs.magnitude()));
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
	return vec2(-x, -y);
}

vec2 vec2::operator*(const float rhs) const
{
	return vec2(x * rhs, y * rhs);
}

vec2 & vec2::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
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
	return &x;
}

vec2::operator const float*() const
{
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

vec2 vec2::getRotated(float deg) const
{
	vec2 temp(x, y);
	temp.rotate(deg);
	return temp;
}

vec2 &vec2::rotate(float deg)
{
	/*
	// rotate cw
	deg *= -1;
	// float normFact = magnitude();
	deg *= DEG_TO_RAD;
	// 0 deg = (1, 0)
	// add current angle
	deg += angleBetween(vec2(0, 1));
	// make rad
	// deg *= RAD_TO_DEG;

	vec2 temp;

	// temp.x = x * cos(deg) - y * sin(deg);
	// temp.y = x * sin(deg) + y * cos(deg);

	// this makes length = 1
	temp.x = cos(deg);
	temp.y = sin(deg);

	if (temp == vec2(0, temp.y)) {
		temp.x = 0;
	}
	if (temp == vec2(temp.x, 0)) {
		temp.y = 0;
	}

	// make same length
	temp *= magnitude();

	x = temp.x;
	y = temp.y;


	return *this;

	*/
	/*

	vec2 temp;

	temp.x = x * cos(deg) - y * sin(deg);
	temp.y = x * sin(deg) + y * cos(deg);

	x = temp.x;
	y = temp.y;

	// return *this;

	deg *= DEG_TO_RAD;

	float angleFromOrig = angleBetween(vec2(1, 0)) * RAD_TO_DEG;
	vec2 temp2 = vec2(magnitude() * cos((deg + angleFromOrig) * RAD_TO_DEG), magnitude() * cos((deg + angleFromOrig) * RAD_TO_DEG));
	return temp2;
	*/

	// get current angle first
	vec2 temp;
	float angleFromOrig = this->angleBetween(vec2(1, 0)) * RAD_TO_DEG; 
	temp = vec2(cos(deg + angleFromOrig), sin(deg + angleFromOrig));

	temp.normalize();

	temp.x *= cos(deg + angleFromOrig);
	temp.y *= sin(deg + angleFromOrig);

	x = temp.x;
	y = temp.y;

	return *this;
}

//operator Vector2()
//{
//}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	return vec2(rhs.x * lhs, rhs.y * lhs);
}
