#include "transform2d.h"

transform2d::transform2d()
{
	localPos = { 0.0f, 0.0f };
	localRot = 0.0f;
	localScale = { 1.0f, 1.0f };
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
	mat3 base;
	base = mat3::identity();
	
	// translate, rotate, scale
	base *= base.translation(localPos);
	base *= base.rotation(localRot);
	base *= base.scale(localScale.x, localScale.y);

	return base;
}

mat3 transform2d::getWorldTRSMatrix() const
{
	mat3 base;
	base = getLocalTRSMatrix();

	// multiply by parent matrix
	transform2d * tempParent = parent;

	while (tempParent != nullptr)
	{
		base *= tempParent->getLocalTRSMatrix();
		tempParent = tempParent->parent;
	}

	return base;
}

transform2d * transform2d::getTopParent() const
{
	transform2d * temp = parent;
	while (temp != nullptr)
	{
		temp = temp->parent;
	}
	return temp;
}

vec2 transform2d::worldPosition() const
{
	return vec2(getWorldTRSMatrix().m1, getWorldTRSMatrix().m5);
}

float transform2d::worldRotation() const
{
	
}

vec2 transform2d::worldScale() const
{

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
