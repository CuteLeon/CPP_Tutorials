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

