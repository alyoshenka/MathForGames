#include "mat3.h"

mat3::mat3()
{
	m1 = 0.0f;
	m2 = 0.0f;
	m3 = 0.0f;
	m4 = 0.0f;
	m5 = 0.0f;
	m6 = 0.0f;
	m7 = 0.0f;
	m8 = 0.0f;
	m9 = 0.0f;
}

mat3::~mat3()
{
}

mat3::mat3(float * ptr) : mat3()
{	
	if (ptr == nullptr)
	{
		*this = mat3();
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			m[i] = *ptr;
			ptr++;
			// this puts ptr into unauthorized territory
			// at the end but since i am not accessing it
			// it should be ok
			// (famous last words)
		}
	}	
}

mat3::mat3(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}

mat3::operator float*()
{
	return &m1;
}

vec3 & mat3::operator[](const int index)
{
	vec3 temp = { mm[index][0], mm[index][1], mm[index][2] };
	return temp;
}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 temp;
	// ultimately make loop
	// [row][col]
	temp.m1 = mm[0][0] * rhs.mm[0][0] + mm[0][1] * rhs.mm[1][0] + mm[0][2] * rhs.mm[2][0];
	temp.m2 = mm[1][0] * rhs.mm[0][0] + mm[1][1] * rhs.mm[1][0] + mm[1][2] * rhs.mm[2][0];
	temp.m3 = mm[2][0] * rhs.mm[0][0] + mm[2][1] * rhs.mm[1][0] + mm[2][2] * rhs.mm[2][0];
	temp.m4 = mm[0][0] * rhs.mm[0][1] + mm[0][1] * rhs.mm[1][1] + mm[0][2] * rhs.mm[2][1];
	temp.m5 = mm[1][0] * rhs.mm[0][1] + mm[1][1] * rhs.mm[1][1] + mm[1][2] * rhs.mm[2][1];
	temp.m6 = mm[2][0] * rhs.mm[0][1] + mm[2][1] * rhs.mm[1][1] + mm[2][2] * rhs.mm[2][1];
	temp.m7 = mm[0][0] * rhs.mm[0][2] + mm[0][1] * rhs.mm[1][2] + mm[0][2] * rhs.mm[2][2];
	temp.m8 = mm[1][0] * rhs.mm[0][2] + mm[1][1] * rhs.mm[1][2] + mm[1][2] * rhs.mm[2][2];
	temp.m9 = mm[2][0] * rhs.mm[0][2] + mm[2][1] * rhs.mm[1][2] + mm[2][2] * rhs.mm[2][2];
	return temp;	
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	*this = *this * rhs;
	return *this;
}

bool mat3::operator==(const mat3 & rhs) const
{
	bool test = false;
	for (int i = 0; i < 9; i++)
	{
		if (m[i] == rhs.m[i])
		{
			test = true;
		}
		else
		{
			test = false;
		}
	}
	return test;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	return !(*this == rhs);
}

mat3 mat3::identity()
{
	mat3 temp;
	temp.m1 = 1.0f;
	temp.m4 = 1.0f;
	temp.m7 = 1.0f;
	return temp;
}

void mat3::set(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}

void mat3::set(float * ptr)
{
	*this = mat3(ptr);
}

void mat3::transpose()
{
	*this = getTranspose();
}

mat3 mat3::getTranspose() const
{
	mat3 temp(*this);
	temp.m2 = m4;
	temp.m4 = m2;
	temp.m3 = m7;
	temp.m7 = m3;
	temp.m6 = m8;
	temp.m8 = m6;
	return temp;
}

mat3 mat3::translation(float x, float y)
{
	return mat3(1, 0, 0, 0, 1, 0, x, y, 1);
}

mat3 mat3::translation(const vec2 & vec)
{
	return translation(vec.x, vec.y);
}

// rot in rad
mat3 mat3::rotation(float rot)
{
	return mat3((float)cos(rot), (float)sin(rot), 0.0f,
				(-sin(rot)), cos(rot), 0.0f,
				0.0f, 0.0f, 1.0f);
}

mat3 mat3::scale(float xScale, float yScale)
{
	return mat3(xScale, 0, 0, 0, yScale, 0, 0, 0, 1);
}

vec3 mat3::operator*(const vec3 & rhs) const
{
	vec3 temp;
	temp.x = rhs.x * m1 + rhs.x * m4 + rhs.x * m7;
	temp.y = rhs.y * m2 + rhs.y * m5 + rhs.y + m8;
	temp.z = rhs.z * m3 + rhs.z * m6 + rhs.z * m9;
	return temp;
}

vec2 mat3::operator*(const vec2 & rhs) const
{
	// remember, mat3 used for 2d
	vec2 temp;
	temp.x = rhs.x * m1 + rhs.x * m4;
	temp.y = rhs.y * m2 + rhs.y * m5;
	return temp;
}
