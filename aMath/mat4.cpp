#include "mat4.h"

mat4::mat4()
{
	for (int i = 0; i < 16; i++)
	{
		m[i] = 0.0f;
	}
}

mat4::~mat4()
{
}

mat4::mat4(float * ptr)
{
	if (ptr == nullptr)
	{
		*this = mat4();
	}
	else
	{
		for (int i = 0; i < 16; i++)
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

mat4::mat4(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9, float _m10, float _m11, float _m12, float _m13, float _m14, float _m15, float _m16)
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
	m10 = _m10;
	m11 = _m11;
	m12 = _m12;
	m13 = _m13;
	m14 = _m14;
	m15 = _m15;
	m16 = _m16;
}

mat4 mat4::identity()
{
	mat4 temp;
	temp.m1 = 1.0f;
	temp.m6 = 1.0f;
	temp.m11 = 1.0f;
	temp.m16 = 1.0f;
	return temp;
}

mat4 mat4::translation(float x, float y, float z)
{
	mat4 temp;
	temp.xAxis += x;
	temp.yAxis += y;
	temp.zAxis += z;
	return temp;
}

mat4 mat4::translation(const vec3 & vec)
{
	return translation(vec.x, vec.y, vec.z);
}

mat4 mat4::rotationX(float xRotation)
{
	mat4 temp;
	temp.m1 = 1.0f;
	temp.m6 = cos(xRotation);
	temp.m7 = sin(xRotation);
	temp.m10 = -sin(xRotation);
	temp.m11 = cos(xRotation);
	temp.m16 = 1.0f;
	return temp;
}

mat4 mat4::rotationY(float yRotation)
{
	mat4 temp;
	temp.m6 = 1.0f;
	temp.m1 = cos(yRotation);
	temp.m3 = -sin(yRotation);
	temp.m9 = sin(yRotation);
	temp.m11 = cos(yRotation);
	temp.m16 = 1.0f;
	return temp;
}

mat4 mat4::rotationZ(float zRotation)
{
	mat4 temp;
	temp.m11 = 1.0f;
	temp.m1 = cos(zRotation);
	temp.m2 = sin(zRotation);
	temp.m5 = -sin(zRotation);
	temp.m6 = cos(zRotation);
	temp.m16 = 1.0f;
	return temp;
}

mat4 mat4::rotation(float x, float y, float z)
{
	mat4 mx = mat4::rotationX(x);
	mat4 my = mat4::rotationY(y);
	mat4 mz = mat4::rotationZ(z);

	mat4 temp = mat4::identity();
	temp *= mx;
	temp *= my;
	temp *= mz;

	return temp;
}

mat4 mat4::scale(float xScale, float yScale, float zScale)
{
	mat4 temp;
	temp.m4 = xScale;
	temp.m8 = yScale;
	temp.m12 = zScale;
	return temp;
}

mat4 mat4::scale(const vec3 & vec)
{
	return scale(vec.x, vec.y, vec.z);
}

mat4::operator float*()
{
	return &m1;
}

mat4::operator const float*() const
{
	return &m1;
}

vec4 & mat4::operator[](const int index)
{
	vec4 temp = { mm[index][0], mm[index][1], mm[index][2], mm[index][3] };
	return temp;
}

const vec4 & mat4::operator[](const int index) const
{
	vec4 temp = { mm[index][0], mm[index][1], mm[index][2], mm[index][3] };
	return temp;
}

mat4 mat4::operator*(const mat4 & rhs) const
{
	mat4 temp;
	mat4 transp = getTranspose();

	temp.m1 = transp.xAxis.dot(rhs.xAxis);
	temp.m2 = transp.yAxis.dot(rhs.xAxis);
	temp.m3 = transp.zAxis.dot(rhs.xAxis);
	temp.m4 = transp.wAxis.dot(rhs.xAxis);

	temp.m5 = transp.xAxis.dot(rhs.yAxis);
	temp.m6 = transp.yAxis.dot(rhs.yAxis);
	temp.m7 = transp.zAxis.dot(rhs.yAxis);
	temp.m8 = transp.wAxis.dot(rhs.yAxis);

	temp.m9 = transp.xAxis.dot(rhs.zAxis);
	temp.m10 = transp.yAxis.dot(rhs.zAxis);
	temp.m11 = transp.zAxis.dot(rhs.zAxis);
	temp.m12 = transp.wAxis.dot(rhs.zAxis);

	temp.m13 = transp.xAxis.dot(rhs.wAxis);
	temp.m14 = transp.yAxis.dot(rhs.wAxis);
	temp.m15 = transp.zAxis.dot(rhs.wAxis);
	temp.m16 = transp.wAxis.dot(rhs.wAxis);

	return temp;
}

mat4 & mat4::operator*=(const mat4 & rhs)
{
	*this = *this * rhs;
	return *this;
}

vec4 mat4::operator*(const vec4 & rhs) const
{
	vec4 temp;
	// so we can get rows from axis
	mat4 transp = getTranspose();

	// put into loop
	temp.x = transp.xAxis.dot(rhs);
	temp.y = transp.yAxis.dot(rhs);
	temp.z = transp.zAxis.dot(rhs);
	temp.w = transp.wAxis.dot(rhs);

	return temp;
}

vec3 mat4::operator*(const vec3 & rhs) const
{
	vec3 temp;
	// so we can get rows from axis
	mat4 transp = getTranspose();

	// put into loop
	temp.x = transp.xAxis.x * rhs.x + transp.xAxis.y * rhs.x + transp.xAxis.z;
	temp.y = transp.yAxis.x * rhs.x + transp.yAxis.y * rhs.x + transp.yAxis.z;
	temp.z = transp.zAxis.x * rhs.x + transp.zAxis.y * rhs.x + transp.zAxis.z;

	return temp;
}

bool mat4::operator==(const mat4 & rhs) const
{
	bool test = false;
	for (int i = 0; i < 16; i++)
	{
		if (m[i] - rhs.m[i] <= EQUAL && m[i] - rhs.m[i] >= -1 * EQUAL)
		{
			test = true;
		}
		else
		{
			return false;
		}
	}
	return test;
}

bool mat4::operator!=(const mat4 & rhs) const
{
	return !(*this == rhs);
}

void mat4::print()
{
	for (int c = 0; c < 4; c++)
	{
		for (int r = 0; r < 4; r++)
		{
			std::cout << mm[c][r] << " ";
		}
		std::cout << std::endl;
	}
}

void mat4::set(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9, float _m10, float _m11, float _m12, float _m13, float _m14, float _m15, float _m16)
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
	m10 = _m10;
	m11 = _m11;
	m12 = _m12;
	m13 = _m13;
	m14 = _m14;
	m15 = _m15;
	m16 = _m16;
}

void mat4::set(float * ptr)
{
	*this = mat4(ptr);
}

void mat4::transpose()
{
	*this = getTranspose();
}

mat4 mat4::getTranspose() const
{
	mat4 temp(*this);
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			temp.mm[col][row] = mm[row][col];
		}
	}
	return temp;
}
