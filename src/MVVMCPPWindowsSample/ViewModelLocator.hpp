#pragma once
#include "MainViewModel.hpp"

namespace AppViewModel
{
	class ViewModelLocator
	{
	private:
		MainViewModel* mainViewModel = nullptr;

	public:
		ViewModelLocator();
		~ViewModelLocator();

		MainViewModel* getMainViewModel();
	};
}
