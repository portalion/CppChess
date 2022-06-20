#include "Console.h"
#include <windows.h>

void Console::setColor(Color color)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, static_cast<int>(color));
}

void Console::resetToDefault()
{
	setColor(Color::Default);
}
