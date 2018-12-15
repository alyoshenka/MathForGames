#pragma once
#include "particle.h"

class particleSpawner
{
	int cnt;
	vec2 pos;
	// particle array
	particle * parts;
	// is there one particle effect
	bool isOne;
	// going away speed
	float speed;

public:
	particleSpawner();
	~particleSpawner();

	void update();
	void draw();
};

