//https://www.interviewcake.com/question/matching-parens?utm_source=weekly_email

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int PosLastParenthesis(string str, int pos)
{
	int result = -1;
	stack<char> stk;
	int savedSize = -1;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '(')
		{
			if (i == pos)
			{
				savedSize = stk.size();
			}

			stk.push('(');
		}
		else if (str[i] == ')')
		{
			stk.pop();

			if (stk.size() == savedSize)
			{
				result = i;
				break;
			}
		}
	}

	return result;
}

//int main()
int Match_Parenthesis()
{
	string str = "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing.";
	cout << PosLastParenthesis(str, 10) << endl;
	cout << PosLastParenthesis(str, 28) << endl;
	cout << PosLastParenthesis(str, 57) << endl;
	cout << PosLastParenthesis(str, 68) << endl;

	int test;
	cin >> test;

	return 0;
}