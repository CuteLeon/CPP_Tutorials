#pragma once
#include <iostream>

using namespace std;
class Line
{
public:
    static int getLineCount();
    int getLength(void);
    Line(int len);             // 简单的构造函数
    Line(const Line& obj);     // 拷贝构造函数
    ~Line();                   // 析构函数

private:
    static int lineCount;
    int* ptr;
};
