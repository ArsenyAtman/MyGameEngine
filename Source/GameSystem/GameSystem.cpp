#include "GameSystem.h"

#include <iostream>
#include <chrono>
#include <thread>

#include "../Engine.h"

void GameSystem::initialize(Engine* engine)
{

}

void GameSystem::engineTick(float deltaTime)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(0));
	std::cout << "GameTick: " << deltaTime << std::endl;
}
