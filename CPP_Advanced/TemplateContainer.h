#pragma once
class TemplateContainer
{
public:
	template <typename T>
	static inline T Max(const T v1, const T v2)
	{
		return v1 > v2 ? v1 : v2;
	}
};
