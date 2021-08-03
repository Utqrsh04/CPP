#include<bits/stdc++.h>
using namespace std;

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

int Height(BstNode* root)   {

    if(root==NULL)
        return -1;

    int left = Height(root-left);    
    int right = Height(root-right);    

    return max(left , right) +1 ;
}