#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *leftnode;
	struct tree *rightnode;
};

struct tree *root=NULL;
void insert(int value)
{
	struct tree *tnode=(struct tree *)malloc(sizeof(struct tree));
	struct tree *curr=NULL;
	struct tree *parent=NULL;
	tnode->data=value;
	tnode->leftnode=NULL;
	tnode->rightnode=NULL;
	if(root==NULL)
	{
		root=tnode;
	}
	else
	{
		curr=root;
		parent=NULL;
		while(2)
		{
			parent=curr;
			if(value<parent->data)
			{
				curr=curr->leftnode;
				if(curr==NULL)
				{
					parent->leftnode=tnode;
					return;
				}
				
			}
			else
			{
				curr=curr->rightnode;
				if(curr==NULL)
				{
					parent->rightnode=tnode;
					return;
				}
				
			}
		
		}
		
	}
	
}
 void inorder_traversal(struct tree *root)
{
	if(root!=NULL)
	{
		inorder_traversal(root->leftnode);
		printf("%d",root->data);
		inorder_traversal(root->rightnode);
	}
	
}
void postorder_traversal(struct tree *root)
{
	if(root!=NULL)
	{
		postorder_traversal(root->leftnode);
		postorder_traversal(root->rightnode);
		printf("%d",root->data);
	}
}
void preorder_traversal(struct tree *root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		preorder_traversal(root->leftnode);
		preorder_traversal(root->rightnode);
	
	}
}
void main()
{
	int a,i;
	int b[8]={50,30,20,10,70,40,60,80};

	for(i=0;i<8;i++)
	{
		insert(b[i]);
	}
	printf("Inorder traversal is as follows \n ");
	inorder_traversal(root);
	printf("postorder traversal is as follows \n ");
	postorder_traversal(root);
	printf("preorder traversal is as follows \n ");
	preorder_traversal(root);
}

