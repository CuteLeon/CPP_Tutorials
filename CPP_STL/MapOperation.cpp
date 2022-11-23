#include "MapOperation.h"

using namespace std;

void MapOperation::Execute()
{
	cout << "Map Operation..." << endl;

	// 插入
	for (size_t i = 0; i < 10; i++)
	{
		mPersons.insert(pair<int, Person>(i, Person(i, "Person_" + to_string(i), i)));
	}

	// insert or emplace will not replace, just skipped
	// mPersons.insert(make_pair(5, Person(5, "Replace_5", 105)));
	mPersons.insert(make_pair(15, Person(15, "Insert_15", 115)));
	mPersons.emplace(15, Person(15, "Replace_15", 115));

	// 插入和替换
	mPersons[13] = Person(13, "Insert_13", 113);
	mPersons[3] = Person(3, "Replace_3", 103);

	// 查找
	auto target1 = mPersons.find(8);
	if (target1 != mPersons.end())
	{
		cout << "Target: [" << target1->first << "] => " << target1->second << endl;
	}
	else
	{
		cout << "Can't find target object." << endl;
	}
	target1 = mPersons.find(18);
	if (target1 != mPersons.end())
	{
		cout << "Target: [" << target1->first << "] => " << target1->second << endl;
	}
	else
	{
		cout << "Target: Can't find target object." << endl;
	}

	auto& target2 = mPersons.at(7);
	cout << "Target: " << target2<< endl;
	try
	{
		// at() 可能导致异常
		target2 = mPersons.at(17);
		cout << "Target: " << target2 << endl;
	}
	catch (const std::exception& ex)
	{
		cerr << "Exception when call at on map: " << ex.what() << endl;
	}

	// 遍历
	for (auto iter = mPersons.rbegin(); iter != mPersons.rend(); iter++)
	{
		cout << "Loop by iterator: " << iter->first << " => " << iter->second << endl;
	}
	for (auto& pair : mPersons)
	{
		cout << "Loop by pair: " << pair.first << " => " << pair.second << endl;
	}

	// 删除
	cout << "Count => " << mPersons.size() << endl;
	mPersons.erase(4);
	mPersons.erase(14);

	// 检查是否存在
	cout << "检查 => " << (mPersons.count(2) ? "存在" : "不存在") << "; " << (mPersons.count(12) ? "存在" : "不存在") << endl;

	// 获取总数
	cout << "Size : " << mPersons.size() << endl;

	// 检查是否为空
	cout << "Is emptry : " << mPersons.empty() << endl;

	// 清空
	mPersons.clear();
	cout << "Size => " << mPersons.size() << ", Is emptry: " << mPersons.empty() << endl;
}
