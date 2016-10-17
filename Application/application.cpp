#include "application.hpp"

namespace Framework
{
	Application::Application(android_app* state)
		: n_rendererTask(state, Task::RENDER_PRIORITY),
		  n_androidTask(state, Task::PLATFORM_PRIORITY, &n_rendererTask),
		  n_timerTask(Task::TIMER_PRIORITY)
	{
		File::SetAssetManager(state->activity->assetManager);
	}

	Application::~Application()
	{
		// Dtor clean up
	}

	bool Application::Initialize()
	{
		bool ret = true;

		n_kernel.AddTask(&n_androidTask);
		n_kernel.AddTask(&n_timerTask);
		n_kernel.AddTask(&n_rendererTask);

		return ret;
	}

	void Application::P_Thread()
	{
		n_kernel.Execute();
	}
}