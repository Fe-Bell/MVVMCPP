#pragma once
#include <functional>
#include <memory>
#include <unordered_map>
#include "DSharedDef.hpp"
#include "IMessage.hpp"

namespace Messaging
{
	/// <summary>
	/// A messenger that broadcasts messages to listeners.
	/// </summary>
	class WeakMessenger
	{
	public:
		typedef std::unique_ptr<Messaging::IMessage> SafeMessagePtr;
		typedef std::function<void(const SafeMessagePtr& message)> IMessageHandler;

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
		static void sendMessage(const SafeMessagePtr& message);

		/// <summary>
		/// Subscribes a listener to message events.
		/// </summary>
		/// <param name="listener"></param>
		/// <param name="handler"></param>
		static void subscribeListener(Object listener, const IMessageHandler& handler);

	private:
		/// <summary>
		/// Map where listeners are stored.
		/// </summary>
		static std::unordered_map<Object /*Listener instance*/, std::vector<IMessageHandler>> s_listeners;

		/// <summary>
		/// Singleton pointer for the WeakMessenger.
		/// </summary>
		static std::unique_ptr<WeakMessenger> s_instance;

		/// <summary>
		/// Constructor.
		/// </summary>
		WeakMessenger();
	};
}
