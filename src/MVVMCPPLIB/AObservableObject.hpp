#pragma once
#include <functional>
#include <vector>
#include "INotifyPropertyChanged.hpp"

namespace ViewModel
{
	/// <summary>
	/// Defines an abstract, observable, class that can propagate property changed events.
	/// </summary>
	class ObservableObject :
		public INotifyPropertyChanged
	{
	private:
		std::vector<PropertyChangedEventHandler> propertyChangedEventHandlers;

	protected:
		/// <summary>
		/// Constructor.
		/// </summary>
		ObservableObject();

		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~ObservableObject() {};

		/// <summary>
		/// Notifies listeners that a property has changed.
		/// </summary>
		/// <param name="propertyName"></param>
		void raisePropertyChanged(const String& propertyName);

	public:

		/// <summary>
		/// Subscribes an event handler to listen to property changes.
		/// </summary>
		/// <param name="eventHandler"></param>
		void subscribePropertyChangedEvent(const PropertyChangedEventHandler& eventHandler);
	};
}

