#pragma once

#include "../EngineSystem.h"

class InputSystem : public IEngineSystem
{
public:

	virtual void initialize(class Engine* engine) override;

	virtual void engineTick(float deltaTime) override;
};
