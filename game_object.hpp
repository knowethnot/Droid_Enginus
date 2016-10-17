#ifndef __GAME_OBJECT_HPP__
#define __GAME_OBJECT_HPP__

#include <unordered_map>

class GameObject
{
	public:
		GameObject();
		~GameObject();

		template <class T>
		bool AddComponents();

	private:
		template <class t>
		friend T* component_cast(GameObject& object);

		template <class T>
		friend T* component_cast(GameObject* p_object);

		typedef std::tr1::unordered_map<unsigned int, Component*> ComponentUnorderedMap;
		typedef ComponentUnorderedMap::iterator 				  ComponentUnorderedMapIterator;

		ComponentUnorderedMap 									  n_components;

		template <class T>
		T* GetComponent() { return static_cast<T*>(GetComponent(T::GetId())); }

		Component* GetComponent(unsigned int id);
};

#endif // __GAME_OBJECT_HPP__