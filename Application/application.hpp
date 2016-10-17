#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include <android_native_app_glue.h>

#include "../Kernel/kernel.hpp"
#include "../Platform/android.hpp"
#include "../Renderer/renderer.hpp"
#include "../Utils/timer.hpp"

namespace Framework
{
	class Application
	{
		public:
			Application(android_app* state);
			virtual ~Application();

			virtual bool Initialize();

			virtual void P_Thread();

		protected:
			Kernel 		n_kernel;
			Renderer	n_rendererTask;
			Android 	n_androidTask;
			Timer 		n_timeTask;
	};
}

#endif // __APPLICATION_HPP__