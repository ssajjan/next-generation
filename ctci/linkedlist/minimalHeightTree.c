#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct TreeNode {
  int data;
  struct TreeNode * left;
  struct TreeNode * right;
};

struct TreeNode * minimalHeightSearchTree(int * sortedNums, int first, int last);

void displayTree(struct TreeNode * head){
  struct Queue * q1 = newQueue();
  struct Queue * q2 = newQueue();
  struct TreeNode * tmp = head; 
  enQueue(q1, head);
  int count = 1;

  while(!queueEmpty(q1)){
    printf("level %d: ", count);
    tmp = (struct TreeNode *)deQueue(q1);
    printf(" %d ", tmp->data);

    while(tmp->left || tmp->right){
      enQueue(q2, tmp->left);
      enQueue(q2, tmp->right);
      tmp = (struct TreeNode *)deQueue(q1);
    }

    while(!queueEmpty(q2))
      enQueue(q1, (struct TreeNode *)deQueue(q2));

    printf("\n");
    count += 1;
  }

  freeQueue(q1);
  freeQueue(q2);
}

int main(){
  int sortedNums[11] = {0, 1, 4, 6, 7, 9, 12, 25, 32, 33, 34};
  int length = 11; 

  struct TreeNode * head = minimalHeightSearchTree(sortedNums, 0, length);
  struct TreeNode * left = head->left;
  struct TreeNode * right = head->right;

  displayTree(head);

  exit(EXIT_SUCCESS);
}

struct TreeNode * minimalHeightSearchTree(int * searchNums, int first, int last){
  int center = (first + last)/2; 
  struct TreeNode * rootNode = malloc(sizeof(struct TreeNode));
  if((last - first) == 1){
    struct TreeNode * right = malloc(sizeof(struct TreeNode));
    right->data = searchNums[first];
    rootNode->right = right;
    return rootNode;
  }
  rootNode->data = searchNums[center];
  printf("%d ", searchNums[center]);
  rootNode->right = minimalHeightSearchTree(searchNums, first, center);
  rootNode->left = minimalHeightSearchTree(searchNums, center, last);
  return rootNode;
}
