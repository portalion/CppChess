#pragma once
#include <vector>
#include <string>

class Piece;
enum class PieceId;

class Move
{
protected:
	const unsigned int posX;
	const unsigned int posY;
	const unsigned int boardSize;
	const bool isWhite;
public:
	Move(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite);

	virtual std::vector<std::pair<unsigned int, unsigned int>> getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const = 0;
	virtual std::string getMoveNames(const std::vector<std::vector<Piece>>& pieces) const;//TODO

	static Move* getMove(const PieceId& id, unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite);
};

class PawnMove : public Move
{
public:
	PawnMove(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite);
	std::vector<std::pair<unsigned int, unsigned int>> getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const override;
};

class KingMove : public Move
{
public:
	KingMove(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite);
	std::vector<std::pair<unsigned int, unsigned int>> getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const override;
};

class RookMove : public Move
{
public:
	RookMove(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite);
	std::vector<std::pair<unsigned int, unsigned int>> getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const override;
};

class BishopMove : public Move
{
public:
	BishopMove(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite);
	std::vector<std::pair<unsigned int, unsigned int>> getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const override;
};

class QueenMove : public Move
{
public:
	QueenMove(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite);
	std::vector<std::pair<unsigned int, unsigned int>> getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const override;
};