#include<stdio.h>
#include<stdlib.h>  // String and malloc function here
#include<stdbool.h> // bool
#include<stdint.h>  // uint32_t
#include<string.h>  // memset
#define MIN(a,b)  (a)<(b)?(a):(b)
#define MAX(a,b)  (a)>(b)?(a):(b)

int max_in_array(int a[], int size){

	int max = a[0];
	int till = a[0];

	for (int i =1; i < size; i+=){
		till+=a[i];
		if(till > max)
			max=till;
		if(till<0)
			till = 0;
	}

	return max;
}

int main(int argc, char* argv[]){

	printf("This is test main func\n");
	
	return 0;
}

