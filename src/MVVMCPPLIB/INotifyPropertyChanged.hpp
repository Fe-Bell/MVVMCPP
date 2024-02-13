#pragma once
#include <functional>
#include "DSharedDef.hpp"

namespace ViewModel
{
	/// <summary>
	/// Interface the defines the minimum contract for objects that can be observed via property model.
	/// </summary>
	class INotifyPropertyChanged
	{
	public:
		typedef std::function<void(const String& propertyName)> PropertyChangedEventHandler;

		/// <summary>
		/// Subscribes an event handler to listen to property changes. An object can only subscribe to property changes once.
		/// </summary>
		/// <param name="eventHandler"></param>
		virtual void subscribePropertyChangedEvent(const PropertyChangedEventHandler& eventHandler) = 0;

	protected:
		/// <summary>
		/// Constructor.
		/// </summary>
		INotifyPropertyChanged() {};

		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~INotifyPropertyChanged() {};

		/// <summary>
		/// Raises a notification for a property that changed.
		/// </summary>
		/// <param name="propertyName"></param>
		virtual void raisePropertyChanged(const String& propertyName) = 0;
	};
}