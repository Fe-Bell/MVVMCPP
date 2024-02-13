#pragma once
#include <functional>
#include <memory>
#include <unordered_map>
#include "DSharedDef.hpp"
#include "IMessage.hpp"

namespace Messaging
{
	class WeakMessenger
	{
	public:
		typedef std::unique_ptr<Messaging::IMessage> SafeMessagePtr;
		typedef std::function<void(const SafeMessagePtr& message)> IMessageHandler;

		~WeakMessenger();

		static Messaging::WeakMessenger* instance();

		static void sendMessage(const SafeMessagePtr& message);

		static void subscribeListener(Object listener, const IMessageHandler& handler);

	private:
		static std::unordered_map<Object /*Listener instance*/, std::vector<IMessageHandler>> s_listeners;
		static std::unique_ptr<WeakMessenger> s_instance;

		WeakMessenger();
	};
}
