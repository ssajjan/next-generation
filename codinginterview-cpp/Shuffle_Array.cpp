// https://www.interviewcake.com/question/shuffle?utm_source=weekly_email
// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle

#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
#include <time.h>
#include "HelperMethod.h"

using namespace std;

void shuffleArray(vector<int>& arr)
{
	for (int i = arr.size() - 1; i >= 1; --i)
	{
		int index = rand() % (i + 1);
		int tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}
}

//int main()
int shuffle_array()
{
	srand(time(NULL));

	vector<int> arr = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 1; ++i)
	{
		shuffleArray(arr);
		HelperMethod::printArray(arr);
	}

	cout << endl;
	int count = 0;
	for (int i = 0; i < 12000; ++i)
	{
		shuffleArray(arr);
		if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5)
		{
			++count;
		}
	}
	printf("%d\n", count);

	int test;
	cin >> test;

	return 0;
}