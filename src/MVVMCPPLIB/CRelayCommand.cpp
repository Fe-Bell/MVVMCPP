#include "CRelayCommand.hpp"

Command::RelayCommand::RelayCommand()
{

}

Command::RelayCommand::RelayCommand(const ExecuteHandler& execute, const CanExecuteHandler& canExecute)
{
	this->executeHandler = execute;
	this->canExecuteHandler = canExecute;
}

Command::RelayCommand::~RelayCommand()
{

}

const bool Command::RelayCommand::canExecute()
{
	if (this->canExecuteHandler == nullptr)
		return false;

	return this->canExecuteHandler();
}

void Command::RelayCommand::execute()
{
	if (this->executeHandler == nullptr)
		return;

	this->executeHandler();
}

void Command::RelayCommand::subscribeCanExecuteChangedEventHandler(const CanExecuteChangedEventHandler& eventHandler)
{
	this->canExecuteChangedEventHandler = eventHandler;
}

void Command::RelayCommand::notifyCanExecuteChanged()
{
	if (this->canExecuteChangedEventHandler == nullptr)
		return;

	this->canExecuteChangedEventHandler();
}
