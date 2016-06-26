//https://www.interviewcake.com/question/product-of-other-numbers

#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<int, int> productsFromStart;
map<int, int> productsFromEnd;

vector<int> productOthers(vector<int> arg)
{
	vector<int> result;

	int product = 1;
	for (int i = 0; i < arg.size() - 1; ++i)
	{
		product *= arg[i];
		productsFromStart[i] = product;
	}

	product = 1;
	for (int i = arg.size() - 1; i >= 1; --i)
	{
		product *= arg[i];
		productsFromEnd[arg.size() - 1- i] = product;
	}

	for (int i = 0; i < arg.size(); ++i)
	{
		int fromStart = i > 0 ? productsFromStart[i - 1] : 1;
		int fromEnd = i < arg.size() - 1 ? productsFromEnd[arg.size() - 2 - i] : 1;
		result.emplace_back(fromStart * fromEnd);
	}

	return result;
}

int main()
//int Product_of_Other_Numbers()
{
	vector<int> arg = { 1, 7, 3, 4 };
	vector<int> result = productOthers(arg);

	for (int i = 0; i < result.size(); ++i)
	{
		printf("%d\n", result[i]);
	}

	int test;
	cin >> test;

	return 0;
}
