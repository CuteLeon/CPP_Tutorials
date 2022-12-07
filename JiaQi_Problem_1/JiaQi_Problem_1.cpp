#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <set>
#include <string>

using namespace std;

/// <summary>
/// Pattern matching in string
/// PatternString only contains 3 kinds of different characters
/// </summary>
/// <param name="pattern">Pattern string</param>
/// <param name="str">Source string</param>
/// <returns>Count of matching result</returns>
int patternMatch(string pattern, string str)
{
	map<char, int> patternIndex;
	vector<int> patterns;
	int lastIndex = 0;
	for (int i = 0; i < pattern.length(); i++)
	{
		auto target = patternIndex.find(pattern[i]);
		if (target == patternIndex.end())
		{
			patternIndex[pattern[i]] = lastIndex;
			patterns.emplace_back(lastIndex);
			lastIndex++;
		}
		else
		{
			patterns.emplace_back(target->second);
		}
	}

	int result = 0;
	for (int i = 0; i < str.length() - pattern.length(); i++)
	{
		set<char> savedChar;
		map<int, char> matchChars;
		bool matched = true;
		for (int p = 0; p < pattern.size(); p++)
		{
			auto stringChar = str[i + p];
			auto matchChar = matchChars.find(pattern[p]);
			if (matchChar == matchChars.end())
			{
				if (savedChar.find(stringChar) != savedChar.end())
				{
					matched = false;
					break;
				}
				savedChar.insert(stringChar);
				matchChars[pattern[p]] = stringChar;
			}
			else
			{
				if (stringChar != matchChar->second)
				{
					matched = false;
					break;
				}
			}
		}
		if (matched)
		{
			cout << "Pattern matched: " << str.substr(i, pattern.length()) << endl;
			result++;
		}
	}

	return result;
}

void printString(string str)
{
	int index = 0;
	int length = 1;
	int lineIndex = 0;
	int width = sqrt(str.length());
	while (index < str.length())
	{
		for (int j = lineIndex; j < width; j++)
		{
			cout << ' ';
		}
		cout << str.substr(index, length) << endl;
		lineIndex++;
		index += length;
		length += 2;
	}
}

int main()
{
	string str = "asdfasdfasdfafafasdsdfsadfasdfgfafasdffasdfasdfafasasfedfafafasdfasd";
	set<char> counter;
	for (int i = 0; i < str.size(); i++)
	{
		counter.insert(str[i]);
	}
	cout << counter.size() << endl;

	patternMatch("abcbcb", str);
	printString(str);
	return 0;
}
