/*
3.1 
How would you design a stack which, in addition to push and pop, also has a
function min which returns the minimum element? Push, pop and min should all
operate in 0(1) time.
*/

/*
Here we define a new min data variable inside a struct so that each node of the stack linked list
remembers what the min is when it was pushed onto stack. For ex, if we pop out value == min and then
move to next top value in the stack, stack remembering that stage when it was pushed and using calculated min 
then will straightaway give min stored in its variable. 
Extra space used for new variable min and then storing it for all n elements of the stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
	int data;
	int min;
	struct node *next;
};

struct node * newNode(int val) {
	struct node *new = NULL;
	new = (struct node *)malloc(sizeof(struct node));
	if (new) {
		new->data = val;
		new->next = NULL;
		new->min = 0;
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
	int minVal;
	curr = newNode(val);
	if ((*head) == NULL) {
		curr->next = NULL;
		curr->min = curr->data;
		(*head) = curr;
	}
	else {
		minVal = (*head)->min;
		if (val <= minVal) {
			curr->min = curr->data;
		}
		else {
			curr->min = minVal;
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
		return head->min;
	}
}

void printStack(struct node *head) {
	printf("Printing stack: ");

	if (head != NULL) {
		printf("\n");
		while (head != NULL) {
			printf("Value: %d, Curr: %p, Next: %p, Min: %d\n",head->data,head,head->next,head->min);
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
			printf("Value: %d, Curr: %p, Next: %p, Min: %d\n",temp->data,temp,temp->next,temp->min);
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

	pushStack(&stack, 30);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 20);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 30);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 20);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 3);
	printf("Min: %d\n",minStack(stack));
	printStack(stack);
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	popStack(&stack);
	printf("Min: %d\n",minStack(stack));
	printStack(stack);
	pushStack(&stack, 10);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 1);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 1);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 1);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 1);
	printf("Min: %d\n",minStack(stack));
	pushStack(&stack, 1);
	printf("Min: %d\n",minStack(stack));
	printStack(stack);
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
