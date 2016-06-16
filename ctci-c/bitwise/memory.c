#include<stdio.h>
#include<stdlib.h>
#define dimension1_max 10
#define dimension2_max 10

int main(){
	int** x;
	int* temp;

	x = malloc(dimension1_max * sizeof(int*));
	temp = malloc(dimension1_max * dimension2_max * sizeof(int));
	for (int i = 0; i < dimension1_max; i++) {
	  x[i] = temp + (i * dimension2_max);
	}

	free(temp);
	free(x);
	return 0;
}
