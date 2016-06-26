//https://www.interviewcake.com/question/merging-ranges

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Range
{
	Range(int start, int end) :
		start(start), end(end)
	{
	}

	string ToString()
	{
		ostringstream stream;
		stream << "(" << start << "," << end << ")";

		return stream.str();
	}

	bool operator<(Range& other)
	{
		return this->start - other.start < 0 ? true : false;
	}

	void operator=(Range& other)
	{
		this->start = other.start;
		this->end = other.end;
	}

	void swap(Range& other)
	{
		Range tmp = *this;
		*this = other;
		other = tmp;
	}

	int start, end;
};

template<typename T>
void Sort(vector<T>& unsorted, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int index = end - 1;
	for (int i = start; i <= end - 1; ++i)
	{
		if (i >= index + 1)
		{
			break;
		}

		if (unsorted[end] < unsorted[i])
		{
			unsorted[i].swap(unsorted[index]);
			--index;
		}
	}

	unsorted[index + 1].swap(unsorted[end]);

	Sort(unsorted, start, index);
	Sort(unsorted, index + 2, end);
}

template<typename T>
void Sort(vector<T>& unsorted)
{
	Sort<T>(unsorted, 0, unsorted.size() - 1);
}

vector<Range> mergeRange(vector<Range> unmerged)
{
	vector<Range> merged;

	Sort<Range>(unmerged);

	for (int i = 0; i < unmerged.size(); ++i)
	{
		if (i == 0 || unmerged[i].start > merged[merged.size() - 1].end)
		{
			merged.emplace_back(unmerged[i]);
		}
		else
		{
			merged[merged.size() - 1].end = merged[merged.size() - 1].end > unmerged[i].end ? merged[merged.size() - 1].end : unmerged[i].end;
		}
	}

	return merged;
}

//int main()
int Merging_Ranges()
{
	vector<Range> unmerged = { Range(0, 1), Range(3, 5), Range(4, 8), Range(10, 12), Range(9, 10) };
	vector<Range> merged = mergeRange(unmerged);

	for (int i = 0; i < merged.size(); ++i)
	{
		printf("%s\n", merged[i].ToString().c_str());
	}

	int test;
	cin >> test;

	return 0;
}