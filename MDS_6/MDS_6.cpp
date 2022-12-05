#include <iostream>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

int weightCapacity(vector<int>& weights, int maxCapacity)
{
	set<int> knownWeights;
	knownWeights.emplace(0);
	int maxWeight = 0;
	for (int index = 0; index < weights.size(); index++)
	{
		set<int> newWeights;
		for (auto& knownWeight : knownWeights)
		{
			auto newWeight = knownWeight + weights[index];
			if (newWeight == maxCapacity)
			{
				return maxCapacity;
			}
			else if (newWeight < maxCapacity)
			{
				maxWeight = max(maxWeight, newWeight);
				newWeights.emplace(newWeight);
			}
		}
		knownWeights.insert(newWeights.begin(), newWeights.end());
	}
	return maxWeight;
}

int main()
{
	vector<int> v = { 3,1,5 };
	cout << weightCapacity(v, 7) << endl;
	return 0;
}