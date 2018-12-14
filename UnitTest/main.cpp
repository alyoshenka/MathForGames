#include <iostream>
#include <cassert>
#include <string>

#include "raylib.h"

#include "utils.h"
#include "vec2.h"
#include "vec3.h"
#include "ball.h"
#include "enem.h"
#include "player.h"
#include "myCircle.h"
#include "lerp.h"
#include "particle.h"
#include "curves.h"

// #define ENABLE_HALT_ON_FAILURE 1
#include "helper.h"

// macros
#define minMacro(a, b) ((a) < (b) ? (a) : (b))
#define sumMacro(a, b) (a + b)

// catch2
// #define CATCH_CONFIG_MAIN
// #include "catch.hpp"
// no clue how to use yet
// easeInOutBack???

// typedef vec2 Vector2;

// min(...) not correct
// fix macros
// fix rotate
// fix pi
// organize main
// where is catch?

int main() {
	/*

	std::cout << min(2, 3) << std::endl;
	std::cout << pow(2, 2) << std::endl;

	// 0 = true
	std::cout << isPowerOfTwo(2) << std::endl;
	std::cout << isPowerOfTwo(3) << std::endl;
	std::cout << isPowerOfTwo(4) << std::endl;
	std::cout << isPowerOfTwo(100) << std::endl;
	std::cout << isPowerOfTwo(64) << std::endl;

	std::cout << nextPowerOfTwo(100) << std::endl;

	std::cout << moveTowards(0.0f, 5.0f, 3.0f) << std::endl;
	std::cout << moveTowards(0.0f, 3.0f, 5.0f) << std::endl;

	// std::cout << min(-10, 1, 2, 3, 4, -5) << std::endl; // this one

	// tests
	assert(abs(-5) == 5);       // the abs value of -5 is 5
	assert(pow(2, 2) == 4);      // 2 to the power of 2 is 4
	assert(min(-5, 5) == -5);   // the lesser of these two values is -5
	// template tests
	assert(min(5, 6) == min(5.0, 6.0));
	assert(abs(-5) == abs(-5.0));
	// vectors
	vec2 v2a = vec2(13.5f, -48.23f);
	vec2 v2b = vec2(5, 3.99f);
	assert(v2a.dot(v2b) == -124.937698364f);
	assert(v2a.magnitude() == 50.0837593079f);
	*/

	/*
	vec2 t1 = vec2(13.5f, -48.23f);
	vec2 t2 = vec2(5, 3.99f);

	assert(t1 + t2 == vec2(18.5f, -44.24f));
	assert(t1 - t2 == vec2(8.5f, -52.22f));

	float * temp = t1;
	assert(temp[1] == -48.23f);

	InitWindow(400, 600, "WrapText");

	std::string txt = "abc def ghi jkl mno pqr stu vwx yz";
	std::string c = "0";

	std::string dist = "x, y";

	ball b;
	vec2 distFromPlayer;

	while (!WindowShouldClose()) {

		// bounds checking for big long line

		// line spacing
		int mod = 10;
		// current pos to draw
		vec2 pos(mod, mod);
		// clipping values
		vec2 max(GetScreenWidth() / 2, GetScreenHeight());

		b.update();
		if (IsMouseButtonDown(0)) {
			distFromPlayer = { (float)GetMouseX(), (float)GetMouseY() };
		}

		BeginDrawing();
		ClearBackground(BLACK);

		for (int i = 0; i < txt.size(); i++) {
			// c = txt[i] + "\0"; // this doesn't work

			// get next word
			c = txt[i];
			c += "\0";

			dist = std::to_string(b.pos.x - distFromPlayer.x) +
				", " + std::to_string(b.pos.y - distFromPlayer.y);

			// DrawText(c.c_str(), pos.x, pos.y, 5, RAYWHITE);
			b.draw();
			DrawCircle(distFromPlayer.x, distFromPlayer.y, 5, BLUE);
			DrawText(dist.c_str(), 10, 10, 10, WHITE);

			// increment
			pos.x += mod;

			// bounds
			if (pos.x >= max.x) {
				pos.x = mod;
				pos.y += mod;
			}
		}

		EndDrawing();
	}

	CloseWindow();

	float scalar = 3.5f;
	vec2 dir = { 0, 1 };
	vec2 newVel = scalar * dir;
	assert(newVel == vec2(0.0f, 3.5f));

	*/

	/*

	InitWindow(500, 600, "Vectors");
	SetTargetFPS(60);

	enem e;
	player p;

	while (!WindowShouldClose()) {

		e.update();
		p.update();

		BeginDrawing();
		ClearBackground(WHITE);

		e.draw();
		p.draw();

		EndDrawing();
	}

	CloseWindow();

	*/

	/*

	InitWindow(800, 800, "sincos");
	SetTargetFPS(60);

	myCircle c;
	float y = 600.0f;
	float wave = 0.0f;

	const int num = 400;
	vec2 pts[num];
	for (int i = 0; i < num; i++) {
		pts[i] = { (float)i * 2, (float)y };
		wave += 0.1; // this stuff right here
		y += sin(wave);
	}

	while (!WindowShouldClose()) {

		// c.update();


		BeginDrawing();
		ClearBackground(WHITE);

		// c.draw();

		DrawText(std::to_string(c.rad).c_str(), 10, 10, 20, BLACK);

		for (int i = 0; i < num; i++) {
			DrawCircle(pts[i].x, pts[i].y, 1, PURPLE);
		}

		EndDrawing();
	}

	CloseWindow();

	vec2 v1(1, 0);
	vec2 v2(1, 0);
	// std::cout << v1.angleBetween(v2) * RAD_TO_DEG << std::endl;

	std::cout << v2.x << ", " << v2.y << std::endl;
	v2.rotate(90);
	std::cout << v2.x << ", " << v2.y << std::endl;

	// std::cout << v1.angleBetween(v2) * RAD_TO_DEG << std::endl;

	// std::cout << vec2(sqrt(2), sqrt(2)).angleBetween(vec2(0, 1)) << std::endl;
	// std::cout << vec2(0, 1).angleBetween(vec2(1, 1)) << std::endl;

	*/

	/*
	aassert("true is true", true);
	aassert("the opposite of false is true", !false);
	aassert("1+1=2", 1 + 1 == 2);
	aassert("1+2=4", 1 + 2 == 4);

	aassert("sum I", 3, sum(1, 2));
	aassert("sum II", 5, sum(2, 3));
	aassert("min", 3, min(3, 7));
	aassert("max", 7, max(3, 7));
	// pass in this impl
	aassert("clamp", 5, clamp(5, 3, 7)); // clamp(val, lowerBound, upperBound)

	vec3 a = { 2, 2, 2 };
	vec3 b = { 1, 1, 1 };
	vec3 diff = a - b;

	aassert("diff x", 1.0f, diff.x, 0.0001f);
	aassert("diff y", 1.0f, diff.y, 0.0001f);
	aassert("diff z", 1.0f, diff.z, 0.0001f);

	aassert("minMacro", 1, minMacro(1, 4)); // pass
	aassert("sumMacro", 5, sumMacro(1, 3)); // fail

	*/

	/*
	InitWindow(700, 800, "lerp");
	SetTargetFPS(60);

	// particle spawner and ui transitions not done

	float scale = 0.0f;
	Rectangle rec1 = { 0, 0, 10, 10 };

	vec2 pos1 = { 300, 100 };
	vec2 pos2 = { 300, 200 };
	vec2 dest1 = { 600, 100 };
	vec2 dest2 = { 600, 200 };

	vec2 waypoints[10];
	for (int i = 0; i < 10; i++)
	{
		waypoints[i] = { (float)GetRandomValue(10, 290), (float)GetRandomValue(10, 290) };
	}
	int carryOver = 0;
	int curIdx = 0;

	float enemyCurrentHealth = 250.0f;
	float enemyMaxHealth = 250.0f;
	Rectangle enemyHealthBar = { 50, 700, 600, 50 };
	int hitDir = -1;

	Texture2D testParticle = LoadTexture("fish.png");
	Color particleR = RED; // r = red
	Color particleG = GRAY; // g = gray
	Color particleC = RED; // c = current
	float colScale = 0.0f;
	int colDir = 1;

	particle guy1;
	guy1.pos = { 550, 450 };

	while (!WindowShouldClose())
	{
		scale += GetFrameTime() / 10;
		// pos1 = lerp1(pos1, dest1, scale);
		pos1 = easeInSine(scale, pos1, dest1 - pos1, 2.0f); // t = elapsed time
		// pos1.x = -easeInOutBack(scale, pos1.x, 600, 2.0f);
		pos2 = lerp2(pos2, dest2, scale);

		// carryOver++;
		if (scale > 1.0f)
		{
			scale = 0.0f;
			// carryOver = 0;
			curIdx++;
		}
		int nextIdx = curIdx + 1;
		if (nextIdx > 9)
		{
			nextIdx = 0;
		}
		if (curIdx > 9)
		{
			curIdx = 0;
		}

		if (enemyCurrentHealth <= 0 || enemyCurrentHealth >= enemyMaxHealth)
		{
			hitDir *= -1;
		}
		enemyCurrentHealth += hitDir * GetFrameTime() * 50;

		if (colScale >= 1 || colScale <= 0){
			colDir *= -1;
		}

		colScale += colDir * GetFrameTime() / 2;
		particleC.r = lerp2(particleR.r, particleG.r, colScale);
		particleC.g = lerp2(particleR.g, particleG.g, colScale);
		particleC.b = lerp2(particleR.b, particleG.b, colScale);

		guy1.update();

		BeginDrawing();

		ClearBackground(WHITE);

		DrawRectangle(pos1.x, pos1.y, rec1.width, rec1.height, BLUE);
		DrawRectangle(pos2.x, pos2.y, rec1.width, rec1.height, BLUE);

		vec2 temp = lerp2(waypoints[curIdx], waypoints[nextIdx], scale);
		DrawRectangle(temp.x, temp.y, 10, 10, PURPLE);

		for (int i = 0; i < 10; i++)
		{
			DrawRectangle(waypoints[i].x, waypoints[i].y, 3, 3, BLACK);
			DrawText(std::to_string(i+1).c_str(), waypoints[i].x + 5, waypoints[i].y + 5, 5, BLACK);
		}

		DrawRectangleRec(enemyHealthBar, BLACK);
		int newWidth = lerp2(0.0f, enemyHealthBar.width - 10, enemyCurrentHealth / enemyMaxHealth);
		DrawRectangle(enemyHealthBar.x + 5, enemyHealthBar.y + 5, newWidth, enemyHealthBar.height - 10, GREEN);
		std::string s = std::to_string((int)enemyCurrentHealth) + " / " + std::to_string((int)enemyMaxHealth);
		DrawText(s.c_str(), 50, 670, 20, BLACK);

		DrawTextureEx(testParticle, { 250, 350 }, 0.0f, 3.0f, particleC);

		guy1.draw();

		EndDrawing();
	}

	UnloadTexture(testParticle);
	CloseWindow();

	*/

	InitWindow(700, 700, "curves and splines");
	SetTargetFPS(60);

	// guyAngle

	vec2 pts[10];
	int rad = 5;
	for (int i = 0; i < 10; i++)
	{
		pts[i].x = cos(360 / 10 * i * DEG_TO_RAD) * 200 + GetScreenWidth() / 2;
		pts[i].y = sin(360 / 10 * i * DEG_TO_RAD) * 200 + GetScreenHeight() / 2;
	}
	float cur = 0.0f;
	int curMod = 1;

	vec2 p1 = { 100, 100 };
	vec2 p2 = { 100, 600 };
	vec2 p3 = { 600, 600 };

	vec2 guyPos = p1;
	float guyT = 0.0f;
	int guyDir = 1;
	Texture2D guySprite = LoadTexture("fish.png");
	float guyAngle = 0.0f;

	while (!WindowShouldClose())
	{
		if (cur <= 0 || cur >= 1) {
			curMod *= -1;
		}
		cur += GetFrameTime() * curMod / 2;
		if (cur < 1) 
		{
			// cur += GetFrameTime() * curMod / 2;
		}
				
		// check collision
		for (int i = 0; i < 10; i++)
		{
			// move pnt
			if (IsMouseButtonDown(0) && CheckCollisionPointCircle(GetMousePosition(), pts[i], rad)) {
				pts[i] = GetMousePosition();
			}
		}

		float prevGuyT = guyT;
		if (guyT > 1 || guyT < 0)
		{
			guyDir *= -1;
		}
		guyT += GetFrameTime() * guyDir / 5;
		guyPos = quadraticBezier(p1, p2, p3, guyT);
		// guyAngle = quadraticBezier(p1, p2, p1, guyT - GetFrameTime()).angleBetween(quadraticBezier(p1, p2, p1, guyT + GetFrameTime()));
		
		/*float x = quadraticBezier(p1.x, p2.x, p3.x, guyT);
		float y = quadraticBezier(p1.y, p2.y, p3.y, guyT);
		guyAngle = atan(y / x);*/

		BeginDrawing();

		ClearBackground(WHITE);

		for (int i = 0; i < 10; i++) 
		{
			DrawCircleV(pts[i], rad, BLACK);
			DrawText(std::to_string(i+1).c_str(), pts[i].x+5, pts[i].y+5, 5, BLACK);

			for (float j = 0; j < cur; j += 0.02)
			{
				int cur = i;
				int next = i + 1;
				int prev = i - 1;
				if (next > 9) {
					next = 0;
				}
				if (prev < 0) {
					prev = 9;
				}

				DrawPixelV(quadraticBezier(pts[prev], pts[cur], pts[next], j), BLACK);
			}
		}

		DrawTextureEx(guySprite, guyPos, guyAngle, 1.0f, WHITE);
		DrawCircleV(p1, 3, GREEN);
		DrawCircleV(p2, 3, GREEN);
		DrawCircleV(p3, 3, GREEN);

		EndDrawing();
	}

	UnloadTexture(guySprite);
	CloseWindow();

	// system("pause");

	return 0;
}