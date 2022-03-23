#pragma once

class IEngineSystem
{
public:

	virtual void initialize(class Engine* engine) = 0;

	virtual void engineTick(float DeltaTime) = 0;
};