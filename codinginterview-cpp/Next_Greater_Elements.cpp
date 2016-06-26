#include <iostream>
#include <vector>
#include "HelperMethod.h"
#include <stack>

using namespace std;

vector<int> GenerateNextGreater(const vector<int>& arr)
{
    vector<int> result;
    result.resize(arr.size());

    stack<int> nextGreater;

    for (int i = arr.size() - 1; i >= 0; --i)
    {
        while (!nextGreater.empty())
        {
            if (nextGreater.top() > arr[i])
            {
                break;
            }
            else
            {
                nextGreater.pop();
            }
        }

        if (nextGreater.empty())
        {
            nextGreater.push(arr[i]);
            result[i] = -1;
        }
        else
        {
            result[i] = nextGreater.top();
            if (nextGreater.top() > arr[i]) {
                nextGreater.push(arr[i]);
            }
        }
    }

    return result;
}

// int main()
int next_greater_element()
{
    vector<int> arr;
    HelperMethod::generateArray(arr, 10, 1, 1000);
    HelperMethod::printArray(arr);

    cout << endl;
    vector<int> nextGreater = GenerateNextGreater(arr);
    HelperMethod::printArray(nextGreater);

    int test;
    cin >> test;

    return 0;
}