#include "AViewModelBase.hpp"

ViewModel::ViewModelBase::ViewModelBase()
{
}

Messaging::WeakMessenger* ViewModel::ViewModelBase::getMessenger()
{
	return Messaging::WeakMessenger::instance();
}
