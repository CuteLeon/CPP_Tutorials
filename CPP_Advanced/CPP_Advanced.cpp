#include <iostream>
#include <vector>
#include <csignal>
#include "MyException.h"
#include "TemplateContainer.h"
#include "Stack.h"
using namespace std;

void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") received.\n";
	// 清理并关闭
	// 终止程序  
	exit(signum);
}

int main()
{
	cout << "Hello World!\n";

	// 异常处理
	for (int index = 0; index < 5; index++)
	{
		try
		{
			switch (index)
			{
			case 0: {
				throw "String exception 0";
			}
			case 1: {
				string message = "domain_error 1";
				throw domain_error(message);
			}
			case 2: {
				const char* message = "My exception 2";
				throw MyException(message);
			}
			case 3:
			{
				throw invalid_argument("Invalid argument 3");
			}
			default:
				throw - 1;
				break;
			}
		}
		catch (const domain_error& ex)
		{
			cout << "std::bad_exception => " << ex.what() << endl;
		}
		catch (const MyException& ex)
		{
			cout << "MyException => " << ex.what() << endl;
		}
		// std::exception& 分支应晚于已知的继承自 std::exception 的异常类型
		catch (const std::exception& ex)
		{
			cout << "std::exception => " << ex.what() << endl;
		}
		catch (const char* ex)
		{
			cout << "Char* => " << ex << endl;
		}
		catch (...)
		{
			cout << "Unknown type exception." << endl;
		}
	}

	// new 和 delete
	double* pvalue = NULL; // 初始化为 null 的指针
	pvalue = new double;   // 为变量请求内存

	*pvalue = 29494.99;     // 在分配的地址存储值
	cout << "Value of pvalue : " << *pvalue << endl;

	delete pvalue;         // 释放内存

	// 模板
	cout << "Max => " << TemplateContainer::Max(1, 2) << endl;
	cout << "Max => " << TemplateContainer::Max(1.1, 2.1) << endl;

	Stack<int> stackInt;
	Stack<string> stackString;
	stackString.push("string_a");
	stackString.push("string_b");
	stackString.push("string_c");
	stackInt.push(1);
	stackInt.push(2);
	stackInt.push(3);
	cout << "Top: " << stackInt.top() << ", " << stackString.top() << endl;
	stackString.pop();
	stackInt.pop();
	cout << "Top: " << stackInt.top() << ", " << stackString.top() << endl;

	// signal
	signal(17, signalHandler);
	raise(17);
	system("pause");
}
