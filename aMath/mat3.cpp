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
	return;
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
			m[i] = *(ptr+i);
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
	return axis[index];
}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 temp;
	mat3 transp = getTranspose();

	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 3; m++)
		{
			temp.mm[n][m] = transp.axis[n].dot(rhs.axis[m]);
		}
	}

	return temp.getTranspose();	
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
		if (m[i] - rhs.m[i] <= EQUAL && m[i] - rhs.m[i] >= -1 * EQUAL)
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
	temp.m[0] = 1.0f;
	temp.m[4] = 1.0f;
	temp.m[8] = 1.0f;
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
	return mat3(cos(rot), -sin(rot), 0.0f,
				sin(rot), cos(rot), 0.0f,
				0.0f, 0.0f, 1.0f);
}

mat3 mat3::scale(float xScale, float yScale)
{
	return mat3(xScale, 0, 0, 0, yScale, 0, 0, 0, 1);
}

vec3 mat3::operator*(const vec3 & rhs) const
{
	vec3 temp;
	// allows us to use axis
	mat3 transp = getTranspose();

	temp.x = transp.xAxis.dot(rhs);
	temp.y = transp.yAxis.dot(rhs);
	temp.z = transp.zAxis.dot(rhs);

	return temp;
}

vec2 mat3::operator*(const vec2 & rhs) const
{
	vec3 temp = *this * vec3(rhs.x, rhs.y, 0);
	return {temp.x, temp.y};
}

mat3 mat3::rotationX(float rot)
{
	mat3 temp;
	temp.m1 = 1.0f;
	temp.m5 = cos(rot);
	temp.m6 = -sin(rot);
	temp.m8 = sin(rot);
	temp.m9 = cos(rot);

	return temp;
}

mat3 mat3::rotationY(float rot)
{
	mat3 temp;
	temp.m1 = cos(rot);
	temp.m3 = sin(rot);
	temp.m5 = 1.0f;
	temp.m7 = -sin(rot);
	temp.m9 = cos(rot);

	return temp;
}

mat3 mat3::rotationZ(float rot)
{
	mat3 temp;
	temp.m1 = cos(rot);
	temp.m2 = -sin(rot);
	temp.m4 = sin(rot);
	temp.m5 = cos(rot);
	temp.m9 = 1.0f;

	return temp;
}

void mat3::print()
{
	for (int c = 0; c < 3; c++)
	{
		for (int r = 0; r < 3; r++)
		{
			std::cout << mm[r][c] << " ";
		}
		std::cout << std::endl;
	}
}
