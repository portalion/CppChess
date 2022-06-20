#include "Console.h"
#include <windows.h>

void Console::setColor(Color color, Color background)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,static_cast<int>(color) + 16 * static_cast<int>(background));
}

void Console::resetToDefault()
{
	setColor(Color::Default);
}
