#include "android.hpp"

namespace Framework
{
	bool Android::n_closing = false;
	bool Android::n_paused = false;

	static void android_handle_cmd(struct android_app* app, int32_t cmd)
	{
		switch (cmd)
		{
			case APP_CMD_INIT_WINDOW:
			{
				Renderer* p_renderer = static_cast<Renderer*>(app->userData);
				assert(p_renderer);
				p_renderer->Init();
			} break;
			case APP_CMD_DESTROY:
			{
				Renderer* p_renderer = static_cast<Renderer*>(app->userData);
				assert(p_renderer);
				p_renderer->Destroy();
			} break;
			case APP_CMD_TERM_WINDOW:
			{
				Renderer* p_renderer = static_cast<Renderer*>(app->userData);
				assert(p_renderer);
				p_renderer->Destroy();
			} break;
			case APP_CMD_RESUME:
			{
				Android::SetPaused(false);
			} break;
			case APP_CMD_PAUSE:
			{
				Android::SetPaused(true);
			} break;
		}
	}

	Android::Android(android_app* p_state, const unsigned int priority, Renderer* renderer)
		: Task(priority)
	{
		n_state = p_state;
		n_state->onAppCmd = android_handle_cmd;
		n_state->userData = static_cast<void*>(p_renderer);
	}

	Android::~Android()
	{
		// Dtor
	}

	bool Android::Start()
	{
		return true;
	}

	void Android::OnSuspend()
	{
		// Termination State
	}

	void Android::Update()
	{
		int events;
		struct android_poll_source* p_source;
		int ident = ALooper_pollAll(0, 0, &events, (void**)&p_source);

		if (ident >= 0)
		{
			if (p_source) p_source->process(n_state, p_source);
		}

		if (n_state->destroyRequested) n_closing = true;
	}

	void Android::OnResume()
	{
		// State Resumal (lol)
	}

	void Android::Stop()
	{
		// Halt State
	}
}