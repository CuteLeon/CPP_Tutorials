#include "MapOperation.h"

using namespace std;

void MapOperation::Execute()
{
	cout << "Map Operation..." << endl;

	// ����
	for (size_t i = 0; i < 10; i++)
	{
		mPersons.insert(pair<int, Person>(i, Person(i, "Person_" + to_string(i), i)));
	}

	// insert or emplace will not replace, just skipped
	// mPersons.insert(make_pair(5, Person(5, "Replace_5", 105)));
	mPersons.insert(make_pair(15, Person(15, "Insert_15", 115)));
	mPersons.emplace(15, Person(15, "Replace_15", 115));

	// ������滻
	mPersons[13] = Person(13, "Insert_13", 113);
	mPersons[3] = Person(3, "Replace_3", 103);

	// ����
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
		// at() ���ܵ����쳣
		target2 = mPersons.at(17);
		cout << "Target: " << target2 << endl;
	}
	catch (const std::exception& ex)
	{
		cerr << "Exception when call at on map: " << ex.what() << endl;
	}

	// ����
	for (auto iter = mPersons.rbegin(); iter != mPersons.rend(); iter++)
	{
		cout << "Loop by iterator: " << iter->first << " => " << iter->second << endl;
	}
	for (auto& pair : mPersons)
	{
		cout << "Loop by pair: " << pair.first << " => " << pair.second << endl;
	}

	// ɾ��
	cout << "Count => " << mPersons.size() << endl;
	mPersons.erase(4);
	mPersons.erase(14);

	// ����Ƿ����
	cout << "��� => " << (mPersons.count(2) ? "����" : "������") << "; " << (mPersons.count(12) ? "����" : "������") << endl;

	// ��ȡ����
	cout << "Size : " << mPersons.size() << endl;

	// ����Ƿ�Ϊ��
	cout << "Is emptry : " << mPersons.empty() << endl;

	// ���
	mPersons.clear();
	cout << "Size => " << mPersons.size() << ", Is emptry: " << mPersons.empty() << endl;
}
