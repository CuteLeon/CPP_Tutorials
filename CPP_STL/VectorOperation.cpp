#include "VectorOperation.h"

using namespace std;

void VectorOperation::Execute()
{
	cout << "Vector Operation..." << endl;

	// ����
	cout << "Capacity : " << mPersons.capacity() << ", Max size : " << mPersons.max_size() << endl;
	mPersons.reserve(100);
	cout << "Capacity : " << mPersons.capacity() << ", Max size : " << mPersons.max_size() << endl;

	// ����
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

	// ��һ��Ԫ�� �� ���һ��Ԫ��
	cout << mPersons.front() << endl;
	cout << mPersons.back() << endl;

	// ����
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

	// ����
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

	// ɾ��
	cout << "Count => " << mPersons.size() << endl;
	mPersons.pop_back();
	// mPersons.erase(mPersons.end()--);

	// ��ȡ����
	cout << "Size : " << mPersons.size() << endl;

	// �޸�����
	mPersons.resize(15);
	cout << "Size : " << mPersons.size() << endl;

	// ����Ƿ�Ϊ��
	cout << "Is emptry : " << mPersons.empty() << endl;

	// ���
	mPersons.clear();
	cout << "Size => " << mPersons.size() << ", Is emptry: " << mPersons.empty() << endl;
}