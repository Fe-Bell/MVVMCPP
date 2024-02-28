#include "BasicMessage.hpp"
#include "fCppStringUtils.hpp"

BasicMessage::BasicMessage()
{

}

BasicMessage::BasicMessage(const char* content)
{
    if (this->content != nullptr)
    {
        //Wipe current pointer
        delete[](this->content);
        this->content = nullptr;
    }

    //Overwite
    if (content != nullptr)
    {
        this->content = copyFromConst(content);
    }
}

BasicMessage::BasicMessage(const wchar_t* content)
{
	if (content != nullptr)
	{
		char* str = convertFromWide(content);
		this->content = str;
		delete [] (str);
	}
}

BasicMessage::~BasicMessage()
{
    delete[](this->content);
    this->content = nullptr;
}

const char* BasicMessage::getContent()
{
	return this->content;
}
