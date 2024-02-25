#include "AViewModelBase.hpp"
#include "WeakMessenger.hpp"

ViewModel::ViewModelBase::ViewModelBase()
{
}

Messaging::IMessenger* ViewModel::ViewModelBase::getMessenger()
{
	return Messaging::WeakMessenger::instance();
}
