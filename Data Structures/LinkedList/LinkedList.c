#include<stdio.h>
#include<stdlib.h>

void create(int);
void insertbeg(int);
void insertend(int);
void deletebeg();
void deleteend();
void display();

struct node
{
	int data;
	struct node* next;
}*head=NULL;

int main()
{
int opt,x,n;

while(1)
{
printf("\n----------------\nEnter option 1: create 2:insertbeg 3:insertend 4:deletebeg 5:deleteend 6:display 7:exit\n");
scanf("%d",&opt);
switch(opt)
{
	case 1: printf("enter no of nodes to create\n");
			scanf("%d",&x);
			create(x);
			break;
		
	case 2: printf("enter data\n");
			scanf("%d",&n);
			insertbeg(n);
			break;

	case 3: printf("enter data\n");
			scanf("%d",&n);
			insertend(n);
			break;

	case 4: deletebeg();
			break;

	case 5: deleteend();
			break;

	case 6: display();
			break;

	case 7: exit(1);

default: printf("Enter valid option\n");		
}
}
return 0;
}

void create(int x)
{	
	int i,n;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	for(i=0;i<x;i++)
	{
		printf("Enter data\n");
		scanf("%d",&n);

		if(head==NULL)
		{	
			temp->next=NULL;
			temp->data=n;
			head=temp;
		}
		else
			insertend(n);
	}
}
void insertbeg(int n)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=head;
	head=temp;
}
void insertend(int n)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	struct node* p;
	p=head;
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
	temp->next=NULL;
	temp->data=n;
}
void deletebeg()
{	
	struct node* p;
	p=head;
	head=head->next;
	free(p);
}
void deleteend()
{
	struct node *p,*q;
	p=head;
	while(p->next->next!=NULL)
		p=p->next;
	q=p->next;
	p->next=NULL;
	free(q);
}
void display()
{
	struct node* p;
	p=head;
	printf("The data present is:\n");
	while(p!=NULL)
	{	
		printf("%d  ",p->data);
		p=p->next;
	}
}
