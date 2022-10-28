#include<stdio.h>
#include<malloc.h>
struct stack
{
	int data;
	struct stack *ptr;
};

struct stack *Top=NULL;


void display()
{
	struct stack *node=Top;
	while(node!=NULL)
	{
		printf("->%d",node->data);
		node=node->ptr;

	}
}

void push()
{
    struct stack *node=(struct stack *)malloc(sizeof(struct stack));
	printf("enter the value to insert");
	fflush(stdin);
	scanf("%d",&node->data);
	node->ptr=Top;
	Top=node;
}


void pop()
{
    struct stack *node=Top;
    Top=Top->ptr;
    free(node);
}

void peep()
{
	return Top->data;
}


int main()
{

	int ch;
	while(5)
	{
		printf("\nenter 1 for push");
		printf("\nenter 2 for pop");
		printf("\nenter 3 for display");
		printf("\nenter 4 for peep");
		printf("\nenter 5 for exit");
		printf("\nenter your menu choice");
		fflush(stdin);
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;

			case 2:
				pop();
				break;

			case 3:
				display();
				break;

			case 4:
				peep();
				break;
			
			case 5:
				return 0;
		}

	}

}
