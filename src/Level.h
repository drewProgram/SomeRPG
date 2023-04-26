#pragma once

#include <array>

class Level
{
public:
	Level();
	~Level();

private:
	int m_LayoutSize;
	std::array<int, m_LayoutSize> m_Layout;
};