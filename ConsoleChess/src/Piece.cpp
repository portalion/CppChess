#include "Piece.h"
#include <iostream>
#include "Console.h"

const std::unordered_map<PieceId, char> Piece::pieceAbbr = {
	std::make_pair(PieceId::None, ' '),
	std::make_pair(PieceId::Pawn, 'P'),
	std::make_pair(PieceId::Knight, 'N'),
	std::make_pair(PieceId::Bishop, 'B'),
	std::make_pair(PieceId::Rook, 'R'),
	std::make_pair(PieceId::Queen, 'Q'),
	std::make_pair(PieceId::King, 'K')
};

Piece::Piece(PieceId id, bool isWhite)
	:id(id), isWhite(isWhite)
{
}

void Piece::setPiece(PieceId piece, bool isWhite)
{
	this->id = piece;
	this->isWhite = isWhite;
}

void Piece::draw() const
{
	Console::setColor(this->isWhite ? Console::Color::White : Console::Color::Black);
	std::cout << pieceAbbr.at(this->id);
	
	Console::resetToDefault();
}
