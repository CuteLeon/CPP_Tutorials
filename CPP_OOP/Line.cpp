#include "Line.h"

Line::Line(int len)
{
	cout << "Normal constructor allocating ptr： " << ++lineCount << endl;
	// 为指针分配内存
	ptr = new int;
	*ptr = len;
}

Line::Line(const Line& obj)
{
	cout << "Copy constructor allocating ptr." << endl;
	ptr = new int;
	*ptr = *obj.ptr; // copy the value
}

Line::~Line(void)
{
	cout << "Freeing memory!" << endl;
	delete ptr;
}

int Line::getLength(void)
{
	return *ptr;
}

int Line::getLineCount()
{
	return Line::lineCount;
}

// 在类的定义之外为静态变量赋值，否则默认为0
int Line::lineCount = 10;
