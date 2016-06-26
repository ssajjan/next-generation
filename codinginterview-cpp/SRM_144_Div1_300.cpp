#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class BinaryCode
{
public:
	string Decrypt(string message, int start)
	{
		if (message.length() == 0)
			return std::string("NONE");

		ostringstream stream;
		stream << start;
		int prev2 = 0;
		int prev = start;
		for (int i = 1; i < message.length(); ++i)
		{
			int cur = (message[i] - '0') - prev - prev2;
			if (cur < 0 || cur > 1)
				return std::string("NONE");

			stream << cur;
			prev2 = prev;
			prev = cur;
		}

		return stream.str();
	}

	vector<string> decode(string message)
	{
		vector<string> results;
		string zero = Decrypt(message, 0);
		string one = Decrypt(message, 1);
		results.emplace_back(zero);
		results.emplace_back(one);

		return results;
	}
};

int SRM_144_Div1_300()
{
	BinaryCode code;
	vector<string> results = code.decode("123210122");
	cout << results[0] << endl;
	cout << results[1] << endl;

	int test = 0;
	cin >> test;

	return 0;
}