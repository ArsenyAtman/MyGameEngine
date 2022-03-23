#pragma once

#include "../EngineSystem.h"

class PhysicsSystem : public IEngineSystem
{
public:

	virtual void initialize(class Engine* engine) override;

	virtual void engineTick(float deltaTime) override;
};