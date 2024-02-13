#include "MainViewModel.hpp"
#include "CRelayCommand.hpp"
#include "WeakMessenger.hpp"
#include "BasicMessage.hpp"

const bool AppViewModel::MainViewModel::canExecuteTestCommand()
{
	return true;
}

void AppViewModel::MainViewModel::executeTestCommand()
{
	Messaging::WeakMessenger::SafeMessagePtr msg(new BasicMessage());
	this->getMessenger()->sendMessage(msg);
}

AppViewModel::MainViewModel::MainViewModel()
{
	this->testCommand = new Command::RelayCommand(
		std::bind(&MainViewModel::executeTestCommand, this), 
		std::bind(&MainViewModel::canExecuteTestCommand, this));
}

AppViewModel::MainViewModel::~MainViewModel()
{
}

Command::ICommand* AppViewModel::MainViewModel::getTestCommand()
{
	return this->testCommand;
}

void AppViewModel::MainViewModel::setState(const bool& value)
{
	this->state = value;
	this->raisePropertyChanged("State");
}

const bool AppViewModel::MainViewModel::getState() const
{
	return this->state;
}
