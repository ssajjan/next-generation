#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include "HelperMethod.h"

using namespace std;

void find_min_unsorted_subarray_which_sorted_make_complete_sorted(const vector<int>& arr, int& low, int& high)
{
    int leftIndex = -1;
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            leftIndex = i;
            break;
        }
    }

    int rightIndex = arr.size();
    for (int i = arr.size() - 1; i > 0; --i)
    {
        if (arr[i - 1] > arr[i])
        {
            rightIndex = i;
            break;
        }
    }

    if (leftIndex == -1)
    {
        return;
    }

    int min = arr[leftIndex];
    int max = arr[rightIndex];
    for (int i = leftIndex; i < rightIndex; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    low = leftIndex;
    for (int i = 0; i <= leftIndex; ++i)
    {
        if (arr[i] >= min)
        {
            low = i;
            break;
        }
    }

    high = rightIndex;
    for (int i = arr.size() - 1; i >= rightIndex; --i)
    {
        if (arr[i] <= max)
        {
            high = i;
            break;
        }
    }
}

vector<int> find_k_closest_elems(const vector<int>& arr, int x, int k)
{
    int low = 0;
    int high = arr.size() - 1;

    int lowIndex = -1;
    int highIndex = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            lowIndex = mid - 1;
            highIndex = mid + 1;
            break;
        }
        else if (arr[mid] < x)
        {
            if (mid == arr.size() - 1 || arr[mid + 1] > x)
            {
                lowIndex = mid;
                highIndex = mid + 1;
                break;
            }

            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            if (mid == 0 || arr[mid - 1] < x)
            {
                lowIndex = mid - 1;
                highIndex = mid;
            }

            high = mid - 1;
        }
    }

    vector<int> result;
    int found = 0;
    while (true)
    {
        if (lowIndex < 0 && highIndex > arr.size() - 1)
        {
            break;
        }

        if (found >= k)
        {
            break;
        }

        if (lowIndex < 0)
        {
            result.emplace_back(arr[highIndex]);
            ++highIndex;
            ++found;
        }
        else if (highIndex > arr.size() - 1)
        {
            result.emplace_back(arr[lowIndex]);
            --lowIndex;
            ++found;
        }
        else
        {
            if (x - arr[lowIndex] > arr[highIndex] - x)
            {
                result.emplace_back(arr[highIndex]);
                ++highIndex;
                ++found;
            }
            else
            {
                result.emplace_back(arr[lowIndex]);
                --lowIndex;
                ++found;
            }
        }
    }

    return result;
}

void closest_pair_from_two_sorted_array_with_closest_sum(const vector<int>& arr1, const vector<int>& arr2, int x)
{
    if (arr1.size() == 0 || arr2.size() == 0)
    {
        return;
    }

    int left = 0;
    int right = arr2.size() - 1;

    int minDiff = INT_MAX;
    int leftIndex = -1;
    int rightIndex = -1;
    while (true)
    {
        int total = arr1[left] + arr2[right];
        if (minDiff > abs(total - x))
        {
            minDiff = abs(total - x);
            leftIndex = left;
            rightIndex = right;
        }

        if (total == x)
        {
            break;
        }
        else if (total > x)
        {
            if (right == 0)
            {
                break;
            }

            --right;
        }
        else
        {
            if (left == arr1.size() - 1)
            {
                break;
            }

            ++left;
        }
    }

    cout << arr1[leftIndex] << " " << arr2[rightIndex] << endl;
}

// http://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
// int main()
int min_unsorted_subarray_which_sorted_make_complete_sorted()
{
    vector<int> arr = { 10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60 };
    int low = -1;
    int high = -1;
    find_min_unsorted_subarray_which_sorted_make_complete_sorted(arr, low, high);
    cout << low << " " << high << endl;

    vector<int> arr2 = { 10, 12, 20, 30, 40, 50, 60 };
    low = -1;
    high = -1;
    find_min_unsorted_subarray_which_sorted_make_complete_sorted(arr2, low, high);
    cout << low << " " << high << endl;

    vector<int> arr3 = { 10, 12, 20, 40, 30, 50, 60 };
    low = -1;
    high = -1;
    find_min_unsorted_subarray_which_sorted_make_complete_sorted(arr3, low, high);
    cout << low << " " << high << endl;

    int test;
    cin >> test;

    return 0;
}

// http://www.geeksforgeeks.org/find-k-closest-elements-given-value/
// int main()
int find_k_closest_elems()
{
    vector<int> arr = { 10, 12, 20, 30, 40, 50, 60 };
    vector<int> closest1 = find_k_closest_elems(arr, 31, 3);
    HelperMethod::printArray(closest1);

    vector<int> closest2 = find_k_closest_elems(arr, 30, 3);
    HelperMethod::printArray(closest2);

    vector<int> closest3 = find_k_closest_elems(arr, 9, 4);
    HelperMethod::printArray(closest3);

    vector<int> closest4 = find_k_closest_elems(arr, 63, 4);
    HelperMethod::printArray(closest4);

    vector<int> closest5 = find_k_closest_elems(arr, 20, 10);
    HelperMethod::printArray(closest5);

    int test;
    cin >> test;

    return 0;
}

// http://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/
// int main()
int closest_pair_from_two_sorted_array_with_closest_sum()
{
    vector<int> arr1 = { 1, 4, 5, 7 };
    vector<int> arr2 = { 10, 20, 30, 40 };
    closest_pair_from_two_sorted_array_with_closest_sum(arr1, arr2, 32);
    closest_pair_from_two_sorted_array_with_closest_sum(arr1, arr2, 50);

    int test;
    cin >> test;

    return 0;
}