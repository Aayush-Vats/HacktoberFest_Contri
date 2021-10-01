#include<iostream>
using namespace std;

struct node
{
    int key;
    struct node *left;
    struct node *right;
    node(int k)
    {
    key=k;
    left=right=NULL;
    }
};

int height(node *root)
{
    if(root==NULL)
        return 0;
    else
        return(1+max(height(root->right),height(root->left)));
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->right=new node(40);
    root->right->right->left=new node(50);
    root->right->right->left->right=new node(60);
    cout<<"height of the tree: "<<height(root);
}