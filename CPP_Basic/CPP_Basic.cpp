#include <iostream>
#include "EnumDemo.h"

using namespace CPP_Basic;

// Main 外不要套 namespace
// *.cpp 文件内不需要重复声明class类型，如果已经在 *.h 文件内声明过了
int main()
{
	// Enum
	EnumDemo::Colors color1 = EnumDemo::Colors::Black;
	EnumDemo pen;

	std::cout << (int)color1 << std::endl;
	std::cout << (int)pen.mBookColor << std::endl;
	std::cout << (int)pen.mPenColor << std::endl;
	std::cout << "Hello World!" << std::endl;
	system("pause");
	return 0;
}
