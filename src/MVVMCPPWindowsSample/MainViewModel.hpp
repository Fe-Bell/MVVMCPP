#pragma once
#include "AViewModelBase.hpp"
#include "ICommand.hpp"

namespace AppViewModel
{
	class MainViewModel :
		public ViewModel::ViewModelBase
	{
	private:
		bool state = false;
		Command::ICommand* testCommand = nullptr;

		const bool canExecuteTestCommand();
		void executeTestCommand();

	public:
		MainViewModel();
		~MainViewModel();

		Command::ICommand* getTestCommand();
		void setState(const bool& value);
		const bool getState() const;
	};
}