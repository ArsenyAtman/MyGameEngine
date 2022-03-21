#include "Engine.h"

#include <chrono>

#include "SystemInputHandler/SystemInputHandler.h"
#include "Game/Game.h"
#include "Graphics/Graphics.h"

Engine::Engine()
{
	systemInputHandler = std::unique_ptr<SystemInputHandler>(new SystemInputHandler());
	game = std::unique_ptr<Game>(new Game());
	graphics = std::unique_ptr<Graphics>(new Graphics());
}

void Engine::start()
{
	using Clock = std::chrono::system_clock;
	using TickDuration = std::chrono::duration<float>;
	using TimePoint = std::chrono::time_point<Clock>;

	TickDuration tickDuration = TickDuration();

	while (true)
	{
		TimePoint tickStart = Clock::now();
		engineLoop(tickDuration.count());
		TimePoint tickEnd = Clock::now();

		tickDuration = tickEnd - tickStart;
	}
}

void Engine::engineLoop(float deltaTime)
{
	systemInputHandler->inputTick(deltaTime);
	game->gameTick(deltaTime);
	graphics->drawTick(deltaTime);
}
