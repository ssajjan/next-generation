/*
3.1 
How would you design a stack which, in addition to push and pop, also has a
function min which returns the minimum element? Push, pop and min should all
operate in 0(1) time.
*/

/*
Combination of using a new stack for min as well as using a min pointer for each node.
Stack is pushed when value<= min and min pointers of each node are edited only when its the new min,
referring to the red arrows flowing through the linked list.
Extra space used in new stack as well as in nextmin pointer in each node, but used judiciously with nextmin 
updated only for new min (or to traverse through min list) and min pushed only when val<=min.
"Also gives two ways of traversing the list, one through next and other through nextmin"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *next;
	struct node *nextmin;
};

struct node * min = NULL;

struct node * newNode(int val) {
	struct node *new = NULL;
	new = (struct node *)malloc(sizeof(struct node));
	if (new) {
		new->data = val;
		new->next = NULL;
		new->nextmin = NULL;
	}
	else {
		printf("Error in allocating memory for new node");
	}

	return new;
}

int topStack(struct node *head) {
	printf("Top of stack: \n");
	if (head) {
		return head->data;
	}
	else {
		printf("Stack empty\n");
		return false;
	}
}

bool pushStack(struct node **head, int val) {
	printf("Pushing value: %d in stack: \n",val);
	struct node *curr = NULL;
	curr = newNode(val);
	if ((*head) == NULL) {
		curr->next = NULL;
		(*head) = curr;
		min = curr;
	}
	else {
		if (val <= min->data) {
			curr->nextmin = min;
			min = curr;
		}
		curr->next = (*head);
		(*head) = curr;
	}
	return true;
}

int popStack(struct node **head) {
	printf("Popping stack: \n");
	int val;
	struct node *temp = NULL;

	if ((*head) == NULL) {
		printf("Stack empty\n");
		return false;
	}
	else {
		temp = (*head);
		val = temp->data;
		if (val == min->data) {
			min = min->nextmin;
		}
		(*head) = (*head)->next;
		free(temp);
		return val;
	}
}

int minStack(struct node *head) {
	printf("Finding min in stack: ");
	if (head == NULL) {
		printf("Stack empty\n");
		return false;
	}
	else {
		return min->data;
	}
}

void printStack(struct node *head) {
	printf("Printing stack: ");

	if (head != NULL) {
		printf("\n");
		while (head != NULL) {
			printf("Value: %d, Curr: %p, Next: %p, Min: %p\n",head->data,head,head->next,head->nextmin);
			head = head->next;
		}
	}
	else {
		printf("Stack empty\n");
	}
}

void freeStack(struct node *head) {
	struct node *temp;
	printf("Freeing stack: ");

	if (head != NULL) {
		printf("\n");
		while (head != NULL) {
			temp = head;
			printf("Value: %d, Curr: %p, Next: %p, Min: %p\n",temp->data,temp,temp->next,temp->nextmin);
			head = head->next;
			free(temp);
		}
	}
	else {
		printf("Stack empty\n");
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
	struct node *stack = NULL;

	pushStack(&stack, 10);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 2);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 15);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 25);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 13);
	printf("Min: %d\n",minStack(stack));
	printStack(stack);
	printStack(min);
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	printStack(stack);
	printStack(min);
	pushStack(&stack, 19);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 12);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 18);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 11);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 10);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 2);
	printf("Min: %d\n",minStack(stack));
	printStack(stack);
	printStack(min);
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	printStack(stack);

	freeStack(stack);
	return 0;
}
