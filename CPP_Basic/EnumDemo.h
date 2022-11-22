#pragma once

namespace CPP_Basic {
	class EnumDemo
	{
	public:
		enum Colors {
			Black,      // 默认为 0
			Red,        // 自动根据前一值递增为 1
			Yellow = 3, // 可以显式设置为任意值为 3
			Green,      // 自动根据前一值递增为 4
			Blue,
			White
		} mPenColor, mBookColor; // 变量名称

		EnumDemo();
	};
}

