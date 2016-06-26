#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> maxLens;

int GetMaxLen(const vector<vector<char>>& mat, int i, int j)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (maxLens[i][j] != -1)
    {
        return maxLens[i][j];
    }

    int maxLen = 1;
    for (int m = -1; m <= 1; ++m)
    {
        for (int n = -1; n <= 1; ++n)
        {
            if (m == 0 && n == 0) {
                continue;
            }

            if (i + m >= 0 && j + n >= 0 && i + m < mat.size() && j + n < mat[0].size() && mat[i + m][j + n] == mat[i][j] + 1)
            {
                int curLen = GetMaxLen(mat, i + m, j + n) + 1;
                if (maxLen < curLen)
                {
                    maxLen = curLen;
                }
            }
        }
    }

    maxLens[i][j] = maxLen;

    return maxLen;
}

int genLen(const vector<vector<char>>& mat, char start)
{
    int maxLen = 0;
    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[i].size(); ++j)
        {
            if (mat[i][j] == start)
            {
                int len = GetMaxLen(mat, i, j);
                if (len > maxLen)
                {
                    maxLen = len;
                }
            }
        }
    }

    return maxLen;
}

// int main()
int LongestConsecutivePath()
{
    vector<vector<char>> mat =
    {
    { 'a', 'c', 'd' },
    { 'h', 'b', 'a' },
    { 'i', 'g', 'f' }
    };

    maxLens.resize(mat.size());
    for (int i = 0; i < mat.size(); ++i)
    {
        maxLens[i].resize(mat[0].size());
        for (int j = 0; j < mat[i].size(); ++j)
        {
            maxLens[i][j] = -1;
        }
    }

    cout << genLen(mat, 'a') << endl;
    cout << genLen(mat, 'e') << endl;
    cout << genLen(mat, 'b') << endl;
    cout << genLen(mat, 'f') << endl;

    int test;
    cin >> test;

    return 0;
}