#pragma once
#include "AObservableObject.hpp"
#include "IMessenger.hpp"

namespace ViewModel
{
	/// <summary>
	/// Defines a base class for ViewModels
	/// </summary>
	class ViewModelBase :
		 public ObservableObject
	{
	protected:
		/// <summary>
		/// Constructor.
		/// </summary>
		ViewModelBase();

		/// <summary>
		/// Gets the current instance of the messenger.
		/// </summary>
		/// <returns></returns>
		Messaging::IMessenger* getMessenger();

	public:
		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~ViewModelBase() {};
	};
}

