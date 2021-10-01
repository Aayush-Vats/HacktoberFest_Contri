#include<iostream>//1612
using namespace std;
#define MAX 100
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

/*struct mystack
{
    node *head;
    int pos;
    mystack()
    {
        head=NULL;
        pos=0;
    }*/
    node *head=NULL;
    int pos=0;

    void push(int x)
    {
        node *temp=new node(x);
        if(head==NULL)
        {
            temp->next=NULL;
            head=temp;
        }
        else
        {
           
            temp->next=head;
            head=temp;
            
        }
       
       
    }

    int pop()
    {
        if(head==NULL)
        {
            cout<<"underflow condition";
            return 0;
        }
        else
        {
            int store=head->data;
            node *temp=head;
            head=head->next;
            delete(temp);
            pos--;
            return store;
        }

    }
    int peek()
    {
        if(head==NULL)
        {
            cout<<"Stack is empty";
            return 0;
        }
        else
            return head->data;
    }
    int display()
    {
        if(head==NULL)
        {
            cout<<"Stack is empty";
            return 0;
        }
        else
        {
            node *curr=head;
            while (curr!=NULL)
            {
                cout<<curr->data<<" ";
                curr=curr->next;
            }
        }
    }
    


/*struct stack *top=NULL;
struct stack *push(struct stack *,int);
struct stack *pop(struct stack *);
struct stack *peek(struct stack *);
struct stack *display(struct stack *);*/

int main()
{
	
	int option,val;
	do
	{

	
	cout<<"MENU"<<endl;
	cout<<"1.Push"<<endl;
	cout<<"2.Pop"<<endl;
	cout<<"3.Display"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Enter the option"<<endl;
	cin>>option;
	
	switch(option)
	{
		case 1:
			cout<<"Enter the no you want to add: ";
			cin>>val;
			push(val);
			break;
		case 2:
			cout<<"head deleted";
			pop();
			break;
		case 3:
			cout<<"Display: ";
			display();
			break;
		case 4:
			cout<<"Top of the stack: ";
			peek();
			break;
		
	}
	}
	while(option != 5);
    	return 0;
		

	
}

