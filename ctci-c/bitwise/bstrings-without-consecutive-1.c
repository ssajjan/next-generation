//gcc -o bstrings-without-consecutive-1 bstrings-without-consecutive-1.c -std=c99

#include<stdio.h>
#include<string.h> //strtoul
#include<stdint.h> // uint32_t
#include<stdlib.h> // memset
#include<unistd.h> // for sleep usleep
#include<limits.h>


//fibonacci series.
//0,1,1,2,3,5,8,13,21,34,55,89,144,233

uint32_t countString(uint32_t n){

	uint32_t a[n];
	memset(a,0, n*sizeof(int));
	a[0]=1;
	a[1]=2;
//	printf("\n a[%d]=%d\n",0,a[0]);
	printf(" UINT_MAX = %d, %u",UINT_MAX,UINT_MAX);
	for(int i = 2; i<=n;i++){
		if(a[i-1] > (UINT_MAX-a[i-2])){
			printf("addition is not safe for %u bits number",i);	
			return 0;
		}
		else{
			a[i]=a[i-1]+a[i-2];
		}
		printf(" a[%d] = %u\n",i,a[i]);
	}
	return a[n];
}

int main(int argc, char **argv)
{
    uint32_t x;
    uint32_t input = 0;
    uint32_t range = 0;
    if (argc == 2)
    {
        input = strtoul(argv[1], NULL, 0);
	printf("%d bits number has %u binary strings without consecutive 1's ",input, countString(input));
	return 0;
    }

    if (argc >= 3)
    {
        range = (uint32_t)strtoul(argv[2], NULL, 0);
        printf("range %d\n", range);
    }

    printf("argc =  %d x = %d\n", argc, x);
    for (x = 0; x < range; x++)
    {
	printf("%d bits number has %u binary strings without consecutive 1's \n",x, countString(x));
	usleep(100);
    }
    return 0;
}
