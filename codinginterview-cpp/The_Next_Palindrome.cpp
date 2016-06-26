//http://www.spoj.com/problems/PALIN/

#include <iostream>
#include <string.h>

using namespace std;

int The_Next_Palindrome()
{
	int numTests = 1;
	//scanf("%d", &numTests);

	while (numTests--)
	{
		//char digit[1000001];
		//char digit[1000000] = "899";
		//char digit[1000000] = "999";
		//char digit[1000000] = "1001";
		//char digit[1000000] = "196916390160631690360196263916293618639160663066386802964312986";
		char digit[1000000] = "192";
		//char digit[1000000] = "0";
		//char digit[1000001] = "99";
		//scanf("%s", digit);

		int length = (strlen(digit) + 1) / 2;

		char* halfPalin = new char[length + 2];

		bool carriedOver = true;
		for (int i = length-1; i >= 0; --i)
		{
			if (digit[i] > digit[strlen(digit) - i - 1])
			{
				carriedOver = false;
				break;
			}
			else if (digit[i] < digit[strlen(digit) - i - 1])
			{
				carriedOver = true;
				break;
			}
		}

		for (int i = length - 1; i >= 0; --i)
		{
			if (!carriedOver)
			{
				halfPalin[length - 1 - i] = digit[i];
			}
			else
			{
				int value = (digit[i] - '0') + 1;
				if (value < 10)
				{
					halfPalin[length - 1 - i] = '0' + value;
					carriedOver = false;
				}
				else
				{
					halfPalin[length - 1 - i] = '0';
					carriedOver = true;
				}
			}
		}

		int strlength = strlen(digit);
		if (carriedOver)
		{
			if (strlength % 2 == 0)
			{
				halfPalin[length] = '1';
				halfPalin[length + 1] = '\0';
				++length;
			}
			else
			{
				halfPalin[length - 1] = '1';
				halfPalin[length] = '\0';
			}
			++strlength;
		}
		else
		{
			halfPalin[length] = '\0';
		}

		for (int i = length - 1; i >= 0; --i)
		{
			printf("%c", halfPalin[i]);
		}

		for (int i = (strlength % 2); i < length; ++i)
		{
			printf("%c", halfPalin[i]);
		}

		printf("\n");
	}

	cin >> numTests;

	return 0;
}