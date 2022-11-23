#include "SetOperation.h"

using namespace std;

void SetOperation::Execute()
{
	cout << "Set Operation..." << endl;
	
	// 插入
	for (size_t i = 0; i < 10; i++)
	{
		mPersons.insert(Person(i, "Person_" + to_string(i), i));
	}

	// insert or emplace will not replace, just skipped
	// mPersons.insert(Person(5, "Replace_5", 105));
	auto person_15 = mPersons.insert(Person(15, "Insert_15", 115));
	mPersons.emplace(Person(15, "Replace_15", 115));
	auto unplacedPerson = Person();

	// 查找
	auto target1 = mPersons.find(*person_15.first);
	if (target1 != mPersons.end())
	{
		cout << "Target: " << *target1 << endl;
	}
	else
	{
		cout << "Can't find target object." << endl;
	}
	target1 = mPersons.find(unplacedPerson);
	if (target1 != mPersons.end())
	{
		cout << "Target: " << *target1 << endl;
	}
	else
	{
		cout << "Target: Can't find target object." << endl;
	}

	// 遍历
	for (auto iter = mPersons.begin(); iter != mPersons.end(); iter++)
	{
		cout << "Loop by iterator: " << *iter << endl;
	}
	for (auto& pair : mPersons)
	{
		cout << "Loop by pair: " << pair << endl;
	}

	// 检查是否存在
	cout << "检查 => " << (mPersons.count(*person_15.first) ? "存在" : "不存在") << "; " << (mPersons.count(unplacedPerson) ? "存在" : "不存在") << endl;

	// 删除
	cout << "Count => " << mPersons.size() << endl;
	mPersons.erase(*person_15.first);
	mPersons.erase(unplacedPerson);

	// 获取总数
	cout << "Size : " << mPersons.size() << endl;

	// 检查是否为空
	cout << "Is emptry : " << mPersons.empty() << endl;

	// 清空
	mPersons.clear();
	cout << "Size => " << mPersons.size() << ", Is emptry: " << mPersons.empty() << endl;
}