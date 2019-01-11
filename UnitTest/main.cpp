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
// #include "mat3.h"
#include "mat4.h"

#include "test.h"
#include "particleSpawner.h"

#include "unitTest.h"

// #define ENABLE_HALT_ON_FAILURE 1
#include "helper.h"

// macros
#define minMacro(a, b) ((a) < (b) ? (a) : (b))
#define sumMacro(a, b) (a + b)

int main() {

	// Unit Test
	// if all tests pass, there will be no assert error (no news is good news)

	// vector addition
	vec2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	vec3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	vec4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	TEST("Vector2 addition", v2c, vec2(18.5f, -44.24f));
	TEST("Vector3 addition", v3c, vec3(18.5f, -44.24f, 850));
	TEST("Vector4 addition", v4c, vec4(18.5f, -44.24f, 850, 1));

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

	TEST("Vector2 subtraction", v2c, vec2(8.5f, -52.22f));
	TEST("Vector3 subtraction", v3c, vec3(8.5f, -52.22f, 874));
	TEST("Vector4 subtraction", v4c, vec4(8.5f, -52.22f, 874, -1));

	// vector post-scale
	v2a = vec2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = vec3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	TEST("Vector2 post-scale", v2c, vec2(33.5069999695f, -119.706863403f));
	TEST("Vector3 post-scale", v3c, vec3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 post-scale", v4c, vec4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = vec2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = vec3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	TEST("Vector2 pre-scale", v2c, vec2(33.5069999695f, -119.706863403f));
	TEST("Vector3 pre-scale", v3c, vec3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 pre-scale", v4c, vec4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

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

	TEST("Vector2 dot", dot2, -124.937698364f);
	TEST("Vector3 dot", dot3, -10468.9375f);
	TEST("Vector4 dot", dot4, -10468.9375f);

	// vector cross product
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = vec3(5, 3.99f, -12);
	v3c = v3a.cross(v3b);
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = vec4(5, 3.99f, -12, 1);
	v4c = v4a.cross(v4b);

	TEST("Vector3 cross", v3c, vec3(-2860.62011719f, 4472.00000000f, 295.01498413f));
	TEST("Vector4 cross", v4c, vec4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));

	// vector magnitude
	v2a = vec2(13.5f, -48.23f);
	float mag2 = v2a.magnitude();
	v3a = vec3(13.5f, -48.23f, 862);
	float mag3 = v3a.magnitude();
	v4a = vec4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.magnitude();

	TEST("Vector2 magnitude", mag2, 50.0837593079f);
	TEST("Vector3 magnitude", mag3, 863.453735352f);
	TEST("Vector4 magnitude", mag4, 863.453735352f);

	// vector normalize
	v2a = vec2(-13.5f, -48.23f);
	v2a.normalize();
	v3a = vec3(13.5f, -48.23f, 862);
	v3a.normalize();
	v4a = vec4(243, -48.23f, 862, 0);
	v4a.normalize();

	TEST("Vector2 normalize", v2a, vec2(-0.269548f, -0.962987f));
	TEST("Vector3 normalize", v3a, vec3(0.0156349f, -0.0558571f, 0.998316f));
	TEST("Vector4 normalize", v4a, vec4(0.270935f, -0.0537745f, 0.961094f, 0));

	// matrix rotation
	mat3 m3a, m3b, m3c, m3d;
	mat4 m4a, m4b, m4c, m4d;
	m3a = mat3::rotationX(3.98f);
	m4a = mat4::rotationX(4.5f);
	m3b = mat3::rotationY(1.76f);
	m4b = mat4::rotationY(-2.6f);
	m3c = mat3::rotationZ(9.62f);
	m4c = mat4::rotationZ(0.72f);

	TEST("Matrix3 set rotate", m3a, mat3(1, 0, 0, 0, -0.668648f, -0.743579f, 0, 0.743579f, -0.668648f));
	TEST("Matrix3 set rotate", m3b, mat3(-0.188077f, 0, -0.982154f, 0, 1, 0, 0.982154f, 0, -0.188077f));
	TEST("Matrix3 set rotate", m3c, mat3(-0.981005f, -0.193984f, 0, 0.193984f, -0.981005f, 0, 0, 0, 1));
	TEST("Matrix4 set rotate", m4a, mat4(1, 0, 0, 0, 0, -0.210796f, -0.97753f, 0, 0, 0.97753f, -0.210796f, 0, 0, 0, 0, 1));
	TEST("Matrix4 set rotate", m4b, mat4(-0.856889f, 0, 0.515501f, 0, 0, 1, 0, 0, -0.515501f, 0, -0.856889f, 0, 0, 0, 0, 1));
	TEST("Matrix4 set rotate", m4c, mat4(0.751806f, 0.659385f, 0, 0, -0.659385f, 0.751806f, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));

	// vector transform
	v2a = vec2(13.5f, -48.23f);
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix transform", v3b, vec3(844.077941895f, -48.2299995422f, -175.38130188f));
	TEST("Vector3 matrix transform", v3c, vec3(-22.5994224548f, 44.6950683594f, 862));
	TEST("Vector4 matrix transform", v4b, vec4(-455.930236816f, -48.2299995422f, -731.678771973f, 0));
	TEST("Vector4 matrix transform", v4c, vec4(41.951499939f, -27.3578968048f, 862, 0));

	// matrix multiply
	m3d = m3a * m3c;
	m4d = m4c * m4b;

	TEST("Matrix3 multiply", m3d, mat3(-0.981004655361f, 0.129707172513f, 0.14424264431f, 0.193984255195f, 0.655946731567f, 0.729454636574f, 0, 0.743579149246f, -0.668647944927f));
	TEST("Matrix4 multiply", m4d, mat4(-0.644213855267f, -0.565019249916f, 0.515501439571f, 0, -0.659384667873f, 0.751805722713f, 0, 0, -0.387556940317f, -0.339913755655f, -0.856888711452f, 0, 0, 0, 0, 1));

	// homogeneous point translation
	m3b = mat3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b.axis[2] = vec3(55, 44, 1);
	m3c = mat3::rotationZ(2.2f);
	m3c.axis[2] = vec3(55, 44, 1);
	m4b = mat4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b.axis[3] = vec4(55, 44, 99, 1);
	m4c = mat4::rotationZ(2.2f);
	m4c.axis[3] = vec4(55, 44, 99, 1);

	v3a = vec3(13.5f, -48.23f, 1);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = vec4(13.5f, -48.23f, -54, 1);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix translation A", v3b, vec3(68.5f, -4.23f, 1));
	TEST("Vector3 matrix translation B", v3c, vec3(86.0490112305f, 83.2981109619f, 1));
	TEST("Vector4 matrix translation A", v4b, vec4(68.5f, -4.23f, 45, 1));
	TEST("Vector4 matrix translation B", v4c, vec4(86.0490112305f, 83.2981109619f, 45, 1));

	// homogeneous vector translation
	m3b = mat3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b.axis[2] = vec3(55, 44, 1);
	m3c.rotationZ(2.2f);
	m3c.axis[2] = vec3(55, 44, 1);
	m4b = mat4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b.axis[3] = vec4(55, 44, 99, 1);
	m4c.rotationZ(2.2f);
	m4c.axis[3] = vec4(55, 44, 99, 1);

	v3a = vec3(13.5f, -48.23f, 0);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = vec4(13.5f, -48.23f, -54, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix translation C", v3b, vec3(13.5f, -48.23f, 0));
	TEST("Vector3 matrix translation D", v3c, vec3(31.0490131378f, 39.2981109619f, 0));
	TEST("Vector4 matrix translation C", v4b, vec4(13.5f, -48.23f, -54, 0));
	TEST("Vector4 matrix translation D", v4c, vec4(31.0490131378f, 39.2981109619f, -54, 0));

	// more tests
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

	// more tests
	assert(absoluteVal(-5) == 5);       // the abs value of -5 is 5
	assert(pow(2, 2) == 4);      // 2 to the power of 2 is 4
	assert(min(-5, 5) == -5);   // the lesser of these two values is -5
	// template tests
	assert(min(5, 6) == min(5.0, 6.0));
	assert(absoluteVal(-5) == abs(-5.0));
	// vectors
	vec2 v2a1 = vec2(13.5f, -48.23f);
	vec2 v2b1 = vec2(5, 3.99f);
	assert(v2a1.dot(v2b1) == -124.937698364f);
	assert(v2a1.magnitude() == 50.0837593079f);

	vec2 t1 = vec2(13.5f, -48.23f);
	vec2 t2 = vec2(5, 3.99f);

	assert(t1 + t2 == vec2(18.5f, -44.24f));
	assert(t1 - t2 == vec2(8.5f, -52.22f));

	float * temp = t1;
	assert(temp[1] == -48.23f);

	float scalar = 3.5f;
	vec2 dir = { 0, 1 };
	vec2 newVel = scalar * dir;
	assert(newVel == vec2(0.0f, 3.5f));

	// Alexi Assertions
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

	vec3 va = { 2, 2, 2 };
	vec3 vb = { 1, 1, 1 };
	vec3 diff = va - vb;

	aassert("diff x", 1.0f, diff.x, 0.0001f);
	aassert("diff y", 1.0f, diff.y, 0.0001f);
	aassert("diff z", 1.0f, diff.z, 0.0001f);

	aassert("minMacro", 1, minMacro(1, 4)); // pass
	aassert("sumMacro", 5, sumMacro(1, 3)); // fail if ENABLE_HALT_ON_FAILURE defined

	// transform2d test
	// demo application

	InitWindow(600, 400, "transform2d");

	Texture2D guy = LoadTexture("ice_zombie.png");
	transform2d guyT;
	Rectangle guyRec = { 0, 0, guy.width, guy.height };
	guyT.localScale = { 3, 3 };
	guyT.localPos = { 200, 200 };
	// guyT.localRot = PI / 2;

	Texture2D staff = LoadTexture("staff.png");
	transform2d staffT;
	Rectangle staffRec = { 0, 0, staff.width, staff.height };
	staffT.localPos = { 30, 10 };
	staffT.localScale = { 0.5f, 0.5f };

	staffT.setParent(&guyT);
	guyT.addChild(&staffT);

	float rotSpd = 0.0005f;
	float scaleSpd = 0.1f;

	const int bulletAlloc = 10;
	// bullet positions
	vec2 pos[bulletAlloc];
	// bullet angles, < 0 = unused
	float angle[bulletAlloc];
	float bulletSpd = 200.0f;

	while (!WindowShouldClose())
	{

		if (IsKeyDown(KEY_LEFT))
		{
			if (IsKeyDown(KEY_ONE))
			{
				guyT.localRot -= rotSpd;
			}
			if (IsKeyDown(KEY_TWO))
			{
				staffT.localRot -= rotSpd;
			}
		}
		if (IsKeyDown(KEY_RIGHT))
		{
			if (IsKeyDown(KEY_ONE))
			{
				guyT.localRot += rotSpd;
			}
			if (IsKeyDown(KEY_TWO))
			{
				staffT.localRot += rotSpd;
			}
		}

		if (GetMouseWheelMove() > 0)
		{
			if (IsKeyDown(KEY_ONE))
			{
				guyT.localScale.x += scaleSpd;
				guyT.localScale.y += scaleSpd;
			}
			if (IsKeyDown(KEY_TWO))
			{
				staffT.localScale.x += scaleSpd;
				staffT.localScale.y += scaleSpd;
			}
		}
		if (GetMouseWheelMove() < 0)
		{
			if (IsKeyDown(KEY_ONE))
			{
				guyT.localScale.x -= scaleSpd;
				guyT.localScale.y -= scaleSpd;
			}
			if (IsKeyDown(KEY_TWO))
			{
				staffT.localScale.x -= scaleSpd;
				staffT.localScale.y -= scaleSpd;
			}
		}

		Rectangle guyScaleRec = { guyT.worldPosition().x, guyT.worldPosition().y,
			guy.width * guyT.worldScale().x, guy.height * guyT.worldScale().y };
		Rectangle staffScaleRec = { staffT.worldPosition().x, staffT.worldPosition().y,
			staff.width * staffT.worldScale().x, staff.height * staffT.worldScale().y };

		vec2 guyOrig = { guy.width / 2.0f * guyT.worldScale().x, guy.height / 2.0f * guyT.worldScale().y };
		vec2 staffOrig = { staff.width / 2.0f * staffT.worldScale().x, staff.height / 2.0f * staffT.worldScale().y };

		// bullets
		if (IsMouseButtonPressed(0))
		{
			// search for avail
			for (int i = 0; i < bulletAlloc; i++)
			{
				if (angle[i] < 0)
				{
					// fire
					vec2 staffHead = staffT.worldPosition();					
					// don't make angle negative
					// - 90 deg = + 270 deg)
					angle[i] = staffT.worldRotation() + 3 * PI / 2;
					// staffHead.y += sin(angle[i]) * staffOrig.y;

					// bulletWid / 2;
					// staffHead.x -= 2.5;
					pos[i] = staffHead;
					break;
				}
			}
		}
		// update
		for (int i = 0; i < bulletAlloc; i++)
		{
			// deallocate
			if (pos[i].x > GetScreenWidth() || pos[i].x < -5 ||
				pos[i].y > GetScreenHeight() || pos[i].y < -5)
			{
				angle[i] = -1.0f;
			}
			// or update
			else 
			{
				pos[i].x += cos(angle[i]) * bulletSpd * GetFrameTime();
				pos[i].y += sin(angle[i]) * bulletSpd * GetFrameTime();
			}
		}

		BeginDrawing();

		ClearBackground(WHITE);

		// bullets
		for (int i = 0; i < bulletAlloc; i++)
		{
			if (angle[i] >= 0)
			{
				DrawRectangleV(pos[i], { 5, 5 }, GRAY);
			}
		}

		// NOTE: Using DrawTexturePro() we can easily rotate and scale the part of the texture we draw
		// sourceRec defines the part of the texture we use for drawing
		// destRec defines the rectangle where our texture part will fit (scaling it to fit)
		// origin defines the point of the texture used as reference for rotation and scaling
		// rotation defines the texture rotation (using origin as rotation point)

		DrawTexturePro(guy, guyRec, guyScaleRec, guyOrig, guyT.worldRotation() * RAD_TO_DEG, WHITE);
		DrawTexturePro(staff, staffRec, staffScaleRec, staffOrig, staffT.worldRotation() * RAD_TO_DEG, WHITE);

		// explanation
		std::string s1 = "1 to move parent (ice zombie)";
		std::string s2 = "2 to move child (goblin)";
		std::string s3 = "LEFT and RIGHT to rotate";
		std::string s4 = "MOUSE WHEEL to scale";

		DrawText(s1.c_str(), 10, 10, 10, BLACK);
		DrawText(s2.c_str(), 10, 25, 10, BLACK);
		DrawText(s3.c_str(), 10, 40, 10, BLACK);
		DrawText(s4.c_str(), 10, 55, 10, BLACK);

		EndDrawing();
	}

	UnloadTexture(guy);
	UnloadTexture(staff);

	CloseWindow();

	/*
	InitWindow(800, 600, "trnsform gizmos");

	Rectangle bigBlue = {10, 10, 50, 50};
	Rectangle medRed = {20, 70, 30, 30}; 
	Rectangle lilYellow = {30, 110, 10, 10};
	Rectangle choiceRecs[3] = {bigBlue, medRed, lilYellow};
	Color choiceColors[3] = {BLUE, RED, YELLOW};

	enum Rects 
	{
		n = -1, // n
		b, // blue
		r, // red
		y // yellow
	};

	Rects current = n;

	struct obj
	{
		transform2d transform;
		Rects type;
		Rectangle rec;
		Color c;
	};

	const int poolS = 100;
	obj objects[poolS];
	int idx = 0;

	while (!WindowShouldClose())
	{
		// select rectangle
		if (IsMouseButtonPressed(0))
		{
			vec2 pos = GetMousePosition();
			// select new
			if (current == n)
			{

				if (CheckCollisionPointRec(pos, bigBlue))
				{
					current = b;
				}
				else if (CheckCollisionPointRec(pos, medRed))
				{
					current = r;
				}
				else if (CheckCollisionPointRec(pos, lilYellow))
				{
					current = y;
				}
			}

			// parent/ place
			else
			{
				obj temp;
				temp.type = current;
				temp.rec = choiceRecs[current];
				temp.transform.localPos = pos;
				temp.c = choiceColors[current];

				bool parented = false;
				// check if parenting
				for (int i = 0; i < idx; i++) 
				{
					if (CheckCollisionPointRec(pos, objects[i].rec))
					{
						temp.transform.setParent(&objects[i].transform);
						objects[i].transform.addChild(&temp.transform);
						objects[i] = temp;
						idx++;
						parented = true;
						break;
					}
				}
				// otherwise place
				if (!parented)
				{
					objects[idx++] = temp;
				}

				// reset
				current = n;
			}
		}

		BeginDrawing();

		ClearBackground(BLACK);

		// selections
		DrawRectangleRec(bigBlue, BLUE);
		DrawRectangleRec(medRed, RED);
		DrawRectangleRec(lilYellow, YELLOW);

		for (int i = 0; i < idx; i++)
		{
			DrawRectangleRec({ objects[i].transform.worldPosition().x, objects[i].transform.worldPosition().y, objects[i].rec.width, objects[i].rec.height }, objects[i].c);
		}

		EndDrawing();
	}
	*/

	return 0;
}