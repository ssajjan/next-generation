// https://www.interviewcake.com/question/cake-thief

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> capToValue;
int howManyCall = 0;

struct cake
{
	cake(int weight, int value) :
		weight(weight),
		value(value)
	{
	}

	int weight;
	int value;
};

int max_duffel_bag_value(vector<cake> cakes, int capacity)
{
	// Dynamic programming is here
	if (capToValue.find(capacity) != capToValue.end())
	{
		return capToValue[capacity];
	}

	++howManyCall;
	if (capacity == 0)
	{
		return 0;
	}
	
	int max = 0;

	for (int i = 0; i < cakes.size(); ++i)
	{
		if (cakes[i].weight <= capacity)
		{
			int recurseResult = max_duffel_bag_value(cakes, capacity - cakes[i].weight);
			capToValue[capacity - cakes[i].weight] = recurseResult;

			if (recurseResult + cakes[i].value > max)
			{
				max = recurseResult + cakes[i].value;
			}
		}
	}

	return max;
}

int Cake_Thief()
{
	vector<cake> cakes;
	cakes.emplace_back(cake(7, 160));
	cakes.emplace_back(cake(3, 90));
	cakes.emplace_back(cake(2, 15));

	printf("%d\n", max_duffel_bag_value(cakes, 20));
	printf("%d\n", howManyCall);

	int test;
	cin >> test;

	return 0;
}