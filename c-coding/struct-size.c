#include <stdio.h>

struct l_list{
   int number;
   char *name;
   double value;
   struct l_list *next;
};

typedef struct l_list *PhoneBook;

struct MyData {
  short x;
  int y;
  char string[10];
  char z;
};

typedef struct MyDara *MyDataType;


int main()
{

int x = 0;
int *xp = (int *)0;


while (x < 5) {
   printf(" x is %d\n", x++);
   printf(" xp is %d\n", (int)xp++);
}


   printf("%u\n", sizeof(struct l_list));

   PhoneBook person1;
//MyDataType 
PhoneBook checkDta;

   printf("%u\n", sizeof(*person1));
   printf("%u\n", sizeof(PhoneBook));

printf("\n%u\n",sizeof(struct MyData));
printf("%u\n",sizeof(checkDta));
printf("%u\n",sizeof(*checkDta));

   return 0;
}
