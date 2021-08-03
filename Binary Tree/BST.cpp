#include<bits/stdc++.h>
using namespace std;

struct TNode {
    int data;
    TNode *Left, *Right;
};

TNode* root;

class Binary_TNode {
    public:
        Binary_TNode()
        {
            root = NULL;
        }
        void insert(int);
        void Delete(int);
        void pretrav(TNode*);
        void intrav(TNode*);
        void posttrav(TNode*);

    private:
        TNode* insert2(TNode*, TNode*);
};


TNode* Binary_TNode::insert2(TNode* temp, TNode* newnode)
{
    if (temp == NULL) {
        temp = newnode;
    }
    else if (temp->data < newnode->data) {
        insert2(temp->Right, newnode);
        if (temp->Right == NULL)
            temp->Right = newnode;
    }
    else {
        insert2(temp->Left, newnode);
        if (temp->Left == NULL)
            temp->Left = newnode;
    }
    return temp;
}

// Insert Function
void Binary_TNode::insert(int n)
{
    TNode *temp = root, *newnode;
    newnode = new TNode;
    newnode->Left = NULL;
    newnode->Right = NULL;
    newnode->data = n;
    root = insert2(temp, newnode);
}

// PreOrder Traversal 
void Binary_TNode::pretrav(TNode* t = root)
{
    if (root == NULL) {
        cout << "Nothing to display";
    }
    else if (t != NULL) {
        cout << t->data << " ";
        pretrav(t->Left);
        pretrav(t->Right);
    }
}

// InOrder Traversal
void Binary_TNode::intrav(TNode* t = root)
{
    if (root == NULL) {
        cout << "Nothing to display";
    }
    else if (t != NULL) {
        intrav(t->Left);
        cout << t->data << " ";
        intrav(t->Right);
    }
}

// PostOrder Traversal
void Binary_TNode::posttrav(TNode* t = root)
{
    if (root == NULL) {
        cout << "Nothing to display";
    }
    else if (t != NULL) {
        posttrav(t->Left);
        posttrav(t->Right);
        cout << t->data << " ";
    }
}

// Delete Function
void Binary_TNode::Delete(int key)
{
    TNode *temp = root, *parent = root, *marker;
    if (temp == NULL)
        cout << "The TNode is empty" << endl;
    else {
        while (temp != NULL && temp->data != key) {
            parent = temp;
            if (temp->data < key) {
                temp = temp->Right;
            }
            else {
                temp = temp->Left;
            }
        }
    }
    marker = temp;
    if (temp == NULL)
        cout << "No node present";
    else if (temp == root) {
        if (temp->Right == NULL && temp->Left == NULL) {
            root = NULL;
        }
        else if (temp->Left == NULL) {
            root = temp->Right;
        }
        else if (temp->Right == NULL) {
            root = temp->Left;
        }
        else {
            TNode* temp1;
            temp1 = temp->Right;
            while (temp1->Left != NULL) {
                temp = temp1;
                temp1 = temp1->Left;
            }
            if (temp1 != temp->Right) {
                temp->Left = temp1->Right;
                temp1->Right = root->Right;
            }
            temp1->Left = root->Left;
            root = temp1;
        }
    }
    else {
        if (temp->Right == NULL && temp->Left == NULL) {
            if (parent->Right == temp)
                parent->Right = NULL;
            else
                parent->Left = NULL;
        }
        else if (temp->Left == NULL) {
            if (parent->Right == temp)
                parent->Right = temp->Right;
            else
                parent->Left = temp->Right;
        }
        else if (temp->Right == NULL) {
            if (parent->Right == temp)
                parent->Right = temp->Left;
            else
                parent->Left = temp->Left;
        }
        else {
            TNode* temp1;
            parent = temp;
            temp1 = temp->Right;
            while (temp1->Left != NULL) {
                parent = temp1;
                temp1 = temp1->Left;
            }
            if (temp1 != temp->Right) {
                temp->Left = temp1->Right;
                temp1->Right = parent->Right;
            }
            temp1->Left = parent->Left;
            parent = temp1;
        }
    }
    delete marker;
}
int main()
{
    Binary_TNode bt;
    
    bt.insert(10);
    bt.insert(50);
    bt.insert(15);
    bt.insert(5);
    bt.insert(1);
    bt.insert(30);
    bt.intrav();
    cout<<"\n";
    bt.Delete(15);
    bt.intrav();
    cout<<"\n";
    bt.posttrav();
    cout<<"\n";
    bt.pretrav();
    cout<<"\n";
    return 0;
}