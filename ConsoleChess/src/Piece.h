#pragma once
#include <unordered_map>
#include "Console.h"

enum class PieceId
{
	None = 0,
	Pawn = 1,
	Bishop = 2,
	Knight = 3,
	Rook = 4,
	Queen = 5,
	King = 6,
	Size = (static_cast<int>(King) + 1)
};



class Piece
{
private:
	//Constants
	static const std::unordered_map<PieceId, char> pieceAbbr;

	//Variables
	bool white;
	PieceId id;

public:
	Piece(PieceId id = PieceId::None, bool isWhite = false);
	void setPiece(PieceId piece = PieceId::None, bool isWhite = false);
	const PieceId& getId() const;
	bool isWhite() const;

	void draw(const Console::Color& background = Console::Color::None) const;
};

