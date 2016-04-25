#include<stdio.h>
#include<stdlib.h>  // String and malloc function here
#include<stdbool.h> // bool
#include<stdint.h>  // uint32_t
#include<string.h>  // memset
#define MIN(a,b)  (a)<(b)?(a):(b)
#define MAX(a,b)  (a)>(b)?(a):(b)


int main(int argc, char* argv[]){

	int a=5, b=16;
	int x = 5,y=10;
	printf("a = %d, b=%d\n",a,b);


	x = x + y;  // x now becomes 15
	y = x - y;  // y becomes 10
	x = x - y;  // x becomes 5

	 a += b - (b += a);

	printf("a = %d, b=%d\n",a,b);

	
	return 0;
}

