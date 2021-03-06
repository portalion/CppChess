#include "Move.h"
#include "Piece.h"
#include <tuple>

Move::Move(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite)
	:posX(posX), posY(posY), boardSize(boardSize), isWhite(isWhite)
{
}

std::string Move::getMoveNames(const std::vector<std::vector<Piece>>& pieces) const
{
	return "";
}

Move* Move::getMove(const PieceId& id, unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite)
{
	Move* result = nullptr;
	switch (id)
	{
	case PieceId::Pawn:
		result = new PawnMove(posX, posY, boardSize, isWhite);
		break;
	case PieceId::Rook:
		result = new RookMove(posX, posY, boardSize, isWhite);
		break;
	case PieceId::Bishop:
		result = new BishopMove(posX, posY, boardSize, isWhite);
		break;
	case PieceId::King:
		result = new KingMove(posX, posY, boardSize, isWhite);
		break;
	case PieceId::Queen:
		result = new QueenMove(posX, posY, boardSize, isWhite);
		break;
	}
	return result;
}

PawnMove::PawnMove(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite)
	:Move(posX, posY, boardSize, isWhite)
{
}

std::vector<std::pair<unsigned int, unsigned int>> PawnMove::getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const
{
	std::vector<std::pair<unsigned int, unsigned int>> result;
	result.reserve(4);
	bool isSomethingAhead = (posY ==  0 ? true : pieces[posY - 1][posX].getId() != PieceId::None);

	if (posY == 0) return result;
	if (posY == boardSize - 2 && !isSomethingAhead && pieces[posY - 2][posX].getId() == PieceId::None) 
		result.emplace_back(posX, posY - 2);
	if (!isSomethingAhead) result.emplace_back(posX, posY - 1);
	if (posY != 0 && posX != 0 && pieces[posY - 1][posX - 1].getId() != PieceId::None && pieces[posY - 1][posX - 1].isWhite() != isWhite)
		result.emplace_back(posX - 1, posY - 1);
	if (posY != 0 && posX != boardSize - 1 && pieces[posY - 1][posX + 1].getId() != PieceId::None && pieces[posY - 1][posX + 1].isWhite() != isWhite)
		result.emplace_back(posX + 1, posY - 1);
	return result;
}

KingMove::KingMove(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite)
	:Move(posX, posY, boardSize, isWhite)
{
}

std::vector<std::pair<unsigned int, unsigned int>> KingMove::getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const
{
	std::vector<std::pair<unsigned int, unsigned int>> result;
	result.reserve(8);
	for (int i = -1; i <= 1; i++)
	{
		if (posX + i < 0 || posX + i >= boardSize)continue;
		for (int j = -1; j <= 1; j++)
		{
			if (posY + j < 0 || posX + j >= boardSize)continue;
			const Piece& toCheck = pieces[posY + j][posX + i];
			if (toCheck.getId() == PieceId::None) result.emplace_back(posX + i, posY + j);
			else if (toCheck.isWhite() != isWhite) result.emplace_back(posX + i, posY + j);
		}
	}
	return result;
}

RookMove::RookMove(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite)
	:Move(posX, posY, boardSize, isWhite)
{
}

enum class Direction
{
	up = 0,
	down = 1,
	left = 2,
	right = 3
};

static void checkMoves(bool& up, bool& down, bool& left, bool& right, const bool& isWhite,
	const std::unordered_map<Direction, std::pair<unsigned int, unsigned int>>& toCheck,
	std::vector < std::pair<unsigned int, unsigned int>>& result,
	const std::vector<std::vector<Piece>>& pieces);

std::vector<std::pair<unsigned int, unsigned int>> RookMove::getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const
{
	std::vector<std::pair<unsigned int, unsigned int>> result;
	result.reserve(14);
	bool up = true, down = true, left = true, right = true;
	for (unsigned int i = 1; i < boardSize; i++)
	{
		std::unordered_map<Direction, std::pair<unsigned int, unsigned int>> toCheck;

		if (posX + i >= boardSize) right = false;
		if (posX - i >= boardSize) left = false;
		if (posY - i >= boardSize) down = false;
		if (posY + i >= boardSize) up = false;

		if (right) toCheck[Direction::right] = { posX + i, posY };
		if (left) toCheck[Direction::left] = { posX - i, posY };
		if (up) toCheck[Direction::up] = { posX, posY + i };
		if (down) toCheck[Direction::down] = { posX, posY - i };

		if (toCheck.empty()) return result;

		checkMoves(up, down, left, right, isWhite, toCheck, result, pieces);
	}
	return result;
}

BishopMove::BishopMove(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite)
	:Move(posX, posY, boardSize, isWhite)
{
}

std::vector<std::pair<unsigned int, unsigned int>> BishopMove::getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const
{
	std::vector<std::pair<unsigned int, unsigned int>> result;
	result.reserve(14);
	bool up = true, down = true, left = true, right = true;
	for (unsigned int i = 1; i < boardSize; i++)
	{
		std::unordered_map<Direction, std::pair<unsigned int, unsigned int>> toCheck;

		if (posX + i >= boardSize || posY + i >= boardSize) right = false;
		if (posX - i >= boardSize || posY - i >= boardSize) left = false;
		if (posY - i >= boardSize || posX + i >= boardSize) down = false;
		if (posY + i >= boardSize || posX - i >= boardSize) up = false;

		if (right) toCheck[Direction::right] = { posX + i, posY + i};
		if (left) toCheck[Direction::left] = { posX - i, posY - i };
		if (up) toCheck[Direction::up] = { posX - i, posY + i };
		if (down) toCheck[Direction::down] = { posX + i, posY - i };

		if (toCheck.empty()) return result;

		checkMoves(up, down, left, right, isWhite, toCheck, result, pieces);
		
	}
	return result;
}

QueenMove::QueenMove(unsigned int posX, unsigned int posY, unsigned int boardSize, bool isWhite)
	:Move(posX, posY, boardSize, isWhite)
{
}

std::vector<std::pair<unsigned int, unsigned int>> QueenMove::getPossibleMoves(const std::vector<std::vector<Piece>>& pieces) const
{
	std::vector<std::pair<unsigned int, unsigned int>> result;
	std::vector<std::pair<unsigned int, unsigned int>> tmp;

	BishopMove bishop(posX, posY, boardSize, isWhite);
	RookMove rook(posX, posY, boardSize, isWhite);

	tmp = rook.getPossibleMoves(pieces);
	result = bishop.getPossibleMoves(pieces);
	result.insert(result.end(), tmp.begin(), tmp.end());

	return result;
}

static void checkMoves(bool& up, bool& down, bool& left, bool& right, const bool& isWhite,
	const std::unordered_map<Direction, std::pair<unsigned int, unsigned int>>& toCheck,
	std::vector < std::pair<unsigned int, unsigned int>>& result,
	const std::vector<std::vector<Piece>>& pieces)
{
	for (const auto& position : toCheck)
	{
		const Piece& field = pieces[position.second.second][position.second.first];
		if (field.getId() != PieceId::None)
		{
			if (field.isWhite() != isWhite)result.emplace_back(position.second);

			switch (position.first)
			{
			case Direction::up:
				up = false;
				break;
			case Direction::down:
				down = false;
				break;
			case Direction::left:
				left = false;
				break;
			case Direction::right:
				right = false;
				break;
			}
		}
		else result.emplace_back(position.second);
	}
}
