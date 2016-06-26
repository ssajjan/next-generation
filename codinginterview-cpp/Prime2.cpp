//http://www.spoj.com/problems/PRINT/

#include <iostream>
#include <string.h>

using namespace std;

void PrintPrimes(int lowerBound, int upperBound, int* primes, int numPrime)
{
	for (int i = 0; i < numPrime; ++i)
	{
		if (upperBound < primes[i]) break;

		if (lowerBound <= primes[i])
		{
			printf("%d\n", primes[i]);
		}
	}
}

int Prime2()
{
	int numtest = 2;
	//scanf("%d", &numtest);

	int lowerBound[150];
	int upperBound[150];

	int max = 0;

	int index = 0;
	int numtestcopy = numtest;
	while (numtestcopy--)
	{
		//upperBound[0] = 10;
		//lowerBound[0] = 2;
		//upperBound[1] = 1000;
		//lowerBound[1] = 3;
		//scanf("%d %d", &(lowerBound[index]), &(upperBound[index]));
		if (upperBound[index] > max) max = upperBound[index];
		index++;
	}

	int size = (max - 3) / 2 + 1;
	bool* sieves = (bool*)malloc(2147483647/2);
	//memset(sieves, 0, size*sizeof(bool));

	int numPrime = 0;
	for (int i = 0; i < size; i++)
	{
		if (sieves[i] == false)
		{
			int prime = i * 2 + 3;
			//cout << prime << endl;

			int index = 3;
			int mul = 1;
			while (index * prime <= max)
			{
				sieves[i + mul*prime] = true;
				index += 2;
				mul++;
			}

			numPrime++;
		}
	}

	int* primes = new int[numPrime];
	index = 0;
	for (int i = 0; i < size; i++)
	{
		if (sieves[i] == false)
		{
			primes[index] = i * 2 + 3;
			index++;
		}
	}

	//cout << numtest << endl;
	for (int i = 0; i < numtest; i++)
	{
		if (upperBound[i] >= 2 && lowerBound[i] <= 2)
			printf("2\n");

		if (lowerBound[i] % 2 == 0) lowerBound[i]++;
		if (upperBound[i] % 2 == 0) upperBound[i]--;
		if (upperBound[i] < lowerBound[i]) continue;

		PrintPrimes(lowerBound[i], upperBound[i], primes, numPrime);
	}

	//delete[] sieves;
	//delete[] lowerBound;
	//delete[] upperBound;
	//cin >> numtest;

	return 0;
}
