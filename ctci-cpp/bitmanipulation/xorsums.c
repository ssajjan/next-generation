//gcc -g -o xorsums xorsums.c --std=c99
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


typedef struct range {
    int start, end, sum;
} range_t;


typedef struct sum_struct{
   int left;
   int right;
   unsigned sum;
}sums_t ;

range_t maxsubseqsum_dyn(const unsigned int sequence[], const int len)
{
    int i,idx;
    range_t res;
    sums_t sums[len];
    sums_t *prev = &sums[0] , *current = prev + 1;
    memset(sums, 0, sizeof(sums));
    sums[0].right = sums[0].left = 0 ;
    sums[0].sum = sequence[0];
    for(i = 1, current = &sums[i]; i < len; i++, current++, prev++)
    {
        unsigned int elem = sequence[i];

        if ((unsigned)(prev->sum ^ elem) > (unsigned)elem) 
        {
            current->sum = prev->sum ^ elem; 
            current->left = prev->left;
            current->right = prev->right + 1;
        }
        else
        {
            current->sum = elem;
            current->right = current->left = i;
        }
    }
    
    idx = 0;
    for (i = 0; i < len; i++)
        printf("%u,%u,%u \n", sums[i].sum, sums[i].left, sums[i].right);
    printf("\n");
    for (i = 0; i < len; i++)
    {
        if(sums[idx].sum < sums[i].sum)
            idx = i;
    }

    res.start = sums[idx].left;
    res.end = sums[idx].right;
    res.sum = sums[idx].sum;
    return res;
}


range_t maxsubseqsum(const unsigned int sequence[], const int len)
{
    int i, k, j;
    unsigned int left, right, max;
    unsigned int sums[len][len];
    
    max = 0;
    memset(sums, 0, sizeof(sums));
    for ( i = 0; i < len; i++)
    {
        printf(" %4d ", sequence[i]);
    }
    printf("*\n");
    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
            for (k = i; k <= j; k++)
            {
                sums[i][j] ^= sequence[k];
            }
            if (sums[i][j] > max)
            {
                left = i;
                right = j;
                max = sums[i][j];
            }
        }
    }
    
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
        {
            printf(" %4d ", sums[i][j]);
        }
        printf("\n");
    }
    return (range_t){.start = left, .end = right, .sum = max};
}

int main(int argc, char **argv)
{
    unsigned int *seq = NULL;
    int nelems = 10, i ;
    int range = 100;
    unsigned int seed = 0;
    range_t res1 = {0}, res2 = {0};
    --argc;
    ++argv;
    while (*argv && *(*argv)++ == '-') {
	    int option = **argv;
    	printf("a %s\n", *argv);
    	assert(argc-- >= 0);
    	switch (option) {

    	case 's':
    	    argv++;
    	    printf("Size : %d\n", nelems = strtoul(*argv, NULL, 0));
    	    assert(argc-- >= 0 && nelems);
    	    argv++;
    	    break;

        case 'r':
            argv++;
    	    printf("range : %d\n", range = strtoul(*argv, NULL, 0));
    	    assert(argc-- >= 0 && range);
    	    argv++;
    	    break;
        
        case 'n':
    	    printf("randomize with seed : %d\n", seed = (unsigned int)time(NULL));
            argv++;
    	    break;
        
        case 'd':
            argv++;
    	    printf("randomize with seed : %d\n", seed = strtoul(*argv, NULL,0 ));
    	    assert(argc-- >= 0 && seed);
    	    argv++;
    	    break;
            
    	default:
    	    break;
    	}
    }
    seq = malloc(nelems * sizeof(*seq));
    if(seed)
        srand(seed);
    for (i = 0; i < nelems; i++)
    {
        int val = rand();
        val = ((double)val*range)/(RAND_MAX + 1.0);
        seq[i] = val + range/2;        
#if 0
        printf("%d \n", seq[i]);
#endif
    }
    res1 = maxsubseqsum_dyn(seq, nelems);
    res2 = maxsubseqsum(seq, nelems);
    printf("r1: %d %d %d\n", res1.start, res1.end, res1.sum);
    printf("r2: %d %d %d\n", res2.start, res2.end, res2.sum);
    return 0;
}
