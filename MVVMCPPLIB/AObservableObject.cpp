#include "AObservableObject.hpp"

ViewModel::ObservableObject::ObservableObject()
{

}

void ViewModel::ObservableObject::subscribePropertyChangedEvent(const PropertyChangedEventHandler& eventHandler)
{
	if (eventHandler == nullptr)
		return;
		
	this->propertyChangedEventHandlers.push_back(eventHandler);
}

void ViewModel::ObservableObject::raisePropertyChanged(const String& propertyName)
{
	for (const PropertyChangedEventHandler& handler : this->propertyChangedEventHandlers)
	{
		handler(propertyName);
	}
}
