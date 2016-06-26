#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>

using namespace std;

bool oneCharApart(const string& start, const string& target)
{
	if (start.length() != target.length())
	{
		return false;
	}

	int diff = 0;
	for (int i = 0; i < start.length(); ++i)
	{
		if (start[i] != target[i])
		{
			++diff;
		}

		if (diff > 1)
		{
			return false;
		}
	}

	return diff == 1;
}

set<string> findAllWordsOneCharApart(const set<string>& dic, const string& start, const map<string, int>& distance)
{
	set<string> result;

	for (const string& word : dic)
	{
		if (distance.find(word) == distance.end())
		{
			if (oneCharApart(start, word))
			{
				result.emplace(word);
			}
		}
	}

	return result;
}

int shortest_chain_to_reach_target_word(const set<string>& dic, const string& start, const string& target, map<string, int>& distance)
{
	queue<string> words;
	words.emplace(start);
	distance.insert(pair<string, int>(start, 0));

	while (!words.empty())
	{
		string nextWord = words.front();
		cout << nextWord << endl;
		if (nextWord == target)
		{
			cout << "here " << nextWord << endl;
			return distance.find(nextWord)->second;
		}
		words.pop();

		int curDistance = distance.find(nextWord)->second;
		set<string> nextSet = findAllWordsOneCharApart(dic, nextWord, distance);
		for (const string& nextSetWord : nextSet)
		{
			words.push(nextSetWord);
			distance.insert(pair<string, int>(nextSetWord, curDistance + 1));
		}
	}

	return -1;
}

int shortest_chain_to_reach_target_word(const set<string>& dic, const string& start, const string& target)
{
	map<string, int> distance;
	int shortestDistance = shortest_chain_to_reach_target_word(dic, start, target, distance);
	cout << shortestDistance << endl;

	return shortestDistance;
}

// int main()
int shortest_chain_to_reach_target_word()
{
	set<string> dic;
	dic.insert("poon");
	dic.insert("plee");
	dic.insert("same");
	dic.insert("poie");
	dic.insert("plie");
	dic.insert("poin");

	string start = "toon";
	string target = "plea";

	cout << shortest_chain_to_reach_target_word(dic, start, target) << endl;

	int test;
	cin >> test;

	return 0;
}