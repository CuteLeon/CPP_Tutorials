#pragma once
#include <iostream>

class Box
{
public:
	friend void printWidth(Box box);
	void setWidth(double wid);
    
    // 重载 + 运算符，用于把两个 Box 对象相加
    Box operator+(const Box& b)
    {
        Box box;
        box.width = this->width + b.width;
        return box;
    }
private:
	double width;
};

