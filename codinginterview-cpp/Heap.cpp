#include <iostream>
#include <sstream>
#include "HelperMethod.h"
#include <time.h>

using namespace std;

// int main()
int Heap()
{
    std::vector<int> arr;
    HelperMethod::generateArray(arr, 20, 1, 1000);
    HelperMethod::printArray(arr);

    cout << endl;
    HelperMethod::HeapSort(arr);
    HelperMethod::printArray(arr);

    cout << endl;
    HelperMethod::BuildMaxHeap(arr);
    for (int i = 0; i < 20; ++i) {
        printf("%d ", HelperMethod::RemoveLargestHeap(arr));
    }

    int test;
    cin >> test;

    return 0;
}