#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
typedef tuple<int, int> Result;
typedef vector<Result> Results;
typedef vector<int> Numbers;

void Scan(Numbers& numbers, Results& results, int targetSum)
{
	Numbers leftSums;
	leftSums.emplace_back(numbers[0]);
	for (int index = 1; index < numbers.size(); index++)
		leftSums.emplace_back(leftSums.back() + numbers.at(index));
	int leftIndex = 0, rightIndex = 0;
	while (rightIndex < numbers.size() &&
		leftIndex < numbers.size())
	{
		int currentSum = leftSums[rightIndex] - leftSums[leftIndex] + numbers[leftIndex];
		if (currentSum < targetSum)
		{
			rightIndex++;
		}
		else if (currentSum > targetSum)
		{
			leftIndex++;
		}
		else
		{
			results.emplace_back(make_tuple(leftIndex, rightIndex));
			rightIndex++;
			leftIndex++;
		}
	}

}

int main()
{
	std::cout << "Hello World!\n";
	Numbers numbers = { 1,4,2,5,7,3,5,7,9,5,3,5,7,8,3,1,3,4,5,7,8,9,6,5 };

	Results results;
	Scan(numbers, results, 20);
	for (Result& result : results)
	{
		cout << get<0>(result) << " ~ " << get<1>(result) << endl;
	}

	system("pause");
}