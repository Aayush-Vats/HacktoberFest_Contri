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

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);	
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		inorder(root->right);
		cout<<root->key<<" ";
		
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		inorder(root->left);
		inorder(root->right);
	
	}
}



int main()
{
	int x;
	cout<<"enter value";
	cin>>x;
	node *root=new node(x);
	
	root->left=new node(20);
	root->right=new node(30);
	root->left->left=new node(40);
	root->left->right=new node(50);
	root->right->right=new node(70);
	root->right->left=new node(60);
	inorder(root);
	cout<<" ";
	preorder(root);
	cout<<" ";
	postorder(root);
	cout<<" ";
}











