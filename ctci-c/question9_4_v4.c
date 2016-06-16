/*
9.4
Write a method to return all subsets of a set.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define N 8

void printBits(unsigned int num) {
	static int count = 0;
	count++;
        if (num == 0) {
		while (count <= N) {
			printf("0");
			count++;
		}
		count = 0;
        }
        else {
                printBits(num/2);
                printf("%d",num%2);
        }
}

void printSubsets(char *set, int num, int count) {
	static int totalsets = 0;
        if (num == 0) {
		printf("%d: ",++totalsets);
        }
        else {
                printSubsets(set, num/2, count-1);
		if (num%2 == 1) {
			printf("%c,",set[count]);
		}
        }
}

void generateBits(int numbits) {
	int num = 0;
	int max = 1<<(numbits);

	while (num < max) {
		printBits(num);printf("\n");
		num++;
	}
}

void generateSubsets(char *set, int numbits) {
	int num = 0;
	int max = 1<<(numbits);

	while (num < max) {
		printSubsets(set, num, numbits-1);printf("\n");
		num++;
	}
}

int main(int argc, char *argv[]) {
	char set[N] = {'a','b','c','d','1','2','3','4'};
	
	//generateBits(N);
	generateSubsets(set,N);

	return 0;
}
