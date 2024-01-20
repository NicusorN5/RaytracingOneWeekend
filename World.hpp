#pragma once
#include <vector>
#include <type_traits>
#include <memory>

#include "Color.hpp"
#include "Ray.hpp"
class Object;

template<typename T>
concept object_derived = std::is_base_of_v<Object, T>;

class World
{
	std::vector<std::unique_ptr<Object>> objects;
public:
	World() = default;
	World(const World&) = delete;
	World(World&&) = delete;

	template<object_derived T>
	void add(T&& obj)
	{
		objects.push_back(std::move(obj));
	}

	template<object_derived T, typename... Params>
	void add(Params&&... params)
	{
		T newobj(std::forward<Params>(params)...);
		add(std::move(newobj));
	}

	Object* at(size_t i);

	template<object_derived T>
	T* at(size_t i) const
	{
		return dynamic_cast<T*>(objects.at(i).get());
	}

	Color hit(const Ray& r) const;
};