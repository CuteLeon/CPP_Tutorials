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

# Set

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

# Vector

在 C++ 中，vector 是一个十分有用的容器。它能够像容器一样存放各种类型的对象，简单地说，vector是一个能够存放任意类型的动态数组，能够增加和压缩数据。

向量（vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。跟任意其它类型容器一样，它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放任意类型的动态数组。

## 容器特性

### 1.顺序序列

顺序容器中的元素按照严格的线性顺序排序。可以通过元素在序列中的位置访问对应的元素。

### 2.动态数组

支持对序列中的任意元素进行快速直接访问，甚至可以通过指针算述进行该操作。操供了在序列末尾相对快速地添加/删除元素的操作。

### 3.能够感知内存分配器的（Allocator-aware）

容器使用一个内存分配器对象来动态地处理它的存储需求。

## 函数

1. push_back 在数组的最后添加一个数据
2. pop_back 去掉数组的最后一个数据
3. at 得到编号位置的数据
4. begin 得到数组头的指针
5. end 得到数组的最后一个单元+1的指针
6. front 得到数组头的引用
7. back 得到数组的最后一个单元的引用
8. max_size 得到vector最大可以是多大
9. capacity 当前vector分配的大小
10. size 当前使用数据的大小
11. resize 改变当前使用数据的大小，如果它比当前使用的大，者填充默认值
12. reserve 改变当前vecotr所分配空间的大小
13. erase 删除指针指向的数据项
14. clear 清空当前的vector
15. rbegin 将vector反转后的开始指针返回(其实就是原来的end-1)
16. rend 将vector反转构的结束指针返回(其实就是原来的begin-1)
17. empty 判断vector是否为空
18. swap 与另一个vector交换数据