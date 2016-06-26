//https://www.interviewcake.com/question/compress-url-list?utm_source=weekly_email

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int FindRotationPoint(vector<string> dic)
{
	int index = 0;

	const string& first = dic[0];
	int start = 0;
	int end = dic.size() - 1;

	while (true)
	{
		int middle = (start + end) / 2;

		if (dic[middle].compare(first) > 0)
		{
			start = middle;
		}
		else if (dic[middle].compare(first) <= 0)
		{
			if (middle == 0 || dic[middle].compare(dic[middle - 1]) < 0)
			{
				index = middle;
				break;
			}

			end = middle;
		}
	}

	return index;
}

//int main()
int Rotation_Point()
{
	vector<string> dic = {
		"panda",
		"ptolemaic",
		"retrograde",
		"supplant",
		"undulate",
		"xenoepist",
		"asymptote",
		"babka",
		"banoffee",
		"engender",
		"karpatka",
		"othellolagkage",
		"ozone"
	};
	int index = FindRotationPoint(dic);
	printf("%d\n", index);

	vector<string> dic2 = {
		"asymptote",
		"babka",
		"banoffee",
		"engender",
		"karpatka",
		"othellolagkage",
		"ozone"
	};
	index = FindRotationPoint(dic2);
	printf("%d\n", index);

	int test;
	cin >> test;

	return 0;
}