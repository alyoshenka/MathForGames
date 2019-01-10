#pragma once

#include "vec4.h"
#include "vec3.h"

struct mat4
{
	union
	{
		struct
		{
			vec4 xAxis;
			vec4 yAxis;
			vec4 zAxis;
			vec4 wAxis;
		};
		vec4 axis[4];
		struct
		{
			float m1, m2, m3, m4,
				m5, m6, m7, m8,
				m9, m10, m11, m12,
				m13, m14, m15, m16;
		};
		struct
		{
			float m[16];
		};
		struct
		{
			float mm[4][4];
		};
	};

	mat4();
	~mat4();
	mat4(float *ptr);
	mat4(float _m1, float _m2, float _m3, float _m4,
		float _m5, float _m6, float _m7, float _m8,
		float _m9, float _m10, float _m11, float _m12,
		float _m13, float _m14, float _m15, float _m16);

	static mat4 identity();
	static mat4 translation(float x, float y, float z);
	static mat4 translation(const vec3 &vec);
	static mat4 rotationX(float xRotation);
	static mat4 rotationY(float yRotation);
	static mat4 rotationZ(float zRotation);
	// static mat4 rotation(float x, float y, float z);
	static mat4 scale(float xScale, float yScale, float zScale);
	static mat4 scale(const vec3 &vec);

	// rebuild the matrix
	void set(float _m1, float _m2, float _m3, float _m4,
		float _m5, float _m6, float _m7, float _m8,
		float _m9, float _m10, float _m11, float _m12,
		float _m13, float _m14, float _m15, float _m16);

	// rebuild the matrix - expects pointer to array of 9 floats
	void set(float *ptr);

	void transpose();
	mat4 getTranspose() const;

	operator float *();
	operator const float *() const;

	vec4 &operator[](const int index);
	const vec4 &operator[](const int index) const;

	mat4 operator*(const mat4 &rhs) const;
	mat4 &operator*=(const mat4 &rhs);

	// transforms a 4D vector by performing 4x4 x 4x1 matrix multiplication
	vec4 operator*(const vec4 &rhs) const;
	// convenience function for transforming a 3D vector
	vec3 operator*(const vec3 &rhs) const;

	bool operator==(const mat4 &rhs) const;
	bool operator!=(const mat4 &rhs) const;
};
