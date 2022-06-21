#pragma once
#include "Piece.h"
#include "Move.h"
#include <vector>
#include <iostream>
#include <algorithm>

class Board
{
private:
	const unsigned int size = 8;
	std::vector<std::vector<Piece>> pieces;
	bool asWhite;
	unsigned int chosenX;
	unsigned int chosenY;

	std::vector < std::pair<unsigned int, unsigned int>> possibleMoves;

	Console::Color getFieldBackground(const unsigned int& posX, const unsigned int& posY) const;
public:
	Board();
	void setNewBoard();
	void swapColors();

	void update();
	void draw() const;
};

