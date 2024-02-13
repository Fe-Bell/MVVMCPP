#include "ViewModelLocator.hpp"

AppViewModel::ViewModelLocator::ViewModelLocator()
{
	this->mainViewModel = new MainViewModel();
}

AppViewModel::ViewModelLocator::~ViewModelLocator()
{

}

AppViewModel::MainViewModel* AppViewModel::ViewModelLocator::getMainViewModel()
{
	return this->mainViewModel;
}
