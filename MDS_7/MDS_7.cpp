#include <string>
#include <math.h>
#include <vector>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);


/*
 * Complete the 'maxValue' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY rounds
 */

long maxValue(int n, vector<vector<int>> rounds)
{
	vector<long> amounts(n);
	amounts.assign(n, 0);
	long maxAmount = 0;
	for (const auto& operation : rounds)
	{
		if (operation.size() < 3) continue;
		if (operation[0] < 1 || operation[1] <1 || operation[1] > n) continue;
		for (long index = operation[0] - 1; index <= operation[1] - 1; index++)
		{
			amounts[index] += operation[2];
			maxAmount = max(maxAmount, amounts[index]);
		}
	}
	return maxAmount;
}
int main()
{
	vector<vector<int>> rounds;
	rounds.emplace_back(vector<int> {1, 2, 100});
	rounds.emplace_back(vector<int> {2, 5, 100});
	rounds.emplace_back(vector<int> {3, 4, 100});
	auto result = maxValue(5, rounds);
	return 0;
}
