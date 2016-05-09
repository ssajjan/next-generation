/*
7.7
Design an algorithm to find the kth number such that the only prime factors are 3,
5, and 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define N 10000
int n = 30746875;

bool divisible357Only(int num) {
	bool status;

	printf("%d-->\n",num);

	//if ((num/3 == 1 && num%3 == 0) || (num/5 == 1 && num%5 == 0) || (num/7 == 1 && num%7 == 0)) {
	if ((num == 3) || (num == 5) || (num == 7)) {
		//printf("aaaa-->");
		return true;
	}
	//else if ((num/3 == 0 && num%3 != 0) || (num/5 == 0 && num%5 != 0) || (num/7 == 0 && num%7 != 0)) {
	else if ((num == 2) || (num == 4) || (num == 6)) {
		//printf("bbbb-->");
		return false;
	}
	else {
		if (num%3 == 0) {
			status = divisible357Only(num/3);
			return status;
		}
		else if (num%5 == 0) {
			status = divisible357Only(num/5);
			return status;
		}
		else if (num%7 == 0) {
			status = divisible357Only(num/7);
			return status;
		}
		else {
			//printf("cccc-->");
			return false;
		}
	}
}

void checkNum(bool *flag, int num) {
	bool status;
	status = divisible357Only(num);
	//printf("%s",status==1?"True":"False");
	//printf("\n");
	if (status) {
		flag[num] = 1;
	}
}

void printNum(bool *flag) {
	int index = 0;
	printf("Prime Numbers are: ");
	while (index < n) {
		if (flag[index]) {
			printf("%d,",index);
		}
		index++;
	}
	printf("\n");
}

void printKNum(bool *flag, int k) {
	int index = 0, count = 0;
	printf("%dth number with 3,5,7 prime Numbers is: ", k);
	while (index < n) {
		if (flag[index]) {
			count++;
			if (count == k) {
				printf("%d\n",index);
			}
		}
		index++;
	}
	//printf("\n");
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

	bool flag[n];
	memset(flag,0,n*sizeof(bool));

	int index = 1;
	flag[index++] = 1;

	while (index < n) {
		checkNum(flag, index);
		index++;
	}

	//printNum(flag);

	int k = 203;
	printKNum(flag,k);
	return 0;
}
