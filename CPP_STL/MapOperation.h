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

