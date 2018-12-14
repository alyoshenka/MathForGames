#include "particle.h"



particle::particle()
{
	pos = { (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight()) };
	sprite = LoadTexture("knight.png");
	c = WHITE;
	curC = c;
	lifetime = 5.0f;
	age = 0.0f;
}

particle::particle(float minLifetime, float maxLifetime) : particle()
{
	// because it only does floats
	lifetime = GetRandomValue(minLifetime * pow(10, 38), maxLifetime * pow(10, 38)) / pow(10, 38);;
}


particle::~particle()
{
	UnloadTexture(sprite);
}

void particle::update()
{
	// GRAY = {130, 130, 130}
	age += GetFrameTime();

	if (age < lifetime) 
	{
		curC.r = lerp2((int)c.r, 130, age / lifetime);
		curC.g = lerp2((int)c.g, 130, age / lifetime);
		curC.b = lerp2((int)c.b, 130, age / lifetime);
	}	
}

void particle::draw()
{
	// go away after 5 seconds
	if (age < lifetime + 5)
	{
		DrawTextureEx(sprite, pos, 0, 2, curC);
		if (age < lifetime)
		{
			std::string s = std::to_string(age) + " / " + std::to_string(lifetime);
			DrawText(s.c_str(), pos.x, pos.y, 5, BLACK);
		}
	}
}
