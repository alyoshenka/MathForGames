#include "particleEffect.h"



particleEffect::particleEffect()
{
	pos = { 0, 0 };
	speed = 100.0f;
	age = 0.0f;
	lifetime = 1.0f;
	particleCount = 12;
	particleSize = 3;
	isAlive = true;

	for (int i = 0; i < particleCount; i++) {
		particles.push_back(pos);
	}
}


particleEffect::~particleEffect()
{
}

void particleEffect::update()
{
	age += GetFrameTime();

	if (age >= lifetime) 
	{
		isAlive = false;
	}
	else 
	{
		// color
		curC.r = lerp2((int)c.r, 130, age / lifetime);
		curC.g = lerp2((int)c.g, 130, age / lifetime);
		curC.b = lerp2((int)c.b, 130, age / lifetime);
		// curC.a = lerp2((int)c.a, 0, age / lifetime);

		// pos
		for (int i = 0; i < particleCount; i++)
		{
			float angle = 360 / particleCount * i;
			vec2 delta = { cos(angle), sin(angle) };
			delta.normalize();
			delta *= speed * GetFrameTime();
			particles[i] += delta;
		}
	}
}

void particleEffect::draw()
{
	// for all particles
	for (vec2 particle : particles)
	{
		DrawCircleV(particle, particleSize, curC);
	}
}
