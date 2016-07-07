//g++ -g  main_binarytree.cpp
#include "binarytree.h"
#include "traversal_binarytree.h"
#include "view_binarytree.h"

int main(){
	int array[] = {10, 20, 30, 50, 70, 86, 89, 90, 100,671};

	BinaryTree *root = sortedArrayToBST(array,0, sizeof(array)/sizeof(int)-1);

	cout << "\nTree pretty print with level=1 and indentSpace=0\n\n";
	printPretty(root, 1, 0, cout);

	// Create a file and output to that file
//	cout << "\n\nTree pretty print with level=5 and indentSpace=3,\noutput to file \"tree_pretty.txt\".\n\n";
//	ofstream fout("pretty.txt");
	// Now print a tree that's more spread out to the file
//	printPretty(root, 3, 0, cout);
	
	preorderIterativeTraversal(root);
	inorderIterativeTraversal(root);
	postorderIterativeTraversal_2stack(root);
	printLevelOrder(root);

	cout<<endl<<endl<<"Left view"<<endl;
	leftView(root);
	cout<<endl<<endl<<"right view"<<endl;
	rightView(root);


	cout<<endl<<endl<<"max height= "<<maxHeight(root)<<endl;
	cout<<endl<<endl<<"min height= "<<minHeight(root)<<endl;
	cout<<endl<<endl<<"min depth= "<<minDepth(root)<<endl;
	return 0;
}
