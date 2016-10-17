#include "task.hpp"

namespace Framework
{
	Task::Task(const unsigned int priority)
	{
		n_priority = priority;
		n_canKill  = false;
	}

	Task::~Task()
	{
		// Dtor
	}

	void Task::SetCanKill(const bool canKill)
	{
		n_canKill = canKill;
	}

	bool Task::CanKill() const
	{
		return n_canKill;
	}

	unsigned int Task::Priority() const
	{
		return n_priority;
	}
}