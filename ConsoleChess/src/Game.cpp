#include "Game.h"
#include <iostream>

void Game::handleInput()
{
	std::cin >> this->inGame;
}

void Game::draw() const
{
	system("cls");
	chessBoard.draw();
}

void Game::update()
{
	std::cout << "UPDATING...\n";
	chessBoard.update();
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