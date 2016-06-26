#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include "HelperMethod.h"

using namespace std;

vector<int> maximum_all_subarray_sizek_queue(const vector<int>& arr, int k)
{
    vector<int> result;
    deque<int> max;

    for (int i = 0; i < k - 1; ++i)
    {
        if (max.empty() || arr[max.back()] > arr[i])
        {
            max.emplace_back(i);
        }
        else
        {
            while (!max.empty() && arr[max.back()] < arr[i])
            {
                max.pop_back();
            }

            max.emplace_back(i);
        }
    }

    for (int i = k - 1; i < arr.size(); ++i)
    {
        if (max.empty() || arr[max.back()] > arr[i])
        {
            max.emplace_back(i);
        }
        else
        {
            while (!max.empty() && arr[max.back()] < arr[i])
            {
                max.pop_back();
            }

            max.emplace_back(i);
        }

        if (i - max.front() >= k)
        {
            max.pop_front();
        }

        result.emplace_back(arr[max.front()]);
    }


    return result;
}


// int main()
int maximum_all_subarray_sizek()
{
    vector<int> arr;
    HelperMethod::generateArray(arr, 20, 1, 1000);
    HelperMethod::printArray(arr);

    cout << endl;
    vector<int> result = maximum_all_subarray_sizek_queue(arr, 4);
    HelperMethod::printArray(result);

    int test;
    cin >> test;

    return 0;
}