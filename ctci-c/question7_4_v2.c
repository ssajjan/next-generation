/*
7.4
Write methods to implement the multiply, subtract, and divide operations for inte-
gers. Use only the add operator.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int negate(int num) {
	int negt = 0;
	int d = num>0?-1:1;

	while (num != 0) {
		negt += d;
		num += d;
	}
	return negt;
}

int abs(int num) {
	if (num >= 0) {
		return num;
	}
	else {
		return negate(num);
	}
}

int multiply(int a, int b) {
	if (a < b) {
		return multiply(b,a);     /* Less number of operations for (4+4) rather than (2+2+2+2) */
	}

	int count = 0, prod = 0;

	while (count < abs(b)) {
		prod += a;
		count++;
	}

	if (b >= 0) {
		return prod;
	}
	else {
		return negate(prod);
	}
}

int subtract(int a, int b) {
	return (a + negate(b));      /* Seeing that a-b is actually a+(-1)*b or a+~b */
}

int divide(int a, int b) {
	if (b == 0) {
		printf("Indefinite result\n");
		return 0;
	}

	int absa = abs(a);
	int absb = abs(b);
	int divd = 0;
	int prod = 0;

	while (prod < absa) {
		prod += absb;
		if (prod <= absa) {     /* Wrong way=> First check whether addition makes it greater than a, */
			divd++;                               /* then add */
		}
	}

	if ((a>0 && b>0) || (a<0 && b<0)) {
		return divd;
	}
	else {
		return negate(divd);
	}
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

	int a = 50, b = -30;
	int prod = 0, diff = 0, divd = 0;

	prod = multiply(a,b);
	printf("Product of (%d)*(%d): %d\n",a,b,prod);

	diff = subtract(a,b);
	printf("Difference of (%d)-(%d): %d\n",a,b,diff);

	divd = divide(a,b);
	printf("Divisor of (%d)/(%d): %d\n",a,b,divd);

	return 0;
}
