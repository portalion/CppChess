#pragma once
#include <unordered_map>

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

	bool isWhite;
	PieceId id;

public:
	Piece(PieceId id = PieceId::None, bool isWhite = false);
	void setPiece(PieceId piece = PieceId::None, bool isWhite = false);

	void draw() const;
};

