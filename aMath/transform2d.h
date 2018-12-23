#pragma once
#include "mat3.h"

struct transform2d
{
	vec2 localPosition() const;
	// in rad
	float localRotation() const;
	vec2 localScale() const;

	void setLocalPosition(const vec2 &newPos);
	void setLocalRotation(const float newRot);
	void setLocalScale(const vec2 &newScale);

	void translate(const vec2& offset);
	void rotate(const float angle);

private:
	mat3 trsMatrix;
	// x rot.x scale.x
	// y rot.y scale.y
	// 0 0     0 or 1
};