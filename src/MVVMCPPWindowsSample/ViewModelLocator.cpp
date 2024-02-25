#include "ViewModelLocator.hpp"
#include "CBasicIoC.hpp"

AppViewModel::ViewModelLocator::ViewModelLocator()
{
	DependencyInjection::BasicIoc::instance()
		->store((std::function<MainViewModel*()>)[]() { return new MainViewModel(); });
}

AppViewModel::ViewModelLocator::~ViewModelLocator()
{

}

AppViewModel::MainViewModel* AppViewModel::ViewModelLocator::getMainViewModel()
{
	return DependencyInjection::BasicIoc::instance()->acquire<MainViewModel>();
}
