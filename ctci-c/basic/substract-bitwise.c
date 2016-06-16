Subtraction using bit wise operator:

int sub(int a, int b)
{
  while( b )
  {
    a ^= b;
    b &= a;
    b <<= 1;
  }
  return a;
}


Addition using bit wise operator:

void Add(int x,int y)
{
  while(y)
  {
z=x^y;
y=(x&y)<<1;
x=z;
  }
  printf("sum = %d",z);

getch();
}


Swapping using bitwise operator:
b=a^b;
a=a^b;
b =a^b;




