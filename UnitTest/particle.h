#pragma once
#include "raylib.h"
#include "lerp.h"
#include "math.h"
#include "vec2.h"
#include <string>

class particle
{
public:
	vec2 pos;
	vec2 movement;
	Texture2D sprite;
	Color c;
	Color curC; // current color
	float lifetime; // seconds
	float age; // s

	particle();
	particle(float minLifetime, float maxLifetime);
	~particle();

	void update();
	void draw();
	void reset();
};

