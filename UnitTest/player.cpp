#include "player.h"



player::player()
{
	health = 10;
	tint = GREEN;
	pos = { 0, 0 };
	speed = 100.0f;
}


player::~player()
{
}

void player::draw()
{
	DrawCircle(pos.x, pos.y, 10, tint);
}

void player::update()
{
	vec2 delta;

	if (IsKeyDown(KEY_W)) {
		delta.y -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_S)) {
		delta.y += speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_A)) {
		delta.x -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_D)) {
		delta.x += speed * GetFrameTime();
	}

	delta.normalize();
	delta *= speed;
	pos += delta;
}
