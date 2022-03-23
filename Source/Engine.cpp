#include "Engine.h"

#include <chrono>

#include "GameSystem/GameSystem.h"
#include "GraphicsSystem/GraphicsSystem.h"

Engine::Engine()
{
	engineSystems.push_back(std::make_unique<GameSystem>());
	engineSystems.push_back(std::make_unique<GraphicsSystem>());
}

void Engine::start()
{
	startEngineLoop();
}

void Engine::end()
{
	endEngineLoop();
}

void Engine::startEngineLoop()
{
	playing = true;

	for (auto& system : engineSystems)
	{
		system->initialize(this);
	}

	engineLoop();
}

void Engine::engineLoop()
{
	using Clock = std::chrono::system_clock;
	using TimePoint = std::chrono::time_point<Clock>;
	using TickDuration = std::chrono::duration<float>;

	TickDuration tickDuration = TickDuration();

	while (playing)
	{
		TimePoint tickStart = Clock::now();
		systemsTick(tickDuration.count());
		TimePoint tickEnd = Clock::now();

		tickDuration = tickEnd - tickStart;
	}
}

void Engine::endEngineLoop()
{
	playing = false;
}

void Engine::systemsTick(float deltaTime)
{
	for (auto& system : engineSystems)
	{
		system->engineTick(deltaTime);
	}
}