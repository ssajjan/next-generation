#include<stdio.h>

void main(void)
{
    char *ptr = (char*)malloc(10);

    if(NULL == ptr)
    {
        printf("\n Malloc failed \n");
        return;
    }
    else
    {
        // Do some processing

        printf("\n Malloc success \n");
	scanf("\n %s",ptr);
	printf("\n string= %s\n", ptr);
        free(ptr);
    }

    return;
}
