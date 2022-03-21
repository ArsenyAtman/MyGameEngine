#include "Game.h"

#include <iostream>
#include <chrono>
#include <thread>

void Game::gameTick(float deltaTime)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(0));
	std::cout << "GameTick: " << deltaTime << std::endl;
}
