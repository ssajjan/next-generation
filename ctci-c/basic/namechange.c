//gcc -o namechange namechange.c

//check background process name using command: ps -ef | grep *

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int i = 0;
    char buff[100];

    memset(buff,0,sizeof(buff));

    strncpy(buff, argv[0], sizeof(buff));
    memset(argv[0],0,strlen(buff));

	printf("argc = %d\n",argc);
	
	if(argc > 1){
	    strncpy(argv[0], argv[1], sizeof(argv[1]));
	    printf("argv[0] = %s\n",argv[0]);
	}else{
	    strncpy(argv[0],"ssajjan", 7);
	    printf("argv[0] = %s\n",argv[0]);
	}

    // Simulate a wait. Check the process
    // name at this point.
    for(;i<0xffffffff;i++);

    return 0;
}
