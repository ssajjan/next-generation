/* quicksort, for linked lists */

#include <stdio.h>
#include <stdlib.h>

typedef int T;                  /* type of item to be sorted */

typedef struct listTag {        /* typical node to be sorted */
    struct listTag *next;
    struct listTag *prev;
    T data;
} listNode;

#define compLT(a,b) (a < b)
#define compGT(a,b) (a > b)

listNode *partition(listNode *lb, listNode *rb) {
    T t, pivot;
    listNode *i, *j;
    int done;           /* record if pointers cross (means we're done!) */

   /********************************************************
    * partition list [lb..rb], and return pointer to pivot *
    ********************************************************/

    /* select a pivot */
    pivot = lb->data;
    done = 0;

    /* scan from both ends, swapping when needed */
    /* care must be taken not to address outside [lb..rb] with pointers */
    i = lb; j = rb;
    while(1) {
        while (compGT(j->data, pivot)) {
            j = j->prev;
            if (i == j) done = 1;
        }
        if (done) return j;
        while (compLT(i->data, pivot)) {
            i = i->next;
            if (i == j) done = 1;
        }
        if (done) return j;

        /* swap i, j */
        t = i->data;
        i->data = j->data;
        j->data = t;

        /* examine next element */
        j = j->prev;
        if (i == j) done = 1;
        i = i->next;
        if (i == j) done = 1;
    }
}

void quickSort(listNode *lb, listNode *rb) {
    listNode *m;

   /************************
    *  sort list [lb..rb]  *
    ************************/

    if (lb == rb) return;

    m = partition(lb, rb);

    if (m != lb) quickSort(lb, m);              /* sort left side */
    if (m != rb) quickSort(m->next, rb);        /* sort right side */
}

int main(int argc, char *argv[]) {
    /* command-line:
     *
     *   quilist maxnum
     *
     *   quilist 2000
     *       sorts 2000 records
     *
     */

    listNode *p0;
    int maxnum, i;

    maxnum = atoi(argv[1]);
    if ((p0 = malloc(maxnum * sizeof(listNode))) == 0) {
        fprintf (stderr, "insufficient memory (a)\n");
        exit(1);
    }

    /* initialize list */
    srand(1);
    for (i = 0; i < maxnum; i++) {
        p0[i].next = p0 + i + 1;
        p0[i].prev = p0 + i - 1;
        p0[i].data = rand();
    }

    quickSort(p0, p0 + maxnum-1);

    return 0;
}
