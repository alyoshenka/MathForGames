#include <iostream>
#include <cassert>
#include <string>

#include "raylib.h"

#include "utils.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "ball.h"
#include "enem.h"
#include "player.h"
#include "myCircle.h"
#include "lerp.h"
#include "particle.h"
#include "curves.h"
#include "random.h"
#include "transform2d.h"

#include "test.h"
#include "particleSpawner.h"

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
// to_string(T) in random
// easeInSine

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

	/*
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
		// angle between starting and ending vectors, multiplied by current scale between,
		// converted to degrees, flipped negatively, scaled to half, rotated for correct direction
		guyAngle = vec2(-1, 0).angleBetween(vec2(1, 0)) * guyT * RAD_TO_DEG / -2 + 90;

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
	*/

	/*
	InitWindow(700, 700, "rand");

	randGen<float> r;
	r.seedRand(123456);

	bool notYet = true;

	const int num = 100; // 100 shows a good spread
	int vals[num];
	int vals2[num];
	for (int i = 0; i < num; i++) {
		vals[i] = r.rand(100, 600);
		vals2[i] = lerp1(100, 600, r.randDecimal(0.000, 1.000));

		// check for repeat
		for (int j = 0; j < i; j++) {
			if (vals[i] == vals[j] && notYet)
			{
				notYet = false;
				// idx where they repeat
				std::cout << i << std::endl;
				// std::abort();
			}
		}
	}
	int idx = 0;
	float elapsedTime = 0.0f;
	float delay = 0.2f;

	vec2 enemPos = { 0, 0 };
	vec2 enemStart = enemPos;
	bool atDest = false;
	vec2 enemDest = enemPos;
	float enemDist = 1.0f;

	vec2 enem2Pos = { 350, 350 };
	vec2 enem2Move = { 0, 0 };
	int enem2MaxDelta = 20;
	float enem2Elapsed = 0.0f;
	float enem2Delay = 1.0f;

	test myGuy;

	while (!WindowShouldClose())
	{
		elapsedTime += GetFrameTime();
		if (elapsedTime >= delay && idx < num - 1) {
			elapsedTime = 0;
			idx++;
		}

		enemDist += GetFrameTime() / 2;
		if (enemDist > 1) {
			enemDist = 0.0f;
			enemStart = enemDest;
			enemDest = vec2(r.rand(100, 600), r.rand(100, 600));
		}
		enemPos = lerp1(enemStart, enemDest, enemDist);
		if (enemPos == enemDest) {
			// enemDest = vec2(r.rand(100, 600), r.rand(100, 600));
		}

		enem2Elapsed += GetFrameTime();
		if (enem2Elapsed >= enem2Delay) {
			enem2Elapsed = 0;
			// enem2
			enem2Move.x += r.rand(-1 * enem2MaxDelta, enem2MaxDelta);
			enem2Move.y += r.rand(-1 * enem2MaxDelta, enem2MaxDelta);
		}
		

		enem2Pos += enem2Move.normalize() * GetFrameTime() * 100.0f;;
		// wrap
		if (enem2Pos.x > GetScreenWidth() + 5) {
			enem2Pos.x = -5;
		}
		if (enem2Pos.x < -5) {
			enem2Pos.x = GetScreenWidth() + 5;
		}
		if (enem2Pos.y > GetScreenHeight() + 5) {
			enem2Pos.y = -5;
		}
		if (enem2Pos.y < -5) {
			enem2Pos.y = GetScreenHeight() + 5;
		}

		myGuy.update();

		BeginDrawing();

		ClearBackground(WHITE);
		for (int i = 0; i < idx; i++)
		{
			DrawCircle(vals[i], 100, 2, BLACK);
			DrawCircle(vals2[i], 200, 2, BLACK);
		}
		DrawText(std::to_string(idx + 1).c_str(), 20, 20, 5, BLACK);
		// dot line bounds
		DrawCircle(100, 100, 3, RED);
		DrawCircle(100, 200, 3, RED);
		DrawCircle(600, 100, 3, RED);
		DrawCircle(600, 200, 3, RED);
		// titles
		DrawText("rand", 50, 100, 5, BLACK);
		DrawText("dec rand", 50, 200, 5, BLACK);

		DrawRectangleV(enemDest, {5, 5}, RED);
		DrawCircleV(enemPos, 5, GREEN);
		DrawText("rand pnt gen", enemDest.x + 5, enemDest.y + 5, 5, BLACK);

		DrawCircleV(enem2Pos, 5, BLUE);

		std::string seedS = "Seed: " + std::to_string(r.getSeed());
		DrawText(seedS.c_str(), 600, 10, 10, BLACK);

		myGuy.draw();

		EndDrawing();
	}

	CloseWindow();

	*/

	// system("pause");

	/*
	// vector addition
	vec2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	vec3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	vec4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	assert(v2c == vec2(18.5f, -44.24f));
	assert(v3c == vec3(18.5f, -44.24f, 850));
	assert(v4c == vec4(18.5f, -44.24f, 850, 1));

	// vector subtraction
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	v2c = v2a - v2b;
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = vec3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = vec4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;

	assert(v2c == vec2(8.5f, -52.22f));
	assert(v3c == vec3(8.5f, -52.22f, 874));
	assert(v4c == vec4(8.5f, -52.22f, 874, -1));

	// vector post-scale
	v2a = vec2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = vec3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	assert(v2c == vec2(33.5069999695f, -119.706863403f));
	assert(v3c == vec3(3.45600008965f, -12.3468809128f, 220.672012329f));
	assert(v4c == vec4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = vec2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = vec3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	assert(v2c == vec2(33.5069999695f, -119.706863403f));
	assert(v3c == vec3(3.45600008965f, -12.3468809128f, 220.672012329f));
	assert(v4c == vec4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector dot product
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	float dot2 = v2a.dot(v2b);
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = vec3(5, 3.99f, -12);
	float dot3 = v3a.dot(v3b);
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = vec4(5, 3.99f, -12, 1);
	float dot4 = v4a.dot(v4b);

	assert(dot2 == -124.937698364f);
	assert(dot3 == -10468.9375f);
	assert(dot4 == -10468.9375f);

	// vector cross product
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = vec3(5, 3.99f, -12);
	v3c = v3a.cross(v3b);
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = vec4(5, 3.99f, -12, 1);
	v4c = v4a.cross(v4b);

	assert(v3c == vec3(-2860.62011719f, 4472.00000000f, 295.01498413f));
	assert(v4c == vec4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));

	// vector magnitude
	v2a = vec2(13.5f, -48.23f);
	float mag2 = v2a.magnitude();
	v3a = vec3(13.5f, -48.23f, 862);
	float mag3 = v3a.magnitude();
	v4a = vec4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.magnitude();

	assert(mag2 == 50.0837593079f);
	assert(mag3 == 863.453735352f);
	assert(mag4 == 863.453735352f);

	// vector normalize
	v2a = vec2(-13.5f, -48.23f);
	v2a.normalize();
	v3a = vec3(13.5f, -48.23f, 862);
	v3a.normalize();
	v4a = vec4(243, -48.23f, 862, 0);
	v4a.normalize();
	*/

	// ????
	// close but no cigar
	// assert(v2a == vec2(-0.269548f, -0.962987f));
	// assert(v3a == vec3(0.0156349f, -0.0558571f, 0.998316f));
	// assert(v4a == vec4(0.270935f, -0.0537745f, 0.961094f, 0));

	/*
	InitWindow(800, 800, "particle effect");
	SetTargetFPS(60);

	particleSpawner ps;

	while (!WindowShouldClose()) {

		ps.update();

		BeginDrawing();
		ClearBackground(GRAY);

		ps.draw();

		EndDrawing();
	}

	CloseWindow();
	*/

	/*
	InitWindow(500, 500, "fov");
	SetTargetFPS(60);

	vec2 enemPos = { 250, 250 };
	float enemSpeed = 150.0f;
	float enemRot = 0.0f; // deg, rot cw
	float enemRotSpeed = 50.0f;
	float fov = 60.0f; // deg
	int fovLen = 100; // i could draw arc with bezier curve

	vec2 orig = { 1, 0 };

	float a = orig.angleBetween(vec2(-1, 0));

	while (!WindowShouldClose()) {

		// left
		if (IsKeyDown(KEY_A))
		{
			enemRot -= enemRotSpeed * GetFrameTime();
		}
		// right
		if (IsKeyDown(KEY_D))
		{
			enemRot += enemRotSpeed * GetFrameTime();
		}
		// forwards
		if (IsKeyDown(KEY_W))
		{
			enemPos += orig.getRotated(enemRot) * enemSpeed * GetFrameTime();
		}
			

		BeginDrawing();
		ClearBackground(GRAY);

		// enem
		vec2 pl = orig.getRotated(fov / -2 + enemRot) * fovLen; // point left
		vec2 pr = orig.getRotated(fov / 2 + enemRot) * fovLen; // point right
		DrawLineV(enemPos, enemPos + pl, BLACK);
		DrawLineV(enemPos, enemPos + pr, BLACK);
		// so enem overlaps
		DrawCircleV(enemPos, 10, BLUE);

		// arc
		vec2 offset = orig.getRotated(enemRot) * fovLen * 1.2; // math for correct scale?
		vec2 prev = pl;
		for(float i = 0; i < 1; i += 0.01f) 
		{
			vec2 next = quadraticBezier(pl, offset, pr, i);
			DrawLineV(prev + enemPos, next + enemPos, BLACK);
			prev = next;
		}
		// test
		// DrawLineV(enemPos, orig * fovLen + enemPos, BLACK);

		EndDrawing();
	}

	CloseWindow();
	*/

	// transform2d test
	InitWindow(600, 400, "transform2d");

	Texture2D guy = LoadTexture("ice_zombie.png");
	transform2d guyT;
	guyT.localPos = { 200, 200 };
	// guyT.localRot = PI / 2;

	Texture2D lilGuy = LoadTexture("goblin.png");
	transform2d lilGuyT;
	lilGuyT.setParent(&guyT);
	lilGuyT.localPos = {50, 50};

	guyT.addChild(&lilGuyT);

	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_LEFT))
		{
			if (IsKeyDown(KEY_ONE))
			{
				guyT.localRot -= 0.0005;
			}
			if (IsKeyDown(KEY_TWO))
			{
				lilGuyT.localRot -= 0.0005;
			}
		}
		if (IsKeyDown(KEY_RIGHT))
		{
			if (IsKeyDown(KEY_ONE))
			{
				guyT.localRot += 0.0005;
			}
			if (IsKeyDown(KEY_TWO))
			{
				lilGuyT.localRot += 0.0005;
			}
		}

		if (GetMouseWheelMove() > 0)
		{
			if (IsKeyDown(KEY_ONE))
			{
				guyT.localScale.x += 0.1f;
				guyT.localScale.y += 0.1f;
			}
			if (IsKeyDown(KEY_TWO))
			{
				lilGuyT.localScale.x += 0.1f;
				lilGuyT.localScale.y += 0.1f;
			}
		}
		if (GetMouseWheelMove() < 0)
		{
			if (IsKeyDown(KEY_ONE))
			{
				guyT.localScale.x -= 0.1f;
				guyT.localScale.y -= 0.1f;
			}
			if (IsKeyDown(KEY_TWO))
			{
				lilGuyT.localScale.x -= 0.1f;
				lilGuyT.localScale.y -= 0.1f;
			}
		}

		BeginDrawing();

		ClearBackground(WHITE);

		// draw in center
		vec2 guyTP = { guyT.worldPosition().x - guy.width / 2,  guyT.worldPosition().y - guy.height / 2 };
		vec2 lilGuyTP = { lilGuyT.worldPosition().x - lilGuy.width / 2,  lilGuyT.worldPosition().y - lilGuy.height / 2 };

		DrawTextureEx(guy, guyTP, guyT.worldRotation() * RAD_TO_DEG, guyT.worldScale().x, WHITE);
		DrawTextureEx(lilGuy, lilGuyTP, lilGuyT.worldRotation() * RAD_TO_DEG, lilGuyT.worldScale().x, WHITE); // SCALE

		EndDrawing();
	}

	UnloadTexture(guy);
	UnloadTexture(lilGuy);

	CloseWindow();

	// no matrix (yet)


	return 0;
}