#pragma once

namespace CPP_Basic {
	class EnumDemo
	{
	public:
		enum Colors {
			Black,      // Ĭ��Ϊ 0
			Red,        // �Զ�����ǰһֵ����Ϊ 1
			Yellow = 3, // ������ʽ����Ϊ����ֵΪ 3
			Green,      // �Զ�����ǰһֵ����Ϊ 4
			Blue,
			White
		} mPenColor, mBookColor; // ��������

		EnumDemo();
	};
}

