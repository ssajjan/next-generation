//gcc -o tree tree.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree {
  int data;
  struct tree *left, *right;
}Node_t;


void print_preorder(Node_t *node){
	if(node){
		printf("%d ",node->data);
		print_preorder(node->left);
		print_preorder(node->right);
	}	
}

void print_inorder(Node_t *node){
	if(node){
		print_inorder(node->left);
		printf("%d ",node->data);
		print_inorder(node->right);
	}	
}

void print_postorder(Node_t *node){
	if(node){
		print_postorder(node->left);
		print_postorder(node->right);
		printf("%d ",node->data);
	}	
}

void print_levelorder(Node_t * head){
	return;
}
 
Node_t* createNode(int data){
	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(Node_t **tree, int data){
	Node_t *temp=NULL;
	
	if(!(*tree)){
		temp = (Node_t *)malloc(sizeof(Node_t));
		temp->data=data;
		temp->left=temp->right=NULL;
		
		*tree = temp;
	}else{
		
		if((*tree)->data > data)
			insert(&(*tree)->left,data);
		else if((*tree)->data < data)
			insert(&(*tree)->right,data);
	}
}


int main(){

	Node_t *head = createNode(10);

	head->left = createNode(8);
	head->left->left = createNode(6);
	head->left->right = createNode(9);
	head->right = createNode(11);
	head->right->right = createNode(14);
	head->right->right->right = createNode(17);
	insert(&head, 3);
	print_inorder(head);

	exit(EXIT_SUCCESS);
}
