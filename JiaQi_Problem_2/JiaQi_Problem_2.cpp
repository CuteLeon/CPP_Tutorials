#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

struct Point
{
	Point(int x, int y)
		: X(x)
		, Y(y)
	{
	}

	int X;
	int Y;

	bool operator<(const Point& p) const
	{
		if (this->X < p.X) return true;
		if (this->X > p.X) return false;
		if (this->Y < p.Y) return true;
		return false;
	}
};
typedef set<Point> Points;
typedef tuple<Points, Point> Path;
typedef vector<Path> Paths;
typedef map<int, Paths> StepPaths;

static StepPaths dp;

/// <summary>
/// 在二维网格中不可重复地行走，计算第N步有几种不同的路径
/// </summary>
/// <param name="N"></param>
/// <returns></returns>
long long solveProblem2(int N)
{
	Paths previousPaths;
	auto previousStates = dp.find(N - 1);
	if (previousStates == dp.end())
	{
		solveProblem2(N - 1);
		previousStates = dp.find(N - 1);
	}

	previousPaths = previousStates->second;
	for (auto& previousPath : previousPaths)
	{
		auto& previousPathPoints = get<0>(previousPath);
		auto& previousPathTail = get<1>(previousPath);
		const int x = previousPathTail.X;
		const int y = previousPathTail.Y;

		if (x > 0)
		{
			auto next = Point(x - 1, y);
			if (previousPathPoints.count(next) == 0)
			{
				Points currentPoints(previousPathPoints);
				currentPoints.insert(next);
				Path currentPath(currentPoints, next);
				dp[N].emplace_back(currentPath);
			}
		}

		if (y > 0)
		{
			auto next = Point(x, y - 1);
			if (previousPathPoints.count(next) == 0)
			{
				Points currentPoints(previousPathPoints);
				currentPoints.insert(next);
				Path currentPath(currentPoints, next);
				dp[N].emplace_back(currentPath);
			}
		}

		{
			auto next = Point(x + 1, y);
			if (previousPathPoints.count(next) == 0)
			{
				Points currentPoints(previousPathPoints);
				currentPoints.insert(next);
				Path currentPath(currentPoints, next);
				dp[N].emplace_back(currentPath);
			}
		}

		{
			auto next = Point(x, y + 1);
			if (previousPathPoints.count(next) == 0)
			{
				Points currentPoints(previousPathPoints);
				currentPoints.insert(next);
				Path currentPath(currentPoints, next);
				dp[N].emplace_back(currentPath);
			}
		}
	}
	dp.erase(N - 1);
	return dp[N].size();
}

int main()
{
	dp[0] = { Path(make_tuple(Points{ Point(0,0) }, Point(0, 0))) };
	dp[1] = { Path(make_tuple(Points{ Point(0,0), Point(1, 0) }, Point(1, 0))) };
	for (int i = 5; i <= 25; i++)
	{
		cout << solveProblem2(i) << endl;
	}

	getchar();
	return 0;
}
