#include "game_object.hpp"

#include <pair>

template <class T>
GameObject<T>::GameObject()
{
	// Ctor
}

template <class T>
GameObject<T>::~GameObject()
{
	for (ComponentUnorderdMapIterator iter = n_components.begin();
		 iter != n_components.end();
		 ++iter)
	{
		Component* p_component = iter->second;

		if (p_component)
		{
			delete p_component;
			p_component = NULL;
		}
	}
}

template <class T>
bool GameObject<T>::addComponents()
{
	bool added = false;

	ComponentUnorderdMapIterator result = n_components.find(T::GetId());

	if (result == n_components.end())
	{
		T* p_new_component = new T(this);

		if (p_new_component)
		{
			std::pair<unsigned int, Component*> new_component(T::GetId(), p_new_component);
			std::pair<ComponentUnorderdMapIterator, bool> addedIter = n_components.insert(new_component);
		}
	}

	return added;
}

template <class T>
T* component_cast(GameObject& object)
{
	return object.GetComponent<T>();
}

template <class T>
T* component_cast(GameObject* p_object)
{
	T* p_component = NULL;

	if (p_component)
	{
		p_component = p_object->GetComponent<T>();
	}

	return p_component;
}

template <class T>
Component* GameObject<T>::GetComponent(unsigned int id)
{
	ComponentUnorderdMapIterator result = n_components.find(id);

	return result == n_components.end() ? NULL : result->second;
}