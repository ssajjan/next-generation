//g++ -g -o tree tree.cpp
#include <fstream>
#include <iostream>
//#include <deque>
#include <queue>
#include <iomanip>
#include <sstream>
#include <string>
#include "binary_tree.h"
using namespace std;

void printLevelOrder(BinaryTree *head){

	if(head == NULL) return;

	queue<BinaryTree *> Q;
	Q.push(head);

	while(Q.empty() == false){
		BinaryTree *node = Q.front();
		cout<< node->data <<" ";
		Q.pop();

		if(node->left != NULL)
			Q.push(node->left);
		if(node->right !=NULL)
			Q.push(node->right);
	}
}

int main(){
	int array[] = {-10,0,10, 20, 30, 50, 70, 86, 89, 90, 100,671};

	BinaryTree *root = sortedArrayToBST(array,0, sizeof(array)/sizeof(int)-1);

	printLevelOrder(root);

	cout << "\nTree pretty print with level=1 and indentSpace=0\n\n";
	// Output to console
	printPretty(root, 1, 0, cout);
	cout << "\n\nTree pretty print with level=5 and indentSpace=3,\noutput to file \"tree_pretty.txt\".\n\n";
	// Create a file and output to that file
	ofstream fout("tree_pretty.txt");
	// Now print a tree that's more spread out to the file
	printPretty(root, 5, 0, fout);
	
	cout<<"preorder:";
	preorderTraversal(root);

  return 0;
}
