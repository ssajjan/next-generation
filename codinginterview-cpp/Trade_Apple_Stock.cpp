//https://www.interviewcake.com/question/stock-price

#include <iostream>
#include <vector>

using namespace std;

int MaxProfit(vector<int> stockPrices)
{
	int maxProfit = 0;
	int maxValuePast = 0;

	for (int i = stockPrices.size() - 1; i >= 0; --i)
	{
		if (maxValuePast < stockPrices[i])
		{
			maxValuePast = stockPrices[i];
		}
		else
		{
			int profit = maxValuePast - stockPrices[i];

			if (profit > maxProfit)
			{
				maxProfit = profit;
			}
		}
	}

	return maxProfit;
}

//int main()
int Trade_Apple_Stock()
{
	vector<int> stockPrices1 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	cout << MaxProfit(stockPrices1) << endl;

	vector<int> stockPrices2 = { 1, 4, 3, 4, 5, 4, 3, 2, 1 };
	cout << MaxProfit(stockPrices2) << endl;

	int test;
	cin >> test;

	return 0;
}