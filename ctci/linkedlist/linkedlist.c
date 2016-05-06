#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int val;
  struct list * next;
} Node;

void printList(Node * curr);

void push(Node ** headRef, int newValue);

void removeDups(Node * curr);

Node * kth_to_last_el(Node * curr, int k);

void deleteNode(Node * curr);

void partition(Node ** head, int val);

void main(){
  Node * head = (Node *)malloc(sizeof(Node));
  head->val = 5;
  head->next = NULL;
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);

  printList(head);

  partition(&head, 4);

  printList(head);
}

void partition(Node ** head, int val){
  Node * runner = *head;
  while(runner->next && runner->next->val){
    if(runner->next->val < val){
      push(head, runner->next->val);
      deleteNode(runner->next);
    } else {
      runner = runner->next; 
    }
  }
}

void deleteNode(Node * curr){
  Node * destroy = curr->next;
  curr->val = destroy->val;
  curr->next = destroy->next; 
  free(destroy);
}

Node * kth_to_last_el(Node * curr, int k){
  int i;
  Node * runner = (Node *)malloc(sizeof(Node));
  for(;;){
    runner = curr;
    for(i = 0; i < k; i++) runner = runner->next;
    if(!runner) return curr;
    curr = curr->next;
  }
}

void push(Node ** headRef, int newValue){
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->val = newValue;
  newNode->next = *headRef;
  *headRef = newNode;
}

void printList(Node * curr){
  if(!curr){
    printf("\n");
    return;
  }
  printf("%d ->", curr->val);
  printList(curr->next);
}

void removeDups(Node * curr){
  Node * runner = curr;
  Node * dup = (Node *)malloc(sizeof(Node *));
  while(runner && runner->next){
    if(runner->next->val == curr->val){
      dup = runner->next;
      runner->next = runner->next->next; 
      free(dup);
    } else {
      runner = runner->next;
    }
  }
  if(!curr->next) return;
  removeDups(curr->next);
}
