//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BYTE_GROUP (8)
int cards[52] = {0};
//mtx_t lock;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return ;
}

void shuffle(int *a, int n)
{
    int i;   
    for( i = 0; i < n - 1 ; i++)
    {
        int rand_num = (int)(drand48()*(51-i+1));
        //printf("range : %d num :%d\n", (51 - i), rand_num);
        swap(&a[rand_num], &a[51-i]);
        
    }
}

void dump_row(char *c, size_t n)
{
    int sz = n;
    printf("%08x:", c);
    printf("\n sajjan:  %p:", c);
    while(n--) 
    {
        printf(" %02x",*c);
        c++;
    }
    c = c - sz;
    printf(" ");
    while(sz--)
        printf("%c",isprint(*c)?*c++:'.');
    printf("\n");
    return;
}

void dumpbytes(char *c, size_t n)
{
    int i;
    for(i = 0; i < n/BYTE_GROUP; i++)
    {
       dump_row(c, BYTE_GROUP); 
       c += BYTE_GROUP;
    }
    if( n & (BYTE_GROUP-1))
        dump_row(c, n & (BYTE_GROUP-1));

    return;
}

int main()
{
    int i;
    int fd = 0;
    short unsigned int seed[3];
    fd = open("/dev/urandom",O_RDONLY);
    if(fd < 0)
    {
        perror("Open Failed");
        exit(1);
    }

    do
    {
        i = read(fd, &seed[0], sizeof(seed));
    }while(i != sizeof(seed));
    seed48(seed);
    printf("Entropy read: %d\n", i);
    dumpbytes(seed, sizeof(seed));
    for(i = 0; i < 52; i++)
        cards[i] = i;
    shuffle(cards, 52);
    for(i = 0; i < 52; i++)
    {
        printf("%d%c",cards[i],(i!=51)?',':' ');
    }
    printf("\n"); 
    
    return 0;
}
