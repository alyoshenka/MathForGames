#pragma once
#include "raylib.h"
#include "vec2.h"

class myCircle
{
public:

	vec2 pos;
	vec2 orig;
	float rad;
	int numOfGuys;
	float startAngle; // deg
	float rotSpeed;
	float curAngle;
	int rotRad;

	myCircle();
	~myCircle();

	void draw();
	void update();
};

