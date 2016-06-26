#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <map>
#include <set>

using namespace std;

class Lottery
{
public:
	int Options(vector<int>& soFar, int& choices, int blank, bool& sorted, bool& unique)
	{
		if (blank == 0)
		{
			return 1;
		}

		set<int> options;
		for (int i = 1; i <= choices; ++i)
		{
			options.insert(i);
		}

		if (sorted)
		{
			if (soFar.size() > 0)
			{
				for (int i = 1; i < soFar[soFar.size()-1]; ++i)
				{
					options.erase(i);
				}
			}
		}

		if (unique)
		{
			for (int i = 0; i < soFar.size(); ++i)
			{
				options.erase(soFar[i]);
			}
		}

		int result = 0;
		for (int i : options)
		{
			soFar.push_back(i);
			result += Options(soFar, choices, blank - 1, sorted, unique);
			soFar.pop_back();
		}

		return result;
	}

	int NumOptions(int choices, int blank, bool sorted, bool unique)
	{
		vector<int> soFar;

		return Options(soFar, choices, blank, sorted, unique);
	}

	vector <string> sortByOdds(vector<string> rules)
	{
		vector<string> results;

		std::map<string, int> ruleToNum;
		for (int i = 0; i < rules.size(); ++i)
		{
			string ruleName;
			int choices = 0;
			int blank = 0;
			bool sorted = false;
			bool unique = false;
			
			int index = rules[i].find(":");
			ruleName = rules[i].substr(0, index);

			string rule = rules[i].substr(index + 1);

			istringstream iss(rule);
			vector<string> tokens{
				istream_iterator<string>{iss},
				istream_iterator<string>{} };

			choices = std::stoi(tokens[0]);
			blank = std::stoi(tokens[1]);
			if (tokens[2] == "T")
			{
				sorted = true;
			}

			if (tokens[3] == "T")
			{
				unique = true;
			}

			int numOptions = NumOptions(choices, blank, sorted, unique);
			ruleToNum.emplace(std::make_pair(ruleName, numOptions));
			cout << ruleName << " : " << numOptions << endl;
		}

		return results;
	}
};

int SRM_144_Div1_550()
{
	Lottery lottery;
	vector<string> rules = {
		"PICK ANY TWO: 10 2 F F"
		,"PICK TWO IN ORDER: 10 2 T F"
		,"PICK TWO DIFFERENT: 10 2 F T"
		,"PICK TWO LIMITED: 10 2 T T" };

	vector<string> sortedRules = lottery.sortByOdds(rules);
	for (int i = 0; i < sortedRules.size(); ++i)
	{
		printf("%s\n", sortedRules.at(i));
	}

	int test = 0;
	cin >> test;

	return 0;
}