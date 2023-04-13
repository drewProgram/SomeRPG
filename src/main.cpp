// System headers
#include <windows.h>

// C++ headers
#include <iostream>
#include <string>

#define _IN
#define _OUT

// Escape
#define ESC "\x1b"
// Control Sequence Introduction
#define CSI "\x1b["

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

	// game constants
	/*const int ScreenWidth = 100;
	const int ScreenHeight = 50;*/

	//wchar_t* Screen = new wchar_t[ScreenHeight * ScreenWidth];
	

	// Setting window title?
	std::cout << ESC << "]0;RPG\x1b\x5c";

	CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
	if (GetConsoleScreenBufferInfo(hOut, &ScreenBufferInfo) == 0)
	{
		GetLastError();
		return -1;
	}
	COORD Size;
	Size.X = ScreenBufferInfo.srWindow.Right - ScreenBufferInfo.srWindow.Left + 1;
	Size.Y = ScreenBufferInfo.srWindow.Bottom - ScreenBufferInfo.srWindow.Top + 1;

	wchar_t* Screen = new wchar_t[Size.X * Size.Y + 1];

	// Switching to alternate buffer
	std::cout << CSI << "?1049h";

	// Clear screen
	std::cout << CSI << "2J";

	for (int x = 0; x < Size.X; x++)
	{
		for (int y = 0; y < Size.Y; y++)
		{
			
			Screen[x + y * Size.X] = 'o';
		}
	}
	
	Screen[Size.Y * Size.X] = '\0';
	WriteConsole(hOut, Screen, Size.Y * Size.X, &dwBytesWritten, NULL);

	//int n = 0;
	//while (n == 0) 
	//{
	//	n++;
	//	// processInput();
	//	// update()
	//	// render()
	//}
	//} 

	delete[] Screen;

	return 0;
}