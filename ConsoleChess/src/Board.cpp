#include "Board.h"

Board::Board()
	:pieces(size, std::vector<Piece>(size))
{
}

void Board::draw() const
{
	std::cout << "Board\n";
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
				if (i == 1)pieces[j][i].draw();
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
