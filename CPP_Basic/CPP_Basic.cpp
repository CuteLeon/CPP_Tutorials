#include <iostream>
#include "EnumDemo.h"

using namespace std;
using namespace CPP_Basic;

// Main 外不要套 namespace
// *.cpp 文件内不需要重复声明class类型，如果已经在 *.h 文件内声明过了
int main()
{
	// Enum
	EnumDemo::Colors color1 = EnumDemo::Colors::Black;
	EnumDemo pen;

	cout << "Color1: " << (int)color1 << endl;
	cout << "mBookColor: " << (int)pen.mBookColor << endl;
	cout << "mPenColor: " << (int)pen.mPenColor << endl;
	cout << "Hello World!" << endl;

	// Pointer
    int  var = 20;
    int* ip = &var;
    cout << "Value of var variable: " << var << endl;
    cout << "Address stored in ip variable: " << ip << endl;
    *ip = 35;
    cout << "Value of *ip variable: " << *ip << endl;

	auto* penPtr = &pen;
	penPtr->mPenColor = EnumDemo::Colors::Red;
	cout << "mPenColor: " << (int)pen.mPenColor << endl;

	system("pause");
	return 0;
}
