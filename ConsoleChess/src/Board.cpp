#include "Board.h"
#include "Console.h"


Board::Board()
	:pieces(size, std::vector<Piece>(size)), asWhite(true)
{
	setNewBoard();
	chosenX = 4;
	chosenY = 4;
	Move* tmp = new QueenMove(chosenX, chosenY, size, true);
	possibleMoves = tmp->getPossibleMoves(pieces);
	delete tmp;
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

void Board::swapColors()
{
	this->asWhite = !this->asWhite;
}

Console::Color Board::getFieldBackground(const unsigned int& posX, const unsigned int& posY)const
{
	bool youCanMoveThere = std::find(this->possibleMoves.begin(), this->possibleMoves.end(), std::make_pair(posX, posY)) != this->possibleMoves.end();
	if (chosenX == posX && chosenY == posY) return Console::Color::Aqua;
	else if (youCanMoveThere && pieces[posY][posX].getId() != PieceId::None)return Console::Color::Red;
	else if (youCanMoveThere) return Console::Color::Yellow;
	return Console::Color::None;
}

static void writeBoardLine(const unsigned int& boardSize);
static void writeBoardLetters(const unsigned int& boardSize, const bool& isWhite);
static void writeBoardNumber(const unsigned int& numerToWrite, const unsigned int& boardSize, const bool& isWhite);

void Board::draw() const
{
	writeBoardLetters(this->size, this->asWhite);
	for (unsigned int yIndex = 0; yIndex < this->size; yIndex++)
	{
		writeBoardLine(this->size);

		for (unsigned int i = 0; i < 3; i++)
		{
			if (i == 1) writeBoardNumber(yIndex, this->size, this->asWhite);
			else std::cout << "   ";
			for (unsigned int xIndex = 0; xIndex < this->size; xIndex++)
			{
				std::cout << '|';

				Console::Color background = getFieldBackground(xIndex, yIndex);
				Console::setColor(Console::Color::Default, background);

				std::cout << "  ";
				if (i == 1)pieces[asWhite ? yIndex : this->size - yIndex - 1][asWhite ? xIndex : this->size - xIndex - 1].draw(background);
				else std::cout << ' ';
				std::cout <<"  ";

				Console::resetToDefault();
			}
			std::cout << '|';
			if (i == 1) writeBoardNumber(yIndex, this->size, this->asWhite);
			std::cout << '\n';
		}
		
	}
	writeBoardLine(this->size);
	writeBoardLetters(this->size, this->asWhite);
}

void writeBoardLine(const unsigned int& boardSize)
{
	std::cout << "   ";
	for (unsigned int i = 0; i < boardSize; i++) std::cout << "------";
	std::cout << "-\n";
}

void writeBoardLetters(const unsigned int& boardSize, const bool& isWhite)
{
	std::cout << "   ";
	for (unsigned int i = 0; i < boardSize; i++)
	{
		std::cout << "   ";
		std::cout << static_cast<char>(isWhite ? 'A' + i : 'A' + boardSize - i - 1);
		std::cout << "  ";
	}
	std::cout << '\n';
}

void writeBoardNumber(const unsigned int& numerToWrite, const unsigned int& boardSize, const bool& isWhite)
{
	std::cout << ' ';
	if (!isWhite)std::cout << numerToWrite + 1;
	else std::cout << boardSize - numerToWrite;
	std::cout << ' ';
}
