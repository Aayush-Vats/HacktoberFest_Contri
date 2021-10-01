#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};

void sorted_insert(node *head,int x)
{
	 node *curr=head;
	 node *temp=new node(x);
	if(head==NULL)
	{
		cout<<temp->data;
	}
//	if(x<head->NULL)
//	{
//		temp->next=head;
//		cout<<temp->data;
//	}
	
	
	while(curr->next!=NULL&&curr->next->data<temp->data)
	{

		curr=curr->next;
	}
	temp->next=curr->next;
	curr->next=temp;

}


void print(node *head)
{
	node *curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data;
		curr=curr->next;
	}

}

int main()
{

	node *head;//=new node(0);
	node *t;//=new node(0);
	node *t1;//=new node(0);
	node *t2;//=new node(0);
	head->next=t;
	t->next=t1;
	t1->next=t2;
	sorted_insert(head,48);
	print(head);
	return 0;
	

}
