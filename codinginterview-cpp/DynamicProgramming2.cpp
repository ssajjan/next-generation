#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int palindrome_partitioning(const string& str, int startIndex)
{
    if (startIndex >= str.length())
    {
        return 0;
    }

    bool palindrome = true;
    int minPartition = 0;
    for (int i = startIndex; i < str.length(); ++i)
    {

    }
}

int palindrome_partitioning(const string& str)
{
    return palindrome_partitioning(str, 0);
}

// http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/
int main()
// int palindrome_partitioning()
{
    std::string str = "ababbbabbababa";
    cin << palindrome_partitioning(str) << endl;

    int test;
    cin >> test;

    return 0;
}