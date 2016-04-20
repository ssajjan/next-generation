#include<stdio.h>   /* to scan */
//#include <stdlib.h> /* to use malloc and free */
//#include <assert.h> /* for Assert */

void replace1(char *str, char c)
{
	do
	{
		if(*str == c)
			*++str = c;
		str++;
	}while (*str!='\0');
	
	return;
}

void replace2(char *str, char c, char d)
{
	do
	{
		if(*str == c)
			*++str = d;
		str++;
	}while (*str!='\0');
	
	return;
}

int main(void)
{
    char s[] = "cat in a hat";
	
	printf("\n string: %s\n", s);
	replace1(s,'a');
    printf(" replace1: %s\n", s);
	replace2(s,'h', '\0');
    printf(" replace2: %s\n", s);

    return 0;
}