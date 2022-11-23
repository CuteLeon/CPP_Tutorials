#pragma once
#include "Types.h"
#include <vector>

using namespace std;

typedef vector<Person> PersonVector;

class VectorOperation
{
public:
	void Execute();
private:
	PersonVector mPersons;
};

