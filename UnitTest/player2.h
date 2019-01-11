#pragma once
#include "raylib.h"
#include "transform2d.h"

class player2
{
public:
	Texture2D player;
	Texture2D staff;
	Texture2D knight;

	Rectangle playerRec;
	Rectangle staffRec;
	Rectangle knightRec;

	transform2d playerT;
	transform2d staffT;
	transform2d knightT;

	float rotSpd;
	float scaleSpd;
	float bulletSpd;
	static const int bulletAlloc = 10;
	vec2 pos[bulletAlloc];
	float angle[bulletAlloc];

	Rectangle playerScaleRec;
	Rectangle staffScaleRec;
	Rectangle knightScaleRec;
	vec2 playerOrig;
	vec2 staffOrig;
	vec2 knightOrig;

	player2();
	~player2();

	void update();
	void draw();
};
