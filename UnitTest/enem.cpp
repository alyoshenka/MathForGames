#include "enem.h"



enem::enem()
{
	texture = LoadTexture("enem.png");
	pos = { 200, 200 };
	forwardDir = { 0, -1 }; // up
	fov = 90; // 45 each way
	rotSpeed = 500.0f;
}


enem::~enem()
{
	UnloadTexture(texture);
}

void enem::draw()
{
	Rectangle source = { 0.0f, 0.0f, texture.width - 1.0f, texture.height - 1.0f};
	Rectangle dest = {(float)pos.x, (float)pos.y, (float)texture.width, (float)texture.height };
	Vector2 center = { source.width / 2, source.height / 2 };
	// texture
	DrawTexturePro(texture, source, dest, center, forwardDir.angleBetween(vec2(0, 1)), WHITE); // make rot rad
	// fov
	// float fovLen = 100.0f;
	// vec2 forVec = ()
	// DrawLine(pos.x, pos.y, forwardDir*(180/PI)*pos.getPerpCW().x, forwardDir*(180 / PI)*pos.getPerpCW().y, BLACK);
}

void enem::update()
{
	if (IsKeyPressed(KEY_SPACE)) {
		std::cout << forwardDir.x << ", " << forwardDir.y << std::endl;
		forwardDir.rotate(90);
		std::cout << forwardDir.x << ", " << forwardDir.y << std::endl;
		std::cout << forwardDir.angleBetween(vec2(1, 0)) * RAD_TO_DEG << std::endl;
	}	
}
