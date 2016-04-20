#define operate1(x, y)             (x   &  ~y)
#define operate2(x, y)             (x   >>   y)
#define operate3(x, y, z)        operate2(operate1(x, y), z)


void main()
{

printf("hello boss\n");
int b=10;
int a=2;
int c= b---a;

scanf("%c");
printf("c =%d, b=%d, a=%d\n",c,b,a);

	printf("op3:  %0x \n",operate3(0xff010203, 0xff, 8));
	printf("op1:  %0x \n",operate1(0xff010203, 0xff));
	//printf(" %0x \n",operate3(0xff010203, 0xff, 8));



}
