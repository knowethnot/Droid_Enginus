#ifndef __TIMER_HPP__
#define __TIMER_HPP__

#include "Kernel/task.hpp"

namespace Framework
{
	class Timer : public Task
	{
		public:
			Timer(const unsigned int priority);
			~Timer();

			float GetTimeFrame() const;
			float GetTimeSim() const;

			void SetSimMultiplier(const float sim_multiplier);

			virtual bool Start();
			virtual void OnSuspend();
			virtual void Update();
			virtual void OnResume();
			virtual void Stop(); 

			typedef long long TimeUnits;

		private:
			TimeUnits nanoTime();
			TimeUnits n_timeLastFrame;

			float n_frameDeltaT;
			float n_simDeltaT;
			float n_simMultiplier;
	};
}

#endif // __TIMER_HPP__