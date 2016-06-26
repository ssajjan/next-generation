//g++ -std=gnu++11 -o BackTracking.exe BackTracking.cpp HelperMethod.cpp
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <limits.h>
#include "HelperMethod.h"

using namespace std;

bool knight_tour(vector<vector<int>>& board, int m, int n, int fill)
{
	if (m < 0 || m > 7 || n < 0 || n > 7)
	{
		return false;
	}

	if (board[m][n] != -1)
	{
		return false;
	}

	board[m][n] = fill;

    if (fill == 63)
    {
        return true;
    }

	/*cout << m << " " << n << " " << fill << endl;
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << board[i][j] << " ";
		}

		cout << endl;
	}*/

    bool found = false;

    // Try all 8 options
    for (int i = -2; i <= 2; i += 4)
    {
        for (int j = -1; j <= 1; j += 2)
        {
            found = knight_tour(board, m + i, n + j, fill + 1);
            if (found)
            {
                return true;
            }
        }
    }

    for (int i = -1; i <= 1; i += 2)
    {
        for (int j = -2; j <= 2; j += 4)
        {
            found = knight_tour(board, m + i, n + j, fill + 1);
            if (found)
            {
                return true;
            }
        }
    }

	board[m][n] == -1;

    return false;
}

void knight_tour()
{
    vector<vector<int>> board(8);
    for (int i = 0; i < board.size(); ++i)
    {
        board[i].resize(8, -1);
    }

    bool result = knight_tour(board, 0, 0, 0);
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
			printf(" %2d ", board[i][j]);
        }
        
        cout << endl;
    }
}

bool rat_in_maze(const vector<vector<int>>& maze, vector<vector<int>>& sol, int m, int n)
{
	if (m >= sol.size() || m < 0 || n >= sol[0].size() || n < 0)
	{
		return false;
	}

	if (maze[m][n] != 1 || sol[m][n] == 1)
	{
		return false;
	}

	sol[m][n] = 1;

	if (m == sol.size() - 1 && n == sol[0].size() - 1)
	{
		return true;
	}

	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i + j == 1 || i + j == -1)
			{
				if (rat_in_maze(maze, sol, m + i, n + j))
				{
					return true;
				}
			}
		}
	}

	sol[m][n] = 0;

	return false;
}

bool subset_sum(const vector<int>& vals, vector<int>& subset, int index, int sum)
{
	if (sum == 0)
	{
		return true;
	}

	if (index >= vals.size())
	{
		return false;
	}

	if (sum < 0)
	{
		return false;
	}

	if (subset_sum(vals, subset, index + 1, sum))
	{
		return true;
	}

	subset.emplace_back(vals[index]);
	if (subset_sum(vals, subset, index + 1, sum - vals[index]))
	{
		return true;
	}
	subset.pop_back();

	return false;
}

void graphColoring(const vector<vector<int>>& graph, int numColor, vector<int>& colors)
{

}

// http://www.geeksforgeeks.org/backtracking-set-1-the-knights-tour-problem/
int main()
//int knight_tour_main()
{
    knight_tour();

    int test;
    cin >> test;

    return 0;
}

// http://www.geeksforgeeks.org/backttracking-set-2-rat-in-a-maze/
// int main()
int rat_in_maze()
{
	vector<vector<int>> maze = 
	{
	{ 1, 0, 0, 0 },
	{ 1, 1, 0, 1 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 1, 1 }
	};

	vector<vector<int>> sol =
	{
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 }
	};

	rat_in_maze(maze, sol, 0, 0);

	HelperMethod::printMatrix(sol);

	int test;
	cin >> test;

	return 0;
}

// http://www.geeksforgeeks.org/backttracking-set-4-subset-sum/
// int main()
int subset_sum()
{
	const vector<int> vals = { 10, 7, 5, 18, 12, 20, 15 };
	vector<int> subset;
	subset.reserve(vals.size());

	subset_sum(vals, subset, 0, 35);
	HelperMethod::printArray(subset);

	subset.clear();
	subset_sum(vals, subset, 0, 32);
	HelperMethod::printArray(subset);

	subset.clear();
	subset_sum(vals, subset, 0, 30);
	HelperMethod::printArray(subset);

	subset.clear();
	subset_sum(vals, subset, 0, 27);
	HelperMethod::printArray(subset);

	subset.clear();
	subset_sum(vals, subset, 0, 47);
	HelperMethod::printArray(subset);

	int test;
	cin >> test;

	return 0;
}

// http://www.geeksforgeeks.org/backttracking-set-5-m-coloring-problem/
// int main()
int color_graph()
{
    vector<vector<int>> graph = 
    {
    { 0, 1, 1, 1 },
    { 1, 0, 1, 0 },
    { 1, 1, 0, 1 },
    { 1, 0, 1, 0 },
    };

    vector<int> colors;
    graphColoring(graph, 3, colors);

    return 0;
}
