#pragma once

class Game
{
private:
	//Variables
	bool inGame;

	//Functions
	void handleInput();
	void draw();
	void update();
public:
	Game();

	void run();
};

