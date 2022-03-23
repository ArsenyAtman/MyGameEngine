#pragma once

#include <memory>
#include <vector>

#include "EngineSystem.h"

class Engine
{
public:

	Engine();

	void start();
	void end();

protected:

	void startEngineLoop();
	void engineLoop();
	void endEngineLoop();

	void systemsTick(float deltaTime);

private:

	std::vector<std::unique_ptr<class IEngineSystem>> engineSystems;

	bool playing = false;

	
};
