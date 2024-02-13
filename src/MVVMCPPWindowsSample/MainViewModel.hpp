#pragma once
#include "AObservableObject.hpp"
#include "ICommand.hpp"

namespace AppViewModel
{
	class MainViewModel :
		public ViewModel::ObservableObject
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