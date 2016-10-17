#ifndef __TASK_HPP__
#define __TASK_HPP__

namespace Framework
{
	class Task
	{
		public:
			explicit Task(const unsigned int priority);
			virtual ~Task();

			virtual bool	Start()		= 0;

			virtual void 	OnSuspend() = 0;
			virtual void 	Update()	= 0;
			virtual void 	OnResume()	= 0;
			virtual void 	Stop()		= 0;

			void 			SetCanKill(const bool canKill);

			bool 			CanKill() const;

			unsigned int 	Priority() const;

			static const unsigned int TIMER_PRIORITY 	= 0;
			static const unsigned int PLATFORM_PRIORITY = 1000;
			static const unsigned int FILE_PRIORITY 	= 2000;
			static const unsigned int GAME_PRIORITY 	= 3000;
			static const unsigned int AUDIO_PRIORITY 	= 4000;
			static const unsigned int RENDER_PRIORITY 	= 5000;

		private:
			unsigned int 	n_priority;
			bool 			n_canKill;
	};
}

#endif // __TASK_HPP__