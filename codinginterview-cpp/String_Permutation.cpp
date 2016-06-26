//https://www.interviewcake.com/question/recursive-string-permutations?utm_source=weekly_email

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> PermuteString(string str)
{
	vector<string> result;
	if (str.length() == 1)
	{
		result.emplace_back(str);
		return result;
	}

	for (int i = 0; i < str.length(); ++i)
	{
		string newStr = str;
		char tmp = newStr[0];
		newStr[0] = newStr[i];
		newStr[i] = tmp;

		string subStr = newStr.substr(1);
		vector<string> subResult = PermuteString(subStr);
		for (int j = 0; j < subResult.size(); ++j)
		{
			string perm = newStr[0] + subResult[j];
			//cout << perm << endl;
			result.emplace_back(perm);
		}
	}

	return result;
}

//int main()
int String_Permutation()
{
	string str = "abcdef";
	vector<string> arr = PermuteString(str);
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ;";
	}
	cout << endl;
	cout << arr.size() << endl;

	int test;
	cin >> test;

	return 0;
}