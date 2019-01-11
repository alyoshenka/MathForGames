#include "transform3d.h"

transform3d::transform3d()
{
	localPos = localRot = { 0.0f, 0.0f, 0.0f };
	localScale = { 1.0f, 1.0f, 1.0f };

	// parent = nullptr;
}

void transform3d::translate(const vec3 & offset)
{
	localPos += offset;
}

void transform3d::rotate(const float x, const float y, const float z)
{
	localRot += vec3(x, y, z);
}

void transform3d::lookAt(const transform3d & target)
{
	lookAt(target.worldPosition());
}

void transform3d::lookAt(const vec3 & target)
{
	// unit vectors each way
	// this might be wrong
	localRot.x = vec3(1, 0, 0).angleBetween(target);
	localRot.y = vec3(0, 1, 0).angleBetween(target);
	localRot.z = vec3(0, 0, 1).angleBetween(target);
}

vec3 transform3d::forward() const
{
	vec3 temp(worldRotation()); 
	temp.normalize();
	return temp;
}

void transform3d::setForward(const vec3 & newFwd)
{
	lookAt(newFwd);
}

mat4 transform3d::getLocalTRSMatrix() const
{
	mat4 base = mat4::identity();
	// translate, rotate, scale
	base *= base.translation(localPos);
	base *= base.rotation(localRot.x, localRot.y, localRot.z);
	base *= base.scale(localScale.x, localScale.y, localScale.z);

	return base;
}

mat4 transform3d::getWorldTRSMatrix() const
{
	mat4 base = getLocalTRSMatrix();

	// multiply by parent matrix
	transform3d * tempParent = parent;

	while (tempParent != nullptr)
	{
		// multiply matrices to compound affects
		base *= tempParent->getLocalTRSMatrix();
		tempParent = tempParent->parent;
	}

	return base;
}

vec3 transform3d::worldPosition() const
{
	transform3d * temp = parent;

	if (parent == nullptr)
	{
		return localPos;
	}

	vec3 worldPos = { 0, 0, 0 };

	while (temp != nullptr)
	{
		// sic cos of angles???
		worldPos.x += temp->localPos.x + localPos.x * temp->localScale.x;
		worldPos.y += temp->localPos.y + localPos.y * temp->localScale.y; 
		worldPos.z += temp->localPos.z + localPos.z * temp->localScale.z;

		temp = temp->parent;
	}

	return worldPos;
}

vec3 transform3d::worldRotation() const
{
	transform3d * temp = parent;
	vec3 worldRot = localRot;

	while (temp != nullptr)
	{
		worldRot += temp->localRot;
		temp = temp->parent;
	}

	return worldRot;
}

vec3 transform3d::worldScale() const
{
	transform3d * temp = parent;
	vec3 worldScale = localScale;

	while (temp != nullptr)
	{
		worldScale.x *= temp->localScale.x;
		worldScale.y *= temp->localScale.y;
		worldScale.z *= temp->localScale.z;
		temp = temp->parent;
	}

	return worldScale;
}

void transform3d::setWorldPosition(const vec3 & newPos)
{
	// get pos of everything up to this point
	// and add it all together

	transform3d * temp = parent;
	vec3 pos = temp->localPos;

	while (temp->parent != nullptr)
	{
		temp = temp->parent;
		pos += temp->localPos;
	}

	localScale = pos - newPos;
}

void transform3d::setWorldRotation(const vec3 & newRot)
{
	// get rot of everything up to this point
	// and add it all together

	transform3d * temp = parent;
	vec3 rot = temp->localScale;

	while (temp->parent != nullptr)
	{
		temp = temp->parent;
		rot += temp->localScale;
	}

	localScale = rot / newRot;
}

void transform3d::setWorldScale(const vec3 & newScale)
{
	// get scale of everything up to this point;
	transform3d * temp = parent;
	vec3 scale = temp->localScale;

	while (temp->parent != nullptr)
	{
		temp = temp->parent;
		scale *= temp->localScale;
	}

	// scale * this.localScale = newScale;
	// scale = newScale / this.localScale
	// scale * (1 / newScale) = this.localScale
	// scale / newScale = this.localScale
	localScale = scale / newScale;
}

void transform3d::setParent(transform3d * _parent)
{
	parent = _parent;
}

transform3d * transform3d::getParent()
{
	return parent;
}

transform3d const * transform3d::getParent() const
{
	return parent;
}

void transform3d::addChild(transform3d * child)
{
	children.push_back(child);
}

bool transform3d::removeChild(transform3d * child)
{
	bool removed = false;

	for (auto it = children.begin(); it != children.end();)
	{
		if (*it == child)
		{
			it = children.erase(it);
			removed = true;
		}
		else
		{
			it++;
		}
	}
	return removed;
}

transform3d ** transform3d::getChildren()
{
	return &children[0];
}

transform3d * const * transform3d::getChildren() const
{
	return &children[0];
}

size_t transform3d::getChildrenCount() const
{
	return children.size();
}
