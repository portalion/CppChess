#include "Board.h"

Board::Board()
	:pieces(size, std::vector<Piece>(size))
{
	setNewBoard();
}

void Board::setNewBoard()
{
	for (unsigned int i = 0; i < this->size; i++)
		for (unsigned int j = 0; j < this->size; j++)
			pieces[i][j].setPiece();
	
	//Pawns
	for (unsigned int i = 0; i < this->size; i++) pieces[1][i].setPiece(PieceId::Pawn);
	for (unsigned int i = 0; i < this->size; i++) pieces[this->size - 2][i].setPiece(PieceId::Pawn, true);

	//Rook, knight, bishop, queen, king
	for (unsigned int value = 0; value <= 1; value++)
	{
		bool isWhite = static_cast<bool>(value);
		for (int i = static_cast<int>(PieceId::Rook); i > static_cast<int>(PieceId::Pawn); i--)
		{
			pieces[isWhite ? this->size - 1 : 0][static_cast<int>(PieceId::Rook) - i].setPiece(PieceId(i), isWhite);
			pieces[isWhite ? this->size - 1 : 0][this->size - static_cast<int>(PieceId::Rook) + i - 1].setPiece(PieceId(i), isWhite);
		}
		pieces[isWhite ? this->size - 1 : 0][static_cast<int>(PieceId::Bishop) + 1].setPiece(PieceId::Queen, isWhite);
		pieces[isWhite ? this->size - 1 : 0][static_cast<int>(PieceId::Bishop) + 2].setPiece(PieceId::King, isWhite);
	}
}

void Board::draw() const
{
	std::cout << "   ";
	for (unsigned int i = 0; i < this->size; i++)
		std::cout << "   " << i + 1 << "  ";
	std::cout << '\n';
	for (unsigned int j = 0; j < this->size; j++)
	{
		std::cout << "   ";
		for (unsigned int i = 0; i < this->size; i++) std::cout << "------";
		std::cout << "-\n";

		//std::cout << " " << static_cast<char>('a' + i) << " ";

		for (unsigned int i = 0; i < 3; i++)
		{
			if (i == 1) std::cout << ' ' << static_cast<char>('A' + j) << ' ';
			else std::cout << "   ";
			for (unsigned int k = 0; k < this->size; k++)
			{
				std::cout << "|  ";
				if (i == 1)pieces[j][k].draw();
				else std::cout << ' ';
				std::cout <<"  ";
			}
			
			if (i == 1)std::cout << "| " << static_cast<char>('A' + j) << '\n';
			else std::cout << "|\n";
		}
		
	}
	std::cout << "   ";
	for (unsigned int i = 0; i < this->size; i++) std::cout << "------";
	std::cout << "-\n";

	std::cout << "   ";
	for (unsigned int i = 0; i < this->size; i++)
		std::cout << "   " << i + 1 << "  ";
	std::cout << '\n';
}
