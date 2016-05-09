/*
9.1
A child is running up a staircase with n steps, and can hop either 1 step, 2 steps, or
3 steps at a time. Implement a method to count how many possible ways the child
can run up the stairs
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define N 36

int totalways(int n, int *map) {
	if (n < 0) {
		return 0;
	}
	else if (n == 0) {
		return 1;
	}
	else if (map[n] != 0) {
		printf("%d,",n);
		return map[n];
	}
	else {
		map[n] = totalways(n-1,map) + totalways(n-2,map) + totalways(n-3,map);
		return map[n];
	}
}

int main(int argc, char *argv[]) {
	int map[N+1] = {0};
	printf("Total Number of ways to climb %d steps: %d\n",N,totalways(N,map));
	return 0;
}
