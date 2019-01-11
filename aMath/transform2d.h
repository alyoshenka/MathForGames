#pragma once
#include "mat3.h"
#include <vector>

struct transform2d
{
	transform2d();

	vec2 localPos;
	// rad
	float localRot;
	vec2 localScale;

	void translate(const vec2 &offset);
	void rotate(const float angle);

	// rotate the transform to face another transform
	void lookAt(const transform2d &target);
	// return a vector representing the direction that the transform is facing
	vec2 forward() const;
	void setForward(const vec2 &newFwd);

	// just itself
	mat3 getLocalTRSMatrix() const;
	// relative to world
	mat3 getWorldTRSMatrix() const;
	// top of heirarchy
	transform2d * getTopParent() const;

	// adds local positions
	vec2 worldPosition() const;
	// add up all local rotations
	float worldRotation() const;
	// multiply all local scales
	vec2 worldScale() const;

	void setParent(transform2d * _parent);
	transform2d * getParent() const;

	void addChild(transform2d *child);
	transform2d *getChildren() const;
	size_t getChildrenCount() const;

private:
	transform2d * parent;
	std::vector<transform2d *> children;
};