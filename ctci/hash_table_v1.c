/* Hash Table Implementation*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_BUCKETS 20
#define MULTIPLIER 10
#define MAX_LEN 20

struct cachepts {
        int x;
        int y;
        int paths;
        struct cachepts *next;
};

int hashstring (int xval, int yval) {
        int hash;
        hash= xval*MULTIPLIER + yval;
        return hash%MAX_BUCKETS;
}

struct cachepts *lookup(struct cachepts **table, int xval, int yval)
{
        struct cachepts *curr = NULL;
        int hash = hashstring(xval,yval);
        printf("Hashstring for hash value (%d,%d) is %d\n", xval, yval, hash);
        struct cachepts *wp,*nwp;

        if (table[hash]) {
                wp = table[hash];
        }
        else {
		printf("Assigning new memory for table[hash]\n");
                table[hash] = (struct cachepts *)malloc(sizeof(struct cachepts));
		memset(table[hash],0,sizeof(struct cachepts));
                wp = table[hash];

        }

	printf("Table hash pointer is: %p\n",table);
	printf("Table hash pointer is: %p\n",table[0]);
	printf("Table hash pointer is: %p\n",table[hash]);

        int found = 0;
        for (curr = wp; curr != NULL; curr = curr->next) {
                /* search */
                printf("Curr pointer is %p with value %d\n",curr,curr->x);
                if (curr->x == xval && curr->y == yval) {
                        found = 1;
                        curr->paths++;
			printf("Value %d is already present in hash table\n",curr->x);
                        break;
                }
        }

        if (found == 0) {
                if (wp->paths>0) {
                        printf("Wp existing value for %d is: %d with paths: %d\n",xval,wp->x,wp->paths);
                        //printf("Wp existing pointer is: %p\n",wp);
                        nwp = (struct cachepts *)malloc(sizeof(struct cachepts));
			memset(nwp,0,sizeof(struct cachepts));
                        //printf("nWp new pointer is: %p\n",nwp);
                        nwp->x = xval;
                        nwp->y = yval;
                        nwp->paths++;
                        nwp->next = wp;
                        printf("nWp value is: %d with paths: %d\n",nwp->x,nwp->paths);
                        table[hash] = nwp;
                        curr = nwp;
                }
                else {
                        wp->x = xval;
                        wp->y = yval;
                        wp->paths++;
                        curr = wp;
                        printf("New value: %d with paths: %d\n",wp->x,wp->paths);
                }
                /* add to front */;
        }
        return curr;
}

void freedict(struct cachepts **table) {
        struct cachepts *curr,*temp;
        printf("\nFreeing the dict\n");
        for (int index = 0; index < MAX_LEN; index++) {
                if (table[index]) {
                        curr = table[index];
                        while (curr != NULL) {
                                printf("Curr pointer is %p with value %d and paths %d\n",curr,curr->x,curr->paths);
                                temp = curr;
                                curr=curr->next;
                                free(temp);
                        }
                }
        }
}

/*
int main(int argc, char *argv[]) {
	struct cachepts **table = (struct cachepts **)malloc(sizeof(struct cachepts)*MAX_LEN);  // hash bucket
	lookup(table,x,y);
	delDupsHash(table,head);

        freedict(table);
	return 0;
}
*/
