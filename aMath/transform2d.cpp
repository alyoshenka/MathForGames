#include "transform2d.h"

transform2d::transform2d()
{
	localPos = { 0.0f, 0.0f };
	localRot = 0.0f;
	localScale = { 1.0f, 1.0f };

	parent = nullptr;
}

void transform2d::translate(const vec2 & offset)
{
	localPos += offset;
}

void transform2d::rotate(const float angle)
{
	localRot += angle;
}

void transform2d::lookAt(const transform2d & target)
{
	// angle from orig
	localRot = vec2(1, 0).angleBetween(target.localPos);
}

vec2 transform2d::forward() const
{
	vec2 dir;
	dir.x = cos(localRot);
	dir.y = sin(localRot);
	dir.normalize();

	return dir;
}

void transform2d::setForward(const vec2 & newFwd)
{
	// get angle between and set localRot
	localRot += forward().angleBetween(newFwd);
}

mat3 transform2d::getLocalTRSMatrix() const
{
	// T * R * S == (((thing * S) * R) * T)
	return mat3::translation(localPos) * mat3::rotation(localRot) * mat3::scale(localScale.x, localScale.y);
}

mat3 transform2d::getWorldTRSMatrix() const
{
	if (parent == nullptr)
	{
		return getLocalTRSMatrix();
	}

	// will iterate to top
	// return parent->getWorldTRSMatrix();

	// ahhh I forgot how to do it conceptually
	std::stack<transform2d *> heirarchy;
	transform2d * temp = parent;
	while (temp != nullptr)
	{
		heirarchy.push(temp);
		temp = temp->parent;
	}

	mat3 base = mat3::identity();
	while (heirarchy.size() > 0)
	{
		base *= heirarchy.top()->getLocalTRSMatrix().getTranspose();
		heirarchy.pop();
	}

	// base *= getLocalTRSMatrix();

	return base;
}

vec2 transform2d::worldPosition() const
{
	mat3 t = getWorldTRSMatrix();	
	return { t.m7, t.m8 };
}

vec2 transform2d::worldRotation() const
{
	mat3 t = getWorldTRSMatrix();
	return { t.m1, t.m2 };
}

float transform2d::worldRotationFromOrig()
{
	vec2 v2 = worldRotation();
	return atan2(v2.y, v2.x);
}

vec2 transform2d::worldScale() const
{
	mat3 t = getWorldTRSMatrix();
	vec2 v1(t.m1, t.m2);
	vec2 v2(t.m4, t.m5);
	return { v1.magnitude(), v2.magnitude() };
}

void transform2d::setParent(transform2d * _parent)
{
	parent = _parent;
}

transform2d * transform2d::getParent() const
{
	return parent;
}

void transform2d::addChild(transform2d * child)
{
	children.push_back(child);
}

transform2d * transform2d::getChildren() const
{
	return children.front();
}

size_t transform2d::getChildrenCount() const
{
	return children.size();
}
