#pragma once
#include "IMessage.hpp"

class BasicMessage :
	public Messaging::IMessage
{
private:
	char* content = nullptr;

public:
	BasicMessage();

	BasicMessage(const char* content);

	BasicMessage(const wchar_t* content);

	~BasicMessage();

	const char* getContent();
};

