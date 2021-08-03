// C++ program for linked list implementation of stack
#include <bits/stdc++.h>
using namespace std;

// Node class for Stack
class StackNode {
public:
	int data;
	StackNode* next;
};
// A class to represent stack
class LinkedListStack {
public:
	StackNode* root = NULL;
    LinkedListStack()   { root = NULL ; }
    
    int isEmpty();
    void push(int data);
    int pop();
    int peek();
    StackNode* newNode(int data);


};


    // Function to create newNode for Stack
    StackNode* LinkedListStack :: newNode(int data)
    {
        StackNode* stackNode = new StackNode();
        stackNode->data = data;
        stackNode->next = NULL;
        return stackNode;
    }

    // Function to Check Stack is Empty or not
    int LinkedListStack :: isEmpty()
    {
        return !root;
    }

    //Function to push Values into the Stack 
    void LinkedListStack :: push(int data)
    {
        StackNode* stackNode = newNode(data);
        stackNode->next = root;
        root = stackNode;
        cout << data << " pushed to stack\n";
    }

    // Function to remove values form Stack
    int LinkedListStack :: pop()
    {
        if (isEmpty())
            return INT_MIN;
        StackNode* temp = root;
        root = (root)->next;
        int popped = temp->data;
        free(temp);

        return popped;
    }

    // Functin to get topmost value in Stack
    int LinkedListStack :: peek()
    {
        if (isEmpty())
            return INT_MIN;
        return root->data;
    }

// Driver code
int main()
{
    //Object of class LikedListStack
    LinkedListStack llstack;

	// StackNode* root = NULL;

	llstack.push(10);
	llstack.push(20);
	llstack.push(30);

	cout << llstack.pop() << " popped from stack\n";

	cout << "Top element is " << llstack.peek() << endl;
	
	cout<<"Elements present in stack : ";
	//print all elements in stack :
	while(!llstack.isEmpty())
	{
		// print top element in stack
		cout<<llstack.peek()<<" ";
		// remove top element in stack
		llstack.pop();
	}

	return 0;
}
