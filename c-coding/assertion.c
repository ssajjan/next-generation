#include<stdio.h>   /* to scan */
#include <stdlib.h> /* to use malloc and free */
#include <assert.h> /* for Assert */

void freemem(char *v)
{
	if(v!=0)
	{
		free(v);
		v=0;
	}
	
	return;
	
}

int main(void)
{
    char *ptr = (char*)malloc(10);

    if(NULL == ptr)
    {
        printf("\n Malloc failed \n");
        return 0;
    }
    else
    {    
		// Do somethong           // --> gcc -Wall -ansi assertion.c  -o assertion --> will give error.
        /* Do some processing */  // --> gcc -Wall -ansi assertion.c  -o assertion --> will give No-error.

        printf("\n Malloc success \n");
		scanf("\n %s",ptr);
		printf("\n string= %s\n", ptr);
        freemem(ptr);
		assert(!ptr);   
		//This fails why ?? pointer inside the freemem function is a local variable; a copy of the value passed in stored locally for just that function.
		
    }

    return 0;
}