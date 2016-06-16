Remove duplicates in an array:

#include<stdio.h>
#include<conio.h>
void main()
{
	int a[5];
	int n=5,i,j,k;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				for(k=j;k<n;k++)
				{
					a[k]=a[k+1];
				}
				n=n-1;
				j = j-1;
			}
		}
	}

	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
	getch();
}























