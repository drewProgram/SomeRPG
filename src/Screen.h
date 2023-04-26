#pragma once

#include <string>
#include <array>

struct Screen
{
public:
	Screen(int x, int y);

	wchar_t* m_currentScreen;

private:
	int x;
	int y;
};
