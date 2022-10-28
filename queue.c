#include<stdio.h>
#include<malloc.h>
struct queue
{
	int data;
	struct queue *ptr;
};

struct queue *front=NULL;
struct queue *rear=NULL;



void display()
{
	struct queue *node=front;
	while(node!=NULL)
	{
		printf("->%d",node->data);
		node=node->ptr;

	}
}


void insert(int val)
{
	struct queue *node=(struct queue *)malloc(sizeof(struct queue));
	node->data=val;
	node->ptr=NULL;
	if(rear==NULL)
	{
		front=rear=node;
	}
	else
	{
		rear->ptr=node;
		rear=node;
	}
	
}
void Delete()
{
    if(front==NULL)
    {
    	printf("\n queue is empty");
    	return;
	}
	if(front==rear)
	{
		front=rear=NULL;
	}
	else
	{
		front=front->ptr;
		
	}
}


int main()
{

	int ch;
	while(5)
	{
		printf("\nenter 1 for insert");
		printf("\nenter 2 for delete");
		printf("\nenter 3 for display");
		printf("\nenter 4 for exit");
		printf("\nenter your menu choice");
		fflush(stdin);
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert(32);
				insert(54);
				insert(86);
				insert(23);
				insert(11);
				break;

			case 2:
				Delete();
				break;

			case 3:
				display();
				break;

			case 4:
				return 0;
		}

	}

}
