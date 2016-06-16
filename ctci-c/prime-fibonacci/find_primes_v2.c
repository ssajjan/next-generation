/*
Find prime numbers from 1 to N!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define N 10000

void crossOff(bool *flag, int prime) {
	for (int index = (prime*prime-1)/2; index<N/2; index+=prime) {
		flag[index] = 0;
	}
}

int nextPrime(bool *flag, int prime) {
	int index = (prime-1)/2;
	index++;
	while (flag[index]!= 1 && index < N/2) {
		index++;
	}
	return 2*index+1;
}

void printPrimes(bool *flag) {
	int index = 0;
	printf("Prime Numbers are: ");
	while (index < N/2) {
		if (flag[index]) {
			if (index == 0) {
				printf("%d,",2*index+2);
			}
			else {
				printf("%d,",2*index+1);
			}
		}
		index++;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	/*
	printf("Argument count: %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("Argument vector values:%s at %p memory\n", argv[i], argv[i]);
		for (char *j=argv[i]; *j!='\0'; j++) {
			printf("Another way to print argument vector values: "
                               "%c at %p memory\n", *j, j);
		}
	}
	*/

	bool flag[N/2];
	memset(flag,1,N/2*sizeof(bool));
	printPrimes(flag);

	flag[0] = 1;
	flag[1] = 1;

	int prime = 3;

	while (prime < sqrt(N)) {
		crossOff(flag,prime);
		prime = nextPrime(flag,prime);
		printf("Next Prime: %d\n",prime);
	}

	printPrimes(flag);

	return 0;
}
