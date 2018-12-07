#pragma once
#include "raylib.h"
#include "utils.h"
#include "vec2.h"

// typedef vec2 Vector2;

class ball
{
	Texture2D texture;
	vec2 vel;
	vec2 dest;

	float speed;
	bool hitTarget;

public:

	vec2 pos;

	ball();
	~ball();

	void update();
	void draw();
};

