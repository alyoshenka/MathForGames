#include "player2.h"

player2::player2()
{
	player = LoadTexture("assets/ice_zombie.png");
	staff = LoadTexture("assets/staff.png");
	knight = LoadTexture("assets/knight.png");

	playerRec = { 0, 0, (float)player.width, (float)player.height };
	staffRec = { 0, 0, (float)staff.width, (float)staff.height };
	staffRec = { 0, 0, (float)knight.width, (float)knight.height };

	playerT.localScale = { 1, 1 };
	playerT.localPos = { 400, 400 };
	staffT.localPos = { 300, 10 };
	staffT.localScale = { 0.5f, 0.5f };
	knightT.localScale = { 1, 1 };
	knightT.localPos = {-50, 40};

	staffT.setParent(&playerT);
	playerT.addChild(&staffT);

	knightT.setParent(&staffT);
	staffT.addChild(&knightT);

	rotSpd = 5.0f;
	scaleSpd = 1000.0f;
	bulletSpd = 200.0f;

	vec2 p = playerT.worldPosition();
	vec2 s = staffT.worldPosition();
	vec2 k = knightT.worldPosition();
	playerScaleRec = { p.x, p.y, player.width * playerT.worldScale().x, player.height * playerT.worldScale().y };
	staffScaleRec = { s.x, s.y, staff.width * staffT.worldScale().x, staff.height * staffT.worldScale().y };
	knightScaleRec = { k.x, k.y, knight.width * knightT.worldScale().x, knight.height * knightT.worldScale().y };

	p = playerT.worldScale();
	s = staffT.worldScale();
	k = knightT.worldScale();
	playerOrig = { player.width / 2.0f * p.x, player.height / 2.0f * p.y };
	staffOrig = { staff.width / 2.0f * s.x, staff.height / 2.0f * s.y };
	knightOrig = { knight.width / 2.0f * k.x, knight.height / 2.0f * k.y };
}

player2::~player2()
{
	UnloadTexture(player);
	UnloadTexture(staff);
	UnloadTexture(knight);
}

void player2::update()
{

	if (IsKeyDown(KEY_LEFT))
	{
		if (IsKeyDown(KEY_ONE))
		{
			playerT.localRot -= rotSpd * GetFrameTime();
		}
		if (IsKeyDown(KEY_TWO))
		{
			staffT.localRot -= rotSpd * GetFrameTime();
		}
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		if (IsKeyDown(KEY_ONE))
		{
			playerT.localRot += rotSpd * GetFrameTime();
		}
		if (IsKeyDown(KEY_TWO))
		{
			staffT.localRot += rotSpd * GetFrameTime();
		}
	}

	if (GetMouseWheelMove() > 0)
	{
		if (IsKeyDown(KEY_ONE))
		{
			playerT.localScale.x += scaleSpd * GetFrameTime();
			playerT.localScale.y += scaleSpd * GetFrameTime();
		}
		if (IsKeyDown(KEY_TWO))
		{
			staffT.localScale.x += scaleSpd * GetFrameTime();
			staffT.localScale.y += scaleSpd * GetFrameTime();
		}
	}
	if (GetMouseWheelMove() < 0)
	{
		if (IsKeyDown(KEY_ONE))
		{
			playerT.localScale.x -= scaleSpd * GetFrameTime();
			playerT.localScale.y -= scaleSpd * GetFrameTime();
		}
		if (IsKeyDown(KEY_TWO))
		{
			staffT.localScale.x -= scaleSpd * GetFrameTime();
			staffT.localScale.y -= scaleSpd * GetFrameTime();
		}
	}

	vec2 p = playerT.worldPosition();
	vec2 s = staffT.worldPosition();
	vec2 k = knightT.worldPosition();
	vec2 ps = playerT.worldScale();
	vec2 ss = staffT.worldScale();
	vec2 ks = knightT.worldScale();

	// p /= ps; // why?

	playerScaleRec = { (p / ps).x, (p / ps).y, player.width * ps.x, player.height * ps.y };
	staffScaleRec = { (s / ss).x, (s / ss).y, staff.width*2 * ss.x, staff.height * ss.y };
	knightScaleRec = { k.x, k.y, knight.width * ks.x, knight.height * ks.y };

	playerOrig = { player.width / 2.0f * ps.x, player.height / 2.0f * ps.y };
	staffOrig = { staff.width / 2.0f * ss.x, staff.height / 2.0f * ss.y };
	knightOrig = { knight.width / 2.0f * ks.x, knight.height / 2.0f * ks.y };

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
				angle[i] = staffT.worldRotation().angleBetween(vec2(1, 0)) + 3 * PI / 2;
				// staffHead.y += sin(angle[i]) * staffOrig.y;

				// bulletWid / 2;
				staffHead -= 2.5;
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
}

void player2::draw()
{
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

	DrawTexturePro(player, playerRec, playerScaleRec, playerOrig, playerT.worldRotationFromOrig() * RAD_TO_DEG, WHITE);
	DrawTexturePro(staff, staffRec, staffScaleRec, staffOrig, staffT.worldRotationFromOrig() * RAD_TO_DEG, WHITE);
	// DrawTexturePro(knight, knightRec, knightScaleRec, knightOrig, knightT.worldRotationFromOrig() * RAD_TO_DEG, WHITE);
}
