#pragma once
#include "raylib.h"
#include "vec2.h"

#include <iostream>

class enem
{
	Texture2D texture;
	vec2 pos;
	vec2 forwardDir; // in deg
	float fov; // in deg
	float rotSpeed;

public:
	enem();
	~enem();

	void draw();
	void update();
};

