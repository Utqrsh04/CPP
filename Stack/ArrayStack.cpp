
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack

	// Constructor
    Stack() { top = -1; }

	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

// function to push data into Stack
bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

// function to remove data from Stack
int Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}

// This function returns the topmost value of Stack
int Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

// Check is stack is Empty or Not
bool Stack::isEmpty()
{
	return (top < 0);
}

// Driver program to test above functions
int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	cout << s.pop() << " Popped from stack\n";
	//print all elements in stack :
	cout<<"Elements present in stack : ";
	while(!s.isEmpty())
	{
		// print top element in stack
		cout<<s.peek()<<" ";
		// remove top element in stack
		s.pop();
	}

	return 0;
}
