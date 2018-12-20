#pragma once
#include <vector>
#include "math.h"

#include "raylib.h"

#include "vec2.h"
#include "lerp.h"


class particleEffect
{
public:

	vec2 pos;
	float speed;
	float age;
	float lifetime;
	int particleCount;
	int particleSize;
	bool isAlive;
	// begin color
	Color c;
	// current color
	Color curC;

	std::vector<vec2> particles;

	particleEffect();
	~particleEffect();

	void update();
	void draw();
};

