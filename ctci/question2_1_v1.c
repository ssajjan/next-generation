/*
2.1
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 15

struct node {
	int data; /* payload */
	int count;
	struct node *next;
};

struct node * nalloc(int data) {
	struct node *newNode =(struct node *) malloc(sizeof(struct node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->count = 0;
		newNode->next = NULL;

	}

	return newNode;
}

struct node * append(struct node *end, int data) {
	struct node *newEnd = nalloc(data);
	if (newEnd != NULL) {
		end->next = newEnd;
	}

	return newEnd;
}

void iterate(struct node *start) {
	printf("Iterating over Linked List:\n");
	for (struct node *p = start; p!=NULL;p=p->next) {
		printf("Value: %d, Count: %d, Address: %p, Next Address: %p\n",p->data,p->count,p,p->next);
	}
}

// Removes single instance of the value
struct node * deldups(struct node *start) {
	struct node *temp,*prev=NULL,*p=start;

	while (p!=NULL) {
		if (p->count > 0){
			printf("Removing Value: %d, %d occurence\n",p->data,p->count);
			temp = p;
			if (prev !=  NULL) {
				prev->next = p->next;
			}
			else {
				start = p->next;
			}
			free(temp);
		}
		else {
			prev = p;
		}
		p=p->next;
	}
	return start;
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
	//int arr[len] = {5,5,5,5,5,0,2,7,9,8,6,5,20,15,15};
	int arr[len] = {5,5,5,5,5,5,5,15,15,5,5,5,5,5,5};

	struct node *head = NULL; /* beginning */
	struct node *end = NULL; /* end */

	head = nalloc(arr[0]);

	//printf("Start Pointer of Linked List is: %p\n",head);
	//printf("Start Data of Linked List is: %d\n",head->data);

	end = nalloc(arr[1]);
	head->next = end;
	//printf("Initial End Pointer of Linked List is: %p\n",end);
	//printf("Initial End Data of Linked List is: %d\n",end->data);

	for (int num = 2; num<len; num++) {
		end = append(end,arr[num]);
		//printf("Appended Pointer of Linked List is: %p\n",end);
		//printf("Appended Data of Linked List is: %d\n",end->data);
	}

	iterate(head);

	for (struct node *p = head; p!= NULL; p=p->next) {
		for (struct node *q = p->next; q!= NULL; q=q->next) {
			if (p->data == q->data) {
				q->count++;
			}
		}
	}

	iterate(head);

	head = deldups(head);

	iterate(head);

	printf("Freeing Linked List:\n");
	struct node *temp;
	while (head!=NULL) {
		temp = head;
		head=head->next;
		free(temp);
	}

	//head = NULL;     /* Mark list as empty*/

	return 0;
}
