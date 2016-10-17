#include "kernel.hpp"
#include "../Platform/android.hpp"

// #include <algorithm>

namespace Framework
{
	Kernel::Kernel()
	{
		// Ctor	
	}

	Kernel::~Kernel()
	{
		// Dtor cleanup
	}

	void Kernel::PriorityAdd(Task* p_task)
	{
		TaskListIterator iter;

		for (iter = n_tasks.begin(); iter != n_tasks.end(); ++iter)
		{
			Task* p_current_task = (*iter);

			if (p_current_task->Priority() > p_task->Priority())
			{
				break;
			}
		}

		n_tasks.insert(iter, p_task);
	}

	void Kernel::Execute()
	{
		while (n_tasks.size())
		{
			if (Android::IsClosing())
			{
				KillAllTasks();
			}

			TaskListIterator iter;

			for (iter = n_tasks.begin(); iter != n_tasks.end(); ++iter)
			{
				Task* p_task = (*iter);
				if (!p_task->CanKill()) p_task->Update();
			}

			for (iter = n_tasks.begin(); iter != n_tasks.end(); ++iter)
			{
				Task* p_task = (*iter);

				++iter;

				if (p_task->CanKill())
				{
					p_task->Stop();
					n_tasks.remove(p_task);
					p_task = 0;
				}
			}
		}

		Android::ClearClosing();
	}

	bool Kernel::AddTask(Task* p_task)
	{
		bool started = p_task->Start();

		if (started) PriorityAdd(p_task);

		return started;
	}

	void Kernel::SuspendTask(Task* p_task)
	{
		if (std::find(n_tasks.begin(), n_tasks.end(), p_task) != n_tasks.end())
		{
			p_task->OnSuspend();
			n_tasks.remove(p_task);
			n_pausedTasks.push_back(p_task);
		}
	}

	void Kernel::ResumeTask(Task* p_task)
	{
		if (std::find(n_pausedTasks.begin(), n_pausedTasks.end(), p_task) != n_pausedTasks.end())
		{
			p_task->OnResume();
			n_pausedTasks.remove(p_task);
			PriorityAdd(p_task);
		}
	}

	void Kernel::RemoveTask(Task* p_task)
	{
		if (std::find(n_tasks.begin(), n_tasks.end(), p_task) != n_tasks.end())
		{
			p_task->SetCanKill(true);
		}
	}

	void Kernel::KillAllTasks()
	{
		for (TaskListIterator iter = n_tasks.begin(); iter != n_tasks.begin(); ++iter)
		{
			(*iter)->SetCanKill(true);
		}	
	}
}