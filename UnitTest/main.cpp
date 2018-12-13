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

// #define ENABLE_HALT_ON_FAILURE 1
#include "helper.h"

// macros
#define minMacro(a, b) ((a) < (b) ? (a) : (b))
#define sumMacro(a, b) (a + b)

// catch2
// #define CATCH_CONFIG_MAIN
// #include "catch.hpp"
// no clue how to use yet

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

	system("pause");

	return 0;
}