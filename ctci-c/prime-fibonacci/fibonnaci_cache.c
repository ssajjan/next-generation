/*
Fibonnaci numbers with cache!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define N 100

int fib[N] = {0};

int fibonacci(int i){
    if (i == 0) {
    	printf("%d\n",i);
        return 0;
    }
    if (i == 1) {
   	 printf("%d\n",i);
        return 1;
    }

    if (fib[i] != 0) {
    	printf("%d\n",i);
        return fib[i];
    }

    printf("fib[%d]=fibonacci(%d)+fibonacci(%d)\n",i,i-1,i-2);
    fib[i] = fibonacci(i - 1) + fibonacci(i - 2);

    return fib[i];
}



int main(int argc, char *argv[]) {
	printf("%d\n",fibonacci(5));
	return 0;
}
