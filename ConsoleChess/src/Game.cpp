#include "Game.h"
#include <iostream>

void Game::handleInput()
{
}

void Game::draw()
{
}

void Game::update()
{
}

Game::Game()
	:inGame(true)
{
}

void Game::run()
{
	while (this->inGame)
	{
		this->handleInput();
		this->update();
		this->draw();
	}
}