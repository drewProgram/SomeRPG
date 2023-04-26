#pragma once

#include <queue>

#include "Level.h"
#include "Screen.h"

class Game
{
public:
	Game();
	~Game();

	void ProcessInput();
	void Update();
	void Render();

private:
	std::queue<Level> m_Levels;
	Screen* m_GameScreen;
	
};
