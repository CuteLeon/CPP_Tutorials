#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Numbers;

class Containers
{
public:
	Containers(const int max)
		: maxSize(max)
	{
	}
	double Insert(int number)
	{
		if (currentSize < maxSize)
		{
			currentSize++;
			numbers.emplace_back(number);
			currentIndex++;
		}
		else
		{
			currentSum -= numbers[currentIndex];
			numbers[currentIndex++] = number;
		}
		if (currentIndex == maxSize) currentIndex = 0;
		currentSum += number;
		return (double)currentSum / (double)currentSize;
	}
private:
	int maxSize;
	int currentSum = 0;
	int currentSize = 0;
	int currentIndex = 0;
	Numbers numbers;
};

int main()
{
	cout << "Hello World!\n";
	Containers container(5);
	for (int i = 0; i < 20; i++)
	{
		cout << "Insert: " << i << ", returen: " << container.Insert(i) << endl;
	}

	system("pause");
}
