#pragma once

namespace Console
{
	enum class Color
	{
		None = 0,
		Black = 1,
		White = 8,
		Red = 4,
		Yellow = 14,
		Aqua = 11,
		Default = 7,
	};

	void setColor(Color color, Color background = Color::None);
	void resetToDefault();
}