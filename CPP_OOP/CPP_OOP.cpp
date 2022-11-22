#include <iostream>
#include "Line.h"
#include "Box.h"

int main()
{
	// 构造函数
	std::cout << "Hello World!\n";
	Line line(10);
	cout << line.getLength() << endl;

	Line another = line; // 此处不是赋值，而是调用 "拷贝构造函数"
	cout << another.getLength() << endl;

	Box box;
	box.setWidth(10.0);
	printWidth(box); // 使用友元函数输出宽度
	system("pause");
}
