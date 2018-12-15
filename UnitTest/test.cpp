#include "test.h"

test::test()
{
	pos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	size = 5;
	speed = 100.0f;
	randSpeed = 1.0f;
	t = 0.0f;
	randMovement = true;
}

test::~test()
{
}

void test::update()
{
	// update state
	if (IsKeyPressed(KEY_SPACE))
	{
		// switch
		randMovement = !randMovement;
	}

	if (randMovement)
	{
		t += GetFrameTime() * randSpeed;
		pos = lerp1(orig, dest, t);
	}
	else
	{

	}

	// if at dest
	if (pos = dest)
	{
		// set new
		orig = dest;
		dest = vec2((float)r.rand(0, GetScreenWidth()), (float)r.rand(0, GetScreenHeight()));
	}
}

void test::draw()
{
	DrawCircleV(pos, size, GRAY);
}
