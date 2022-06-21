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
	:id(id), white(isWhite)
{
}

void Piece::setPiece(PieceId piece, bool isWhite)
{
	this->id = piece;
	this->white = isWhite;
}

const PieceId& Piece::getId() const
{
	return this->id;
}

bool Piece::isWhite() const
{
	return white;
}

void Piece::draw(const Console::Color& background) const
{
	Console::setColor(this->white ? Console::Color::White : Console::Color::Black, background);
	std::cout << pieceAbbr.at(this->id);
	
	Console::setColor(Console::Color::Default, background);
}
