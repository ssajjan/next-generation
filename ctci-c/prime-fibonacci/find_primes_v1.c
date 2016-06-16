/*
Find prime numbers from 1 to N!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define N 100

void crossOff(bool *flag, int prime) {
	for (int index = prime*prime; index<N; index+=prime) {
		flag[index] = 0;
	}
}

int nextPrime(bool *flag, int prime) {
	prime++;
	while (flag[prime]!= 1 && prime < N) {
		prime++;
	}
	return prime;
}

void printPrimes(bool *flag) {
	int index = 0;
	printf("Prime Numbers are: ");
	while (index < N) {
		if (flag[index]) {
			printf("%d,",index);
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

	bool flag[N];
	memset(flag,1,N*sizeof(bool));

	flag[0] = 0;
	flag[1] = 0;
	int prime = 2;

	while (prime < N) {
		crossOff(flag,prime);
		prime = nextPrime(flag,prime);
	}

	printPrimes(flag);

	return 0;
}
