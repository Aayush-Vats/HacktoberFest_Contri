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

void middle_link(node *head)
{
	if(head==NULL)
	{
		cout<<"No node found";
	}
	node *slow=head;
	node *fast=head;
	while(fast!=NULL&&fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<slow->data;
}

void print(node *head)
{
	node *curr=head;
	while(curr!=NULL)
	{
		cout<<" ";
		cout<<curr->data;
		curr=curr->next;
	}
	
}
int main()
{
	node *head=new node(10);
	node *t1=new node(20);
	node *t2=new node(30);
	head->next=t1;
	t1->next=t2;
	print(head);
	cout<<"\n"<<"middle of linked list: "<<"\n";
	middle_link(head);

	
}
	
	
	
	









