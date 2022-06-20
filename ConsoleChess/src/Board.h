#pragma once
#include "Piece.h"
#include <vector>
#include <iostream>

class Board
{
private:
	const unsigned int size = 8;
	std::vector<std::vector<Piece>> pieces;
public:
	Board();
	void setNewBoard();

	void draw() const;
};

