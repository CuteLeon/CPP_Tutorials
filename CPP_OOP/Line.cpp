#include "Line.h"

Line::Line(int len)
{
	cout << "Normal constructor allocating ptr�� " << ++lineCount << endl;
	// Ϊָ������ڴ�
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

// ����Ķ���֮��Ϊ��̬������ֵ������Ĭ��Ϊ0
int Line::lineCount = 10;
