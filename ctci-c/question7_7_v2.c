/*
7.7
Design an algorithm to find the kth number such that the only prime factors are 3,
5, and 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 10

/* Linked List Implementation*/
struct node {
	int data;
        struct node *next;
};

struct node *qFront = NULL;
struct node *qRear = NULL;

struct node *newNode(int num) {
        struct node *newNode =(struct node *) malloc(sizeof(struct node));
        if (newNode != NULL) {
		newNode->data = num;
                newNode->next = NULL;
        }
        return newNode;
}

struct node *appendNode(struct node *rear, int num) {
        struct node *newRear = newNode(num);
        if (newRear != NULL && rear != NULL) {
                rear->next = newRear;
        }
        return newRear;
}

void iterateNodes(struct node *front) {
        printf("\nIterating over Linked List:\n");
        for (struct node *p = front; p!=NULL;p=p->next) {
                printf("Data: %d, Address: %p, Next Address: %p\n",p->data,p,p->next);
        }
        printf("\n");
}

void enqueue(int num) {
	if (qRear == NULL && qFront == NULL) {
		qFront = newNode(num);
		qRear = qFront;
	}
	else {
		qRear = appendNode(qRear,num);
	}
}

int dequeue() {
	struct node *temp = NULL;
	int val;

	if (qRear == NULL && qFront == NULL) {
		printf("Queue empty\n");
		return 0;
	}
	else {
		if (qFront != qRear) {
			temp = qFront;
			val = qFront->data;
			qFront = qFront->next;
			free(temp);
		}
		else {
			temp = qFront;
			val = qFront->data;
			free(temp);

			qFront = NULL;
			qFront = NULL;
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

	enqueue(1);
	enqueue(2);
	enqueue(3);

	iterateNodes(qFront);

	dequeue();
	iterateNodes(qFront);

        printf("\nFreeing Linked List:\n");
        struct node *temp;
        while (qFront != NULL) {
                printf("Data: %d, Address: %p, Next Address: %p\n",qFront->data,qFront,qFront->next);
                temp = qFront;
                qFront = qFront->next;
                free(temp);
        }

	return 0;
}
