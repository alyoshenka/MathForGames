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
		// multiply matrices to compound affects
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
	transform2d * temp = parent;

	if (parent == nullptr)
	{
		return localPos;
	}

	vec2 worldPos = { 0, 0 };

	while (temp != nullptr)
	{
		float ratio = localPos.y / localPos.x;
		if (ratio != ratio) // nan
		{
			ratio = 0.0f;
		}

		worldPos.x += temp->localPos.x + localPos.x * cos(temp->localRot) * temp->localScale.x * ratio;
		worldPos.y += temp->localPos.y + localPos.x * sin(temp->localRot) * temp->localScale.y * ratio; // no idea why using x
		
		temp = temp->parent;
	}

	return worldPos;
}

float transform2d::worldRotation() const
{
	transform2d * temp = parent;
	float worldRot = localRot;

	while (temp != nullptr)
	{
		worldRot += temp->localRot;
		temp = temp->parent;
	}

	return worldRot;
}

vec2 transform2d::worldScale() const
{
	transform2d * temp = parent;
	vec2 worldScale = localScale;

	while (temp != nullptr)
	{
		worldScale.x *= temp->localScale.x;
		worldScale.y *= temp->localScale.y;
		temp = temp->parent;
	}

	return worldScale;
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
