#include "SetOperation.h"

using namespace std;

void SetOperation::Execute()
{
	cout << "Set Operation..." << endl;
	
	// ����
	for (size_t i = 0; i < 10; i++)
	{
		mPersons.insert(Person(i, "Person_" + to_string(i), i));
	}

	// insert or emplace will not replace, just skipped
	// mPersons.insert(Person(5, "Replace_5", 105));
	auto person_15 = mPersons.insert(Person(15, "Insert_15", 115));
	mPersons.emplace(Person(15, "Replace_15", 115));
	auto unplacedPerson = Person();

	// ����
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

	// ����
	for (auto iter = mPersons.begin(); iter != mPersons.end(); iter++)
	{
		cout << "Loop by iterator: " << *iter << endl;
	}
	for (auto& pair : mPersons)
	{
		cout << "Loop by pair: " << pair << endl;
	}

	// ����Ƿ����
	cout << "��� => " << (mPersons.count(*person_15.first) ? "����" : "������") << "; " << (mPersons.count(unplacedPerson) ? "����" : "������") << endl;

	// ɾ��
	cout << "Count => " << mPersons.size() << endl;
	mPersons.erase(*person_15.first);
	mPersons.erase(unplacedPerson);

	// ��ȡ����
	cout << "Size : " << mPersons.size() << endl;

	// ����Ƿ�Ϊ��
	cout << "Is emptry : " << mPersons.empty() << endl;

	// ���
	mPersons.clear();
	cout << "Size => " << mPersons.size() << ", Is emptry: " << mPersons.empty() << endl;
}