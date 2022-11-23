#pragma once
#include <iostream>
#include <exception>

using namespace std;

struct MyException : public exception
{
public:
    MyException(string& message)
        : mMessage(message.c_str())
    { }

    MyException(const char* message)
        : mMessage(message)
    { }

    const char* what() const throw ()
    {
        return mMessage;
    }

private:
    const char* mMessage;
};