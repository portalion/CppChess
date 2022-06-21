#include "Game.h"
#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
	//HANDLE  hConsole;
	//int k;

	//hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//// you can loop k higher to see more color choices
	//for (k = 1; k < 255; k++)
	//{
	//	// pick the colorattribute k you want
	//	SetConsoleTextAttribute(hConsole, k);
	//	cout << k << " I want to be nice today!" << endl;
	//}

	Game game;
	game.run();

}