//http://www.spoj.com/problems/FARIDA/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, long long int> values;

long long int MaxCoin(const long long int* coins, int size)
{
    if (size == 0)
    {
        return 0;
    }

    if (size == 1)
    {
        return coins[0];
    }

    if (values.find(size) != values.end())
    {
        return values.at(size);
    }

    long long int maxNonSkip = coins[0] + MaxCoin(coins + 2, size - 2);
    values.insert(std::make_pair(size - 2, maxNonSkip));

    long long int maxSkip = MaxCoin(coins + 1, size - 1);
    values.insert(std::make_pair(size - 1, maxSkip));

    return maxNonSkip > maxSkip ? maxNonSkip : maxSkip;
}

//int main()
int Princess_Farida_DP()
{
    int numTest;
    scanf_s("%d", &numTest);

    for (int i = 0; i < numTest; ++i)
    {
        values.clear();
        int numMonster = 0;
        scanf_s("%d", &numMonster);

        long long int* coins = new long long int[numMonster];
        for (int j = 0; j < numMonster; ++j)
        {
            scanf_s("%lld", coins + j);
        }

        printf("Case %d: %lld\n", i + 1, MaxCoin(coins, numMonster));
        delete[] coins;
    }

    int test;
    cin >> test;

    return 0;
}