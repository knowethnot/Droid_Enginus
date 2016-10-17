#ifndef __KERNEL_HPP__
#define __KERNEL_HPP__

#include <list>

#include "task.hpp"

namespace Framework
{
	class Kernel
	{
		public:
			Kernel();
			virtual ~Kernel();

			void Execute();

			bool AddTask(Task* p_task);

			void SuspendTask(Task* p_task);
			void ResumeTask(Task* p_task);
			void RemoveTask(Task* p_task);
			void KillAllTasks();

			bool HasTasks()	{ return n_tasks.size(); }

		private:
			typedef std::list<Task*> 		   TaskList;
			typedef std::list<Task*>::iterator TaskListIterator;

			TaskList 	n_tasks;
			TaskList 	n_pausedTasks;

			void PriorityAdd(Task* p_task);
	};
}

#endif // __KERNEL_HPP__