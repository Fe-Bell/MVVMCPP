#include "WeakMessenger.hpp"

std::unordered_map<Object, std::vector<Messaging::WeakMessenger::IMessageHandler>> Messaging::WeakMessenger::s_listeners;
std::unique_ptr<Messaging::WeakMessenger> Messaging::WeakMessenger::s_instance(new Messaging::WeakMessenger());

Messaging::WeakMessenger::WeakMessenger()
{

}

Messaging::WeakMessenger* Messaging::WeakMessenger::instance()
{
    return s_instance.get();
}

Messaging::WeakMessenger::~WeakMessenger()
{

}

void Messaging::WeakMessenger::subscribeListener(Object listener, const IMessageHandler& handler)
{
    std::vector<IMessageHandler> lst;
    if (s_listeners.find(listener) != s_listeners.end())
    {
        lst = s_listeners[listener];
    }
    else
    {
        s_listeners[listener] = lst;
    }

    s_listeners[listener].push_back(handler);
}

void Messaging::WeakMessenger::sendMessage(const SafeMessagePtr& message)
{
    for(const std::pair<Object, std::vector<Messaging::WeakMessenger::IMessageHandler>>& pair : s_listeners)
    {
        for(const Messaging::WeakMessenger::IMessageHandler& mh : pair.second)
        {
            mh(message);
        }
    }
}
