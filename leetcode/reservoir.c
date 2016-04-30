#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>

typedef long data_t;

typedef struct reservoir_state
{
    long m;
    long n;
    data_t *d;
}reservoir_state_t;

long range(long start, long end)
{
    double rand = drand48();
    long vals = (end - start) + 1;
    vals = vals*rand + start;
    return vals;
} 

void reservoir_sample(reservoir_state_t *r, data_t d)
{

    if (r->m > r->n)
    {
        r->d[r->n] = d;
    }
    else
    {
        if (range(1, r->n  + 1) <= r->m)
        {
            long remove = range(1, r->n);
            r->d[remove] = d;
        }
    }
    r->n++;
    return ; 
}

void dump_reservoir(reservoir_state_t *r)
{
    long i;
    for (i = 0; i < r->m; i++)
    {
        printf("%ld\n", r->d[i]);
    }
}

reservoir_state_t *initialize_reservoir(long m)
{
    reservoir_state_t *r = calloc(1, sizeof(*r));
    r->d = calloc(m, sizeof(data_t));
    r->m = m;
    r->n = 0;
    return r;
}

int main()
{
    long i = 10000;
    reservoir_state_t *r = NULL;
    srand48(time(NULL));
    r = initialize_reservoir(128);
    while(i-- > 0)
    {
        reservoir_sample(r, range(1,128));
    }
    
    dump_reservoir(r);
    return 0;
}
