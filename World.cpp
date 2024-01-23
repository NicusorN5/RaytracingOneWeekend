#include "World.hpp"
#include "Object.hpp"

Object* World::at(size_t i)
{
	return objects.at(i).get();
}

World::iterator World::begin()
{
	return iterator(objects.begin());
}

World::iterator World::end()
{
	return iterator(objects.end());
}

Object* World::iterator::operator*()
{
	return std::vector<std::unique_ptr<Object>>::iterator::operator*().get();
}

Object* World::iterator::operator->()
{
	return std::vector<std::unique_ptr<Object>>::iterator::operator*().get();
}