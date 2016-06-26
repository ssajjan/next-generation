//https://www.interviewcake.com/question/find-duplicate-optimize-for-space-beast-mode?utm_source=weekly_email

#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include "HelperMethod.h"

using namespace std;

void PrintDuplicate(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		while (arr[arr[i] - 1] != arr[i])
		{
			int tmp = arr[i];
			arr[i] = arr[tmp - 1];
			arr[tmp - 1] = tmp;
		}
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] != (i + 1))
		{
			printf("%d ", arr[i]);
		}
	}
}

//int main()
int Find_Duplicate()
{
	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
	{
		vector<int> arr;
		HelperMethod::generateArray(arr, 10, 1, 9);
		HelperMethod::printArray(arr);
		PrintDuplicate(arr);
		cout << endl;
		cout << endl;
	}

	int test;
	cin >> test;

	return 0;
}