 #include "raylib.h"
 #include "gameState.h"

int main() {
	int w = 1000;
	int h = 600;
	InitWindow(w, h, "AKGJ");
	SetTargetFPS(60);

	 gameState gs = gameState::getInstance();

	while (!WindowShouldClose())
	{
		gs.go();
		/*BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();*/

	}

	CloseWindow();

}