/* skip list */

#include <stdio.h>
#include <stdlib.h>

/* implementation dependent declarations */
typedef enum {
    STATUS_OK,
    STATUS_MEM_EXHAUSTED,
    STATUS_DUPLICATE_KEY,
    STATUS_KEY_NOT_FOUND
} statusEnum;

typedef int keyType;            /* type of key */

/* user data stored in tree */
typedef struct {
    int stuff;                  /* optional related data */
} recType;

#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

/* levels range from (0 .. MAXLEVEL) */
#define MAXLEVEL 15

typedef struct nodeTag {
    keyType key;                /* key used for searching */
    recType rec;                /* user data */
    struct nodeTag *forward[1]; /* skip list forward pointer */
} nodeType;

/* implementation independent declarations */
typedef struct {
    nodeType *hdr;              /* list Header */
    int listLevel;              /* current level of list */
} SkipList;

SkipList list;                  /* skip list information */

#define NIL list.hdr

statusEnum insert(keyType key, recType *rec) {
    int i, newLevel;
    nodeType *update[MAXLEVEL+1];
    nodeType *x;

   /***********************************************
    *  allocate node for data and insert in list  *
    ***********************************************/

    /* find where key belongs */
    x = list.hdr;
    for (i = list.listLevel; i >= 0; i--) {
        while (x->forward[i] != NIL 
          && compLT(x->forward[i]->key, key))
            x = x->forward[i];
        update[i] = x;
    }
    x = x->forward[0];
    if (x != NIL && compEQ(x->key, key)) 
        return STATUS_DUPLICATE_KEY;

    /* determine level */
    for (
      newLevel = 0; 
      rand() < RAND_MAX/2 && newLevel < MAXLEVEL; 
      newLevel++);

    if (newLevel > list.listLevel) {
        for (i = list.listLevel + 1; i <= newLevel; i++)
            update[i] = NIL;
        list.listLevel = newLevel;
    }

    /* make new node */
    if ((x = malloc(sizeof(nodeType) + newLevel*sizeof(nodeType *))) == 0)
        return STATUS_MEM_EXHAUSTED;
    x->key = key;
    x->rec = *rec;

    /* update forward links */
    for (i = 0; i <= newLevel; i++) {
        x->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = x;
    }
    return STATUS_OK;
}

statusEnum delete(keyType key) {
    int i;
    nodeType *update[MAXLEVEL+1], *x;

   /*******************************************
    *  delete node containing data from list  *
    *******************************************/

    /* find where data belongs */
    x = list.hdr;
    for (i = list.listLevel; i >= 0; i--) {
        while (x->forward[i] != NIL 
          && compLT(x->forward[i]->key, key))
            x = x->forward[i];
        update[i] = x;
    }
    x = x->forward[0];
    if (x == NIL || !compEQ(x->key, key)) return STATUS_KEY_NOT_FOUND;

    /* adjust forward pointers */
    for (i = 0; i <= list.listLevel; i++) {
        if (update[i]->forward[i] != x) break;
        update[i]->forward[i] = x->forward[i];
    }

    free (x);

    /* adjust header level */
    while ((list.listLevel > 0)
    && (list.hdr->forward[list.listLevel] == NIL))
        list.listLevel--;

    return STATUS_OK;
}

statusEnum find(keyType key, recType *rec) {
    int i;
    nodeType *x = list.hdr;

   /*******************************
    *  find node containing data  *
    *******************************/

    for (i = list.listLevel; i >= 0; i--) {
        while (x->forward[i] != NIL 
          && compLT(x->forward[i]->key, key))
            x = x->forward[i];
    }
    x = x->forward[0];
    if (x != NIL && compEQ(x->key, key)) {
        *rec = x->rec;
        return STATUS_OK;
    }
    return STATUS_KEY_NOT_FOUND;
}

void initList() {
    int i;

   /**************************
    *  initialize skip list  *
    **************************/

    if ((list.hdr = malloc(
            sizeof(nodeType) + MAXLEVEL*sizeof(nodeType *))) == 0) {
        printf ("insufficient memory (initList)\n");
        exit(1);
    }
    for (i = 0; i <= MAXLEVEL; i++)
        list.hdr->forward[i] = NIL;
    list.listLevel = 0;
}

int main(int argc, char **argv) {
    int i, maxnum, random;
    recType *rec;
    keyType *key;
    statusEnum status;


    /* command-line:
     *
     *   skl maxnum [random]
     *
     *   skl 2000
     *       process 2000 sequential records
     *   skl 4000 r
     *       process 4000 random records
     *
     */

    maxnum = atoi(argv[1]);
    random = argc > 2;

    initList();

    if ((rec = malloc(maxnum * sizeof(recType))) == 0) {
        fprintf (stderr, "insufficient memory (rec)\n");
        exit(1);
    }
    if ((key = malloc(maxnum * sizeof(keyType))) == 0) {
        fprintf (stderr, "insufficient memory (key)\n");
        exit(1);
    }

    if (random) {
        /* fill "a" with unique random numbers */
        for (i = 0; i < maxnum; i++) key[i] = rand();
        printf ("ran, %d items\n", maxnum);
    } else {
        for (i = 0; i < maxnum; i++) key[i] = i;
        printf ("seq, %d items\n", maxnum);
    }

    for (i = 0; i < maxnum; i++) {
        status = insert(key[i], &rec[i]);
        if (status) printf("pt1: error = %d\n", status);
    }

    for (i = maxnum-1; i >= 0; i--) {
        status = find(key[i], &rec[i]);
        if (status) printf("pt2: error = %d\n", status);
    }

    for (i = maxnum-1; i >= 0; i--) {
        status = delete(key[i]);
        if (status) printf("pt3: error = %d\n", status);
    }
    return 0;
}
