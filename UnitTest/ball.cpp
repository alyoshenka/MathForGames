#include "ball.h"

ball::ball()
{
	texture = LoadTexture("fish.png");
	pos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	dest = pos;
	vel = { 0.1f, 0.1f };
	// speed = 0.01f;
	hitTarget = true;
}


ball::~ball()
{
	UnloadTexture(texture);
}

void ball::update()
{
	if (IsMouseButtonPressed(0)) {
		dest = { (float)GetMouseX(), (float)GetMouseY() };		
		hitTarget = false;
	}	

	// bounce
	if (hitTarget) {
		vel *= GetFrameTime();
		pos += vel;

		if (pos.x + texture.width > GetScreenWidth() || pos.x < 0) {
			vel.x *= -1;
		}
		if (pos.y + texture.height > GetScreenHeight() || pos.y < 0) {
			vel.y *= -1;
		}
	}
	// move towards target
	else {
		pos = vec2::moveTowards(pos, dest, speed);

		if (pos == dest) {
			hitTarget = true;
		}
	}
	
}

void ball::draw()
{
	DrawTexture(texture, (int)pos.x, (int)pos.y, WHITE);
}
