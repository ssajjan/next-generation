#include<stdio.h>
#include<stdlib.h>  // String and malloc function here
#include<stdbool.h> // bool
#include<stdint.h>  // uint32_t
#include<string.h>  // memset
#include<assert.h>
#define MIN(a,b)  (a)<(b)?(a):(b)
#define MAX(a,b)  (a)>(b)?(a):(b)

extern bool isUnique_improved(char *string);
extern bool isUnique(char *string);

/*
typedef struct range {
    int start, end, sum;
} range_t;


typedef struct sum_struct{
   int left;
   int right;
   long long sum;
}sums_t ;

*/

int main(int argc, char** argv){

   /* int *seq = NULL;
    int nelems = 10, i ;
    int range = 100;
    unsigned int seed = 0;
    range_t res1 = {0}, res2 = {0};
    */
    char *string;
    --argc;
    ++argv;
    while (*argv && *(*argv)++ == '-') {
        int option = **argv;
   	printf("option -%s\n", *argv);
    	assert(argc-- >= 0);
    	switch (option) {

    	case 's':
    	    argv++;
    	    printf("string  : %s\n", string = *argv);
    	    assert(argc-- >= 0 && string);
	    //bool isunique = isUnique(string);
	    bool isunique = isUnique_improved(string);
	    if(isunique)
		printf("is unique string\n");
	    else
		printf("is not unique string\n");
    	    argv++;
    	    break;
/*
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
  */          
    	default:
    	    break;
    	}
    }
 

	return 0;
}

