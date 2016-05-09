/*
3.3 
Imagine a (literal) stack of plates. If the stack gets too high, it migh t topple. Therefore,
in real life, we would likely start a new stack when the previous stack exceeds some
threshold. Implement a data structure SetOfStacks that mimics this. SetOf-
Stacks should be composed of several stacks and should create a new stack once
the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.
pop () should behave identically to a single stack (that is, pop () should return the
same values as it would if there were just a single stack).
FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a
specific sub-stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 10

struct stackArr{
	int count;
	int arr[MAX_LEN];
	struct stackArr *next;
};

struct stackArr * newStackArr(struct stackArr *head) {
	head = (struct stackArr *)malloc(sizeof(struct stackArr));
	if (!head) {
		printf("Failed to allocate memory for stack array\n");
	}
	else {
		for (int index = 0; index<MAX_LEN; index++) {
			head->arr[index] = 0;
		}
		head->count = 0;
		head->next = NULL;
	}
	
	return head;
}

struct stackArr * initSetofStacks(struct stackArr *head) {
	struct stackArr *head1 = NULL, *head2 = NULL, *head3 = NULL;
	head1 = newStackArr(head1);
	head2 = newStackArr(head2);
	head3 = newStackArr(head3);
	head2->next = head3;
	head1->next = head2;
	head = head1;

	return head;
}

bool push(struct stackArr *head, int val) {
	bool pushSuccess = false;
	while (head!= NULL) {
		if (head->count < MAX_LEN) {
			head->arr[head->count]  = val;
			head->count = head->count +1;
			pushSuccess = true;
			break;
		}
		else {
			head = head->next;
		}
	}

	if (!pushSuccess) {
		printf("Stack Full\n");
	}

	return pushSuccess;
}

int pop(struct stackArr *head) {
	int val;
	bool popSuccess = false;
	while (head!= NULL) {
		if (head->count > 0 && head->count < MAX_LEN) {
			head->count = head->count -1;
			val = head->arr[head->count];
			head->arr[head->count] = 0;
			popSuccess = true;
			break;
		}
		else if (head->count == MAX_LEN) {
			if (head->next == NULL || head->next->count == 0) {
				head->count = head->count -1;
				val = head->arr[head->count];
				head->arr[head->count] = 0;
				popSuccess = true;
				break;
			}
			else {
				head = head->next;
			}
		}
		else {
			break;
		}
	}

	if (!popSuccess) {
		printf("Stack Empty\n");
		return popSuccess;
	}

	return val;
}

int popAt(struct stackArr *head,int stackNum) {
	int val;
	bool popSuccess = false;
	while (head!= NULL) {
		if (stackNum == 0 && head->count > 0) {
			head->count = head->count -1;
			val = head->arr[head->count];
			head->arr[head->count] = 0;
			popSuccess = true;
			break;
		}
		else {
			head = head->next;
			stackNum = stackNum-1;
		}
	}

	if (!popSuccess) {
		printf("Stack Specified is Empty or invalid Stack Num specified\n");
		return popSuccess;
	}

	return val;
}

void printSetofStacks(struct stackArr *head) {
	while (head!= NULL) {
		printf("|%p|:",head);
		for (int index = 0; index<MAX_LEN; index++) {
			printf("%d,",head->arr[index]);
		}
		head = head->next;
	}
	printf("\n");
}

void freeSetofStacks(struct stackArr *head) {
	struct stackArr *temp = NULL;
	printf("Freeing Set of Stacks\n");
	while (head!= NULL) {
		temp = head;
		printf("|%p|:",temp);
		for (int index = 0; index<MAX_LEN; index++) {
			temp->arr[index] = 0;
			printf("%d,",temp->arr[index]);
		}
		head = head->next;
		free(temp);
	}
	printf("\n");
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

	struct stackArr *head = NULL;
	head = initSetofStacks(head);
	push(head,0);
	push(head,1);
	push(head,2);
	push(head,3);
	push(head,4);
	push(head,5);
	push(head,6);
	push(head,7);
	push(head,8);
	push(head,9);

	push(head,10);
	push(head,11);
	push(head,12);
	push(head,13);
	push(head,14);
	push(head,15);
	push(head,16);
	push(head,17);
	push(head,18);
	push(head,19);

	push(head,20);
	push(head,21);
	push(head,22);
	push(head,23);
	push(head,24);
	push(head,25);
	push(head,26);
	push(head,27);
	push(head,28);
	push(head,29);

	printf("Popped value: %d\n",pop(head));
	printf("Popped value: %d\n",popAt(head,1));
	printf("Popped value: %d\n",popAt(head,1));
	printf("Popped value: %d\n",popAt(head,1));
	printf("Popped value: %d\n",popAt(head,1));
	printf("Popped value: %d\n",popAt(head,1));
	printf("Popped value: %d\n",popAt(head,1));
	printf("Popped value: %d\n",popAt(head,1));
	printf("Popped value: %d\n",popAt(head,1));
	printf("Popped value: %d\n",popAt(head,1));
	push(head,100);
	push(head,100);
	push(head,100);
	push(head,100);
	push(head,100);
	push(head,100);
	push(head,100);
	push(head,100);
	push(head,100);
	push(head,100);
	push(head,100);
	//printf("Popped value: %d\n",popAt(head,1));

	printSetofStacks(head);

	freeSetofStacks(head);
	return 0;
}
