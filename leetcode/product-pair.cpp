#include<iostream>
#include<cstdlib>

using namespace std;

void maxProduct(int &num, int &max1, int &max2, int &neg_max1, int &neg_max2)
{
	if(num >=0)
	{
		if(num > max1 || num > max2)
			max1<max2?max1=num:max2=num;
	}
	else
	{
		if(abs(num) > abs(neg_max1) || abs(num) > abs(neg_max2))
			abs(neg_max1)<abs(neg_max2)?neg_max1=num:neg_max2=num;
	}
}
void print(int i, int j)
{ cout<<"Maximum product pair is {"<<i<<", "<<j<<"}"<<endl;}


int main(int argc, char** argv)
{
	int max1 = 0; // positive first maximum
	int max2 = 0; // positive second maximum
	int neg_max1 = 0; // negative first maximum
	int neg_max2 = 0; // negative second maximum

	int A[] = {1,-10,-1,4, 3, 6, 7, 0};

	for(int i=0;i<8;i++)
		maxProduct(A[i], max1, max2, neg_max1, neg_max2);

	if(max1*max2 > neg_max1*neg_max2)
		print(max1, max2);
	else
		print(neg_max1, neg_max2);
	return 0;
}
