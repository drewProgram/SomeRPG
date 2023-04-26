// System headers
#include <windows.h>

// C++ headers
#include <iostream>
#include <string>

// Project headers
#include "Utils.h"
#include "Screen.h"
#include "Game.h"

bool EnableVTMode(_OUT HANDLE &hOut, _OUT HANDLE &hIn, _OUT DWORD &dwMode)
{
	// set output mode to handle virtual terminal sequences
	// we don't want to work with legacy console apps
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);		// when app is created, system creates handles, so we get the output that was created
	if (hOut == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	if (hIn == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
	{
		return false;
	}

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(hOut, dwMode))
	{
		return false;
	}
}

int main()
{
	// console vars
	HANDLE hOut;
	HANDLE hIn;
	DWORD dwMode;
	DWORD dwBytesWritten;

	bool bSuccessVTMode = EnableVTMode(hOut, hIn, dwMode);
	if (!bSuccessVTMode)
	{
		std::cout << "Unable to enter VT Processing mode. Quitting. \n";
		return -1;
	}

	// Setting window title?
	std::cout << ESC << "]0;RPG\x1b\x5c";
	std::cout << ESC << "[?3h";

	// Switching to alternate buffer
	std::cout << CSI << "?1049h";

	// Clear screen
	std::cout << CSI << "2J";

	const int width = 120;
	const int height = 40;
	Screen* GameScreen = new Screen(width, height);
	
	//WriteConsole(hOut, GameScreen->m_currentScreen, x * y, &dwBytesWritten, NULL);
	std::cout << "X: " << x;
	std::cout << "\nY: " << y;
	int n = 0;
	while (n == 0) 
	{
		n++;
		// processInput();
		// update()
		// render()
	}

	delete GameScreen;

	return 0;
}