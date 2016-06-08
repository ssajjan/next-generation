#include <stdio.h>

void random_array(int my_array[],int size){
	int i;
	for (i = 0; i < size; i++) {
	    my_array[i] = i;//rand()%size;
	}
	return;
}

int BinarySearch(int a[], int size, int x){

	int low=0, high=size-1,mid;

	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid] > x)
			high = mid-1;
		else if(a[mid]< x)
			low = mid+1;
	}
	return -1;
}

int main()
{

	int a[100],x,result;
	random_array(a,100);
	printf("\nRandom Array: \n");
	for(int i = 0; i < sizeof(a)/sizeof(a[0]) ;i++)
		printf("%d ",a[i]);

	printf("\nEnter number to search:");
	scanf("%d",&x);
	
	result=BinarySearch(a,sizeof(a)/sizeof(a[0]),x);
	(result!=-1)? printf("\nFound at %d",result):printf("\nNot found");
//	printf("\n Found %d at index %d",x,BinarySearch(a,sizeof(a)/sizeof(a[0]),x));
	return 0;
}
