#pragma once
#include "raylib.h"
#include "lerp.h"
#include "math.h"
#include <string>

class particle
{
public:
	Vector2 pos;
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
};

