#pragma once
#include "Singleton.h"
#include "ResourceManager.h"
namespace dae
{
	class TimerInfo final : public Singleton<TimerInfo>
	{
	public:
		const float GetElapsedSec() const { return deltaTime; }
		void SetDeltaTime(float dt) { deltaTime = dt; }
		const float GetFixedTimeStep() const { return fixedTimeStep; }
	private:
		friend class Singleton<ResourceManager>;
		const float fixedTimeStep = 0.02f;
		float deltaTime = 0.f;
	};
}