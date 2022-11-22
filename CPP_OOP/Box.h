#pragma once

#include <iostream>

class Box
{
public:
	friend void printWidth(Box box);
	void setWidth(double wid);

private:
	double width;
};

