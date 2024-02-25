#pragma once
#include <functional>
#include <memory>
#include "IMessage.hpp"

namespace Messaging
{
	class IMessenger
	{
	protected:

		IMessenger() {};

	public:

		typedef std::unique_ptr<Messaging::IMessage> SafeMessagePtr;
		typedef std::function<void(const SafeMessagePtr& message)> IMessageHandler;

		virtual ~IMessenger() {};

		/// <summary>
		/// Broadcast a message to all listeners.
		/// </summary>
		/// <param name="message"></param>
		virtual void sendMessage(const Messaging::IMessenger::SafeMessagePtr& message) = 0;

		/// <summary>
		/// Subscribes a listener to message events.
		/// </summary>
		/// <param name="listener"></param>
		/// <param name="handler"></param>
		virtual void subscribeListener(Object listener, const Messaging::IMessenger::IMessageHandler& handler) = 0;
	};
}