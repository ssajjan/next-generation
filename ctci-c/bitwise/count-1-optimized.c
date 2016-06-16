#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int pop( unsigned x )
{
   x = x - ((x >> 1) & 0x55555555);
   x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
   x = (x + (x >> 4)) & 0x0F0F0F0F;
   x = x + (x >> 8);
   x = x + (x >> 16);
   return x & 0x0000003F;
}

uint32_t bit_count(uint32_t x)
{
    x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
    x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    return x;
}


int main(int argc, char **argv)
{
    uint32_t x;
    uint32_t input = 0;
    uint32_t range = 0;
    if (argc == 2)
    {
        input = strtoul(argv[1], NULL, 0);
        printf("EE 0x%x count %u\n", input, bit_count(input));
	return 0;
    }

    if (argc >= 3)
    {
        range = (uint32_t)strtoul(argv[2], NULL, 0);
        printf("%x\n", range);
    }

    printf("argc %d x %x\n", argc, x);
    for (x = 0; x < range; x++)
    {
        printf("0x%x count %u\n", x, bit_count(x));
    }
    return 0;
}
