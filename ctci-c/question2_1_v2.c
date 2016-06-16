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
	printf("Iterating over Linked List:\n");
	for (struct node *p = start; p!=NULL;p=p->next) {
		printf("Value: %d, Address: %p, Next Address: %p\n",p->data,p,p->next);
	}
}

// Removes single instance of the value
struct node * delNode(struct node *start,struct node *cursor) {
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
	int arr[len] = {3,5,5,5,5,0,2,7,2,8,6,6,0,15,15};
	//int arr[len] = {5,5,5,5,5,5,5,15,15,5,5,5,5,5,5};
	//int arr[len] = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};

	struct node *head = NULL; /* beginning */
	struct node *end = NULL; /* end */

	head = newNode(arr[0]);

	//printf("Start Pointer of Linked List is: %p\n",head);
	//printf("Start Data of Linked List is: %d\n",head->data);

	end = newNode(arr[1]);
	head->next = end;
	//printf("Initial End Pointer of Linked List is: %p\n",end);
	//printf("Initial End Data of Linked List is: %d\n",end->data);

	for (int num = 2; num<len; num++) {
		end = appendNode(end,arr[num]);
		//printf("Appended Pointer of Linked List is: %p\n",end);
		//printf("Appended Data of Linked List is: %d\n",end->data);
	}

	iterateNodes(head);

	for (struct  node *p = head; p!= NULL; p=p->next) {
		for (struct  node *q = p->next; q!= NULL; q=q->next) {
			if (p->data == q->data) {
				head = delNode(head,q);
			}
		}
	}

	iterateNodes(head);

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
