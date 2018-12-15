#include "particleSpawner.h"



particleSpawner::particleSpawner()
{
	pos = { 0, 0 };
	cnt = 20;
	parts = new particle[cnt];
	isOne = false;
	speed = 50.0f;
}


particleSpawner::~particleSpawner()
{
	delete[] parts;
}

void particleSpawner::update()
{
	if (IsMouseButtonPressed(0))
	{
		// spawn particle effect
		isOne = true;
		pos = GetMousePosition();

		// pos
		for (int i = 0; i < cnt; i++)
		{
			parts[i].reset();
			parts[i].pos = pos;
		}
	}

	// if going
	if (isOne)
	{
		// update particles
		for (int i = 0; i < cnt; i++)
		{
			parts[i].update();
			// move
			// origin vector
			// vec2 orig = { 1, 0 };
			// angle of particle rotation
			float angle = 360 / cnt * i; // this works
			// vector of orig rotated by angle
			// vec2 rotated = orig.getRotated(angle);
			// deg between orig and rotated vec
			// float deg = orig.angleBetween(rotated) * RAD_TO_DEG;

			// so it must be one of these

			// delta movement of particle
			vec2 delta = {
				cos(angle), sin(angle)
			};

			// normalize
			delta.normalize();
			// scale
			delta *= speed * GetFrameTime();
			// apply
			parts[i].pos += delta;

			// not quite perfect yet
			// parts[i].pos.x += cos(angle) * speed * GetFrameTime(); // speed should scale
			// parts[i].pos.y += sin(angle) * speed * GetFrameTime();
		}
	}

	// if done
	if (parts[0].age >= parts[0].lifetime)
	{
		isOne = false;
		// reset on mouse click
	}
}

void particleSpawner::draw()
{
	if (isOne)
	{
		for (int i = 0; i < cnt; i++)
		{
			parts[i].draw();
		}
	}
	
}
