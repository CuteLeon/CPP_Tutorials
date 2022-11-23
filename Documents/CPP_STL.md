Entity:


```c++
#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Person {
public:
	Person()
		:Person(0, "", 0)
	{
	}
	Person(int id, string name, int age)
		: Id(id)
		, Name(name)
		, Age(age)
	{
	}

	int Id;
	string Name;
	int Age;

	friend ostream& operator<< (ostream& out, const Person& p)
	{
		out << "[" << p.Id << "] " << p.Name << " (" << p.Age << ")";
		return out;
	}

	// Used for set<T>
	bool operator< (const Person& p) const
	{
		return this->Id < p.Id;
	}
};
```

# Map

C++ 中 map 提供的是一种键值对容器，里面的数据都是成对出现的

每一对中的第一个值称之为关键字(key)，每个关键字只能在 map 中出现一次；第二个称之为该关键字的对应值。

```c++
#pragma once
#include "Types.h"
#include <map>

using namespace std;

typedef map<int, Person> PersonMap;

class MapOperation
{
public:
	void Execute();
private:
	PersonMap mPersons;
};

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
	for (auto iter = mPersons.begin(); iter != mPersons.end(); iter++)
	{
		cout << iter->first << " => " << iter->second << endl;
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
```

# SET

```c++
#pragma once
#include "Types.h"
#include <set>

using namespace std;

typedef set<Person> PersonSet;

class SetOperation
{
public:
	void Execute();
private:
	PersonSet mPersons;
};

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
```

