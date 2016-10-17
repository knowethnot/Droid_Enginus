#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include "game_object.hpp"

class Component
{
	public:
		explicit Component(GameObject* p_owner) : n_owner(p_owner) { }

		virtual ~Component() { }

		virtual void Initialize() = 0;

		GameObject* GetOwner() { return n_owner; }

	private:
		GameObject* n_owner;
};

#endif // Component