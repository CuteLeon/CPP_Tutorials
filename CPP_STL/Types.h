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

	friend ostream& operator<< (ostream& out, Person& p)
	{
		out << "[" << p.Id << "] " << p.Name << " (" << p.Age << ")";
		return out;
	}
};