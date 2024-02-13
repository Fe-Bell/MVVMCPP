#pragma once
#include <functional>
#include <vector>
#include "INotifyPropertyChanged.hpp"

namespace ViewModel
{
	class ObservableObject :
		public INotifyPropertyChanged
	{
	private:
		std::vector<PropertyChangedEventHandler> propertyChangedEventHandlers;

	protected:
		ObservableObject();
		virtual ~ObservableObject() {};

		void raisePropertyChanged(const String& propertyName);

	public:

		/// <summary>
		/// Subscribes an event handler to listen to property changes.
		/// </summary>
		/// <param name="eventHandler"></param>
		void subscribePropertyChangedEvent(const PropertyChangedEventHandler& eventHandler);
	};
}

