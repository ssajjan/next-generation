#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "err.h"

struct QueueNode {
  void * data;
  struct QueueNode * next;
};

struct Queue {
  struct QueueNode * head;
  struct QueueNode * tail;
};

struct QueueNode * newQueueNode(void * data);
struct Queue * newQueue(void);
void enQueue(struct Queue * queue, void * data);
void * deQueue(struct Queue * queue);
bool queueEmpty(struct Queue * queue);
void freeQueue(struct Queue * queue);

bool queueEmpty(struct Queue * queue){
  return queue->head ? false : true;
}

struct QueueNode * newQueueNode(void * data){
  struct QueueNode * newNode = malloc(sizeof(struct QueueNode));
  if(!newNode)
    err("failed to allocate memory, abort\n");
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void enQueue(struct Queue * queue, void * data){
  struct QueueNode * newNode = newQueueNode(data);

  if(!queue->tail){
    queue->head = newNode;
  } else {
    queue->tail->next = newNode;
  }

  queue->tail = newNode;
}

void * deQueue(struct Queue * queue){
  struct QueueNode * head = queue->head;
  void * data;

  if(head){
    data = head->data;
    queue->head = head->next; 
  }
free(head); return data; }

struct Queue * newQueue(void){
  struct Queue * queue = malloc(sizeof(struct Queue));
  if(!queue)
    err("failed to allocate memory, abort\n");

  queue->head = malloc(sizeof(struct QueueNode));
  queue->tail = malloc(sizeof(struct QueueNode));
  if(!queue->head || !queue->tail)
    err("failed to allocate memory, abort\n");

  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

void freeQueue(struct Queue * queue){
  while(queue->head){
    deQueue(queue);
  }
  free(queue);

  printf("\nQueue successfully freed\n");
}

