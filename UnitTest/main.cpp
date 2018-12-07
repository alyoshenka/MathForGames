#include <iostream>
#include <cassert>

#include "utils.h"
#include "raylib.h"
#include <string>
#include "vec2.h"
#include "ball.h"

// typedef vec2 Vector2;

// min(...) not correct

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

	std::cout << min(-10, 1, 2, 3, 4, -5) << std::endl; // this one

	// tests
	assert(abs(-5) == 5);       // the abs value of -5 is 5
	assert(pow(2, 2) == 4);      // 2 to the power of 2 is 4
	assert(min(-5, 5) == -5);   // the lesser of these two values is -5
	// template tests
	assert(min(5, 6) == min(5.0, 6.0));
	assert(abs(-5) == abs(-5.0));
	*/

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

	return 0;
}