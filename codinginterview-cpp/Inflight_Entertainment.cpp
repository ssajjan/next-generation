//https://www.interviewcake.com/question/inflight-entertainment?utm_source=weekly_email

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool ExistsExactTotal(vector<int> moviesLength, int flightLength)
{
	bool find = false;

	map<int, set<int>> lengthToIndexes;
	for (int i = 0; i < moviesLength.size(); ++i)
	{
		lengthToIndexes[moviesLength[i]].emplace(i);
	}

	for (int i = 0; i < moviesLength.size(); ++i)
	{
		if (lengthToIndexes.find(flightLength - moviesLength[i]) != lengthToIndexes.end())
		{
			const set<int>& indexes = lengthToIndexes[flightLength - moviesLength[i]];
			if (indexes.find(i) == indexes.end() || indexes.size() > 1)
			{
				find = true;
			}
		}
	}

	return find;
}

//int main()
int Inflight_Entertainment()
{
	vector<int> moviesLength = { 5, 10, 15, 20, 25, 30, 45, 50, 55 };
	int flightLength = 100;
	cout << ExistsExactTotal(moviesLength, flightLength) << endl;

	vector<int> moviesLength2 = { 5, 10, 15, 20, 25, 30, 45, 50 };
	cout << ExistsExactTotal(moviesLength2, flightLength) << endl;

	vector<int> moviesLength3 = { 5, 10, 15, 20, 50, 30, 45, 50 };
	cout << ExistsExactTotal(moviesLength3, flightLength) << endl;

	int test;
	cin >> test;

	return 0;
}