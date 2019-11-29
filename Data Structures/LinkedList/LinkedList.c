#include<stdio.h>
#include<stdlib.h>

void Create(int);
void InsertBeginning(int);
void InsertEnd(int);
void DeleteBeginning();
void DeleteEnd();
void Display();

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
		printf("\n----------------\nEnter option 1: Create 2:InsertBeginning 3:InsertEnd 4:DeleteBeginning 5:DeleteEnd 6:Display 7:exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: printf("enter no of nodes to Create\n");
				scanf("%d",&x);
				Create(x);
				break;
		
			case 2: printf("enter data\n");
				scanf("%d",&n);
				InsertBeginning(n);
				break;

			case 3: printf("enter data\n");
				scanf("%d",&n);
				InsertEnd(n);
				break;

			case 4: DeleteBeginning();
				break;

			case 5: DeleteEnd();
				break;

			case 6: Display();
				break;

			case 7: exit(1);

			default: printf("Enter valid option\n");		
		}
	}
return 0;
}

void Create(int x)
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
			InsertEnd(n);
	}
}
void InsertBeginning(int n)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=head;
	head=temp;
}
void InsertEnd(int n)
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
void DeleteBeginning()
{	
	struct node* p;
	p=head;
	head=head->next;
	free(p);
}
void DeleteEnd()
{
	struct node *p,*q;
	p=head;
	while(p->next->next!=NULL)
		p=p->next;
	q=p->next;
	p->next=NULL;
	free(q);
}
void Display()
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
