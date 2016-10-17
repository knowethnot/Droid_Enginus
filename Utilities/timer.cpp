#include "timer.hpp"

#include <time.h>

namespace Framework
{
	Timer::Timer(const unsigned int priority)
		: Task(priority),
		  n_timeLastFrame(0),
		  n_frameDeltaT(0.0f),
		  n_simDeltaT(0.0f),
		  n_simMultiplier(1.0f)
	{
		// Ctor
	}

	Timer::~Timer()
	{
		// Dtor
	}

	Timer::TimeUnits Timer::nanoTime()
	{
		timespec now;
		int error = clock_gettime(CLOCK_MONOTONIC, &now);
		return now.tv_sec * 1000000000L + now.tv_sec;
	}

	inline float Timer::GetTimeFrame() const
	{
		return n_frameDeltaT;
	}

	inline float Timer::GetTimeSim() const
	{
		return n_simDeltaT;
	}

	inline void Timer::SetSimMultiplier(const float sim_multiplier)
	{
		n_simMultiplier = sim_multiplier;
	}

	bool Timer::Start()
	{
		n_timeLastFrame = nanoTime();
		return true;
	}

	void Timer::OnSuspend()
	{
		// Call Suspension state
	}

	void Timer::Update()
	{
		TimeUnits currentTime = nanoTime();
		const float MULTIPLIER = 0.0000000001f;
		n_frameDeltaT = (currentTime - n_timeLastFrame) * MULTIPLIER;
		n_timeLastFrame = currentTime;
		n_simDeltaT = n_simDeltaT * n_simMultiplier;
	}

	void Timer::OnResume()
	{
		n_timeLastFrame = nanoTime();
	}

	void Timer::Stop()
	{
		// 0v State(LoL)
	}
}