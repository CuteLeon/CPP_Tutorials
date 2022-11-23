#include "MyException.h"

MyException::MyException(string& message)
    : mMessage(message.c_str())
{ }

MyException::MyException(const char* message)
    : mMessage(message)
{ }

const char* MyException::what() const throw ()
{
	return mMessage;
}
