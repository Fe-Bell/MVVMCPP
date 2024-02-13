#pragma once
#include "DSharedDef.hpp"

namespace Messaging
{
	class IMessage
	{
	protected:
		IMessage() {};

	public:
		virtual ~IMessage() {};

	/*public:
		virtual const String getType() const = 0;*/
	};
}