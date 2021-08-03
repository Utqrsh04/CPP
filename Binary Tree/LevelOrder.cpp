#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};


void printLevelOrder(Node *root)
{
	// Base Case
	if (root == NULL) return;

	// Create an empty queue for level order traversal
	queue<Node *> q;

	// Enqueue Root and initialize height
	q.push(root);
	while (q.empty() == false)
	{   
		// Print front of queue and remove it from queue
		Node *node = q.front();
		cout << node->data << " ";
		q.pop();

		/* Enqueue left child */
		if (node->left != NULL)
			q.push(node->left);

		/*Enqueue right child */
		if (node->right != NULL)
			q.push(node->right);
	}

}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	Node *root = newNode(1);
	root->left = newNode(4);
	root->right = newNode(3);
	root->left->left = newNode(10);
	root->left->right = newNode(50);
	root->right->left = newNode(20);
	root->right->right = newNode(30);
    /*           
                      1
                     / \   
                    /   \    
                   /     \
                  /       \            
                 4         3
                / \       / \
               /   \     /   \
              10   50   20    30
    
    */
	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
    cout<<"\n";
	return 0;
}
