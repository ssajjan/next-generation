#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
//#include<limits.h>

int numberOf1s(uint32_t num){

	int count=0;
	while(num){
		
		num = num & (num-1);
		count++;
	}
	return count;
}

int count_1s_optimized(uint32_t num){
	int count = 0;
	uint32_t max = 0xffffffff

01010101010101010101010101010101
	x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
	x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
	x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
}

int main(){

	uint32_t num;
	printf("Enter number:");
	scanf("%d",&num);
	printf("number of 1s: %d",numberOf1s(num));
	return 0;
}
