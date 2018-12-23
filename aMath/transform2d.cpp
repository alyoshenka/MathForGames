#include "transform2d.h"

vec2 transform2d::localPosition() const
{
	return vec2(trsMatrix.m1, trsMatrix.m2);
}

float transform2d::localRotation() const
{
	return atan(trsMatrix.m2 / trsMatrix.m1);
}

vec2 transform2d::localScale() const
{
	return vec2(trsMatrix.m7, trsMatrix.m8);
}

void transform2d::setLocalPosition(const vec2 & newPos)
{
	trsMatrix.m1 = newPos.x;
	trsMatrix.m2 = newPos.y;
}

void transform2d::setLocalScale(const vec2 & newScale)
{
	trsMatrix.m7 = newScale.x;
	trsMatrix.m8 = newScale.y;
}

void transform2d::translate(const vec2 & offset)
{
	trsMatrix.m1 += offset.x;
	trsMatrix.m2 += offset.y;
}
