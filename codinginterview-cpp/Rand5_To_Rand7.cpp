#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

int rand5()
{
	return rand() % 5 + 1;
}

int rand25()
{
	int num1 = rand5() - 1;
	int num2 = rand5() - 1;

	return num1 * 5 + num2;
}

int rand7()
{
	int value = 100;
	while (value > 6)
	{
		value = rand25();
	}

	return value + 1;
}

//int main()
int Rand5_To_Rand7()
{
	map<int, int> frequency;

	for (int i = 0; i < 100000; ++i)
	{
		int val = rand7();
		
		frequency[val]++;
	}

	for (int i = 1; i <= 7; ++i)
	{
		cout << frequency[i] << endl;
	}

	int test;
	cin >> test;

	return 0;
}