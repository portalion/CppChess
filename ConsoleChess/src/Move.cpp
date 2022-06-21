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
		result.push_back(std::make_pair(posX, posY - 2));
	if (!isSomethingAhead) result.push_back(std::make_pair(posX, posY - 1));
	if (posY != 0 && posX != 0 && pieces[posY - 1][posX - 1].getId() != PieceId::None && pieces[posY - 1][posX - 1].isWhite() != isWhite)
		result.push_back(std::make_pair(posX - 1, posY - 1));
	if (posY != 0 && posX != boardSize - 1 && pieces[posY - 1][posX + 1].getId() != PieceId::None && pieces[posY - 1][posX + 1].isWhite() != isWhite)
		result.push_back(std::make_pair(posX + 1, posY - 1));
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
			if (toCheck.getId() == PieceId::None) result.push_back(std::make_pair(posX + i, posY + j));
			else if (toCheck.isWhite() != isWhite) result.push_back(std::make_pair(posX + i, posY + j));
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

		for (const auto& position : toCheck)
		{
			const Piece& field = pieces[position.second.second][position.second.first];
			if (field.getId() != PieceId::None)
			{
				if (field.isWhite() != isWhite)result.push_back(position.second);

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
			else result.push_back(position.second);
		}
	}
	return result;
}
