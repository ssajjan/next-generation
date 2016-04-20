#include <stdio.h>
#include <stdlib.h>
#include "rbtr.h"

int compare(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, char **argv) {
    int maxnum, ct;

    // command-line:
    //
    //   rbtmain 2000
    //       process 2000 records

    RbtIterator i;
    RbtHandle h;
    RbtStatus status;

    maxnum = atoi(argv[1]);

    // obtain handle to red-black tree
    h = rbtNew(compare);

    printf("maxnum = %d\n", maxnum);
    for (ct = maxnum; ct; ct--) {
        int key = rand() % 90 + 1;

        if ((i = rbtFind(h, &key)) != rbtEnd(h)) {
            // found an existing node
            void *keyp, *valuep;

            // get key-value pointers
            rbtKeyValue(h, i, &keyp, &valuep);

            // check to see they contain correct data
            if (*(int *)keyp != key) printf("fail keyp\n");
            if (*(int *)valuep != 10*key) printf("fail valuep\n");

            // erase node in red-black tree
            status = rbtErase(h, i);
            if (status) printf("fail: status = %d\n", status);

            // free the pointers allocated by main
            free(keyp); free(valuep);

        } else {
            // create a new node
            int *keyp, *valuep;

            // allocate key/value data
            keyp = (int *)malloc(sizeof(int));
            valuep = (int *)malloc(sizeof(int));

            // initialize with values
            *keyp = key;
            *valuep = 10*key;

            // insert in red-black tree
            status = rbtInsert(h, keyp, valuep);
            if (status) printf("fail: status = %d\n", status);
        }
    }

    // output nodes in order
    for (i = rbtBegin(h); i != rbtEnd(h); i = rbtNext(h, i)) {
        void *keyp, *valuep;
        rbtKeyValue(h, i, &keyp, &valuep);
        printf("%d %d\n", *(int *)keyp, *(int *)valuep);
    }

    // delete my allocated memory
    for (i = rbtBegin(h); i != rbtEnd(h); i = rbtNext(h, i)) {
        void *keyp, *valuep;
        rbtKeyValue(h, i, &keyp, &valuep);
        free(keyp); free(valuep);
    }

    // delete red-black tree
    rbtDelete(h);

    return 0;
}
