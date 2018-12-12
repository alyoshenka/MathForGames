#pragma once
#include "raylib.h"
#include "vec2.h"

class player
{
	int health;
	Color tint;
	vec2 pos;
	float speed;

public:
	player();
	~player();

	void draw();
	void update();
};

