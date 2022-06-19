#pragma once

enum class PieceId
{
	None = 0,
	Pawn = 1,
	Knight = 2,
	Bishop = 3,
	Rook = 4,
	Queen = 5,
	King = 6,
	Size = (static_cast<int>(King) + 1)
};

class Piece
{
private:
	bool isWhite;
	PieceId id;

public:
	Piece();
	Piece(PieceId id, bool isWhite);
	void draw() const;
};

