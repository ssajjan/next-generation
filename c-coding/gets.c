#include<stdio.h>

int main(void)
{
    char buff[10];
    memset(buff,0,sizeof(buff));

    fgets(buff);

//	buff[10]=NULL;
    printf("\n The buffer entered is [%s]\n",buff);

    return 0;
}
