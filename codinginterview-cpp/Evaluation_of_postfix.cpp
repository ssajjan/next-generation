#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int evaluate(string exp)
{
    stack<int> vals;

    for (int i = 0; i < exp.length(); ++i)
    {
        if (exp[i] == '+') {
            int val1 = vals.top();
            vals.pop();
            int val2 = vals.top();
            vals.pop();
            vals.emplace(val1 + val2);
        }
        else if (exp[i] == '/') {
            int val1 = vals.top();
            vals.pop();
            int val2 = vals.top();
            vals.pop();
            vals.emplace(val2 / val1);
        }
        else if (exp[i] == '*') {
            int val1 = vals.top();
            vals.pop();
            int val2 = vals.top();
            vals.pop();
            vals.emplace(val1 * val2);
        }
        else if (exp[i] == '-') {
            int val1 = vals.top();
            vals.pop();
            int val2 = vals.top();
            vals.pop();
            vals.emplace(val2 - val1);
        }
        else
        {
            vals.emplace(exp[i] - '0');
        }
    }

    return vals.top();
}

// int main()
int evaluation_of_postfix()
{
    string exp = "231*+9-";

    cout << evaluate(exp) << endl;

    int test;
    cin >> test;

    return 0;
}