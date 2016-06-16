#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
  void * data;
  struct stack * next;
} Node;

void raise_exception_if_empty(Node * head);
bool isEmpty(Node * head);
int peek(Node * head);
Node pop(Node * head);
Node push(Node * head, int * newData);

int main(){
  Node myStack;

  int n1 = 3;
  int n2 = 2;
  int n3 = 1;
  myStack = push(&myStack, &n1);
  myStack = push(&myStack, &n2);
  myStack = push(&myStack, &n3);

  //just some demonstration of use
  printf("Peeking... %d\n", peek(&myStack));
  myStack = pop(&myStack);
  printf("Popped: %d\n", *(int *)myStack.data);
  printf("Empty?: %d\n", isEmpty(&myStack));
  myStack = pop(&myStack);
  printf("Popped: %d\n", *(int *)myStack.data);
  printf("Peeking... %d\n", peek(&myStack));
  myStack = pop(&myStack);
  printf("Popped: %d\n", *(int *)myStack.data);
  printf("Empty?: %d\n", isEmpty(&myStack));

  //either should raise error
  //peek(myStack);
  //pop(&myStack);

  exit(EXIT_SUCCESS);
}

void raise_exception_if_empty(Node * head){
  if(isEmpty(head)) {
    fprintf(stderr, "Stack is empty! Aborting...\n");
    exit(EXIT_FAILURE);
  }
}

bool isEmpty(Node * head){
  return !head;
}

int peek(Node * head){
  raise_exception_if_empty(head);
  int * data = head->data;
  return *data; 
}

Node pop(Node * head){
  raise_exception_if_empty(head);
  Node top = *head;
  return *top.next;
}

Node push(Node * head, int * newData){
  Node * newNode = malloc(sizeof(Node));
  raise_exception_if_empty(newNode);
  newNode->data = newData;
  newNode->next = head;
  return *newNode;
}
