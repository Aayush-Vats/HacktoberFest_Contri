#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct list
{
	struct list *ptr;
	int data;
};

struct list *first=NULL;
void create()
{
	struct list *node=NULL;
	char ch='f';
	int i=1;
		while(ch=='f' || ch=='F')
			{
				if(i==1)
				{
					node=(struct list *)malloc(sizeof(struct list));
					node->ptr=NULL;
					printf("\n enter the value");
					scanf("%d",&node->data);
					node->ptr=NULL;
					first=node;
					i=i+1;	
				}
				else
				{
					node->ptr=(struct list *)malloc(sizeof(struct list));
					node=node->ptr;
					printf("\n enter the value");
					fflush(stdin);
					scanf("%d",&node->data);
					node->ptr=NULL;
				}
				printf("\n press f to continue");
				fflush(stdin);
				scanf("%c",&ch);
					
			}
		}
void insert_beg()
{
	struct list *node=(struct list *)malloc(sizeof(struct list));
	node=node->ptr;
	printf("\nEnter the value to insert in beginning");
	scanf("%d",&node->data);
	node->ptr=first;
	first=node;
	
}
			
void insert_end()
{
	
}

void insert_pos()
{
}
				
void delete_beg()
{
}

void delete_end()
{
}

void delete_pos()
{
}
	
		
void display()
{
	struct list *node=first;
	while(node!=NULL)
	{
		printf("->%d",node->data);
		node=node->ptr;
	}
}

int main()
{
	int ch;
	create(); 
	while(1)
	{
		printf("\nenter 1 for insert at beginning");
		printf("\nenter 2 for insert at end");
		printf("\nenter 3 for insert at any position");
		printf("\nenter 4 for delete at beginning");
		printf("\nenter 5 for delete at end");
		printf("\nenter 6 for delete at any position");
		printf("\nenter 7 for display");
		printf("\nenter 8 for exit");
		printf("\nenter your menu choice");
		fflush(stdin);
		scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			insert_beg();
			break;
		case 2:
			insert_end();
			break;
		case 3:
			insert_pos();
			break;
		case 4:
			delete_beg();
			break;
		case 5:
			delete_end();
			break;
		case 6:
			delete_pos();
			break;
		case 7:
			display();
			break;
		case 8:
			return 0;
			
				
	}
	
	}
}
