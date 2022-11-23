#pragma once
#include <iostream>

class Box
{
public:
	friend void printWidth(Box box);
	void setWidth(double wid);
    
    // ���� + ����������ڰ����� Box �������
    Box operator+(const Box& b)
    {
        Box box;
        box.width = this->width + b.width;
        return box;
    }
private:
	double width;
};

