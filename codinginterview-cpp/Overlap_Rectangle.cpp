//https://www.interviewcake.com/question/rectangular-love?utm_source=weekly_email

#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;

struct Rectangle
{
	int x, y;
	int width, height;

	Rectangle()
	{
	}

	Rectangle(int x, int y, int width, int height) :
		x(x), y(y), width(width), height(height)
	{
	}

	void Print()
	{
		printf("x %d, y %d, width %d, height %d", x, y, width, height);
	}
};

bool overlapLine(const int x1, const int width1, const int x2, const int width2, int& x, int& width)
{
	bool overlap = false;

	if (x1 <= x2 && x1 + width1 >= x2)
	{
		x = x2;
		int endPoint = x1 + width1 >= x2 + width2 ? x2 + width2 : x1 + width1;
		width = endPoint - x2;
		overlap = true;
	}
	else if (x2 <= x1 && x2 + width2 >= x1)
	{
		x = x1;
		int endPoint = x2 + width2 >= x1 + width1 ? x1 + width1 : x2 + width2;
		width = endPoint - x1;
		overlap = true;
	}

	return overlap;
}

Rectangle overlap(Rectangle r1, Rectangle r2)
{
	Rectangle result;

	int x, y, width, height;
	bool overlapX = overlapLine(r1.x, r1.width, r2.x, r2.width, x, width);
	bool overlapY = overlapLine(r1.y, r1.height, r2.y, r2.height, y, height);

	if (overlapX && overlapY)
	{
		result.x = x;
		result.y = y;
		result.width = width;
		result.height = height;
	}

	return result;
}

//int main()
int overlap_rectangle()
{
	Rectangle r1(1, 5, 10, 4);
	Rectangle r2(2, 3, 6, 8);
	Rectangle overlapRectangle1 = overlap(r1, r2);
	overlapRectangle1.Print();

	cout << endl;

	Rectangle r3(1, 5, 10, 4);
	Rectangle r4(1, 5, 10, 4);
	Rectangle overlapRectangle2 = overlap(r3, r4);
	overlapRectangle2.Print();

	cout << endl;

	Rectangle r5(1, 5, 10, 4);
	Rectangle r6(100, 500, 10, 4);
	Rectangle overlapRectangle3 = overlap(r5, r6);
	overlapRectangle3.Print();

	int test;
	cin >> test;

	return 0;
}