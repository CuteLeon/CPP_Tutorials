#pragma once
#include "Types.h"
#include <map>

using namespace std;

typedef map<int, Person> Persons;

class MapOperation
{
public:
	void Execute();
private:
	Persons mPersons;
};

