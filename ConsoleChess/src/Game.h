#pragma once
#include <stack>
#include "Board.h"

class State;

class Game
{
private:
	//Variables
	std::stack<State*> gameStateStack;

	bool inGame;
	Board chessBoard;

	//Functions

	void handleInput();
	void draw() const;
	void update();
public:
	Game();
	void run();
};

