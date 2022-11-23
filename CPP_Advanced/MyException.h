#pragma once
#include <iostream>
#include <exception>

using namespace std;

struct MyException : public exception
{
public:
	MyException(string& message);
	MyException(const char* message);
	const char* what() const throw ();

private:
	const char* mMessage;
};