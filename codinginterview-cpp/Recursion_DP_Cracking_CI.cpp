#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <queue>

using namespace std;

int num_paths(int numSteps, map<int, int>& numPaths)
{
    if (numSteps == 0)
    {
        return 1;
    }
    else if (numSteps == 1)
    {
        return num_paths(0, numPaths);
    }
    else if (numSteps == 2)
    {
        return num_paths(0, numPaths) + num_paths(1, numPaths);
    }

    if (numPaths.find(numSteps) == numPaths.end())
    {
        numPaths.insert(pair<int, int>(numSteps, num_paths(numSteps - 1, numPaths) + num_paths(numSteps - 2, numPaths) + num_paths(numSteps - 3, numPaths)));
    }

    return numPaths.find(numSteps)->second;
}

int num_paths(int numSteps)
{
    map<int, int> numPaths;

    return num_paths(numSteps, numPaths);
}

int num_paths_two_dim(int x, int y, map<pair<int, int>, int>& numPaths)
{
    if (x == 0 && y == 0)
    {
        return 1;
    }

    if (x < 0 || y < 0)
    {
        return 0;
    }

    if (numPaths.find(pair<int, int>(x, y)) == numPaths.end())
    {
        numPaths.insert(pair<pair<int, int>, int>(pair<int, int>(x, y), num_paths_two_dim(x - 1, y, numPaths) + num_paths_two_dim(x, y - 1, numPaths)));
    }

    return numPaths.find(pair<int, int>(x, y))->second;
}

int num_paths_two_dim(int x, int y)
{
    map<pair<int, int>, int> numPaths;

    return num_paths_two_dim(x, y, numPaths);
}

void all_subsets_of_set(vector<int>& setInt, vector<vector<int>>& subsets, int lower, int upper)
{
    if (lower > setInt.size() - 1)
    {
        return;
    }

    all_subsets_of_set(setInt, subsets, lower + 1, upper);
    int size = subsets.size();
    for (int i = 0; i < size; ++i)
    {
        vector<int> newSubSet(subsets[i]);
        newSubSet.emplace_back(setInt[lower]);
        subsets.emplace_back(newSubSet);
    }

    vector<int> subset = { setInt[lower] };
    subsets.emplace_back(subset);

    return;
}

void all_subsets_of_set(vector<int>& setInt, vector<vector<int>>& subsets)
{
    all_subsets_of_set(setInt, subsets, 0, setInt.size() - 1);
}

void all_string_perms(string str, vector<string>& allPerms, int start)
{
    if (start == str.length())
    {
        allPerms.emplace_back(str);
        return;
    }

    for (int i = start; i < str.length(); ++i)
    {
        char curChar = str[start];
        str[start] = str[i];
        str[i] = curChar;

        all_string_perms(str, allPerms, start + 1);

        curChar = str[start];
        str[start] = str[i];
        str[i] = curChar;
    }
}

void all_string_perms(string str, vector<string>& allPerms)
{
    all_string_perms(str, allPerms, 0);
}

void comb_n_pairs_parentheses(int numOpen, int numClose, vector<char>& str)
{
    if (numOpen == 0 && numClose == 0)
    {
        for (int i = 0; i < str.size(); ++i)
        {
            cout << str[i];
        }
        cout << endl;
        return;
    }

    if (numOpen > 0)
    {
        str.emplace_back('(');
        comb_n_pairs_parentheses(numOpen - 1, numClose, str);
        str.pop_back();
    }

    if (numClose > numOpen)
    {
        str.emplace_back(')');
        comb_n_pairs_parentheses(numOpen, numClose - 1, str);
        str.pop_back();
    }
}

void comb_n_pairs_parentheses(int n)
{
    vector<char> str;
    comb_n_pairs_parentheses(n, n, str);
}

// Can step either 1, 2, or 3 steps. Calculate num path possible
// int main()
int num_paths()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << num_paths(i) << endl;
    }

    int test;
    cin >> test;

    return 0;
}

// Robot moves from (0, 0) to (x, y). Find all paths
// int main()
int num_paths_two_dim()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << "(" << i << ", " << j << ") " << num_paths_two_dim(i, j) << endl;
        }
    }

    int test;
    cin >> test;

    return 0;
}

// Return all subsets of a set
// int main()
int all_subsets_of_set()
{
    vector<int> setInt = { 1, 2, 3, 4, 5};
    vector<vector<int>> allSubsets;
    all_subsets_of_set(setInt, allSubsets);

    for (const vector<int>& subSet : allSubsets)
    {
        for (const int& elem : subSet)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    int test;
    cin >> test;

    return 0;
}

// All permutations of string
// int main()
int all_string_perms()
{
    string str = "abcd";
    vector<string> allPerms;
    all_string_perms(str, allPerms);

    for (string perm : allPerms)
    {
        cout << perm << endl;
    }

    int test;
    cin >> test;

    return 0;
}

// Print all valid combinations of n pairs of parentheses
// int main()
int comb_n_pairs_parentheses()
{
    comb_n_pairs_parentheses(1);
    cout << endl << endl;

    comb_n_pairs_parentheses(2);
    cout << endl << endl;

    comb_n_pairs_parentheses(3);
    cout << endl << endl;

    int test;
    cin >> test;

    return 0;
}