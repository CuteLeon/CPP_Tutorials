#include <iostream>
#include "MapOperation.h"
#include "SetOperation.h"
#include "VectorOperation.h"

int main()
{
	std::cout << "Hello World!\n";

	auto map = new MapOperation;
	map->Execute();

	auto set = new SetOperation;
	set->Execute();
	
	auto vector = new VectorOperation;
	vector->Execute();

	system("pause");
}
