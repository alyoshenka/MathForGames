#include "vec3.h"
#include "vec2.h"

// row x column
// column-major
struct mat3
{
	// (not standards compliant)
	union
	{
		struct
		{
			vec3 xAxis;
			vec3 yAxis;
			vec3 zAxis;
		};
		vec3 axis[3];
		struct
		{
			// m1 = [0][0]
			// m2 = [0][1]
			float m1, m2, m3,
				m4, m5, m6,
				m7, m8, m9;
		};
		struct
		{
			float m[9];
		};
		struct
		{
			float mm[3][3];
		};
	};

	mat3();
	~mat3();
	mat3(float * ptr);
	mat3(float _m1, float _m2, float _m3, 
		float _m4, float _m5, float _m6, 
		float _m7, float _m8, float _m9);

	// implicit operator to convert mat3 into a float array
	operator float *();
	// returns vec3 objects when accessing by subscript operator
	vec3 &operator[](const int index);
	// concatenates two matrices together and returns the result
	mat3  operator*(const mat3 &rhs) const;
	// concatenates and assigns the result to the matrix
	mat3 &operator*=(const mat3 &rhs);
	// returns true if the matrices are equal
	bool operator==(const mat3 &rhs) const;
	// returns true if the matrices are inequal
	bool operator!=(const mat3 &rhs) const;

	// returns a 3x3 identity matrix
	static mat3 identity();
	// updates the matrix elements with the given values
	void set(float _m1, float _m2, float _m3,
		float _m4, float _m5, float _m6,
		float _m7, float _m8, float _m9);
	// updates the matrix elements with the given values from the given array
	void set(float *ptr);
	// transposes the matrix
	void transpose();
	// returns a transposed copy of the matrix
	mat3 getTranspose() const;

	// returns a translation matrix with the given changes for each axis
	static mat3 translation(float x, float y);
	// returns a translation matrix with the given changes for each axis
	static mat3 translation(const vec2 &vec);
	// returns a rotation matrix with the given rotation
	static mat3 rotation(float rot);
	// returns a translation matrix with the given changes for each axis
	static mat3 scale(float xScale, float yScale);
	// transforms a 4D vector by performing 4x4 x 4x1 matrix multiplication
	vec3 operator*(const vec3 &rhs) const;
	// convenience function for transforming a 2D vector
	vec2 operator*(const vec2 &rhs) const;
};
