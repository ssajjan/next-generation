#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string infixtopostfix(string exp)
{
    stringstream result;
    stack<char> eval;

    for (int i = 0; i < exp.length(); ++i)
    {
        if (exp[i] == '+' || exp[i] == '-')
        {
            while (!eval.empty())
            {
                if (eval.top() == '*' || eval.top() == '/')
                {
                    result << eval.top();
                    eval.pop();
                }
                else
                {
                    break;
                }
            }

            eval.emplace(exp[i]);
        }
        else if (exp[i] == '*' || exp[i] == '/')
        {
            eval.emplace(exp[i]);
        }
        else
        {
            result << exp[i];
        }
    }

    while (!eval.empty())
    {
        result << eval.top();
        eval.pop();
    }

    return result.str();
}

// int main()
int infix_to_postfix()
{
    string exp = "a+b*c+d";
    cout << infixtopostfix(exp) << endl;

    int test;
    cin >> test;

    return 0;
}