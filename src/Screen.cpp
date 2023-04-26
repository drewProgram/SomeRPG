#include "Screen.h"

#include <string>
#include <fstream>
#include <iostream>

Screen::Screen(int x, int y)
{
	x = x;
	y = y;

	m_currentScreen = new wchar_t[x * y + 1];
	m_currentScreen[x * y] = '\0';
	
	/*while (bHasAnotherLevel)
	{
		
	}*/
}
