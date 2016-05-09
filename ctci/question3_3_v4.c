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
			if (head->next != NULL) {
				head = head->next;
			}
			else {
				head->next = newStackArr(head->next);
			}
		}
	}

	if (!pushSuccess) {
		printf("Stack Full. Failed to allocate new stack\n");
	}

	return pushSuccess;
}

int pop(struct stackArr *head) {
	struct stackArr *prev = NULL;
	int val;
	bool popSuccess = false;
	while (head!= NULL) {
		if (head->count > 0 && head->count < MAX_LEN) {
			head->count = head->count -1;
			val = head->arr[head->count];
			head->arr[head->count] = 0;
			popSuccess = true;
			if (head->count == 0) {
				struct stackArr *temp = NULL;
				temp = head;
				if (prev) {
					prev->next = NULL;
					free(temp);
				}
			}
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
				prev = head;
				head = head->next;
			}
		}
		else {
			popSuccess = false;
			break;
		}
	}

	if (!popSuccess) {
		printf("Stack Empty\n");
		return popSuccess;
	}

	return val;
}

void adjust(struct stackArr *head) {
	struct stackArr *curr = NULL;
	struct stackArr *runn = NULL;
	struct stackArr *prev = NULL;
	struct stackArr *temp = NULL;
	int currindex;
	int runnindex;
	curr = head;
	while (curr!= NULL) {
		if (curr->count < MAX_LEN) {
			runn = curr->next;
			if (runn) {
				currindex = 0;
				while (curr->count < MAX_LEN) {
					if (currindex < runn->count) {
						curr->arr[curr->count] = runn->arr[currindex++];
						curr->count = curr->count + 1;
					}
					else {
						break;
					}
				}
				runnindex = 0;
				while (currindex < runn->count) {
					runn->arr[runnindex++] = runn->arr[currindex++];
				}
				runn->count = runnindex;
				while (runnindex<MAX_LEN) {
					runn->arr[runnindex++] = 0;
				}
			}
			else {
				if (curr->count == 0) {
					temp = curr;
					prev->next = NULL;
					free(temp);
				}
				break;
			}
		}
		prev = curr;
		curr = curr->next;
	}
}

int popAt(struct stackArr *head, int stackNum) {
	struct stackArr *curr = head;
	int val,num = stackNum;
	bool popSuccess = false;

	while (curr != NULL) {
		if (stackNum == 0) {
			if (curr->count > 0) {
				curr->count = curr->count -1;
				val = curr->arr[curr->count];
				curr->arr[curr->count] = 0;
				popSuccess = true;
				break;
			}
			else {
				break;
			}
		}
		else {
			stackNum = stackNum-1;
			curr = curr->next;
		}
	}

	if (!popSuccess) {
		printf("Sub Stack: %d to pop is already empty\n",num);
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
	printf("\n\n");
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
	head = newStackArr(head);
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

	push(head,30);
	push(head,31);
	push(head,32);
	push(head,33);
	push(head,34);
	push(head,35);
	push(head,36);
	push(head,37);
	push(head,38);
	push(head,39);

	pop(head);
	pop(head);
	pop(head);
	pop(head);
	pop(head);
	pop(head);
	printSetofStacks(head);

	popAt(head,1);
	popAt(head,1);
	popAt(head,1);
	popAt(head,1);
	popAt(head,1);
	popAt(head,1);
	printSetofStacks(head);

	adjust(head);
	printSetofStacks(head);

	popAt(head,1);
	popAt(head,1);
	popAt(head,1);
	printSetofStacks(head);

	adjust(head);
	printSetofStacks(head);

	pop(head);
	pop(head);
	push(head,100);
	printSetofStacks(head);

	freeSetofStacks(head);
	return 0;
}
