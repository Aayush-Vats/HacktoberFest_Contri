#include<stdio.h>
#include<malloc.h>
struct dlist
{
	int data;
	struct dlist *lptr;
	struct dlist *rptr;
};

struct dlist *first=NULL;
struct dlist *last=NULL;
void create()
{
	struct dlist *node=NULL;
	char ch='y';
	int c=1;
	struct dlist *temp=NULL;
	while(ch=='y' || ch=='Y')
	{
     if(c==1)
		{
			node= (struct dlist *)malloc(sizeof(struct dlist));
			fflush(stdin);
			printf("enter the value ");
			scanf("%d",&node->data);
			node->lptr=NULL;
			node->rptr=NULL;
			first=node;
			last=node;
			c=c+1;
		}
		else
		{
			node->rptr=(struct dlist *)malloc(sizeof(struct dlist));
			temp=node;
			node=node->rptr;
			fflush(stdin);
				printf("enter the value ");
				scanf("%d",&node->data);
				node->rptr=NULL;
				node->lptr=temp;
				last=node;
		}
		fflush(stdin);
		printf("press y to continue");
		scanf("%c",&ch);
		fflush(stdin);
	}
}

void fdisplay()
{
	struct dlist *node=first;
	while(node!=NULL)
	{
		printf("->%d",node->data);
		node=node->rptr;

	}
}
void bdisplay(){

    struct dlist *node=last;
	while(node!=NULL)
	{
		printf("->%d",node->data);
		node=node->lptr;

	}
}

void insert_beg()
{
    struct dlist *node=(struct dlist *)malloc(sizeof(struct dlist));
	printf("enter the value to insert");
	fflush(stdin);
	scanf("%d",&node->data);
	node->lptr=NULL;
	node->rptr=first;
	first=node;
}

void insert_end()
{
    struct dlist *node=(struct dlist *)malloc(sizeof(struct dlist));
	printf("enter the value to insert");
	fflush(stdin);
	scanf("%d",&node->data);
	last->rptr=node;
	node->lptr=last;
	node->rptr=NULL;
	last=node;
    /*
	struct list *node=first;
	while(node->ptr!=NULL)
	{
	node=node->ptr;
	}
	node->ptr=(struct list *)malloc(sizeof(struct list));

	node=node->ptr;
     printf("enter the value to insert");
	fflush(stdin);
	scanf("%d",&node->data);
	node->ptr=NULL;*/
}

void insert_pos()
{
	int i;
	int pos;
	printf("Enter position ");
	fflush(stdin);
	scanf("%d",&pos);
	struct dlist *node=first;
	for(i=0;i<pos-2;i++){
		node=node->rptr;
	}
	int val;
	printf("Enter value to be inserted");
	fflush(stdin);
	scanf("%d",&val);
	struct dlist *n=(struct dlist *)malloc(sizeof(struct dlist));
	n->data=val;
	n->rptr=node->rptr;
	node->rptr->lptr=n;
	n->lptr=node;
	node->rptr=n;

}

void delete_beg()
{
    struct list *node=first;
    first=first->ptr;
    free(node);
}

void delete_end()
{
    struct list *node=first;
    struct list *nnode=first;
    while(node->ptr!=NULL){
        nnode=node;
        node=node->ptr;
    }
    nnode->ptr=NULL;
    free(node);
}

void delete_pos()
{
    int i;
	int pos;
	printf("Enter position ");
	fflush(stdin);
	scanf("%d",&pos);
	struct list *node=first;
	struct list *nnode=first->ptr;
	for(i=0;i<pos-2;i++){
            //node=node->ptr;
            node=node->ptr;
           nnode=nnode->ptr;
	}
	node->ptr=nnode->ptr;
	free(nnode);
	//node->ptr=node->ptr->ptr;
}

void Selection()
{
   struct list *node=first;
   int t;
   struct list *nnode=NULL;
   //int m
   while(node->ptr!=NULL){
    nnode=node->ptr;
    while(nnode!=NULL){
        if(node->data>nnode->data){
            t=node->data;
            node->data=nnode->data;
            nnode->data=t;
        }
        nnode=nnode->ptr;
    }
    node=node->ptr;
   }
}

void Selection(){
 //struct list *node=first;
 struct list *i,*j;
 i=j=NULL;
 int t;
 for(i=first;i->ptr!=NULL;i=i->ptr){
    for(j=i->ptr;j!=NULL;j=j->ptr){
        if(i->data>j->data){
            t=i->data;
            i->data=j->data;
            j->data=t;
        }
    }
 }
}


int main()
{

	int ch;
	create();


	while(5)
	{
		printf("\nenter 1 for insert at beginning");
		printf("\nenter 2 for insert at end");
		printf("\nenter 3 for insert at any position");
		printf("\nenter 4 for delete at beginning");
		printf("\nenter 5 for delete at end");
		printf("\nenter 6 for delete at any position");
		printf("\nenter 7 for fdisplay");
		printf("\nenter 8 for bdisplay");
		printf("\nenter 9 for Selection sort");
		printf("\nenter 10 for exit");
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
				//delete_beg();
				break;

			case 5:
				//delete_end();
				break;

			case 6:
				//delete_pos();
				break;

			case 7:
				fdisplay();
				break;
            case 8:
				bdisplay();
				break;
            case 9:
                //Selection();
                break;
			case 10:
				return 0;
		}

	}

}
