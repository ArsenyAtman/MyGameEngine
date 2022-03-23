#pragma once

#include "../EngineSystem.h"

class GameSystem : public IEngineSystem
{
public:

	virtual void initialize(class Engine* engine) override;

	virtual void engineTick(float deltaTime) override;
};
