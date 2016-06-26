//http://www.spoj.com/problems/PRIME1/

#include <iostream>

using namespace std;

bool isPrime(long number)
{
	if (number == 2 || number == 3) return true;

	if (number < 2 || number % 2 == 0 || number % 3 == 0) return false;

	long i = 1;
	long numDivisible = 0;
	while (i * i <= number)
	{
		if (number % i == 0)
		{
			++numDivisible;

			if (numDivisible > 1)
			{
				return false;
			}
		}

		++i;
	}

	return numDivisible == 1;
}

void PrintPrimes(long lower, long upper)
{
	if (lower > upper || upper <= 0)
	{
		return;
	}

	for (long i = lower; i <= upper; ++i)
	{
		if (isPrime(i))
		{
			cout << i << endl;;
		}
	}
}

int Prime()
{
	long numtest = 1;
	long lower = 1, upper = 10;

	//scanf("%d", &numtest);
	if (numtest <= 0)
	{
		return 0;
	}

	while (numtest--) {
		//scanf("%d %d", &lower, &upper);
		//cout << lower << endl;
		//cout << upper << endl;
		PrintPrimes(lower, upper);

		printf("\n");
	}
	//cin >> numtest;

	return 0;
}