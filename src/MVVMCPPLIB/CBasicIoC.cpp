#include "CBasicIoc.hpp"

DependencyInjection::BasicIoc::SafeBasicIocPtr DependencyInjection::BasicIoc::s_instance = nullptr;

void DependencyInjection::BasicIoc::disposeContents()
{
	delete (this->nodes);
}

DependencyInjection::BasicIoc* DependencyInjection::BasicIoc::instance()
{
	BasicIoc* ptr = nullptr;

	ptr = s_instance.get();

	if (ptr == nullptr)
	{
		ptr = new BasicIoc();
		s_instance.reset(ptr);
	}

	return ptr;
}

DependencyInjection::BasicIoc::BasicIoc()
{

}

DependencyInjection::BasicIoc::~BasicIoc()
{
	this->disposeContents();
}