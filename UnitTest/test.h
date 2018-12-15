#pragma once

#include "raylib.h"
#include "random.h"
#include "vec2.h"
#include "lerp.h"

class test
{
	randGen<float> r;
public:
	vec2 pos;
	int size;
	float randSpeed;
	float speed;
	bool randMovement;
	vec2 orig;
	vec2 dest;
	float t;

	test();
	~test();

	void update();
	void draw();
};

