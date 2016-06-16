#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
//#include<limits.h>

bool isPowerOf2(uint32_t num){

	return ((num!=0)&&!(num&(num-1)));
}

int main(){

	uint32_t num;
	printf("Enter number:");
	scanf("%d",&num);
	if(isPowerOf2(num))
		printf("Is power of 2");
	else
		printf("Is not** power of 2");
}
