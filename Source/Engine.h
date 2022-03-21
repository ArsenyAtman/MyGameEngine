#pragma once

#include <memory>

class Engine
{
public:

	Engine();

	void start();

protected:

	void engineLoop(float deltaTime);

private:

	std::unique_ptr<class SystemInputHandler> systemInputHandler;
	std::unique_ptr<class Game> game;
	std::unique_ptr<class Graphics> graphics;
};
