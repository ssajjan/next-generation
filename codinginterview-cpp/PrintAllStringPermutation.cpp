#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void PrintAllPermutation(string str, int startIndex)
{
    if (startIndex == str.length() - 1) {
        cout << str << endl;
    }

    for (int i = startIndex; i < str.length(); ++i)
    {
        char tmp = str[startIndex];
        str[startIndex] = str[i];
        str[i] = tmp;

        PrintAllPermutation(str, startIndex + 1);

        tmp = str[startIndex];
        str[startIndex] = str[i];
        str[i] = tmp;
    }
}

// int main()
int print_all_string_permutation()
{
    string str = "abcd";

    PrintAllPermutation(str, 0);

    int test;
    cin >> test;

    return 0;
}