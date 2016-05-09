#include <stdio.h>

void swap(int * num1, int * num2)
{
  *num1 = *num2 + (*num2 = *num1) - *num2;
}

int main()
{
  int a = 1;
  int b = 2;
  printf("%d, %d", a, b);
  swap(&a, &b);
  printf("%d, %d", a, b);
  return 0;
}
