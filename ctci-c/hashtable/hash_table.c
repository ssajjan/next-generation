/*
2.1
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 20
#define MULTIPLIER 1
#define MAX_LEN 20

/* Hash Table Implementation*/
struct wordrec {
	int num;
	int count;
	struct wordrec *next;
};

int hashstring (int val) {
	int hash = 0;
	hash= hash*MULTIPLIER + val;
	return hash%MAX_BUCKETS;
}

struct wordrec * lookup(struct wordrec **table, int val)
{
	struct wordrec *curr = NULL;
	int hash = hashstring(val);
	printf("Hashstring for hash value %d is %d\n",val,hash);
	struct wordrec *wp,*nwp;

	printf("Table hash pointer is: %p\n",table);
	printf("Table hash pointer is: %p\n",table[hash]);
	if (table[hash]) {
		wp = table[hash];
	}
	else {
		table[hash] = (struct wordrec *)malloc(sizeof(struct wordrec));
		wp = table[hash];
			
	}

	int found = 0;
	for (curr = wp; curr != NULL; curr = curr->next) {
		/* search */
		printf("Curr pointer is %p with value %d\n",curr,curr->num);
		if (curr->num == val) {
			found = 1;
			curr->count++;
			break;
		}
	}

	printf("made it out\n");
	if (found == 0) {
		if (wp->count>0) {
			printf("Wp existing value for %d is: %d with count: %d\n",val,wp->num,wp->count);
			printf("Wp existing pointer is: %p\n",wp);
			nwp = (struct wordrec *)malloc(sizeof(struct wordrec));
			printf("nWp new pointer is: %p\n",nwp);
			nwp->num = val;
			nwp->count++;
			nwp->next = wp;
			table[hash] = nwp;
			curr = nwp;
		}
		else {
			wp->num = val;
			wp->count++;
			curr = wp;
		}
		/* add to front */;
	}
	return curr;
}

void freedict(struct wordrec **table) {
	struct wordrec *curr,*temp;
	printf("Freeing the dict\n");
	for (int index = 0; index < MAX_LEN; index++) {
		if (table[index]) {
			curr = table[index];
			while (curr != NULL) {
				printf("Curr pointer is %p with value %d and count %d\n",curr,curr->num,curr->count);
				temp = curr;
				curr=curr->next;
				free(temp);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	/*
	printf("Argument count: %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("Argument vector values:%s at %p memory\n", argv[i], argv[i]);
		for (char *j=argv[i]; *j!='\0'; j++) {
			printf("Another way to print argument vector values: "
                               "%c at %p memory\n", *j, j);
		}
	}
	*/

	struct wordrec **table = (struct wordrec **)malloc(sizeof(struct wordrec)*MAX_LEN);  /* hash bucket */
	struct wordrec *dict;

	dict = lookup(table,30);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,100);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,40);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,30);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,29);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,29);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,70);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,80);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,50);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,100);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,40);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,80);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");
	dict = lookup(table,70);
	printf("dict value %d are: %d\n",dict->num,dict->count);
	printf("---------------------\n");

	printf("Dict pointer: %p",dict);

	freedict(table);

	return 0;
}
