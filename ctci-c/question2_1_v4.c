/*
2.1
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 15
#define MULTIPLIER 1
#define MAX_LEN 15

/* Hash Table Implementation*/
struct wordrec {
        int num;
        int count;
        struct wordrec *next;
};
struct wordrec *table[MAX_LEN];  /* hash bucket */

int hashstring (int val) {
        int hash = 0;
        hash= hash*MULTIPLIER + val;
        return hash%MAX_BUCKETS;
}

struct wordrec *lookup(int val)
{
        struct wordrec *curr = NULL;
        int hash = hashstring(val);
        //printf("Hashstring for hash value %d is %d\n",val,hash);
        struct wordrec *wp,*nwp;

        if (table[hash]) {
                wp = table[hash];
        }
        else {
		//printf("Assigning new memory for table[hash]\n");
                table[hash] = (struct wordrec *)malloc(sizeof(struct wordrec));
		memset(table[hash],0,sizeof(struct wordrec));
                wp = table[hash];

        }

        int found = 0;
        for (curr = wp; curr != NULL; curr = curr->next) {
                /* search */
                //printf("Curr pointer is %p with value %d\n",curr,curr->num);
                if (curr->num == val) {
                        found = 1;
                        curr->count++;
			printf("Value %d is already present in hash table\n",curr->num);
                        break;
                }
        }

        if (found == 0) {
                if (wp->count>0) {
                        //printf("Wp existing value for %d is: %d with count: %d\n",val,wp->num,wp->count);
                        //printf("Wp existing pointer is: %p\n",wp);
                        nwp = (struct wordrec *)malloc(sizeof(struct wordrec));
			memset(nwp,0,sizeof(struct wordrec));
                        //printf("nWp new pointer is: %p\n",nwp);
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

void freedict(void) {
        struct wordrec *curr,*temp;
        printf("\nFreeing the dict\n");
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

/* Linked List Implementation*/
struct node {
	int data; /* payload */
	struct node *next;
};

struct node * newNode(int data) {
	struct node *newNode =(struct node *) malloc(sizeof(struct node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;

	}

	return newNode;
}

struct node * appendNode(struct node *end, int data) {
	struct node *newEnd = newNode(data);
	if (newEnd != NULL) {
		end->next = newEnd;
	}

	return newEnd;
}

void iterateNodes(struct node *start) {
	printf("\nIterating over Linked List:\n");
	for (struct node *p = start; p!=NULL;p=p->next) {
		printf("Value: %d, Address: %p, Next Address: %p\n",p->data,p,p->next);
	}
}

void delDupNodes(struct node *start) {
	for (struct  node *p = start; p!= NULL; p=p->next) {
		for (struct  node *q = p->next, *prev = p, *temp; q!= NULL; q=q->next) {
			if (p->data == q->data) {
				printf("Removing Value: %d\n",q->data);
				temp = q;
				prev->next = q->next;
				free(temp);
			}
			else {
				prev = q;
			}
		}
	}
}

struct node * delNodeCursor(struct node *start,struct node *cursor) {
	struct node *temp,*prev=NULL,*p=start;

	while (p!=NULL) {
		if (p == cursor){
			printf("Removing Value: %d\n",p->data);
			temp = p;
			if (prev !=  NULL) {
				prev->next = p->next;
			}
			else {
				start = p->next;
			}
			free(temp);
			break;
		}
		else {
			prev = p;
		}
		p=p->next;
	}
	return start;
}

void delDupsHash(struct node *start) {
        struct wordrec *dict;
	printf("\nRemoving Duplicates using hash table:\n");
	for (struct node *p = start,*prev = p,*temp; p!=NULL;p=p->next) {
		//printf("Value: %d, Address: %p, Next Address: %p\n",p->data,p,p->next);
		dict = lookup(p->data);
		if (dict->count>1) {
			//printf("Duplicate node found: %d\n",p->data);
			temp = p;
			prev->next = p->next;
			free(temp);
		}
		else {
			prev = p;
		}
		//printf("---------------------------\n");
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

	int arr[MAX_LEN] = {5,5,5,5,5,0,2,7,2,15,6,6,0,15,5};
	//int arr[MAX_LEN] = {5,5,5,5,5,5,5,15,15,5,5,5,5,5,5};
	//int arr[MAX_LEN] = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};

	struct node *head = NULL; /* beginning */
	struct node *end = NULL; /* end */

	head = newNode(arr[0]);

	//printf("Start Pointer of Linked List is: %p\n",head);
	//printf("Start Data of Linked List is: %d\n",head->data);

	end = newNode(arr[1]);
	head->next = end;
	//printf("Initial End Pointer of Linked List is: %p\n",end);
	//printf("Initial End Data of Linked List is: %d\n",end->data);

	for (int num = 2; num<MAX_LEN; num++) {
		end = appendNode(end,arr[num]);
		//printf("Appended Pointer of Linked List is: %p\n",end);
		//printf("Appended Data of Linked List is: %d\n",end->data);
	}

	iterateNodes(head);

	delDupsHash(head);

	iterateNodes(head);

	printf("\nFreeing Linked List:\n");
	struct node *temp;
	while (head!=NULL) {
		temp = head;
		head=head->next;
		free(temp);
	}

	//head = NULL;     /* Mark list as empty*/

        freedict();

	return 0;
}
