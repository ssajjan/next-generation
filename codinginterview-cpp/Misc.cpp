#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <set>
#include "HelperMethod.h"

using namespace std;

int longest_1_sequence(const std::vector<int>& input)
{
	vector<int> maxFromRight;
	maxFromRight.resize(input.size());

	int maxFromRightSoFar = 0;
	for (int i = input.size() - 1; i >= 0; --i)
	{
		maxFromRight[i] = maxFromRightSoFar;

		if (input[i] == 1)
		{
			++maxFromRightSoFar;
		}
		else
		{
			maxFromRightSoFar = 0;
		}
	}

	int maxSizeSofar = 0;
	int maxIndexSofar = -1;
	int numOnesToTheLeft = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == 0)
		{
			if (numOnesToTheLeft + 1 + maxFromRight[i] > maxSizeSofar)
			{
				maxIndexSofar = i;
				maxSizeSofar = numOnesToTheLeft + 1 + maxFromRight[i];
			}

			numOnesToTheLeft = 0;
		}
		else
		{
			++numOnesToTheLeft;
		}
	}

	return maxIndexSofar;
}

void total_number_of_non_decreasing_numbers_with_n_digits(int n, int& result, int min)
{
	if (n == 0)
	{
		++result;
		return;
	}

	for (int i = min; i < 10; ++i)
	{
		total_number_of_non_decreasing_numbers_with_n_digits(n - 1, result, i);
	}
}

void total_number_of_non_decreasing_numbers_with_n_digits(int n, int& result)
{
	total_number_of_non_decreasing_numbers_with_n_digits(n, result, 0);
}

bool find_if_subsequence(const string& str1, const string& str2, int index1, int index2)
{
	if (str1.length() == 0 || index1 == str1.length())
	{
		return true;
	}

	if (index2 >= str2.length())
	{
		return false;
	}

	if (str1[index1] == str2[index2])
	{
		return true;
	}

	return find_if_subsequence(str1, str2, index1, index2 + 1);
}

bool find_if_subsequence(const string& str1, const string& str2)
{
	return find_if_subsequence(str1, str2, 0, 0);
}

// Recursive version
/*
int snake_ladder(const vector<int>& moves, int index, set<int>& steps, map<int, int>& cost)
{
	if (index >= moves.size() - 1)
	{
		return 0;
	}

	if (steps.find(index) != steps.end())
	{
		return INT_MAX;
	}

	if (cost.find(index) != cost.end())
	{
		return cost.at(index);
	}

	steps.insert(index);
	steps.insert(moves[index]);

	int minSteps = INT_MAX;
	for (int i = 6; i >= 0; --i)
	{
		if (index + i >= moves.size() - 1)
		{
			return 0;
		}

		int numSteps = INT_MAX;
		if (moves[index + i] != -1)
		{
			numSteps = snake_ladder(moves, moves[index + i], steps, cost);
			cost[moves[index + i]] =  numSteps;
		}
		else
		{
			numSteps = snake_ladder(moves, index + i, steps, cost);
			cost[index + i] = numSteps;
		}

		if (numSteps < INT_MAX && minSteps > numSteps + 1)
		{
			minSteps = numSteps + 1;
		}
	}

	steps.erase(index);
	steps.erase(moves[index]);

	return minSteps;
}

int snake_ladder(const vector<int>& moves)
{
	set<int> steps;
	map<int, int> cost;
	return snake_ladder(moves, 0, steps, cost);
}
*/

// Dijkstra version
int snake_ladder(const vector<int>& moves)
{
    int size = moves.size();

    vector<vector<int>> paths;
    paths.resize(size);
    for (int i = 0; i < size; ++i)
    {
        paths[i].resize(size, 0);
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j <= i + 6; ++j)
        {
            if (j >= 30)
            {
                break;
            }

            if (moves[j] != -1)
            {
                paths[i][moves[j]] = 1;
            }
            else
            {
                paths[i][j] = 1;
            }
        }
    }

    vector<bool> steps(size, false);
    vector<int> shortest(size, INT_MAX);
    shortest[0] = 0;

    for (int i = 0; i < size; ++i)
    {
        int minIndex = -1;
        int minDist = INT_MAX;
        for (int j = 0; j < size; ++j)
        {
            if (steps[j] == false && shortest[j] < minDist)
            {
                minIndex = j;
                minDist = shortest[j];
            }
        }

        if (minIndex == -1)
        {
            break;
        }

        steps[minIndex] = true;
        for (int j = 0; j < size; ++j)
        {
            if (paths[minIndex][j] > 0 && steps[j] == false && minDist + paths[minIndex][j] < shortest[j])
            {
                shortest[j] = minDist + paths[minIndex][j];
            }
        }
    }

    int cost = shortest[29];
    stack<int> shortestSteps;
    shortestSteps.push(29);
    int curIndex = 29;

    while (cost > 0)
    {
        for (int i = 0; i < size; ++i)
        {
            if (paths[i][curIndex] > 0 && shortest[i] + paths[i][curIndex] == cost)
            {
                cost -= paths[i][curIndex];
                curIndex = i;
                shortestSteps.push(curIndex);
                break;
            }
        }
    }

    cout << "Steps are: " << endl;
    while (!shortestSteps.empty())
    {
        cout << shortestSteps.top() << " ";
        shortestSteps.pop();
    }
    cout << endl;

    return shortest[29];
}

void generate_binary_representation_ones_greater_than_zeroes(int length, vector<int>& vals, int numOnes, int numZeroes)
{
    if (length == 0)
    {
        for (int i = 0; i < vals.size(); ++i)
        {
            cout << vals[i];
        }
        cout << endl;
        return;
    }

    if (numOnes > numZeroes)
    {
        vals.emplace_back(0);
        generate_binary_representation_ones_greater_than_zeroes(length - 1, vals, numOnes, numZeroes + 1);
        vals.pop_back();
    }

    vals.emplace_back(1);
    generate_binary_representation_ones_greater_than_zeroes(length - 1, vals, numOnes + 1, numZeroes);
    vals.pop_back();
}

void generate_binary_representation_ones_greater_than_zeroes(int length)
{
    vector<int> vals;
    generate_binary_representation_ones_greater_than_zeroes(length, vals, 0, 0);
}

string minimum_string_rotation(const string& org)
{
    string min = org;
    string doubleOrg = org + org;

    for (int i = 1; i < org.size(); ++i)
    {
        string cur = doubleOrg.substr(i, org.length());
        if (cur < min)
        {
            min = cur;
        }
    }

    return min;
}

vector<int> construct_array_pair_sum_array(const std::vector<int> input, int length)
{
    vector<int> results;
    results.resize(length);

    int sum = 0;
    for (int i = 0; i < input.size(); ++i)
    {
        sum += input[i];
    }
    sum = sum / (length - 1);

    int sumSoFar = 0;
    int index = 0;
    for (int i = 0; i < length - 2; ++i)
    {
        int curSum = sumSoFar;
        for (int j = 0; j < (length - i - 1); ++j)
        {
            curSum += input[index];
            ++index;
        }

        int nextEntry = (curSum - sum) / (length - i - 2);
        sumSoFar += nextEntry;
        results[i] = nextEntry;
    }

    results[length - 2] = input[length - 3] - results[0];
    results[length - 1] = input[length - 2] - results[0];

    return results;
}

bool lessOrEqual(char op1, char op2)
{
    if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-'))
    {
        return true;
    }

    if ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/'))
    {
        return true;
    }

    if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
    {
        return true;
    }

    return false;
}

int evaluate_simple_expression(const string& exp)
{
    if (exp.length() % 2 == 0)
    {
        return -1;
    }

    stringstream posfix;
    stack<char> ops;

    for (int i = 0; i < exp.length(); ++i)
    {
        if (exp[i] == ' ')
        {
            continue;
        }

        if (i % 2 == 0)
        {
            if (exp[i] < '0' || exp[i] > '9')
            {
                return -1;
            }

            posfix << exp[i];
        }
        else
        {
            if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/')
            {
                return -1;
            }

            while (!ops.empty() && lessOrEqual(exp[i], ops.top()))
            {
                posfix << ops.top();
                ops.pop();
            }

            ops.push(exp[i]);
        }
    }

    while (!ops.empty())
    {
        posfix << ops.top();
        ops.pop();
    }

    string postfixStr = posfix.str();
    stack<int> vals;
    for (int i = 0; i < postfixStr.length(); ++i)
    {
        if (postfixStr[i] >= '0' && postfixStr[i] <= '9')
        {
            vals.push(postfixStr[i] - '0');
        }
        else
        {
            int val1 = vals.top();
            vals.pop();
            int val2 = vals.top();
            vals.pop();

            int newVal = 0;
            if (postfixStr[i] == '+')
            {
                newVal = val1 + val2;
            }
            else if (postfixStr[i] == '-')
            {
                newVal = val2 - val1;
            }
            else if (postfixStr[i] == '/')
            {
                newVal = val2 / val1;
            }
            else if (postfixStr[i] == '*')
            {
                newVal = val2 * val1;
            }

            vals.push(newVal);
        }
    }

    return vals.top();
}

int maximum_sum_path_matrix(const vector<vector<int>>& matrix, map<pair<int, int>, int>& sum, int x, int y)
{
	if (y >= matrix.size())
	{
		return 0;
	}

	if (x >= matrix[0].size())
	{
		return 0;
	}

	if (sum.find(pair<int, int>(x, y)) != sum.end())
	{
		return sum.at(pair<int, int>(x, y));
	}

	int maxSumRight = maximum_sum_path_matrix(matrix, sum, x + 1, y);
	int maxSumDown = maximum_sum_path_matrix(matrix, sum, x, y + 1);
	int maxSum = 0;
	if (maxSumRight > maxSumDown)
	{
		cout << "Go down" << endl;
		maxSum = maxSumRight;
	}
	else
	{
		cout << "Go right" << endl;
		maxSum = maxSumDown;
	}

	sum[pair<int, int>(x, y)] = maxSum + matrix[x][y];

	return maxSum + matrix[x][y];
}

int maximum_sum_path_matrix(const vector<vector<int>>& matrix)
{
	map<pair<int, int>, int> sum;
	return maximum_sum_path_matrix(matrix, sum, 0, 0);
}

// http://www.geeksforgeeks.org/find-index-0-replaced-1-get-longest-continuous-sequence-1s-binary-array/
// int main()
int longest_1_sequence()
{
	vector<int> input1 = { 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1 };
	cout << longest_1_sequence(input1) << endl;

	vector<int> input2 = { 1, 1, 1, 1, 0 };
	cout << longest_1_sequence(input2) << endl;

	int test;
	cin >> test;

	return 0;
}

// http://www.geeksforgeeks.org/total-number-of-non-decreasing-numbers-with-n-digits/
// int main()
int total_number_of_non_decreasing_numbers_with_n_digits()
{
	int total = 0;
	total_number_of_non_decreasing_numbers_with_n_digits(1, total);
	cout << total << endl;

	total = 0;
	total_number_of_non_decreasing_numbers_with_n_digits(2, total);
	cout << total << endl;

	total = 0;
	total_number_of_non_decreasing_numbers_with_n_digits(3, total);
	cout << total << endl;

	total = 0;
	total_number_of_non_decreasing_numbers_with_n_digits(4, total);
	cout << total << endl;

	int test;
	cin >> test;

	return 0;
}

// http://www.geeksforgeeks.org/given-two-strings-find-first-string-subsequence-second/
// int main()
int find_if_subsequence()
{
	string str1 = "AXY";
	string str2 = "ADXCPY";
	cout << find_if_subsequence(str1, str2) << endl;

	str1 = "AXY";
	str2 = "YADXCP";
	cout << find_if_subsequence(str1, str2) << endl;

	str1 = "gksrek";
	str2 = "geeksforgeeks";
	cout << find_if_subsequence(str1, str2) << endl;

	int test;
	cin >> test;

	return 0;
}

// http://www.geeksforgeeks.org/snake-ladder-problem-2/
// int main()
int snake_ladder()
{
	vector<int> moves;
	moves.resize(30);

	for (int i = 0; i < 30; i++)
	{
		moves[i] = -1;
	}

	// Ladders
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

	// Snakes
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;

	cout << snake_ladder(moves) << endl;

	int test;
	cin >> test;

	return 0;
}

// http://geeksquiz.com/generate-binary-permutations-1s-0s-every-point-permutations/
// int main()
int generate_binary_representation_ones_greater_than_zeroes()
{
    generate_binary_representation_ones_greater_than_zeroes(1);
    cout << endl;

    generate_binary_representation_ones_greater_than_zeroes(2);
    cout << endl;

    generate_binary_representation_ones_greater_than_zeroes(3);
    cout << endl;

    generate_binary_representation_ones_greater_than_zeroes(4);
    cout << endl;

    generate_binary_representation_ones_greater_than_zeroes(5);
    cout << endl;

    int test;
    cin >> test;

    return 0;
}

// http://geeksquiz.com/lexicographically-minimum-string-rotation/
// int main()
int minimum_string_rotation()
{
    cout << minimum_string_rotation("GEEKSQUIZ") << endl;
    cout << minimum_string_rotation("GFG") << endl;
    cout << minimum_string_rotation("GEEKSFORGEEKS") << endl;

    int test;
    cin >> test;

    return 0;
}

// http://geeksquiz.com/construct-array-pair-sum-array/
// int main()
int construct_array_pair_sum_array()
{
    vector<int> input1 = { 14, 9, 10, 11, 12, 7 };
    vector<int> output1 = construct_array_pair_sum_array(input1, 4);
    HelperMethod::printArray(output1);
    cout << endl;

    vector<int> input2 = { 15, 13, 11, 10, 12, 10, 9, 8, 7, 5 };
    vector<int> output2 = construct_array_pair_sum_array(input2, 5);
    HelperMethod::printArray(output2);
    cout << endl;

    int test;
    cin >> test;

    return 0;
}

// http://geeksquiz.com/program-evaluate-simple-expressions/
// int main()
int evaluate_simple_expression()
{
    cout << evaluate_simple_expression("1+2*3") << endl;
    cout << evaluate_simple_expression("4-2+6*3") << endl;
    cout << evaluate_simple_expression("1++2") << endl;

    int test;
    cin >> test;

    return 0;
}

// http://www.geeksforgeeks.org/amazon-interview-experience-set-226-on-campus/
// int main()
int maximum_sum_path_matrix()
{
	vector<vector<int>> matrix;
	HelperMethod::generateMatrix(matrix, 5, 5, 1, 5);
	HelperMethod::printMatrix(matrix);

	cout << endl;
	cout << maximum_sum_path_matrix(matrix) << endl;

	int test;
	cin >> test;

	return 0;
}

