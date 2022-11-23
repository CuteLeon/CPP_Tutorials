#include <iostream>
#include "Line.h"
#include "Box.h"
#include "Rectangle.h"

int main()
{
	// 构造函数
	std::cout << "Hello World!\n";
	Line line(10);
	Line line1(10);
	Line line2(10);
	cout << line.getLength() << endl;

	Line another = line; // 此处不是赋值，而是调用 "拷贝构造函数"
	cout << another.getLength() << endl;

	Box box;
	box.setWidth(10.0);
	printWidth(box); // 使用友元函数输出宽度

	// Static
	cout << Line::getLineCount() << endl;
	cout << line.getLineCount() << endl;

	// Inheritance
	Rectangle rect;
	rect.setWidth(5);
	rect.setHeight(7);
	int area = rect.getArea();
	cout << "Total area: " << rect.getArea() << endl;
	cout << "Total paint cost: $" << rect.getCost(area) << endl;

	system("pause");
}
