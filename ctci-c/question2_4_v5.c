/*
2.4 
Write code to partition a linked list around a value x, such that all nodes less than
x come before all nodes greater than or equal to x.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUCKETS 15
#define MULTIPLIER 2
#define MAX_LEN 15

/* Hash Table Implementation*/
struct wordrec {
        int num;
        int count;
        struct wordrec *next;
};

int hashstring (int val) {
        int hash = val;
        hash= hash*MULTIPLIER + val;
        return hash%MAX_BUCKETS;
}

struct wordrec *lookup(struct wordrec **table, int val)
{
        struct wordrec *curr = NULL;
        int hash = hashstring(val);
        printf("Hashstring for hash value %d is %d\n",val,hash);
        struct wordrec *wp,*nwp;

        if (table[hash]) {
                wp = table[hash];
        }
        else {
		printf("Assigning new memory for table[hash]\n");
                table[hash] = (struct wordrec *)malloc(sizeof(struct wordrec));
		memset(table[hash],0,sizeof(struct wordrec));
                wp = table[hash];

        }

	printf("Table hash pointer is: %p\n",table);
	printf("Table hash pointer is: %p\n",table[0]);
	printf("Table hash pointer is: %p\n",table[hash]);

        int found = 0;
        for (curr = wp; curr != NULL; curr = curr->next) {
                /* search */
                printf("Curr pointer is %p with value %d\n",curr,curr->num);
                if (curr->num == val) {
                        found = 1;
                        curr->count++;
			printf("Value %d is already present in hash table\n",curr->num);
                        break;
                }
        }

        if (found == 0) {
                if (wp->count>0) {
                        printf("Wp existing value for %d is: %d with count: %d\n",val,wp->num,wp->count);
                        //printf("Wp existing pointer is: %p\n",wp);
                        nwp = (struct wordrec *)malloc(sizeof(struct wordrec));
			memset(nwp,0,sizeof(struct wordrec));
                        //printf("nWp new pointer is: %p\n",nwp);
                        nwp->num = val;
                        nwp->count++;
                        nwp->next = wp;
                        printf("nWp value is: %d with count: %d\n",nwp->num,nwp->count);
                        table[hash] = nwp;
                        curr = nwp;
                }
                else {
                        wp->num = val;
                        wp->count++;
                        curr = wp;
                        printf("New value: %d with count: %d\n",wp->num,wp->count);
                }
                /* add to front */;
        }
        return curr;
}

void freedict(struct wordrec **table) {
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
	if (newEnd != NULL && end != NULL) {
		end->next = newEnd;
	}

	return newEnd;
}

struct node * addNodetoFront(struct node *head, int data) {
	struct node *newHead = newNode(data);
	if (newHead != NULL) {
		newHead->next = head;
	}

	return newHead;
}

void iterateNodes(struct node *start) {
	printf("\nIterating over Linked List:\n");
	for (struct node *p = start; p!=NULL;p=p->next) {
		printf("Value: %d, Address: %p, Next Address: %p\n",p->data,p,p->next);
	}
	printf("\n");
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

void delDupsHash(struct wordrec **table, struct node *start) {
        struct wordrec *dict;
	printf("\nRemoving Duplicates using hash table:\n");
	for (struct node *p = start,*prev = p,*temp; p!=NULL;p=p->next) {
		//printf("Value: %d, Address: %p, Next Address: %p\n",p->data,p,p->next);
		dict = lookup(table,p->data);
		if (dict->count>1) {
			//printf("Duplicate node found: %d\n",p->data);
			temp = p;
			prev->next = p->next;
			free(temp);
		}
		else {
			prev = p;
		}
		printf("---------------------------\n");
	}
}

struct node * findKtoLastold(struct node * start, int k) {
	struct node *curr = start, *runn, *curr0=NULL, *currk=NULL; 
	int count=0;
	while (curr != NULL) {
		runn = curr;
		while (runn != NULL) {
			//printf("COunt: %d\n",count);
			if (count == k) {
				curr0 = curr;
				currk = runn;
				printf("Curr0: %p, Currk: %p\n",curr0,currk);
				break;
			}
			else {
				count++;
				runn=runn->next;
			}
		}
		count = 0;
		curr=curr->next;
	}

	return curr0;
}

struct node * findKtoLastfastold(struct node * start, int k) {
	struct node *curr = NULL, *runn = NULL; 
	int count = 0;

	runn = start;
	while (runn!=NULL) {
		if (count == k) {
			break;
		}
		count++;
		runn= runn->next;
	}

	if (runn != NULL) {
		curr = start;
		while (curr!=NULL) {
			if (runn->next == NULL) {
				break;
			}
			curr = curr->next;
			runn = runn->next;
		}
		return curr;
	}
	else 
		return curr;
}

struct node * findKtoLast2params(struct node * curr, int k) {
	static int rearIndex = 1;
	static int count = 0;
	struct node *newcurr = NULL;

	count++;
	if (curr->next != NULL) {
		newcurr = findKtoLast2params(curr->next,k);
		if (rearIndex == k) {
			//printf("Count: %d, RearIndex: %d, Curr: %p, NewCurr: %p\n",count,rearIndex,curr,newcurr);
			return newcurr;
		}
		else {
			rearIndex++;
			if (rearIndex == count) {
				if (rearIndex == k) {
					//printf("Count: %d, RearIndex: %d, Curr: %p, NewCurr: %p\n",count,rearIndex,curr,newcurr);
					return curr;
				}
				else {	
					//printf("Count: %d, RearIndex: %d, Curr: %p, NewCurr: %p\n",count,rearIndex,curr,newcurr);
					return NULL;
				}
			}
			else {
				//printf("Count: %d, RearIndex: %d, Curr: %p, NewCurr: %p\n",count,rearIndex,curr,newcurr);
				return curr;
			}
		}
	}
	else {
		//printf("Count: %d, RearIndex: %d, Curr: %p, NewCurr: %p\n",count,rearIndex,curr,newcurr);
		return curr;
	}
}

struct node * findKtoLast(struct node *start, int k, int *index) {
	if (start == NULL) {
		return NULL;
	}

	struct node *nd = findKtoLast(start->next,k,index);
	*index=*index+1;

	if (*index == k) {
		return start;
	}

	return nd;
}

struct node * findNthNode(struct node *start, int nthNode) {
	int index = 0;
	printf("Finding %dth node:\n",nthNode);
	while (start != NULL) {
		if (index == nthNode) {
			break;
		}
		index++;
		start = start->next;
	}

	return start;
}

bool delNthNode(struct node *midNode) {
	// Delete nth node without any head pointer of linked list given
	struct node *saveNextNode;
	if (midNode == NULL || midNode->next == NULL) {
		return false;
	}
	else {
		saveNextNode = midNode->next;
		midNode->data = saveNextNode->data;
		midNode->next = saveNextNode->next;
		free(saveNextNode);
		return true;
	}
}

struct node * findNode(struct node * curr, int val) {
	while (curr!= NULL) {
		if (curr->data == val)
			break;
		curr = curr->next;
	}

	return curr;
}

struct node * sortAroundVal(struct node **head, struct node *newhead, int val) {
	printf("Sorting around value %d\n",val);
	struct node *curr = NULL, *prev = NULL;
	int count = 0;

	//newhead = newNode(val);
	struct node *newend = NULL, *saveNext = NULL;
	//newend = newhead;

	curr = *head;
	while (curr!= NULL) {
		saveNext = curr->next;
		if (curr->data == val) {
			//curr->next = NULL;
			newend = curr;
			newhead = curr;
			if (prev)
				prev->next = saveNext;
			else
				*head = saveNext;
			break;
		}
		prev = curr;
		curr = saveNext;
	}

	curr = *head;
	while (curr!= NULL) {
		saveNext = curr->next;
		if (curr->data < val) {
			curr->next = NULL;
			curr->next = newhead;
			newhead = curr;
		}
		else {
			curr->next = NULL;
			newend->next = curr;
			newend = curr;
		}
		curr = saveNext;
	}

	return newhead;
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

	//int arr[MAX_LEN] = {5,60,14,50,9,10,5,14,130,14,0,1,2,13,4,10,5,14,130,14,0,1,2,13,4};
	//int arr[MAX_LEN] = {14,14,14,14,14,14,14,14,14,14,14,14,14,14,14};
	int arr[MAX_LEN] = {13,60,14,50,9,10,5,14,130,14,0,1,2,15,13};
	//int arr[MAX_LEN] = {5,5,5,5,5,0,2,7,2,15,6,6,0,15,5};
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

	//iterateNodes(head);

	head = addNodetoFront(head,14);
	iterateNodes(head);

	int findVal = 14;
	struct node *foundNode, *newHead = NULL;

	foundNode = findNode(head,findVal);
	if (foundNode) {
		printf("Value: %d found at address: %p\n",findVal,foundNode);
		newHead = sortAroundVal(&head,newHead,findVal);
	}
	else {
		printf("Value: %d not found\n",findVal);
	}

	iterateNodes(newHead);

	iterateNodes(head);

	printf("\nFreeing Linked List old:\n");
	struct node *temp;
	while (head!=NULL) {
		temp = head;
		head=head->next;
		free(temp);
	}
	//head = NULL;     /* Mark list as empty*/

	printf("\nFreeing Linked List new:\n");
	while (newHead!=NULL) {
		temp = newHead;
		newHead=newHead->next;
		free(temp);
	}

	return 0;
}
