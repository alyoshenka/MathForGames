#pragma once

#include "vec3.h"
#include "mat4.h"
#include <vector>
#include <math.h>

// NOTE: has not been tested
struct transform3d
{
	transform3d();

	vec3  localPos;
	vec3 localRot;
	vec3  localScale;

	vec3 worldPosition() const; // this definetely needs to be tested
	vec3 worldRotation() const;
	vec3 worldScale() const;

	void setWorldPosition(const vec3& newPos);
	void setWorldRotation(const vec3& newRot);
	void setWorldScale(const vec3& newScale);

	void setParent(transform3d * _parent);
	transform3d *getParent();
	transform3d const *getParent() const;

	void addChild(transform3d *child);
	bool removeChild(transform3d *child);
	transform3d **getChildren();
	transform3d *const* getChildren() const;
	size_t getChildrenCount() const;

	void translate(const vec3 &offset);
	void rotate(const float x, const float y, const float z);

	void lookAt(const transform3d &target);
	void lookAt(const vec3 &target); // test
	vec3 forward() const;
	void setForward(const vec3 &newFwd);

	mat4 getLocalTRSMatrix() const;
	mat4 getWorldTRSMatrix() const;

private:
	transform3d * parent;
	std::vector<transform3d *> children;
};