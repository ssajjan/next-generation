#include <stdint.h>
#include <stdio.h>
#include <limits.h>
int printbinary(unsigned int n);
int mirrorViewCharBits(unsigned char var);
int mirrorViewIntBits(unsigned int var);
int main ()
{
mirrorViewCharBits(32);
mirrorViewIntBits(32);

return 0;
}

int mirrorViewCharBits(unsigned char var)
{
        int i = 0;
        int j = sizeof(unsigned char)*CHAR_BIT-1;
        unsigned char lsbmask = 0, msbmask = 0, lsb = 0, msb = 0;

        printf("\n *****************************888888888888888888888888  Enter mirrorviewofbits for var=%d, j=%d",var, j);
        printbinary(var);
        for (i = 0 ; i < (j+1)/2; i++ ) {

  		lsbmask = 1 << i;
                msbmask = 1 << (j-i);

                printf ("i=%d, lsbmask: %d and msbmask=%d\n",i,lsbmask,msbmask);
                
		/* check the desired bits and assigne opposite mask if 1 */
		lsb = (var & lsbmask)?msbmask:0;
                msb = (var & msbmask)?lsbmask:0;

		/* resert the bits at corresponding mask value */
	        var = var & ~lsbmask;
                var = var & ~msbmask;
//                printbinary(var);
		var |= lsb|msb;
//                printbinary(var);
        }

	printf("\n ********************************888888888888888888888888888  Exit mirrorviewofbits of reverse of var=%d",var);
    	printbinary(var);
        return 0;
}

int mirrorViewIntBits(unsigned int var)
{
        int i = 0;
        int j = sizeof(unsigned int)*CHAR_BIT-1;
        unsigned int lsbmask = 0, msbmask = 0, lsb = 0, msb = 0;

        printf("\n *************  Enter mirrorviewofbits for var=d, j=%u",var, j);
        printbinary(var);
        for (i = 0 ; i < (j+1)/2; i++ ) {

	        lsbmask = 1 << i;
                msbmask = 1 << (j-i);
                printf ("i=%u, lsbmask: %u and msbmask=%u\n",i,lsbmask,msbmask);
		/* This is swapping i and n-i th bit */
                /* check the desired bits and assigne opposite mask if 1 */
                lsb = (var & lsbmask)?msbmask:0;
                msb = (var & msbmask)?lsbmask:0;

                /* resert the bits at corresponding mask value */
                var = var & ~lsbmask;
                var = var & ~msbmask;
 //               printbinary(var);
                var |= lsb|msb;
 //               printbinary(var);
        }

        printf("\n *************  Exit mirrorviewofbits of reverse of var=%u",var);
        printbinary(var);
        return 0;
}


int printbinary(unsigned int n)
{
	
int no_of_bits = sizeof(n) * 8 - 1;
int i;

printf("\n Binary value of %d:",n);
for (i = no_of_bits; i >=0; i--) {

	int mask = 0x1 << i;

	printf ("%d", (n & mask) ? 1 : 0);

}

	printf("\n");
#if 0
printf("\n Binary value of %d:",n);
	while (n) {
	    if (n & 1)
        	printf("1");
	    else
	        printf("0");
	
	    n >>= 1;
	}
	printf("\n");
#endif
return 0;
}
