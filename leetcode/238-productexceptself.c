#include<stdio.h>
#include<stdlib.h> // String and malloc function here
#include<stdbool.h> //bool
#include<stdint.h> // uint32_t
#include<string.h> //memset

#define MIN(a,b)  (a)<(b)?(a):(b)
#define MAX(a,b)  (a)>(b)?(a):(b)
#define SIZE 5

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {


        int from_beg=1, from_end=1;
        int *resultnums = (int *)malloc(sizeof(int)* numsSize);
        int i =0;
	memset(resultnums,true,sizeof(int)* numsSize); // ssajjan-question:  why memset is not working.

	printf("nums = ");
	for(i=0;i<numsSize;i++){
		printf("%d ",resultnums[i]);	
		resultnums[i]=1;
	}
	printf("\n");

        for(i=0;i<numsSize;i++){
                resultnums[i]*=from_beg;
                from_beg*=nums[i];
                resultnums[numsSize-1-i]*=from_end;
                from_end*=nums[numsSize-1-i];
        }
	*returnSize = numsSize;
        return resultnums;
}



int main(int argc, char* argv[]){


	int nums[SIZE]= {2,3,5,7,4};
	int returnSize , i;

	int *resultnums = productExceptSelf(nums,SIZE, &returnSize);
	
	printf("nums = ");
	for(i=0;i<SIZE;i++){
		printf("%d ",nums[i]);	
	}
	printf("\nresultnums = ");
	
	for(i=0;i<returnSize;i++){
		printf("%d ",resultnums[i]);	
	} 
	printf("\n");
	return 0;
}
