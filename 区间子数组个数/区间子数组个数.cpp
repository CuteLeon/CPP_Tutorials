#include <math.h>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
	int res = 0, last2 = -1, last1 = -1;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] >= left && nums[i] <= right) {
			last1 = i;
		}
		else if (nums[i] > right) {
			last2 = i;
			last1 = -1;
		}
		if (last1 != -1) {
			res += last1 - last2;
		}
	}
	return res;
}

int main()
{
	cout << "Hello World!\n";
	// vector<int> nums = { 2,9,2,5,6 };
	// vector<int> nums = { 2,1,4,3 };
	vector<int> nums = { 73,55,36,5,55,14,9,7,72,52 };
	cout << numSubarrayBoundedMax(nums, 32, 69) << endl;
	system("pause");
}
