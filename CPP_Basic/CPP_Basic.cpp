#include <ctime>
#include <time.h>
#include <iostream>
#include "EnumDemo.h"

using namespace std;
using namespace CPP_Basic;

// Main 外不要套 namespace
// *.cpp 文件内不需要重复声明class类型，如果已经在 *.h 文件内声明过了
int main()
{
	clock_t start_t = clock();

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

	// Reference
	int i;
	double d;
	int& r = i;
	double& s = d;

	i = 5;
	cout << "Value of i : " << i << endl;
	cout << "Value of i reference : " << r << endl;

	r = 6;
	cout << "Value of i : " << i << endl;
	cout << "Value of i reference : " << r << endl;

	d = 11.7;
	cout << "Value of d : " << d << endl;
	cout << "Value of d reference : " << s << endl;

	s = 23.5;
	cout << "Value of d : " << d << endl;
	cout << "Value of d reference : " << s << endl;

	// Date Time: #include <ctime>
	time_t now = time(0);
	cout << "1970年1月1日到目前经过的秒数:" << now << endl;
	
	char dt[100];
	ctime_s(dt, 100, &now);
	cout << R"(本地日期和时间：)" << dt << endl;
	
	tm gmtm;
	gmtime_s(&gmtm, &now);
	asctime_s(dt, &gmtm);
	cout << "UTC 日期和时间：" << dt << endl;

	tm ltm;
	localtime_s(&ltm, &now);
	cout << "年: " << 1900 + ltm.tm_year << endl;
	cout << "月: " << 1 + ltm.tm_mon << endl;
	cout << "日: " << ltm.tm_mday << endl;
	cout << "时间: " << ltm.tm_hour << ":" << ltm.tm_min << ":" << ltm.tm_sec << endl;

	clock_t end_t = clock();
	clock_t total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	cout << "Start clock: " << start_t << "; End clock: " << end_t << "; Total seconds: " << total_t << endl;

	double diff = difftime(now, mktime(&gmtm));
	cout << "Local and UTC difference in hours: " << diff / 3600 << endl;

	// I/O
	std::string name; int age;
	cout << "请输入姓名和年龄：" << endl;
	cin >> name >> age;
	cout << name << " 已经 " << age << "岁了" << endl;
	system("pause");
	return 0;
}
