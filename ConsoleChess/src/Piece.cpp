#include "Piece.h"
#include <iostream>

Piece::Piece()
	:id(PieceId::None), isWhite(false)
{
}

Piece::Piece(PieceId id, bool isWhite)
	:id(id), isWhite(isWhite)
{
}

void Piece::draw() const
{
	if (this->id == PieceId::None) std::cout << ".";
}
