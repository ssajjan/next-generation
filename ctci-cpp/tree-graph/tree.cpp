// g++ -o tree.exe  tree.cpp 
#include <fstream>
#include <iostream>
#include <deque>
#include<queue>
#include <iomanip>
#include <sstream>
#include <string>
#include "binary_tree_pretty_print.h"
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
  BinaryTree *root = new BinaryTree(30);
  root->left = new BinaryTree(20);
  root->right = new BinaryTree(40);
  root->left->left = new BinaryTree(10);
  root->left->right = new BinaryTree(25);
  root->right->left = new BinaryTree(35);
  root->right->right = new BinaryTree(50);
  root->left->left->left = new BinaryTree(5);
  root->left->left->right = new BinaryTree(15);
  root->left->right->right = new BinaryTree(28);
  root->right->right->left = new BinaryTree(41);

	printLevelOrder(root);

  cout << "Tree pretty print with level=1 and indentSpace=0\n\n";
  // Output to console
  printPretty(root, 1, 0, cout);

  cout << "\n\nTree pretty print with level=5 and indentSpace=3,\noutput to file \"tree_pretty.txt\".\n\n";
  // Create a file and output to that file
  ofstream fout("tree_pretty.txt");
  // Now print a tree that's more spread out to the file
  printPretty(root, 5, 0, fout);

  return 0;
}

