#include "myCircle.h"



myCircle::myCircle()
{
	orig = { 250, 250 };
	pos = orig;
	rad = 50;
	numOfGuys = 6;
	startAngle = 0.0f;
	rotSpeed = 100.0f;

	curAngle = 0.0f;
	rotRad = 30;
}


myCircle::~myCircle()
{
}

void myCircle::draw()
{
	// center
	DrawCircleV(pos, 5, BLUE);

	// guys
	for (int i = 0; i < numOfGuys; i++) {
		float ex = (cos(360 / numOfGuys * i * DEG_TO_RAD + startAngle * DEG_TO_RAD) * rad) + pos.x;
		float ey = (sin(360 / numOfGuys * i * DEG_TO_RAD + startAngle * DEG_TO_RAD) * rad) + pos.y;
		DrawLine(pos.x, pos.y, ex, ey, BLACK);
		DrawCircle(ex, ey, 2, GREEN);
	}
}

void myCircle::update()
{
	if (IsMouseButtonPressed(0)) {
		numOfGuys++;
	}
	if (IsMouseButtonPressed(1)) {
		numOfGuys--;
	}

	if (IsKeyDown(KEY_RIGHT)) {
		numOfGuys++;
	}
	if (IsKeyDown(KEY_LEFT)) {
		numOfGuys--;
	}

	startAngle += rotSpeed * GetFrameTime();
	curAngle += rotSpeed / 50 * GetFrameTime();

	// move in circle
	pos.x = cos(-curAngle) * rotRad + orig.x;
	pos.y = sin(-curAngle) * rotRad + orig.y;

	rad += cos(curAngle) * GetFrameTime() * rotSpeed;
}
