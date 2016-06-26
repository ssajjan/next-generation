#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class BinaryCode
{
public:
	string decodestream(int start, string message)
	{
		if (message.length() == 0)
			return "NONE";

		ostringstream os;
		os << start;

		int prev = 0;
		int prev2 = start;

		for (int i = 0; i < message.length() - 1; ++i)
		{
			int cur = message[i] - '0';
			cur = cur - prev - prev2;

			if (cur < 0 || cur > 1)
			{
				return "NONE";
			}

			os << cur;

			prev = prev2;
			prev2 = cur;
		}

		return os.str();
	}

	vector<string> decode(string message)
	{
		vector<string> results;
		results.emplace_back(decodestream(0, message));
		results.emplace_back(decodestream(1, message));

		return results;
	}
};

int SRM_144_Div2_550()
{
	BinaryCode binary;
	vector<string> result = binary.decode("1");
	cout << result[0] << endl;
	cout << result[1] << endl;

	int test;
	cin >> test;

	return 0;
}