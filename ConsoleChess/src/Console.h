#pragma once

namespace Console
{
	enum class Color
	{
		Black = 1,
		White = 8,
		Default = 7,
	};

	void setColor(Color color);
	void resetToDefault();
}