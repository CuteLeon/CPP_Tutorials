#pragma once
#include <iostream>

using namespace std;
class Line
{
public:
    static int getLineCount();
    int getLength(void);
    Line(int len);             // �򵥵Ĺ��캯��
    Line(const Line& obj);     // �������캯��
    ~Line();                   // ��������

private:
    static int lineCount;
    int* ptr;
};
