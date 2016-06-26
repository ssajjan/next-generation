#include <iostream>
#include <vector>
#include <sstream>
#include "HelperMethod.h"

using namespace std;

vector<int> sortNearlySortedArray(vector<int> arr, int k)
{
    vector<int> sortedArr;
    vector<int> heap;
    for (int i = 0; i < k - 1; ++i)
    {
        heap.emplace_back(arr[i]);
    }

    HelperMethod::BuildMaxHeap(heap); // O(k)
    for (int i = k - 1; i < arr.size(); ++i) // Total loop: O(n * logk)
    {
        HelperMethod::InsertHeap(heap, arr[i]); // O(logk)
        sortedArr.emplace_back(HelperMethod::RemoveLargestHeap(heap)); // O(logk)
    }

    while (!heap.empty())
    {
        sortedArr.emplace_back(HelperMethod::RemoveLargestHeap(heap)); // O(k)
    }

    // Total cost: O(n * logk)

    return sortedArr;
}

// int main()
int sort_nearly_sorted_array()
{
    int k = 3;
    vector<int> arr = { 8, 56, 12, 3, 6, 2 };
    HelperMethod::printArray(arr);
    cout << endl;

    vector<int> sortedArr = sortNearlySortedArray(arr, k);
    HelperMethod::printArray(sortedArr);
    cout << endl;

    int test;
    cin >> test;

    return 0;
}