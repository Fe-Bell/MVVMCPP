#pragma once

namespace Messaging
{
	/// <summary>
	/// Interface that defines a basic message contract.
	/// </summary>
	class IMessage
	{
	protected:
		IMessage() {};

	public:
		virtual ~IMessage() {};
	};
}