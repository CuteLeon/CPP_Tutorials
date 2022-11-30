#include "VectorOperation.h"

using namespace std;

void VectorOperation::Execute()
{
	cout << "Vector Operation..." << endl;

	// 容量
	cout << "Capacity : " << mPersons.capacity() << ", Max size : " << mPersons.max_size() << endl;
	mPersons.reserve(100);
	cout << "Capacity : " << mPersons.capacity() << ", Max size : " << mPersons.max_size() << endl;

	// 插入
	for (size_t i = 0; i < 10; i++)
	{
		mPersons.push_back(Person(i, "Person_" + to_string(i), i));
	}
	for (size_t i = 10; i < 20; i++)
	{
		mPersons.emplace_back(Person(i, "Person_" + to_string(i), i));
	}
	mPersons.insert(mPersons.begin(), Person(-1, "Insert_-1", -1));
	mPersons.emplace(mPersons.begin(), Person(-2, "Insert_-2", -2));

	auto unplacedPerson = Person();

	// 第一个元素 和 最后一个元素
	cout << mPersons.front() << endl;
	cout << mPersons.back() << endl;

	// 查找
	auto& target1 = mPersons.at(5);
	cout << "Target: " << target1 << endl;
	try
	{
		target1 = mPersons.at(25);
	}
	catch (const std::exception& ex)
	{
		cerr << "Exception when call at on map: " << ex.what() << endl;
	}

	// 遍历
	for (auto iter = mPersons.begin(); iter != mPersons.end(); iter++)
	{
		cout << "Loop by iterator: " << *iter << endl;
	}

	auto* collectionPtr = mPersons.data();
	for (size_t i = 0; i < mPersons.size(); i++)
	{
		cout << "Loop by collection pointer: " << *(collectionPtr++) << endl;
	}
	for (auto& pair : mPersons)
	{
		cout << "Loop by pair: " << pair << endl;
	}

	// 删除
	cout << "Count => " << mPersons.size() << endl;
	mPersons.pop_back();
	// mPersons.erase(mPersons.end()--);

	// 获取总数
	cout << "Size : " << mPersons.size() << endl;

	// 修改总数
	mPersons.resize(15);
	cout << "Size : " << mPersons.size() << endl;

	// 检查是否为空
	cout << "Is emptry : " << mPersons.empty() << endl;

	// 清空
	mPersons.clear();
	cout << "Size => " << mPersons.size() << ", Is emptry: " << mPersons.empty() << endl;
}