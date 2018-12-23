#pragma once
#include "raylib.h"
#include <vector>
#include "particleEffect.h"

// states
enum State
{
	MainMenu = 0,
	InGame,
	GameOver
};

// what are the potential drawbacks of this implementation?
// THIS WAS A DUMB IDEA I SEE WHY NOW

// this singleton class manages the use of
// the current game state
class gameState
{
	// prevents outside use
	gameState();

	State state;

	// state functions
	void mainMenu();
	void inGame();
	void gameOver();

	// game vals
	std::vector<particleEffect> pes;

public:

	~gameState();
	// use to init
	static gameState & getInstance();

	State getState();
	void setState(State _state);

	// main application function
	void go();
};


