/*
3.7
An animal shelter holds only dogs and cats, and operates on a strictly "first in, first
out" basis. People must adopt either the "oldest" (based on arrival time) of all animals
at the shelter, or they can select whether they would prefer a dog or a cat (and will
receive the oldest animal of that type). They cannot select which specific animal they
would like. Create the data structures to maintain this system and implement opera-
tions such as enqueue, dequeueAny, dequeueDog and dequeueCat. You may
use the built-in L inkedL ist data structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 10

/* Linked List Implementation*/
struct node {
        int data; /* payload */
        struct node *next;
};

struct node *head = NULL;
struct node *end = NULL;

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

bool enqueue(int val) {
	if (end == NULL && head == NULL) {
		head = newNode(val);
		end = head;
	}
	else {
		end = appendNode(end,val);
	}

	if (head != NULL) 
		return true;
	else
		return false;
}

int dequeue(void) {
	struct node *temp = NULL;
	int val;

	if (end == NULL && head == NULL) {
		printf("Queue empty\n");
		return false;
	}
	else {
		val = head->data;
		if (head != end) {
			temp = head;
			head = head->next;
			free(temp);
		}
		else {
			temp = head;
			free(temp);

			head = NULL;
			end = NULL;
		}
		return val;
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

        int num[MAX_LEN] = {1,2,3,4,5,6,7,8,9,10};

	enqueue(num[0]);
	enqueue(num[1]);
	enqueue(num[2]);

        iterateNodes(head);
	dequeue();

        iterateNodes(head);
	enqueue(num[3]);
	enqueue(num[4]);

        iterateNodes(head);
	dequeue();
	dequeue();
	dequeue();
	dequeue();

        iterateNodes(head);
	enqueue(num[5]);
	enqueue(num[6]);
        iterateNodes(head);

        printf("\nFreeing Linked List:\n");
        struct node *temp;
        while (head != NULL) {
                printf("Value: %d, Address: %p, Next Address: %p\n",head->data,head,head->next);
                temp = head;
                head = head->next;
                free(temp);
        }

	return 0;
}
