#pragma once

#include "../EngineSystem.h"

class GraphicsSystem : public IEngineSystem
{
public:

	virtual void initialize(class Engine* engine) override;

	virtual void engineTick(float deltaTime) override;
};
