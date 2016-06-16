#include <stdio.h>

int main()
{

int nb;
char *str_nb;

nb=1;

str_nb = (char *)&nb;

if(str_nb[0]==1)
	printf("\n yes bug endian");
else
	printf("\n yes little endian");

return 0;
}


