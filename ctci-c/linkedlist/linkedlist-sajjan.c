//gcc -o linkedlist-sajjan linkedlist-sajjan.c -std=c99

#include<stdio.h> //printf, scanf
#include<stdlib.h> //malloc, free,alloc
//#include<time.h>
//#include<stdint.h> //unsigned int

typedef struct LinkListNode{
	int data;
	struct LinkListNode *next;
}Node_t;



void Build_list(Node_t **headRef,int size){
	for( int i =0;i<size;i++){
		Node_t *node = (Node_t *)malloc(sizeof(Node_t));
		node->data = i;
#if 0 //STACK, -->  push to beginning of list on every increment
		node->next = *headRef;
		*headRef = node;
#else //QUEUE --> push to end  of list on every increment
		node->next = NULL;
		*headRef= node;
		headRef = &node->next;
#endif
	}
}



Node_t* push(Node_t **head, int data)
{
	Node_t* newnode = malloc(sizeof(Node_t));
	newnode->data=data;
	newnode->next=*head;
	//vvvvvvvvvvvvvvvv
	*head = newnode; //you say that now the new node is the head.
	return newnode;
}


Node_t* Pop(Node_t **headRef){
	Node_t *temp = *headRef;
	*headRef = (*headRef)->next;

	temp->next = NULL;
	return temp;
}




void print_list(Node_t *head){
	printf("List: ");
	while(head!=NULL){
		printf("[%p]%4d -->",head, head->data);
		head = head->next;
	}
	printf("NULL\n");
}
//interview-question: Reverse Linked List using reference pointer
void reverseList(Node_t **head){

	Node_t *prev = NULL, *cur=*head, *nxt=NULL;
	while(cur!=NULL){
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	*head = prev;
}

//interview-question: Remove node in linked List using reference pointer
Node_t* RemoveNode_notemp(Node_t **headRef, int searchvalue){
	while(*headRef && (*headRef)->data!=searchvalue){
		headRef = &(*headRef)->next;
	}

	if(*headRef == NULL)
		return NULL;
#if 1
	*headRef = (*headRef)->next;
	return NULL;
#else  // return the node
	Node_t *deletedNode = *headRef;
	*headRef = deletedNode->next;
	deletedNode->next = NULL;

	return deletedNode;
#endif
}

//interview-question: Insert sorted order
void insert_sorted_order(Node_t **head, int newData){
	Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
	newNode->data = newData;
	newNode->next = NULL;

	if (*head == NULL || (*head)->data > newData){
		newNode->next = *head;
		*head = newNode;
	}else
	{
	        Node_t* cur = *head;
	        while ((cur->next != NULL) && (cur->next->data < newData)){
			cur = cur->next;
		}
		newNode->next = cur->next;
        	cur->next = newNode;
	}
}

//Adding Linked list:x1




int main(int argc, char** argv){
	Node_t *list1 = NULL, *list2=NULL;
	Build_list(&list1,5);
	print_list(list1);

	Node_t *topNode = Pop(&list1);
	printf("\n poped list1 list \n");
	print_list(list1);
	print_list(topNode);
	
	printf("\n removal of nodes \n");
	reverseList(&list1);print_list(list1);
	Node_t *removedNode = RemoveNode_notemp(&list1,3);
	print_list(list1);
	print_list(removedNode);

	RemoveNode_notemp(&list1,1);
	print_list(list1);
	RemoveNode_notemp(&list1,2);
	print_list(list1);
	RemoveNode_notemp(&list1,4);
	print_list(list1);

	printf("\n insertion of nodes \n");
	insert_sorted_order(&list1, 0);
	print_list(list1);
	insert_sorted_order(&list1, 10);
	print_list(list1);
	insert_sorted_order(&list1, 8);
	print_list(list1);
	insert_sorted_order(&list1, 9);
	print_list(list1);

	getchar();

	return 0;
}
