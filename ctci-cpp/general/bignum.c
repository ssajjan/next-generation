//gcc -g bignum.c --std=c99
#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#define MAX_ITERS (10)


typedef uint32_t datum_t;
typedef struct bigi
{
   datum_t *n;   
   /* len is in units of data type for above*/
   size_t n_datums;
   uint32_t sign:1;
} bigi_t;

size_t bigi_size(bigi_t *b)
{
    return b->n_datums;
}

void bigi_extend(bigi_t *b, size_t new_datum_count)
{
    if (bigi_size(b) >= new_datum_count)
        return;
    else
    {
        datum_t *n = calloc(new_datum_count, sizeof(datum_t));
        if (b->n)
        {
            memcpy(n, b->n, sizeof(datum_t) * b->n_datums);
            free(b->n);
        }
        b->n = n;
        b->n_datums = new_datum_count;
    }
}


bigi_t *bigi_alloc(size_t len)
{
    bigi_t *b = calloc(1, sizeof(*b));
    b->n = NULL;
    bigi_extend(b, len);
    return b;
}

bigi_t *bigi_clone(bigi_t *src)
{
    bigi_t *b = bigi_alloc(bigi_size(src));
    memcpy(b->n, src->n, sizeof(*b->n)*bigi_size(src));
    b->n_datums = bigi_size(src);
    return b;
}

void bigi_free(bigi_t **b)
{
    free((*b)->n);
    free(*b);
    *b = NULL;
}

void bigi_sanity(bigi_t *b)
{
    if (!b->n)
        assert(0);
}

void bigi_boundcheck(bigi_t *b, size_t bound)
{
    bigi_sanity(b);
    if (b->n_datums < (bound + 1))
        assert(0);
}


#if 0
bool bigi_sign(bigi_t *b)
{
    bigi_sanity(b);
    return b->sign;
}
#endif

datum_t bigi_get_datum(bigi_t *b, size_t idx)
{
    bigi_sanity(b);
    bigi_boundcheck(b, idx);
    return b->n[idx];
}

datum_t bigi_set_datum(bigi_t *b, size_t idx, datum_t datum)
{
    bigi_sanity(b);
    bigi_boundcheck(b, idx);
    return b->n[idx] = datum;
}

bigi_t *bigi_add_uint32(bigi_t *b, uint32_t x)
{
    uint64_t result = x;
    size_t idx = 0;

    for (idx = 0; idx < bigi_size(b) && result; idx++)
    {
        result += bigi_get_datum(b, idx);
        bigi_set_datum(b, idx, result);
        result = result >> 32;
    }

    if (result)
    {
        bigi_extend(b, idx + 1);
        bigi_set_datum(b, idx, result);
    }
    return b;
}


void bigi_add_bigi(bigi_t *dest, bigi_t *src)
{
    size_t dest_sz, src_sz, i;
    uint64_t sum = 0;

    dest_sz = bigi_size(dest);
    src_sz = bigi_size(src);

    if(dest_sz < src_sz)
    {
        dest_sz = src_sz;
        bigi_extend(dest, dest_sz);
    }

    for (i = 0; i < src_sz; i++)
    {
        sum = sum + bigi_get_datum(src, i) + bigi_get_datum(dest, i);
        bigi_set_datum(dest ,i, (uint64_t)sum);
        sum >>= 32;
    }
    
    assert(sum == 0 || sum == 1);

    for ( ; sum && i < dest_sz; i++)
    {
        sum += bigi_get_datum(dest, i);
        bigi_set_datum(dest, i, sum);
        sum >>= 32;
    }

    assert(sum == 0 || sum == 1);

    if (sum && !dest->sign && !src->sign)
    {
        datum_t datum;
        bigi_extend(dest, i + 1);
        datum = bigi_get_datum(dest,i);
        bigi_set_datum(dest, i, sum + datum);
    }
    return ;
}

uint64_t bigi_add_rec_step(uint32_t a, uint32_t b)
{



}

void bigi_add_bigi_rec(bigi_t *dest, bigi_t *src)
{
     

}

datum_t bigi_get_datum_pad(bigi_t *b, size_t idx)
{
    if (!b->n)
        return UINT32_C(0);
    if (idx > b->n_datums - 1)
        return UINT32_C(0);
    return b->n[idx];
}

bigi_t *bigi_sub(bigi_t *a, bigi_t *b)
{
    bigi_t *res = NULL;
    size_t sz_a, sz_b, max;
    uint64_t sum = 1;

    sz_a = bigi_size(a);
    sz_b = bigi_size(b);

    if (sz_a > sz_b)
    {
        max = sz_a;
        res = bigi_alloc(sz_a);
    }
    else
    {
        max = sz_b;
        res = bigi_alloc(sz_b);
    }

    for (size_t i = 0; i < max; i++)
    {
        sum = sum + bigi_get_datum_pad(a, i) + (~bigi_get_datum_pad(b, i));  
        bigi_set_datum(res, i, sum);
        sum = sum >> 32;
    }
    
    if (sum)
    {
        res->sign = false;
    }
    else
    {
        res->sign = true;
    }

    return res;
}

void bigi_print(bigi_t *b, bool newline)
{
    size_t idx, len;
    if (!b)
        return;
    if(!b->n_datums)
    {
        printf("0x%x%c",0, newline ? '\n':' ');
        return;
    }
    len = bigi_size(b);
#if 0
    if (b->sign)
        printf("-");
#endif
    printf("0x");
    for (idx = 0; idx < len; idx++)
    {
        printf("%8.8x", bigi_get_datum(b, len - 1 - idx));
    }
    if (newline)
        printf("\n");
    else
        printf(",");
}

bigi_t *bigi_mpy_naive(bigi_t *b, uint32_t multiplier)
{
    uint32_t i;
    bigi_t *clone = bigi_clone(b);
    for (i = 0; i < multiplier - 1; i++)
    {
        bigi_add_bigi(b, clone);
    }
    bigi_free(&clone);
    return b;
}

void bigi_trim(bigi_t *tr)
{
    datum_t *d;
    size_t sz, idx;
    if (!tr)
        return;
    if (!tr->n)
        return;
    sz = bigi_size(tr);
    for (idx = sz - 1; idx && !bigi_get_datum(tr, idx); idx--)
        ;
    sz++;
    d = malloc(sizeof(*d) * (idx + 1));
    memcpy(d, tr->n, sizeof(*d)*(idx + 1));
    free(tr->n);
    tr->n = d;
    tr->n_datums = idx + 1;
    return; 
}

bigi_t *bigi_add_at_idx(bigi_t *x, size_t idx, void *ptr, size_t len)
{
    datum_t *n, *add = ptr;
    uint64_t partial_sum = 0;
    int i;
    assert(bigi_size(x) >= idx + len);
    n = &x->n[idx];
    (void)n;

    for (i = 0; i <(int)len; i++, idx++)
    {
        partial_sum = partial_sum + bigi_get_datum(x, idx) + add[i];
        bigi_set_datum(x, idx, (uint32_t)partial_sum);
        partial_sum >>= 32;
        assert(partial_sum < 2);
    }

    while (partial_sum)
    {
        if (idx + 1 > bigi_size(x))
        {
            bigi_extend(x, bigi_size(x) + 1);
        }
        partial_sum = partial_sum + bigi_get_datum(x, idx);
        bigi_set_datum(x, idx, partial_sum);
        partial_sum = partial_sum >> 32;
        idx++;
    }
    return x;
}

unsigned int get_val(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    assert(0);
    return 0;
}

bigi_t *bigi_from_str(char *str, long len)
{
    bigi_t *b = NULL;
    uint32_t shift = 0;
    datum_t *d = 0;
    if (*str == '0')
        str++, len--;
    if (*str == 'x')
        str++, len--;
    assert(len > 0);
    b = bigi_alloc((len+7)>>3);
    d = b->n;
    str = str + len - 1;
     
    while (len)
    {

        shift = 0;
        switch((len - 1)%8)
        {
            case 0:
            *d = *d | get_val(*str)<<shift;
            shift += 4;
            str--;
            len--;
            if (!*str)
                break;
            case 7:
            *d = *d| get_val(*str)<<shift;
            shift += 4;
            len--;
            str--;
            /*read 2*/
            case 6:
            *d = *d| get_val(*str)<<shift;
            shift += 4;
            len--;
            str--;
            case 5:
            *d = *d| get_val(*str)<<shift;
            shift += 4;
            len--;
            str--;
            /*read 1*/
            case 4:
            *d = *d| get_val(*str)<<shift;
            shift += 4;
            str--;
            len--;
            case 3:
            *d = *d| get_val(*str)<<shift;
            shift += 4;
            str--;
            len--;
            case 2:
            *d = *d| get_val(*str)<<shift;
            shift += 4;
            len--;
            str--;
            case 1:
            *d = *d| (get_val(*str))<<shift;
            shift += 4;
            len--;
            str--;
            break;
        }
        d++;
    }
    bigi_print(b, true);
    return b;
}

bigi_t *bigi_mpy_rows(bigi_t *x, bigi_t *y)
{
    bigi_t *mpy_result;  
    size_t x_sz = bigi_size(x);
    size_t y_sz = bigi_size(y);
    unsigned __int128 result = 0;

    mpy_result = bigi_alloc(x_sz + y_sz);


    for (x_sz = 0; x_sz < bigi_size(x); x_sz++)
    {
        for (y_sz = 0; y_sz < bigi_size(y); y_sz++)
        {
            result =  (unsigned __int128)bigi_get_datum_pad(x, x_sz) * bigi_get_datum_pad(y, y_sz);

            /* result can max be 65 bits*/
            result += (unsigned __int128)bigi_get_datum_pad(mpy_result, x_sz + y_sz);
            bigi_set_datum(mpy_result, x_sz + y_sz,(uint32_t)result);
            result = result>>32;
            result += bigi_get_datum_pad(mpy_result, x_sz + y_sz + 1);
            bigi_set_datum(mpy_result, x_sz + y_sz + 1, result);
            result = result>>32;
            assert(result == 0 || result == 1);
            if (result)
            {
                /*write(STDERR_FILENO, ".",2);*/
                bigi_add_at_idx(mpy_result,x_sz + y_sz + 2, &result, 1);
            }

        }
    }
    bigi_trim(mpy_result);
    return mpy_result;
}

#if 0
bigi_t *bigi_inverse(biti_t *x)
{




}
#endif

bigi_t *bigi_factorial(uint32_t fact)
{
    bigi_t *res;
    if (fact ==0 || fact == 1)
    {
        res = bigi_alloc(0);
        bigi_add_uint32(res, 1);
        return res;
    }
    else
    {
        res = bigi_factorial(fact - 1);
        bigi_mpy_naive(res, fact);
        printf("Computed # %lu\n", (unsigned long)fact);
        return res;
    }
}

/* Only works for un-signed*/
int32_t bigi_cmp(bigi_t *a, bigi_t *b)
{
    size_t sz_a, sz_b;
    int32_t res = 0;
    if (!a || !b)
        assert(0);
    sz_a = bigi_size(a);
    sz_b = bigi_size(b);
    
    while (sz_a && !bigi_get_datum(a, sz_a - 1))
        sz_a--;

    while (sz_b && !bigi_get_datum(b, sz_b - 1))
        sz_b--;

    if (sz_a > sz_b)
    {
        res = 1;
    }
    else if (sz_a < sz_b)
    {
        res = -1;
    }
    else 
    {
        res = 0;
        while (sz_a-- && sz_b-- && !res)
        {
            datum_t d_a, d_b;
            d_a = bigi_get_datum(a, sz_a);
            d_b = bigi_get_datum(b, sz_b);
            res = (d_a - d_b);

        }
    }
    return res;
}

int main(int argc, char **argv)
{
    uint32_t x;
    uint32_t y;
    uint32_t seed;
    int32_t iters = 0;
    bigi_t *a, *b, *c;
    seed = 10;
    srand48(seed);
    if (argc > 1)
    {
        iters = strtol(argv[1], NULL, 0);
    }
    if (!iters)
        iters = MAX_ITERS;
    
    while(1)
    {
        {
            char *str1 = malloc(100);
            char *str2 = malloc(100);
            assert(fgets(str1, 100, stdin));
            assert(fgets(str2, 100, stdin));
            str1[strcspn(str1, "\r\n")] = 0;
            str2[strcspn(str2, "\r\n")] = 0;
            if (!strcmp(str1, "end"))
                break;
            a = bigi_from_str(str1, strlen(str1));
            b = bigi_from_str(str2, strlen(str1));
            printf("%d\n", bigi_cmp(a, b));
            bigi_free(&a);
            bigi_free(&b);
        }
    }

#if 0
    if (1)
    {
        a = bigi_alloc(0);
        b = bigi_alloc(0);
        while (iters--)
        {

            srand48(seed = (uint32_t)time(NULL)); 
            printf("Seed # %lu\n", seed);
            x = drand48()*UINT32_MAX;
            y = drand48()*UINT32_MAX;
            bigi_add_uint32(a, x);
            bigi_add_uint32(b, y);
            c = bigi_mpy_rows(a, b);
            bigi_print(a, false);
            bigi_print(b, false);
            bigi_print(c, true);
            bigi_free(&a);
            b = c;
            a = b;
        }
        /*fflush(stdout);*/
        bigi_free(&a);
    }
    else
    {
        char *str = "0xffffffffffffffffffffffff00000000";
        bigi_from_str("0xffffffff",10);
        bigi_from_str("0xff",4);
        bigi_from_str("0xf",3);
        bigi_from_str("0x0",3);
        bigi_from_str("0x0123456789abcdef",18);

        a = bigi_add_at_idx(bigi_from_str(str, strlen(str)), 1, &(uint32_t){1}, 1);
        bigi_print(a, true);

    }
#endif
    (void)argv;
    (void)argc;
    return 0;
}
