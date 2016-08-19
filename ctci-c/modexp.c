#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <inttypes.h>
#include <time.h>


#define DEFAULT_ITERS (10)
#define DEFAULT_EXPONENT_RANGE (2147483647)

#define GET_OPT(type, vector, var) do {\
    var = (type)strtol(*vector, NULL, 0);\
    vector++; \
    } while (0)

typedef struct params {
    uint32_t iterations;
    uint32_t exponent_mod;
} params_t;

uint32_t modexp(uint32_t a, uint32_t b, uint32_t c)
{
    uint64_t exps = a;
    uint64_t result = 1;
    while (b)
    {
        if (b & 0x1)
          result = (result * exps) % c;  
        b = b >> 1;
        exps = (exps * exps) % c;
    }
    return result;
}

void run_iterations(params_t *param)
{
    uint32_t a,b,c;
    uint32_t result;
    for (uint32_t i = 0; i < param->iterations; i++)
    {
        a = drand48() * UINT32_MAX;
        b = drand48() * param->exponent_mod;
        c = (drand48() * UINT32_MAX);
        result = modexp(a,b,c);
        printf("%" PRIu32 "," "%" PRIu32 "," "%" PRIu32 "," "%" PRIu32 "\n", a, b ,c, result);
    }
}

int main(int argc, char **argv)
{
    uint32_t iterations = 0;
    bool randomize = false;
    uint32_t exponent_mod = 0;
    uint32_t seed = 0;

    argv++;
    while (*argv && *((*argv)++) == '-')
    {
        char option = **argv;
        argv++;
        argc--;

        switch (option)
        {
            case 'i':
            GET_OPT(uint32_t, argv, iterations);         
            break;

            case 's':
            GET_OPT(long int, argv, seed);
            case 'r':
            randomize = true;
            break;

            case 'm':
            GET_OPT(uint32_t, argv, exponent_mod);
            break;

            case 'n':
            GET_OPT(uint32_t, argv, exponent_mod);
            break;

        }

    }

    if (!iterations) 
        iterations = DEFAULT_ITERS;
    if (!exponent_mod)
        exponent_mod = DEFAULT_EXPONENT_RANGE;

    if (randomize)
    {
        if (seed)
            srand48(seed);
        else
            srand48(time(NULL));
    }
        
    run_iterations(&(params_t){.iterations = iterations, 
            .exponent_mod = exponent_mod});

    (void)argc;
    (void)argv;
    return 0;
}
