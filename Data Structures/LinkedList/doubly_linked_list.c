#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

struct node* CreateNode(int data) {
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void InsertAtEnd(int data) {
	struct node *temp = CreateNode(data);
	if(root == NULL) {
		root = temp;
		temp->left = root;
	}
	else {
		struct node* p = root;
		while(p->right != NULL) {
			p = p->right;
		}
		p->right = temp;
		temp->left = p;
	}
}

void InsertAtBegin(int data){
	struct node *temp = CreateNode(data);
	if(root == NULL) {
		root = temp;
		temp->left = root;
	}
	else {
		temp->right = root->left;
		temp->left= root;
		root = temp;
	}
}

void InsertAtN(int data, int pos)
{
	struct node *temp = CreateNode(data);
	struct node *p = root;
	int i = 1;
	while(i < pos) {
		p = p->right;
		i++;
	}
	temp->right = p->right;
	p->right = temp;
	temp->left = p;
}

void DeleteAtBegin() {
	struct node* p = root;
	root = p->right;
	root->left = root;
	free(p);
}

void DeleteAtEnd() {
	struct node* p = root;
	while((p->right)->right != NULL) {
		p = p->right;
	}
	// remove p->right
	struct node* temp = p->right;
	p->right = NULL;
	free(temp);
}

void DeleteAtN(int pos) {
	struct node *p = root;
	int i = 1;
	while(i < pos) {
		p = p->right;
		i++;
	}
	(p->left)->right = p->right;
	(p->right)->left = p->left;
	free(p);
}

void Display() {
	struct node* p = root;
	while(p != NULL) {
		printf("%d ", p->data);
		p = p->right;
	}
	printf("\n");
}

int main() {
	InsertAtEnd(10);
	InsertAtEnd(20);
	InsertAtEnd(30);
	InsertAtBegin(40);
	InsertAtN(50,3);
	DeleteAtN(3);
	Display();
}
