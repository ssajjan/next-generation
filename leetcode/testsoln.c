/*
TODO:
compile with 
gcc testsoln.c -o testsoln  -ggdb 
TODO: 
run with 
./testsoln -d 1461741195 

randomize with seed : 1461741195
-18,0,0 34,1,1 79,1,2 115,1,3 122,1,4 80,1,5 117,1,6 88,1,7 92,1,8 53,1,9

  -18    34    45    36     7   -42    37   -29     4   -39
  -18    16    61    97   104    62    99    70    74    35
    0    34    79   115   122    80   117    88    92    53
    0     0    45    81    88    46    83    54    58    19
    0     0     0    36    43     1    38     9    13   -26
    0     0     0     0     7   -35     2   -27   -23   -62
    0     0     0     0     0   -42    -5   -34   -30   -69
    0     0     0     0     0     0    37     8    12   -27
    0     0     0     0     0     0     0   -29   -25   -64
    0     0     0     0     0     0     0     0     4   -35
    0     0     0     0     0     0     0     0     0   -39

r1: 1 4 122
r2: 1 4 122

secondary test failed
104
*/



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
   long long sum;
}sums_t ;

range_t maxsubseqsum_dyn(const int sequence[], const int len)
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
        int elem = sequence[i];

        if (prev->sum + elem > elem) 
        {
            current->sum = prev->sum + elem; 
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
#if 0
    for (i = 0; i < len; i++)
        printf("%d,%d,%d ", sums[i].sum, sums[i].left, sums[i].right);
    printf("\n");
#endif
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


range_t maxsubseqsum(const int sequence[], const int len)
{
    int i, k, j;
    int left, right, max;
    int sums[len][len];
    
    max = 0;
    memset(sums, 0, sizeof(sums));
    for ( i = 0; i < len; i++)
    {
        printf(" %4d ", sequence[i]);
    }
    printf("\n");
    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
            for (k = i; k <= j; k++)
            {
                sums[i][j] += sequence[k];
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

long long int ssajjan_max_in_array_neg(int a[], int size)
{
	long long int max = 0;
	long long int till = 0;
	int i =0;

	if(a[0]){
		max=a[0];
		if(a[0]>0)
			till = a[0];
		else
			till = 0;

	}
	for (i = 1; i < size; i++){
		till+=a[i];
		if(till<0)
			till = 0;
		if(till > max)
			max=till;
	}

	return max;
}
long long int ssajjan_max_in_array(int a[], int size)
{
	long long int max = 0;
	long long int till = 0;
	int i =0;

	for (i = 0; i < size; i++){
		till+=a[i];
		if(till<0)
			till = 0;
		if(till > max)
			max=till;
	}

	return max;
}

int main(int argc, char **argv)
{
    int *seq = NULL;
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
        seq[i] = val - range/2;        
#if 0
        printf("%4d \n", seq[i]);
#endif
    }
    res1 = maxsubseqsum_dyn(seq, nelems);
    res2 = maxsubseqsum(seq, nelems);
    

    printf("r1: %d %d %d\n", res1.start, res1.end, res1.sum);
    printf("r2: %d %d %d\n", res2.start, res2.end, res2.sum);

    if (res1.sum != res2.sum)
    {
        printf("Primary test failed\n");
//        exit(1);
    }

#if 1
    long long ssajjan_sum = ssajjan_max_in_array(seq, nelems);
    if (ssajjan_sum != res2.sum)
    {
        printf("failed ssajjan_sum = %lld, res2.sum = %d \n",ssajjan_sum,res2.sum);
        printf("%ld\n",(long) ssajjan_sum);
        exit(2);
    }else
    	printf("Passed ssajjan_sum = %lld, res2.sum = %d \n",ssajjan_sum,res2.sum);
#endif
    return 0;
}
