#ifndef __ANDROID_HPP__
#define	__ANDROID_HPP__

#include <android_native_app_glue.h>

#include "task.hpp"

namespace Framework
{
	class Android : public Task
	{
		public:
			Android(android_app* p_state, const unsigned int priority, Renderer* renderer);
			virtual ~Android();

			android_app* 	GetAppState() { return n_state; }

			virtual bool 	Start();

			virtual void  	OnSuspend();
			virtual void 	Update();
			virtual void 	OnResume();
			virtual void 	Stop();

			static void 	ClearClosing()	{ n_closing = false; }
			static bool 	IsClosing()		{ return n_closing; }
			static void 	SetPaused(const bool paused) { n_paused = paused; }
			static bool		IsPaused()		{ return n_paused; }

		private:
			static bool		n_closing;
			static bool 	n_paused;
			android_app*	n_state;
	};
}

#endif // __ANDROID_HPP__