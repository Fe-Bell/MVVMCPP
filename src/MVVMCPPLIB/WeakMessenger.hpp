#pragma once
#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>
#include "DSharedDef.hpp"
#include "IMessage.hpp"
#include "IMessenger.hpp"

namespace Messaging
{
	/// <summary>
	/// A messenger that broadcasts messages to listeners.
	/// </summary>
	class WeakMessenger : 
		public Messaging::IMessenger
	{
	public:

		/// <summary>
		/// Destructor.
		/// </summary>
		~WeakMessenger();

		/// <summary>
		/// Unique instance of the messenger.
		/// </summary>
		/// <returns></returns>
		static Messaging::WeakMessenger* instance();

		/// <summary>
		/// Broadcast a message to all listeners.
		/// </summary>
		/// <param name="message"></param>
		void sendMessage(const Messaging::IMessenger::SafeMessagePtr& message);

		/// <summary>
		/// Subscribes a listener to message events.
		/// </summary>
		/// <param name="listener"></param>
		/// <param name="handler"></param>
		void subscribeListener(Object listener, const Messaging::IMessenger::IMessageHandler& handler);

	private:
		/// <summary>
		/// Map where listeners are stored.
		/// </summary>
		static std::unordered_map<Object /*Listener instance*/, std::vector<Messaging::IMessenger::IMessageHandler>> s_listeners;

		/// <summary>
		/// Singleton pointer for the WeakMessenger.
		/// </summary>
		static std::unique_ptr<Messaging::WeakMessenger> s_instance;

		/// <summary>
		/// Constructor.
		/// </summary>
		WeakMessenger();
	};
}
