#include "Box.h"

using namespace std;

void Box::setWidth(double wid)
{
    width = wid;
}

// ��ע�⣺printWidth() �����κ���ĳ�Ա����
void printWidth(Box box)
{
	/* ��Ϊ printWidth() �� Box ����Ԫ��������ֱ�ӷ��ʸ�����κγ�Ա */
	cout << "Width of box : " << box.width << endl;
}
