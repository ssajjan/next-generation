#include<stdio.h>

int main(void)
{
    int a = 10, b = 20, c = 30;

    printf("\n %d..%d..%d \n", a+b+c, (b = b*2), (c = c*2));

    return 0;
}
