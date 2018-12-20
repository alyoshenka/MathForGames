#include "gameState.h"

gameState::gameState()
{
	// init
	state = MainMenu;
}

void gameState::mainMenu()
{
	// update
	if (IsKeyPressed(KEY_SPACE))
	{
		state = InGame;
	}

	BeginDrawing();

	// draw
	ClearBackground(WHITE);

	EndDrawing();
}

void gameState::inGame()
{
	// update
	if (IsKeyPressed(KEY_SPACE))
	{
		state = GameOver;
	}

	if (IsKeyPressed(KEY_ONE))
	{
		particleEffect a;
		a.pos = GetMousePosition();
		pes.push_back(a);
	}


	BeginDrawing();

	// draw
	ClearBackground(RED);

	for (auto it = pes.begin(); it != pes.end();)
	{
		it->update();
		if (!it->isAlive)
		{
			it = pes.erase(it);
		}
		else
		{
			it->draw();
			it++;
		}
	}

	EndDrawing();
}

void gameState::gameOver()
{
	// update
	if (IsKeyPressed(KEY_SPACE))
	{
		state = MainMenu;
	}

	BeginDrawing();

	// draw
	ClearBackground(GREEN);

	EndDrawing();
}


gameState::~gameState()
{
}

gameState & gameState::getInstance()
{
	static gameState instance;
	return instance;
}

State gameState::getState()
{
	return state;
}

void gameState::setState(State _state)
{
	state = _state;
}

void gameState::go()
{
	switch (state)
	{
	case 0:
		mainMenu();
		break;
	case 1:
		inGame();
		break;
	case 2:
		gameOver();
		break;
	default:
		// no idea how tf
		break;
	}
}
